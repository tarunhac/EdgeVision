"""
EdgeVision Event Logger
"""

from pathlib import Path
from datetime import datetime
import csv

from src.config import config
from src.face_snapshot import FaceSnapshotService


class EventLogger:
    """
    Logs unknown person events.
    Each track ID is logged only once.
    """

    def __init__(self):

        self.logged_tracks = set()

        self.snapshot = FaceSnapshotService()

        self.log_dir = Path(config.storage["logs"])
        self.log_file = self.log_dir / "events.csv"

    def initialize(self):

        self.snapshot.initialize()

        self.log_dir.mkdir(
            parents=True,
            exist_ok=True
        )

        if not self.log_file.exists():

            with open(self.log_file, "w", newline="") as file:

                writer = csv.writer(file)

                writer.writerow([
                    "timestamp",
                    "track_id",
                    "name",
                    "similarity",
                    "face_image",
                    "frame_image"
                ])

        print("[INFO] Event Logger initialized")

    def log_unknown(self, frame, detection):

        if detection.track_id is None:
            return

        if detection.track_id in self.logged_tracks:
            return

        self.logged_tracks.add(detection.track_id)

        face_path, frame_path = self.snapshot.save(
            frame,
            detection
        )

        with open(self.log_file, "a", newline="") as file:

            writer = csv.writer(file)

            writer.writerow([
                datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
                detection.track_id,
                detection.name,
                round(detection.similarity, 3),
                face_path,
                frame_path
            ])

        print(
            f"[EVENT] Unknown person logged "
            f"(Track {detection.track_id})"
        )