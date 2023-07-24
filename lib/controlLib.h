#ifndef CONTROL_LIB_H
#define CONTROL_LIB_H

#include <stdbool.h>

typedef bool DIN;
typedef bool DOUT;
typedef double AIN;
typedef double AOUT;

// precondition check for cooling system startup
bool system_precheck(DIN IN04, DIN IN05, AIN flowRateAct);

// pump speed control to maintain coolant temperature
double pump_speed_control(double speedAct);

// radiator speed control to maintain coolant temperature
double radiator_fan_control(double tempAct);

#endif
