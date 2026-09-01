"""
EdgeVision Event Logger

Asynchronous event logging.

Disk I/O and SQLite operations are performed by a background
worker so they never block the real-time detection loop.
"""

from pathlib import Path
from datetime import datetime
import csv
import queue
import threading

from edgevision_core.config import config
from edgevision_core.face_snapshot import FaceSnapshotService
from edgevision_core.database import DatabaseService


class EventLogger:
    """
    Logs unknown person events asynchronously.

    The main surveillance loop only places an event into a queue.
    Image saving and database operations happen in a worker thread.
    """

    def __init__(self):

        # ---------------------------------------------------------
        # Prevent duplicate logging for the same track
        # ---------------------------------------------------------

        self.logged_tracks = set()
        self.track_lock = threading.Lock()

        # ---------------------------------------------------------
        # Services
        # ---------------------------------------------------------

        self.snapshot = FaceSnapshotService()
        self.database = DatabaseService()

        # ---------------------------------------------------------
        # CSV
        # ---------------------------------------------------------

        self.log_dir = Path(config.storage["logs"])
        self.log_file = self.log_dir / "events.csv"

        # ---------------------------------------------------------
        # Background event queue
        # ---------------------------------------------------------

        self.event_queue = queue.Queue(maxsize=20)

        self.worker_thread = None
        self.worker_running = False

    def initialize(self):

        self.snapshot.initialize()
        self.database.initialize()

        self.log_dir.mkdir(
            parents=True,
            exist_ok=True
        )

        if not self.log_file.exists():

            with open(
                self.log_file,
                "w",
                newline=""
            ) as file:

                writer = csv.writer(file)

                writer.writerow([
                    "timestamp",
                    "track_id",
                    "name",
                    "similarity",
                    "face_image",
                    "frame_image"
                ])

        # ---------------------------------------------------------
        # Start background worker
        # ---------------------------------------------------------

        self.worker_running = True

        self.worker_thread = threading.Thread(
            target=self._worker,
            daemon=True
        )

        self.worker_thread.start()

        print("[INFO] Event Logger initialized")
        print("[INFO] Event Logger Worker started")

    def log_unknown(self, frame, detection):
        """
        Queue an unknown-person event.

        IMPORTANT:
        This function does NOT perform disk I/O or database I/O.
        """

        track_id = detection.track_id

        if track_id is None:
            return

        # ---------------------------------------------------------
        # Check duplicate track
        # ---------------------------------------------------------

        with self.track_lock:

            if track_id in self.logged_tracks:
                return

            self.logged_tracks.add(track_id)

        # ---------------------------------------------------------
        # Copy frame because the camera frame will be reused.
        # ---------------------------------------------------------

        frame_copy = frame.copy()

        # ---------------------------------------------------------
        # Copy only the information required by the worker.
        # ---------------------------------------------------------

        event = (
            frame_copy,
            detection.x1,
            detection.y1,
            detection.x2,
            detection.y2,
            track_id,
            detection.name,
            detection.similarity
        )

        try:

            self.event_queue.put_nowait(event)

        except queue.Full:

            # Never allow logging to block detection.
            print(
                "[WARNING] Event queue full - "
                "dropping event"
            )

    def _worker(self):
        """
        Background event-processing worker.
        """

        while self.worker_running:

            try:

                event = self.event_queue.get(
                    timeout=0.1
                )

            except queue.Empty:

                continue

            try:

                self._process_event(event)

            except Exception as exc:

                print(
                    f"[ERROR] Event logger worker: {exc}"
                )

            finally:

                self.event_queue.task_done()

    def _process_event(self, event):

        (
            frame,
            x1,
            y1,
            x2,
            y2,
            track_id,
            name,
            similarity
        ) = event

        # ---------------------------------------------------------
        # Reconstruct a minimal detection-like object.
        # ---------------------------------------------------------

        class EventDetection:

            pass

        detection = EventDetection()

        detection.x1 = x1
        detection.y1 = y1
        detection.x2 = x2
        detection.y2 = y2
        detection.track_id = track_id

        # ---------------------------------------------------------
        # Save images
        # ---------------------------------------------------------

        face_path, frame_path = self.snapshot.save(
            frame,
            detection
        )

        timestamp = datetime.now().strftime(
            "%Y-%m-%d %H:%M:%S"
        )

        similarity = round(
            similarity,
            3
        )

        # ---------------------------------------------------------
        # SQLite
        # ---------------------------------------------------------

        self.database.insert_event(
            timestamp,
            track_id,
            name,
            similarity,
            face_path,
            frame_path
        )

        # ---------------------------------------------------------
        # CSV
        # ---------------------------------------------------------

        with open(
            self.log_file,
            "a",
            newline=""
        ) as file:

            writer = csv.writer(file)

            writer.writerow([
                timestamp,
                track_id,
                name,
                similarity,
                face_path,
                frame_path
            ])

        print(
            f"[EVENT] Unknown person logged "
            f"(Track {track_id})"
        )

    def shutdown(self):
        """
        Stop worker and finish queued events.
        """

        self.worker_running = False

        if self.worker_thread is not None:

            self.worker_thread.join(
                timeout=2.0
            )

            self.worker_thread = None

        self.database.close()

        print("[INFO] Event Logger Worker stopped")