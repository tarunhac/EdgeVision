import cv2
import time
from ultralytics import YOLO

RTSP_URL = "rtsp://10.20.23.73:8554/pi_camera"

model = YOLO("models/yolov8n.pt")

cap = cv2.VideoCapture(RTSP_URL, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print("ERROR: Could not open RTSP stream")
    raise SystemExit(1)

print("RTSP connected")
print("Warming up YOLO...")

# Warm-up
for _ in range(5):
    ret, frame = cap.read()
    if not ret:
        continue
    model(
        frame,
        classes=[0],
        conf=0.50,
        verbose=False
    )

print("Benchmark started...")
print("Running for 20 seconds...\n")

start = time.time()
frames = 0
inference_time = 0

while time.time() - start < 20:

    ret, frame = cap.read()

    if not ret:
        print("Frame read failed")
        continue

    t0 = time.time()

    model(
        frame,
        classes=[0],
        conf=0.50,
        verbose=False
    )

    inference_time += time.time() - t0
    frames += 1

elapsed = time.time() - start

print("\n========== YOLO BENCHMARK ==========")
print(f"Frames processed: {frames}")
print(f"Elapsed time:     {elapsed:.2f} s")
print(f"Overall FPS:      {frames / elapsed:.2f}")
print(f"Avg YOLO time:    {inference_time / frames * 1000:.1f} ms")
print("====================================")

cap.release()
