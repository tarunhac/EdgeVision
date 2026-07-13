"""
EdgeVision Database Service
"""

from pathlib import Path
import sqlite3

from edgevision_core.config import config


class DatabaseService:
    """
    Handles all SQLite database operations.

    Responsibilities:
    - Create/open the database
    - Create required tables
    - Insert events
    - Close the database

    This service does NOT:
    - Save images
    - Perform recognition
    - Perform detection
    - Log events
    """

    def __init__(self):

        self.db_dir = Path(config.storage["logs"])
        self.db_path = self.db_dir / "events.db"

        self.connection = None
        self.cursor = None

    def initialize(self):

        self.db_dir.mkdir(
            parents=True,
            exist_ok=True
        )

        self.connection = sqlite3.connect(
            self.db_path
        )

        self.cursor = self.connection.cursor()

        self.cursor.execute(
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

        self.cursor.execute(
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

        if self.connection:

            self.connection.close()

            self.connection = None
            self.cursor = None