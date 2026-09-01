import cv2
import time
from ultralytics import YOLO
import insightface

RTSP_URL = "rtsp://10.20.23.73:8554/pi_camera"

# YOLO
yolo = YOLO("models/yolov8n.pt")

# InsightFace
print("Loading InsightFace...")

app = insightface.app.FaceAnalysis(
    providers=["CPUExecutionProvider"]
)

app.prepare(
    ctx_id=0,
    det_size=(640, 640)
)

print("InsightFace loaded")

# Camera
cap = cv2.VideoCapture(RTSP_URL, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print("ERROR: Could not open RTSP stream")
    raise SystemExit(1)

print("RTSP connected")
print("Starting benchmark...\n")

# Warmup
for _ in range(5):
    ret, frame = cap.read()

    if not ret:
        continue

    results = yolo(
        frame,
        classes=[0],
        conf=0.50,
        verbose=False
    )

    for box in results[0].boxes:
        x1, y1, x2, y2 = map(int, box.xyxy[0])

        person = frame[y1:y2, x1:x2]

        if person.size:
            app.get(person)

print("Warmup complete")
print("Running 20 second benchmark...\n")

start = time.time()

frames = 0
persons = 0
face_calls = 0
face_time = 0.0

while time.time() - start < 20:

    ret, frame = cap.read()

    if not ret:
        continue

    frames += 1

    results = yolo(
        frame,
        classes=[0],
        conf=0.50,
        verbose=False
    )

    for box in results[0].boxes:

        x1, y1, x2, y2 = map(int, box.xyxy[0])

        person = frame[y1:y2, x1:x2]

        if person.size == 0:
            continue

        persons += 1

        t0 = time.time()

        app.get(person)

        face_time += time.time() - t0
        face_calls += 1

elapsed = time.time() - start

print("\n========== INSIGHTFACE BENCHMARK ==========")
print(f"Frames processed:       {frames}")
print(f"Persons detected:       {persons}")
print(f"InsightFace calls:      {face_calls}")
print(f"Elapsed time:            {elapsed:.2f} s")

if frames:
    print(f"YOLO pipeline FPS:       {frames / elapsed:.2f}")

if face_calls:
    print(f"Avg InsightFace time:    {face_time / face_calls * 1000:.1f} ms")
    print(f"InsightFace calls/sec:   {face_calls / elapsed:.2f}")

print("===========================================")

cap.release()
