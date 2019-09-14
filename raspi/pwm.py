#coding: UTF-8
import RPi.GPIO as GPIO
import time

#setPower：出力
def motorPower(setPower,motorNum):
    setPower=0

GPIO.setmode(GPIO.BCM)

for i in range(27):
    GPIO.setup(i, GPIO.OUT)#全ピン出力設定
    GPIO.output(i,GPIO.LOW)#全ピンLOW出力

#0：4,5
#1：6,7
#2：8,9
#3：10,11
#上記2ピンセットでPWM制御を行う

pwmPin = [[0 for i in range(4)] for j in range(4)]#pwmPin[4][2]初期化

for i in range(4):
    for j in range(2):
        print(i,j)
        pwmPin[i][j] = GPIO.PWM((i*2+j+4),1000)#1000HzPWMで駆動設定
        pwmPin[i][j].start(0)

while True:
    for i in range(100):
        pwmPin[0][0].ChangeDutyCycle(i)
        print(i)
        time.sleep(0.02)

servo.stop()
GPIO.cleanup()