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

            cv2.rectangle(
                frame,
                (detection.x1, detection.y1),
                (detection.x2, detection.y2),
                (0, 255, 0),
                2
            )

            cv2.putText(
                frame,
                f"{detection.confidence:.2f}",
                (detection.x1, detection.y1 - 8),
                self.font,
                0.6,
                (0, 255, 0),
                2
            )

        return frame

    def show(self, window_name, frame):

        cv2.imshow(window_name, frame)