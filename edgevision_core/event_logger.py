"""
EdgeVision Event Logger
"""

from pathlib import Path
from datetime import datetime
import csv

from edgevision_core.config import config
from edgevision_core.face_snapshot import FaceSnapshotService
from edgevision_core.database import DatabaseService


class EventLogger:
    """
    Logs unknown person events.
    Each track ID is logged only once.
    """

    def __init__(self):

        self.logged_tracks = set()

        self.snapshot = FaceSnapshotService()
        self.database = DatabaseService()

        self.log_dir = Path(config.storage["logs"])
        self.log_file = self.log_dir / "events.csv"

    def initialize(self):

        self.snapshot.initialize()
        self.database.initialize()

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

        timestamp = datetime.now().strftime(
            "%Y-%m-%d %H:%M:%S"
        )

        similarity = round(
            detection.similarity,
            3
        )

        self.database.insert_event(
            timestamp,
            detection.track_id,
            detection.name,
            similarity,
            face_path,
            frame_path
        )

        with open(self.log_file, "a", newline="") as file:

            writer = csv.writer(file)

            writer.writerow([
                timestamp,
                detection.track_id,
                detection.name,
                similarity,
                face_path,
                frame_path
            ])

        print(
            f"[EVENT] Unknown person logged "
            f"(Track {detection.track_id})"
        )

    def shutdown(self):

      

      self.database.close()

    