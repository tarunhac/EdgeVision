"""
EdgeVision Face Snapshot Service
"""

from pathlib import Path
from datetime import datetime

import cv2

from src.config import config


class FaceSnapshotService:
    """
    Responsible only for saving images.

    This service does not perform recognition or logging.
    """

    def __init__(self):

        self.root = Path(config.storage["unknown_faces"])

        self.face_dir = self.root / "faces"
        self.frame_dir = self.root / "frames"

    def initialize(self):

        self.face_dir.mkdir(
            parents=True,
            exist_ok=True
        )

        self.frame_dir.mkdir(
            parents=True,
            exist_ok=True
        )

        print("[INFO] Face Snapshot Service initialized")

    def save(self, frame, detection):

        timestamp = datetime.now().strftime(
            "%Y%m%d_%H%M%S"
        )

        face_filename = (
            f"track_{detection.track_id}_{timestamp}.jpg"
        )

        frame_filename = (
            f"frame_{detection.track_id}_{timestamp}.jpg"
        )

        face_path = self.face_dir / face_filename
        frame_path = self.frame_dir / frame_filename

        x1 = max(0, detection.x1)
        y1 = max(0, detection.y1)
        x2 = min(frame.shape[1], detection.x2)
        y2 = min(frame.shape[0], detection.y2)

        person_crop = frame[y1:y2, x1:x2]

        if person_crop.size != 0:
            cv2.imwrite(
                str(face_path),
                person_crop
            )

        cv2.imwrite(
            str(frame_path),
            frame
        )

        return (
            str(face_path),
            str(frame_path)
        )