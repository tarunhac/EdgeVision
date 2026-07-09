"""
EdgeVision Surveillance System
"""

import cv2

from src.camera import CameraService
from src.detector import DetectorService
from src.config import config


class SurveillanceSystem:

    def __init__(self):
        self.camera = CameraService()
        self.detector = DetectorService()
        self.running = False

    def initialize(self):
        self.camera.initialize()
        self.detector.initialize()

        self.running = True

        print("[INFO] Surveillance System Started")

    def process_frame(self, frame):

        detections = self.detector.detect(frame)

        for det in detections:

            x1, y1, x2, y2 = det["bbox"]
            confidence = det["confidence"]

            cv2.rectangle(
                frame,
                (x1, y1),
                (x2, y2),
                (0, 255, 0),
                2
            )

            cv2.putText(
                frame,
                f"{confidence:.2f}",
                (x1, y1 - 10),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.6,
                (0, 255, 0),
                2
            )

        return frame

    def run(self):

        self.initialize()

        while self.running:

            ret, frame = self.camera.read()

            if not ret:
                print("[ERROR] Failed to read frame.")
                break

            frame = self.process_frame(frame)

            cv2.imshow(config.display["window_name"], frame)

            if cv2.waitKey(1) & 0xFF == ord("q"):
                break

        self.shutdown()

    def shutdown(self):

        self.running = False
        self.camera.release()

        print("[INFO] Surveillance System Stopped")