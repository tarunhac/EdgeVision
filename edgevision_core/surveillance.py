
"""
EdgeVision Surveillance System

Real-time surveillance pipeline.

Pipeline:

Camera
    ↓
Latest-frame capture
    ↓
YOLO detection + tracking
    ↓
Asynchronous face recognition
    ↓
Rendering
    ↓
Display

Event logging is triggered only when a recognition result
has actually been produced.
"""

import time
import cv2

from edgevision_core.camera import CameraService
from edgevision_core.detector import DetectorService
from edgevision_core.recognizer import RecognizerService
from edgevision_core.renderer import RendererService
from edgevision_core.config import config
from edgevision_core.event_logger import EventLogger


class SurveillanceSystem:

    def __init__(self):

        self.camera = CameraService()
        self.detector = DetectorService()
        self.recognizer = RecognizerService()
        self.renderer = RendererService()
        self.logger = EventLogger()

        self.running = False

        self.previous_time = time.time()

        # ---------------------------------------------------------
        # Performance monitoring
        # ---------------------------------------------------------

        self.frame_count = 0

        self.fps_start_time = time.time()

        self.average_fps = 0.0

    def initialize(self):

        self.camera.initialize()
        self.detector.initialize()
        self.recognizer.initialize()
        self.logger.initialize()

        self.running = True

        print("[INFO] EdgeVision Started")

    def process_frame(self, frame):

        frame_start = time.time()

        # ---------------------------------------------------------
        # YOLO detection + tracking
        # ---------------------------------------------------------

        detections = self.detector.detect(frame)

        # ---------------------------------------------------------
        # Face recognition
        #
        # IMPORTANT:
        # recognize_detection() is asynchronous.
        #
        # It does NOT block the YOLO loop.
        # ---------------------------------------------------------

        for detection in detections:

            self.recognizer.recognize_detection(
                frame,
                detection
            )

        # ---------------------------------------------------------
        # Event logging
        #
        # Only log a detection when it has a valid recognition
        # result.
        #
        # The recognizer uses similarity > 0 to indicate that
        # InsightFace has actually produced a result.
        # ---------------------------------------------------------

        for detection in detections:

            if (
                detection.name == "Unknown"
                and detection.similarity > 0.0
            ):

                self.logger.log_unknown(
                    frame,
                    detection
                )

        # ---------------------------------------------------------
        # Rendering
        # ---------------------------------------------------------

        frame = self.renderer.draw_detections(
            frame,
            detections
        )

        # ---------------------------------------------------------
        # Performance calculation
        # ---------------------------------------------------------

        frame_time = time.time() - frame_start

        if frame_time > 0:

            instant_fps = 1.0 / frame_time

        else:

            instant_fps = 0.0

        # ---------------------------------------------------------
        # Smooth FPS measurement
        # ---------------------------------------------------------

        self.frame_count += 1

        elapsed = time.time() - self.fps_start_time

        if elapsed >= 2.0:

            self.average_fps = (
                self.frame_count / elapsed
            )

            print(
                f"[PERFORMANCE] Average FPS: "
                f"{self.average_fps:.2f}"
            )

            self.frame_count = 0

            self.fps_start_time = time.time()

        # ---------------------------------------------------------
        # Draw FPS
        # ---------------------------------------------------------

        frame = self.renderer.draw_fps(
            frame,
            self.average_fps
        )

        self.previous_time = time.time()

        return frame

    def run(self):

        self.initialize()

        while self.running:

            # -----------------------------------------------------
            # Get newest available frame
            # -----------------------------------------------------

            ret, frame = self.camera.read()

            if not ret:

                print(
                    "[ERROR] Camera connection lost."
                )

                break

            # -----------------------------------------------------
            # No frame available yet
            # -----------------------------------------------------

            if frame is None:

                time.sleep(0.001)

                continue

            # -----------------------------------------------------
            # Process newest frame
            # -----------------------------------------------------

            frame = self.process_frame(frame)

            # -----------------------------------------------------
            # Display
            # -----------------------------------------------------

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

        # ---------------------------------------------------------
        # Stop recognition worker
        # ---------------------------------------------------------

        self.recognizer.shutdown()

        # ---------------------------------------------------------
        # Stop event logger worker
        # ---------------------------------------------------------

        self.logger.shutdown()

        # ---------------------------------------------------------
        # Release camera
        # ---------------------------------------------------------

        self.camera.release()

        cv2.destroyAllWindows()

        print("[INFO] EdgeVision stopped.")

