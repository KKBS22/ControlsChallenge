#ifndef CONTROL_LIB_H
#define CONTROL_LIB_H

#include <stdbool.h>
#include "scalerLib.h"

// precondition check for cooling system startup
bool system_precheck(DIN IN04, DIN IN05, AIN IN01);

// pump speed control to maintain coolant temperature
double pump_speed_control(AIN IN01, double speedAct);

// radiator speed control to maintain coolant temperature
int radiator_fan_control(AIN IN02);

#endif // CONTROL_LIB_H
