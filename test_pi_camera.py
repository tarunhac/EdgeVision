import cv2

RTSP_URL = "rtsp://10.20.23.73:8554/pi_camera"

cap = cv2.VideoCapture(RTSP_URL, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print("ERROR: Could not open Raspberry Pi camera stream")
    raise SystemExit(1)

print("Raspberry Pi camera stream opened successfully")

while True:
    ret, frame = cap.read()

    if not ret:
        print("ERROR: Failed to read frame")
        break

    cv2.imshow("Raspberry Pi Camera", frame)

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
