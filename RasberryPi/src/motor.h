#include "includes.h"

class motor
{
private:
    float _p = 0;
    float _i = 0;
    float _d = 0;

public:
    motor(uint8_t motorNum);
    void setPID(float p, float i, float d);
    ~motor();
};