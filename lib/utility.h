#ifndef UTILITY_LIB_H
#define UTILITY_LIB_H

#include <stdbool.h>

// typedefs
typedef bool DIN;
typedef bool DOUT;
typedef int AIN;
typedef int AOUT;

// Constant
#define MAX_FLOW  80.0 // LPM
#define AIN_MAX_RES  4096
#define AIN_MIN_RES  0
#define AIN_MIN_VOLT  0.0
#define AIN_MAX_VOLT  10.0
#define MIN_FLOW  60.0 // LPM
#define REF_SPEED  2300.0 // Pump RPM at full inverter full load at 80 LPM
#define REF_TEMP  50.0 // Temp ref to maintain at inverter entry
#define MIN_TEMP  40.0
#define MAX_TEMP  60.0
// Full scale values
#define FS_FLOW_RATE  120.0 // LPM

#endif // UTILITY_LIB_H
