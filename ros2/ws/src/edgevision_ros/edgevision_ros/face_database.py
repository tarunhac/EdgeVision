import cv2
import numpy as np
from pathlib import Path

from insightface.app import FaceAnalysis


class FaceDatabase:

    def __init__(self):

        self.face_app = FaceAnalysis(
            providers=["CPUExecutionProvider"]
        )

        self.face_app.prepare(
            ctx_id=0,
            det_size=(640, 640)
        )

        self.embeddings = []

        self.threshold = 0.50


    def load(self, known_faces_dir):
        self.embeddings.clear()

        known_faces_dir = Path(known_faces_dir)

        print("=" * 60)
        print("Loading Face Database")
        print("Directory :", known_faces_dir)
        print("=" * 60)

        if not known_faces_dir.exists():
            print("Directory does not exist!")
            return

        image_files = []

        for extension in ("*.jpg", "*.jpeg", "*.png"):
            image_files.extend(
                known_faces_dir.rglob(extension)
            )

        print(f"Found {len(image_files)} image(s)")

        if len(image_files) == 0:
            print("ERROR: No images found!")
            return

        for image_path in image_files:

            print(f"Loading: {image_path}")

            image = cv2.imread(str(image_path))

            if image is None:
                print(f"Could not read {image_path.name}")
                continue

            faces = self.face_app.get(image)

            if len(faces) == 0:
                print(f"No face detected in {image_path.name}")
                continue

            embedding = faces[0].embedding

            person_name = image_path.parent.name

            self.embeddings.append(
                (
                    person_name,
                    embedding
                )
            )

            print(f"Loaded face for {person_name}")

        print("=" * 60)
        print(f"Loaded {len(self.embeddings)} known face(s)")
        print("=" * 60)


    def match(self, query_embedding):

        if len(self.embeddings) == 0:

            return (
                "Unknown",
                0.0,
                False
            )

        query_embedding = (
            query_embedding /
            np.linalg.norm(query_embedding)
        )

        best_name = "Unknown"

        best_similarity = -1.0
       

        for name, embedding in self.embeddings:

            embedding = (
                embedding /
                np.linalg.norm(embedding)
            )

            similarity = float(
                np.dot(
                    query_embedding,
                    embedding
                )
            )

            if similarity > best_similarity:

                best_similarity = similarity

                best_name = name
        print(f"Best Match: {best_name}")
        print(f"Similarity: {best_similarity:.4f}")
        print(f"Threshold: {self.threshold}")
        print(
            f"Best Match : {best_name} ({best_similarity:.3f})"
        )

        if best_similarity >= self.threshold:

            return (
                best_name,
                best_similarity,
                True
            )

        return (
            "Unknown",
            best_similarity,
            False
        )