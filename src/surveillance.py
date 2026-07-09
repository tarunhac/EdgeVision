"""
EdgeVision Surveillance System
"""

import time

import cv2

from src.camera import CameraService
from src.config import config
from src.renderer import RendererService


class SurveillanceSystem:
    """
    Main application controller.
    """

    def __init__(self):

        self.camera = CameraService()
        self.renderer = RendererService()

        self.running = False

        self.previous_time = time.time()

    def initialize(self):

        self.camera.initialize()

        self.running = True

        print("[INFO] EdgeVision Started")

    def process_frame(self, frame):

        current_time = time.time()

        fps = 1 / (current_time - self.previous_time)

        self.previous_time = current_time

        frame = self.renderer.draw_fps(frame, fps)

        return frame

    def run(self):

        self.initialize()

        while self.running:

            ret, frame = self.camera.read()

            if not ret:
                print("[ERROR] Camera read failed.")
                break

            frame = self.process_frame(frame)

            self.renderer.show(
                config.display["window_name"],
                frame
            )

            key = cv2.waitKey(1) & 0xFF

            if key == ord("q"):
                break

        self.shutdown()

    def shutdown(self):

        self.running = False

        self.camera.release()

        print("[INFO] EdgeVision Stopped")