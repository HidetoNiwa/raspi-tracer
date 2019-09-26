#include "motor.h"

motor::motor(uint8_t motorNum)
{
    //2,3-4,5-6,7-8,9
    wiringPiSetupGpio();
    if(motorNum==0){
        pin[0]=3;
        pin[1]=4;
    }else if(motorNum==1){
        pin[0]=5;
        pin[1]=6;
    }else if(motorNum==2){
        pin[0]=7;
        pin[1]=8;
    }else if(motorNum==3){
        pin[0]=10;
        pin[1]=9;
    }
    for(int i=0;i<2;i++){
        softPwmCreate(pin[i],0,100);
    }
}

void motor::setPID(float p, float i, float d)
{
    _p = p;
    _i = i;
    _d = d;
}

void motor::setPower(int motorPower){
    if(motorPower>MAX_POWER){
        motorPower=MAX_POWER;
    }else if(motorPower<MIN_POWER){
        motorPower=MIN_POWER;
    }
    if(motorPower==0){
        softPwmWrite(pin[0],0);
        softPwmWrite(pin[1],0);
    }else if(motorPower>0){
        softPwmWrite(pin[0],0);
        softPwmWrite(pin[1],motorPower);
    }else if(motorPower<0){
        softPwmWrite(pin[0],-motorPower);
        softPwmWrite(pin[1],0);
    }
}

motor::~motor()
{
}
