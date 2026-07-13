"""
EdgeVision Camera Service
"""

import cv2
from edgevision_core.config import config


class CameraService:
    """Handles camera initialization and frame capture."""

    def __init__(self):
        self.cap = None

    def initialize(self):
        """Open the camera."""

        source = config.camera["source"]

        self.cap = cv2.VideoCapture(source)

        if not self.cap.isOpened():
            raise RuntimeError(f"Unable to open camera: {source}")

        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, config.camera["width"])
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, config.camera["height"])
        self.cap.set(cv2.CAP_PROP_FPS, config.camera["fps"])

        print("[INFO] Camera initialized.")

    def read(self):
        """Read a frame."""

        if self.cap is None:
            return False, None

        return self.cap.read()

    def release(self):
        """Release camera resources."""

        if self.cap is not None:
            self.cap.release()

        cv2.destroyAllWindows()

        print("[INFO] Camera released.")