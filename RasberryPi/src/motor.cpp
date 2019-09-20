#include "includes.h"
#include "motor.h"

motor::motor(uint8_t motorNum)
{
    switch (motorNum)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

void motor::setPID(float p, float i, float d)
{
    _p = p;
    _i = i;
    _d = d;
}

motor::~motor()
{
}
