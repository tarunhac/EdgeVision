"""
EdgeVision ROS2 Face Recognizer
"""

from insightface.app import FaceAnalysis

from edgevision_ros.face_database import FaceDatabase


class FaceRecognizer:


    def __init__(self, known_faces_dir):

        self.face_app = FaceAnalysis(
            providers=[
                "CPUExecutionProvider"
            ]
        )


        self.face_app.prepare(
            ctx_id=0,
            det_size=(640, 640)
        )


        self.database = FaceDatabase()


        self.database.load(
            known_faces_dir
        )



    def recognize(self, person_roi):

        if person_roi is None:

            return (
                "Unknown",
                0.0,
                False,
                None
            )


        if person_roi.size == 0:

            return (
                "Unknown",
                0.0,
                False,
                None
            )



        faces = self.face_app.get(
            person_roi
        )


        if len(faces) == 0:

            return (
                "Unknown",
                0.0,
                False,
                None
            )



        face = faces[0]


        name, similarity, is_known = (
            self.database.match(
                face.embedding
            )
        )



        return (
            name,
            similarity,
            is_known,
            face
        )