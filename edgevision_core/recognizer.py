"""
EdgeVision Face Recognition Service

Asynchronous, track-aware face recognition.

InsightFace runs in a background worker so that expensive
face recognition cannot block the main YOLO/video loop.
"""

from pathlib import Path
import queue
import threading
import time

import cv2
import insightface
import numpy as np

from edgevision_core.config import config


class RecognizerService:
    """
    Recognizes faces inside detected person bounding boxes.

    The main thread submits recognition requests.
    A background worker performs the expensive InsightFace operation.

    Recognition is rate-limited per tracking ID.
    """

    def __init__(self):

        self.app = None

        self.known_embeddings = []
        self.known_names = []

        # ---------------------------------------------------------
        # Recognition cache
        # ---------------------------------------------------------

        # track_id -> {
        #     "name": str,
        #     "similarity": float,
        #     "time": float
        # }
        self.track_cache = {}

        self.cache_lock = threading.Lock()

        # ---------------------------------------------------------
        # Background recognition worker
        # ---------------------------------------------------------

        # Small queue is intentional.
        #
        # We do NOT want old recognition requests building up.
        # A stale face is less useful than the newest frame.
        self.request_queue = queue.Queue(maxsize=2)

        self.worker_thread = None
        self.worker_running = False

        # ---------------------------------------------------------
        # Recognition timing
        # ---------------------------------------------------------

        # Same track will not be submitted more than once/sec.
        self.recognition_interval = 1.0

        # Tracks are removed from cache after this period.
        self.cache_max_age = 10.0

    def initialize(self):

        print("[INFO] Initializing Face Recognizer...")

        self.app = insightface.app.FaceAnalysis(
            providers=[config.recognizer["provider"]]
        )

        self.app.prepare(
            ctx_id=0,
            det_size=(320, 320)
        )

        # Load known faces BEFORE starting the worker.
        self.load_known_faces()

        print(
            f"[INFO] Loaded {len(self.known_names)} identities."
        )

        # Start background worker.
        self.worker_running = True

        self.worker_thread = threading.Thread(
            target=self._recognition_worker,
            daemon=True
        )

        self.worker_thread.start()

        print("[INFO] Face Recognition Worker started")

    def load_known_faces(self):

        self.known_embeddings.clear()
        self.known_names.clear()

        faces_dir = Path(config.storage["known_faces"])

        if not faces_dir.exists():

            print(
                "[WARNING] known_faces directory not found."
            )

            return

        for person_dir in faces_dir.iterdir():

            if not person_dir.is_dir():
                continue

            person_embeddings = []

            for image_path in person_dir.iterdir():

                image = cv2.imread(str(image_path))

                if image is None:
                    continue

                faces = self.app.get(image)

                if len(faces) == 0:
                    continue

                embedding = faces[0].embedding

                norm = np.linalg.norm(embedding)

                if norm == 0:
                    continue

                embedding /= norm

                person_embeddings.append(embedding)

            if len(person_embeddings) == 0:
                continue

            average_embedding = np.mean(
                person_embeddings,
                axis=0
            )

            norm = np.linalg.norm(average_embedding)

            if norm == 0:
                continue

            average_embedding /= norm

            self.known_embeddings.append(
                average_embedding
            )

            self.known_names.append(
                person_dir.name
            )

    def recognize_detection(self, frame, detection):
        """
        Handle recognition for one tracked detection.

        IMPORTANT:
        This function does NOT call InsightFace directly.

        It either:
        1. applies a cached result, or
        2. submits a request to the background worker.
        """

        track_id = detection.track_id

        # ---------------------------------------------------------
        # No tracking ID
        # ---------------------------------------------------------

        if track_id is None:

            # For now, do not block the main loop.
            #
            # Since there is no stable ID, asynchronous recognition
            # cannot be reliably associated with the detection.
            #
            # We simply leave it Unknown.
            detection.name = "Unknown"
            detection.similarity = 0.0

            return

        current_time = time.time()

        # ---------------------------------------------------------
        # Check cached result
        # ---------------------------------------------------------

        with self.cache_lock:

            cached = self.track_cache.get(track_id)

        if cached is not None:

            detection.name = cached["name"]
            detection.similarity = cached["similarity"]

            elapsed = current_time - cached["time"]

            # Recognition result is still fresh.
            if elapsed < self.recognition_interval:

                return

        # ---------------------------------------------------------
        # Submit a new recognition request
        # ---------------------------------------------------------

        self._submit_request(
            frame,
            detection,
            current_time
        )

        # Apply the last known result immediately.
        if cached is not None:

            detection.name = cached["name"]
            detection.similarity = cached["similarity"]

        else:

            detection.name = "Unknown"
            detection.similarity = 0.0

        # Cleanup old tracks.
        self._cleanup_cache(current_time)

    def _submit_request(self, frame, detection, current_time):
        """
        Submit a recognition request without blocking the main loop.
        """

        x1 = max(0, detection.x1)
        y1 = max(0, detection.y1)
        x2 = min(frame.shape[1], detection.x2)
        y2 = min(frame.shape[0], detection.y2)

        if x2 <= x1 or y2 <= y1:
            return

        person = frame[y1:y2, x1:x2]

        if person.size == 0:
            return

        # Copy the crop because the original frame will be reused
        # by the main camera loop.
        person_copy = person.copy()

        request = (
            detection.track_id,
            person_copy,
            current_time
        )

        try:

            self.request_queue.put_nowait(request)

        except queue.Full:

            # Worker is busy.
            #
            # Drop this request instead of blocking the video loop.
            pass

    def _recognition_worker(self):
        """
        Background worker responsible for InsightFace inference.
        """

        while self.worker_running:

            try:

                track_id, person, request_time = (
                    self.request_queue.get(timeout=0.1)
                )

            except queue.Empty:

                continue

            try:

                name, similarity = self._run_recognition(
                    person
                )

                # Store result.
                with self.cache_lock:

                    self.track_cache[track_id] = {
                        "name": name,
                        "similarity": similarity,
                        "time": time.time()
                    }

            except Exception as exc:

                print(
                    f"[ERROR] Face recognition worker: {exc}"
                )

            finally:

                self.request_queue.task_done()

    def _run_recognition(self, person):
        """
        Perform one actual InsightFace recognition operation.

        This function is ONLY called by the background worker.
        """

        faces = self.app.get(person)

        if len(faces) == 0:

            return "Unknown", 0.0

        face = faces[0]

        embedding = face.embedding

        norm = np.linalg.norm(embedding)

        if norm == 0:

            return "Unknown", 0.0

        embedding /= norm

        best_similarity = -1.0
        best_name = "Unknown"

        for known_embedding, name in zip(
            self.known_embeddings,
            self.known_names
        ):

            similarity = float(
                np.dot(
                    embedding,
                    known_embedding
                )
            )

            if similarity > best_similarity:

                best_similarity = similarity
                best_name = name

        if (
            best_similarity
            >= config.recognizer["similarity_threshold"]
        ):

            return best_name, best_similarity

        return "Unknown", best_similarity

    def _cleanup_cache(self, current_time):
        """
        Remove recognition results belonging to old tracks.
        """

        with self.cache_lock:

            expired_tracks = [
                track_id
                for track_id, data in self.track_cache.items()
                if current_time - data["time"]
                > self.cache_max_age
            ]

            for track_id in expired_tracks:

                del self.track_cache[track_id]

    def shutdown(self):
        """
        Stop the background recognition worker.
        """

        self.worker_running = False

        if self.worker_thread is not None:

            self.worker_thread.join(timeout=2.0)

            self.worker_thread = None

        print("[INFO] Face Recognition Worker stopped")