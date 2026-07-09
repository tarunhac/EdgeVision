"""
EdgeVision Detector Service
"""

from ultralytics import YOLO
from src.config import config


class DetectorService:

    def __init__(self):

        self.model = None

    def initialize(self):

        model_path = config.detector["model"]

        self.model = YOLO(model_path)

        print("[INFO] YOLO loaded.")

    def detect(self, frame):

    results = self.model(frame, verbose=False)

    detections = []

    for result in results:

        for box in result.boxes:

            cls = int(box.cls[0])
            conf = float(box.conf[0])

            if cls != config.detector["person_class"]:
                continue

            if conf < config.detector["confidence"]:
                continue

            x1, y1, x2, y2 = map(int, box.xyxy[0])

            width = x2 - x1
            height = y2 - y1

            if width < config.detector["min_width"]:
                continue

            if height < config.detector["min_height"]:
                continue

            aspect_ratio = height / width

            if aspect_ratio < config.detector["min_aspect_ratio"]:
                continue

            if aspect_ratio > config.detector["max_aspect_ratio"]:
                continue

            detections.append({
                "bbox": (x1, y1, x2, y2),
                "confidence": conf
            })

    return detections