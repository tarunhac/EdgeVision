import cv2
from ultralytics import YOLO

RTSP_URL = "rtsp://10.20.23.73:8554/pi_camera"

model = YOLO("models/yolov8n.pt")

cap = cv2.VideoCapture(RTSP_URL, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print("ERROR: Could not open Raspberry Pi stream")
    raise SystemExit(1)

print("Pi camera connected")
print("YOLO tracking started")

while True:
    ret, frame = cap.read()

    if not ret:
        print("ERROR: Failed to read frame")
        break

    results = model.track(
        frame,
        classes=[0],
        conf=0.50,
        persist=True,
        verbose=False
    )

    annotated = results[0].plot()

    cv2.imshow("EdgeVision - Pi Camera + Tracking", annotated)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
