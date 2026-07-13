"""
EdgeVision Detector Service
"""

from ultralytics import YOLO

from edgevision_core.config import config
from edgevision_core.models.detection import Detection


class DetectorService:

    def __init__(self):

        self.model = None

    def initialize(self):

        self.model = YOLO(config.detector["model"])

        self.model.to(config.detector["device"])

        print("[INFO] Detector initialized")

    def detect(self, frame):

        results = self.model.track(
            frame,
            persist=config.data["tracker"]["persist"],
            tracker=config.data["tracker"]["tracker"],
            classes=[config.detector["person_class"]],
            conf=config.detector["confidence"],
            verbose=False
        )

        detections = []

        result = results[0]

        if result.boxes is None:

            return detections

        ids = result.boxes.id

        for i, box in enumerate(result.boxes):

            x1, y1, x2, y2 = map(int, box.xyxy[0])

            confidence = float(box.conf[0])

            class_id = int(box.cls[0])

            track_id = None

            if ids is not None:

                track_id = int(ids[i])

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