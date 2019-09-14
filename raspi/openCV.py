#coding: UTF-8
import cv2
import numpy as np
import sys
import val

cap = cv2.VideoCapture(0)  # 0はカメラのデバイス番号

#tm = cv2.TickMeter()
#tm.start()

count = 0
max_count = 10
fps = 0
l=0
r=0
ranges=val.h/(val.point+1)

while(True):
    ret,frame = cap.read()

    #if count == max_count:
        #tm.stop()
        #fps = max_count/tm.getTimeSec()
        #tm.reset()
        #tm.start()
        #count=0

    frame = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    ret,frame = cv2.threshold(frame,0,255,cv2.THRESH_OTSU)
    #print("fps:{:.1f}".format(fps))
    #h,w=frame.shape[:2]
    #print("w:{:},h:{:}".format(w,h)) #640*480
    for j in range(val.point):
        for i in range(640):
            pixelValue = frame[ranges*(j+1), i]
            if pixelValue==255 :
                l=i
                break
        for i in range(640-l):
            pixelValue = frame[ranges*(j+1), l+i]
            if pixelValue==0 :
                r=l+i
                break
    print(l,r)
    cv2.imshow('frame',frame)
    #count += 1
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

#残り
#最小二乗法で8点程度取得した点をPID制御
#PWMとの関連付け
#基板作成、動作確認