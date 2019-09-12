import cv2

CAP = cv2.VideoCapture(0)  # 0はカメラのデバイス番号

while(True):
    FRAME = CAP.read()
    cv2.imshow('frame', FRAME)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

CAP.release()
cv2.destroyAllWindows()
