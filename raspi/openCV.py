#coding: UTF-8
import cv2
import numpy
import sys

cap = cv2.VideoCapture(0)  # 0はカメラのデバイス番号

tm = cv2.TickMeter()
tm.start()

count = 0
max_count = 10
fps = 0

while(True):
    ret,frame = cap.read()

    if count == max_count:
	tm.stop()
	fps = max_count/tm.getTimeSec()
	tm.reset()
	tm.start()
	count=0

    frame = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    ret,frame = cv2.threshold(frame,0,255,cv2.THRESH_OTSU)
    print("fps:{:.1f}".format(fps))
    cv2.imshow('frame',frame)
    count += 1
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
