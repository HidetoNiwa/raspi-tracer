#include "motor.h"

motor::motor(uint8_t motorNum)
{
    wiringPiSetupGpio();
    for(int i=0;i<2;i++){
        softPwmCreate(i+(motorNum*2)+2,0,100);
        pin[i]=i+(motorNum*2)+2;
    }
}

void motor::setPID(float p, float i, float d)
{
    _p = p;
    _i = i;
    _d = d;
}

void motor::setPower(int8_t motorPower){
    if(motorPower>MAX_POWER){
        motorPower=MAX_POWER;
    }else if(motorPower<MIN_POWER){
        motorPower=MIN_POWER;
    }
    if(motorPower==0){
        softPwmWrite(pin[0],0);
        softPwmWrite(pin[1],0);
    }else if(motorPower>0){

    }else if(motorPower<0){
        motorPower=-motorPower;
    }
}

motor::~motor()
{
}
