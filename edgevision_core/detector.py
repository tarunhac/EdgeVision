"""
EdgeVision Detector Service

Optimized YOLO person detection + tracking.
Designed for low-latency CPU operation and
future Raspberry Pi deployment.
"""

from ultralytics import YOLO

from edgevision_core.config import config
from edgevision_core.models.detection import Detection


class DetectorService:

    def __init__(self):

        self.model = None

        # ---------------------------------------------------------
        # Performance settings
        # ---------------------------------------------------------

        # Smaller inference resolution reduces CPU workload
        # while the original camera frame is still preserved.
        self.imgsz = 416

        # Limit detections because EdgeVision currently tracks
        # people only.
        self.max_det = 10

    def initialize(self):

        self.model = YOLO(
            config.detector["model"]
        )

        self.model.to(
            config.detector["device"]
        )

        print(
            f"[INFO] Detector initialized "
            f"(imgsz={self.imgsz}, device={config.detector['device']})"
        )

    def detect(self, frame):

        # ---------------------------------------------------------
        # YOLO detection + tracking
        # ---------------------------------------------------------

        results = self.model.track(

            frame,

            persist=config.data["tracker"]["persist"],

            tracker=config.data["tracker"]["tracker"],

            classes=[
                config.detector["person_class"]
            ],

            conf=config.detector["confidence"],

            imgsz=self.imgsz,

            max_det=self.max_det,

            verbose=False

        )

        detections = []

        result = results[0]

        if result.boxes is None:

            return detections

        ids = result.boxes.id

        # ---------------------------------------------------------
        # Convert YOLO results to EdgeVision detections
        # ---------------------------------------------------------

        for i, box in enumerate(result.boxes):

            x1, y1, x2, y2 = map(
                int,
                box.xyxy[0]
            )

            confidence = float(
                box.conf[0]
            )

            class_id = int(
                box.cls[0]
            )

            track_id = None

            if ids is not None:

                track_id = int(
                    ids[i]
                )

            # -----------------------------------------------------
            # Optional size filtering
            # -----------------------------------------------------

            width = x2 - x1
            height = y2 - y1

            if width < config.detector["min_width"]:
                continue

            if height < config.detector["min_height"]:
                continue

            detections.append(

                Detection(

                    x1=x1,
                    y1=y1,
                    x2=x2,
                    y2=y2,

                    confidence=confidence,

                    class_id=class_id,

                    track_id=track_id

                )

            )

        return detections