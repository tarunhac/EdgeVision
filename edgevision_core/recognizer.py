"""
EdgeVision Face Recognition Service
"""

from pathlib import Path

import cv2
import insightface
import numpy as np

from edgevision_core.config import config


class RecognizerService:
    """
    Recognizes faces inside detected person bounding boxes.
    """

    def __init__(self):

        self.app = None

        self.known_embeddings = []
        self.known_names = []

    def initialize(self):

        print("[INFO] Initializing Face Recognizer...")

        self.app = insightface.app.FaceAnalysis(
            providers=[config.recognizer["provider"]]
        )

        self.app.prepare(
            ctx_id=0,
            det_size=(640, 640)
        )

        self.load_known_faces()

        print(f"[INFO] Loaded {len(self.known_names)} identities.")

    def load_known_faces(self):

        self.known_embeddings.clear()
        self.known_names.clear()

        faces_dir = Path(config.storage["known_faces"])

        if not faces_dir.exists():

            print("[WARNING] known_faces directory not found.")

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

                embedding /= np.linalg.norm(embedding)

                person_embeddings.append(embedding)

            if len(person_embeddings) == 0:
                continue

            average_embedding = np.mean(
                person_embeddings,
                axis=0
            )

            average_embedding /= np.linalg.norm(
                average_embedding
            )

            self.known_embeddings.append(
                average_embedding
            )

            self.known_names.append(
                person_dir.name
            )

    def recognize_detection(self, frame, detection):
        """
        Updates a Detection object with name and similarity.
        """

        x1 = max(0, detection.x1)
        y1 = max(0, detection.y1)
        x2 = min(frame.shape[1], detection.x2)
        y2 = min(frame.shape[0], detection.y2)

        person = frame[y1:y2, x1:x2]

        if person.size == 0:
            return

        faces = self.app.get(person)

        if len(faces) == 0:
            return

        face = faces[0]

        embedding = face.embedding
        embedding /= np.linalg.norm(embedding)

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

        if best_similarity >= config.recognizer["similarity_threshold"]:

            detection.name = best_name

        else:

            detection.name = "Unknown"

        detection.similarity = best_similarity