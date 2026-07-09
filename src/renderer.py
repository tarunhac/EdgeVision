"""
EdgeVision Renderer Service
"""

import cv2


class RendererService:
    """
    Responsible for drawing overlays on frames.
    """

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

    def show(self, window_name, frame):

        cv2.imshow(window_name, frame)