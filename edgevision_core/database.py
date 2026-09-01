"""
EdgeVision Database Service
"""

from pathlib import Path
import sqlite3
import threading

from edgevision_core.config import config


class DatabaseService:
    """
    Handles SQLite database operations.

    SQLite connection is protected by a lock so that
    Event Logger worker threads can safely use the database.
    """

    def __init__(self):

        self.db_dir = Path(config.storage["logs"])
        self.db_path = self.db_dir / "events.db"

        self.connection = None
        self.lock = threading.Lock()

    def initialize(self):

        self.db_dir.mkdir(
            parents=True,
            exist_ok=True
        )

        # Allow the connection to be used by the Event Logger worker.
        self.connection = sqlite3.connect(
            self.db_path,
            check_same_thread=False
        )

        self.connection.execute(
            """
            CREATE TABLE IF NOT EXISTS events (

                id INTEGER PRIMARY KEY AUTOINCREMENT,

                timestamp TEXT NOT NULL,

                track_id INTEGER NOT NULL,

                name TEXT NOT NULL,

                similarity REAL NOT NULL,

                face_image TEXT NOT NULL,

                frame_image TEXT NOT NULL
            )
            """
        )

        self.connection.commit()

        print("[INFO] Database Service initialized")

    def insert_event(
        self,
        timestamp,
        track_id,
        name,
        similarity,
        face_image,
        frame_image
    ):

        if self.connection is None:
            return

        with self.lock:

            self.connection.execute(
                """
                INSERT INTO events (
                    timestamp,
                    track_id,
                    name,
                    similarity,
                    face_image,
                    frame_image
                )
                VALUES (?, ?, ?, ?, ?, ?)
                """,
                (
                    timestamp,
                    track_id,
                    name,
                    similarity,
                    face_image,
                    frame_image
                )
            )

            self.connection.commit()

    def close(self):

        if self.connection is not None:

            with self.lock:

                self.connection.close()

                self.connection = None