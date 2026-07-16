"""
EdgeVision ROS2 Face Database
"""

from pathlib import Path

import cv2
import numpy as np

from insightface.app import FaceAnalysis


class FaceDatabase:

    def __init__(self):

        self.app = FaceAnalysis(
            providers=["CPUExecutionProvider"]
        )

        self.app.prepare(
            ctx_id=0,
            det_size=(640, 640)
        )

        self.database = {}


    def load(self, known_faces_dir):

        self.database.clear()

        known_faces_dir = Path(known_faces_dir)

        if not known_faces_dir.exists():
            print("[WARNING] known_faces directory not found.")
            return


        for person_dir in known_faces_dir.iterdir():

            if not person_dir.is_dir():
                continue


            embeddings = []


            for image_path in person_dir.iterdir():

                image = cv2.imread(
                    str(image_path)
                )

                if image is None:
                    continue


                faces = self.app.get(image)


                if len(faces) == 0:
                    continue


                embedding = faces[0].embedding

                embedding = (
                    embedding /
                    np.linalg.norm(embedding)
                )

                embeddings.append(
                    embedding
                )


            if len(embeddings) == 0:
                continue


            average_embedding = np.mean(
                embeddings,
                axis=0
            )


            average_embedding = (
                average_embedding /
                np.linalg.norm(average_embedding)
            )


            self.database[
                person_dir.name
            ] = average_embedding


        print(
            f"[INFO] Loaded {len(self.database)} identities."
        )


    def match(
        self,
        embedding,
        threshold=0.45
    ):

        if len(self.database) == 0:

            return (
                "Unknown",
                0.0,
                False
            )


        embedding = (
            embedding /
            np.linalg.norm(embedding)
        )


        best_name = "Unknown"
        best_similarity = -1.0


        for name, known_embedding in self.database.items():

            similarity = float(
                np.dot(
                    embedding,
                    known_embedding
                )
            )


            if similarity > best_similarity:

                best_similarity = similarity
                best_name = name



        if best_similarity >= threshold:

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