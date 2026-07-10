"""
EdgeVision Detector Service
"""

from ultralytics import YOLO

from src.config import config
from src.models.detection import Detection


class DetectorService:

    def __init__(self):
        self.model = None

    def initialize(self):

        self.model = YOLO(config.detector["model"])

        device = config.detector["device"]

        self.model.to(device)

        print(f"[INFO] YOLO initialized on {device}")

    def detect(self, frame):

        results = self.model(frame, verbose=False)
        print(results[0].boxes)

        detections = []

        for result in results:

            for box in result.boxes:

                class_id = int(box.cls[0])

                confidence = float(box.conf[0])

                if class_id != config.detector["person_class"]:
                    continue

                if confidence < config.detector["confidence"]:
                    continue

                x1, y1, x2, y2 = map(int, box.xyxy[0])

                width = x2 - x1
                height = y2 - y1

                detections.append(

                    Detection(
                        x1=x1,
                        y1=y1,
                        x2=x2,
                        y2=y2,
                        confidence=confidence,
                        class_id=class_id
                    )

                )

        return detections