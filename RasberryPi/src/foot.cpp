#include "foot.h"
#include "motor.h"
foot::foot(void)
{

}

void foot::out(float x, float y, float theta)
{
    motor w[4]{
        motor(0),
        motor(1),
        motor(2),
        motor(3)};
    theta = x + y;
    w[0].setPower(0);
    w[1].setPower(0);
    w[2].setPower(0);
    w[3].setPower(0);
}

foot::~foot()
{
}