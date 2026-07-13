"""
EdgeVision Renderer Service
"""

import cv2


class RendererService:

    def __init__(self):

        self.font = cv2.FONT_HERSHEY_SIMPLEX

    def draw_fps(self, frame, fps):

        cv2.putText(
            frame,
            f"FPS: {fps:.1f}",
            (20, 35),
            self.font,
            0.7,
            (0, 255, 0),
            2
        )

        return frame

    def draw_detections(self, frame, detections):

        for detection in detections:

            # Bounding Box
            color = (0, 255, 0)

            if detection.name == "Unknown":
                color = (0, 0, 255)

            cv2.rectangle(
                frame,
                (detection.x1, detection.y1),
                (detection.x2, detection.y2),
                color,
                2
            )

            # Label
            if detection.track_id is None:
                label = detection.name
            else:
                label = f"{detection.name} (ID {detection.track_id})"

            cv2.putText(
                frame,
                label,
                (detection.x1, detection.y1 - 10),
                self.font,
                0.65,
                color,
                2
            )

        return frame

    def show(self, window_name, frame):

        cv2.imshow(window_name, frame)