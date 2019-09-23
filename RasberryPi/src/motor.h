#include "includes.h"

class motor
{
private:
    float _p = 0;
    float _i = 0;
    float _d = 0;
    int8_t MAX_POWER=100;
    int8_t MIN_POWER=-100;
    uint8_t pin[2]={0};

public:
    motor(uint8_t motorNum);
    void setPID(float p, float i, float d);
    void setPower(int8_t motorPower);
    ~motor();
};