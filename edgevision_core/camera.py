"""
EdgeVision Camera Service
Low-latency RTSP camera input
"""

import cv2
import os
import threading
import time

from edgevision_core.config import config


class CameraService:
    """Handles low-latency camera capture."""

    def __init__(self):

        self.cap = None

        # Latest-frame buffer
        self.latest_frame = None
        self.frame_lock = threading.Lock()

        # Capture thread state
        self.running = False
        self.capture_thread = None

    def initialize(self):
        """Open camera and start background capture."""

        source = config.camera["source"]

        # ---------------------------------------------------------
        # Low-latency FFmpeg options for RTSP
        # ---------------------------------------------------------

        if isinstance(source, str) and source.startswith("rtsp://"):

            os.environ["OPENCV_FFMPEG_CAPTURE_OPTIONS"] = (
                "rtsp_transport;tcp|"
                "fflags;nobuffer|"
                "flags;low_delay|"
                "max_delay;0|"
                "reorder_queue_size;0"
            )

        self.cap = cv2.VideoCapture(
            source,
            cv2.CAP_FFMPEG
        )

        if not self.cap.isOpened():

            raise RuntimeError(
                f"Unable to open camera: {source}"
            )

        # Ask OpenCV/backend to minimize buffering.
        self.cap.set(
            cv2.CAP_PROP_BUFFERSIZE,
            1
        )

        print(
            f"[INFO] Camera initialized: {source}"
        )

        # ---------------------------------------------------------
        # Start background capture thread
        # ---------------------------------------------------------

        self.running = True

        self.capture_thread = threading.Thread(
            target=self._capture_loop,
            daemon=True
        )

        self.capture_thread.start()

        # ---------------------------------------------------------
        # Wait for the first frame
        # ---------------------------------------------------------

        timeout = time.time() + 5.0

        while self.running:

            with self.frame_lock:

                if self.latest_frame is not None:

                    break

            if time.time() > timeout:

                self.running = False

                raise RuntimeError(
                    "Camera did not provide a frame."
                )

            time.sleep(0.01)

    def _capture_loop(self):
        """
        Continuously read frames from the camera.

        Only the newest frame is retained.

        Old frames are discarded automatically.
        """

        while self.running:

            ret, frame = self.cap.read()

            if not ret:

                # RTSP/decoder may occasionally fail to decode
                # a frame. Do not immediately kill the system.
                time.sleep(0.01)

                continue

            with self.frame_lock:

                self.latest_frame = frame

    def read(self):
        """
        Return the newest available frame.

        The main processing loop never consumes a backlog
        of old RTSP frames.
        """

        if not self.running:

            return False, None

        with self.frame_lock:

            if self.latest_frame is None:

                # No frame currently available.
                # This is NOT considered a camera failure.
                return True, None

            frame = self.latest_frame

            # Remove the frame from the buffer.
            # The capture thread will immediately replace it
            # with the newest available frame.
            self.latest_frame = None

        return True, frame

    def release(self):
        """Stop capture and release camera resources."""

        self.running = False

        if self.capture_thread is not None:

            self.capture_thread.join(
                timeout=2.0
            )

            self.capture_thread = None

        if self.cap is not None:

            self.cap.release()
            self.cap = None

        cv2.destroyAllWindows()

        print("[INFO] Camera released.")