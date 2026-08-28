import cv2

RTSP_URL = "rtsp://10.26.205.62:8554/laptop"

cap = cv2.VideoCapture(RTSP_URL, cv2.CAP_FFMPEG)

if not cap.isOpened():
    print("ERROR: Could not open RTSP stream")
    exit(1)

print("RTSP stream opened successfully")

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
