#include "foot.h"
#include "motor.h"
foot::foot()
{
    motor w[4]{
        motor(0),
        motor(1),
        motor(2),
        motor(3)};
}

void foot::out(float x, float y, float theta)
{
    theta = x + y;
}

foot::~foot()
{
}