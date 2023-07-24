#include "scalerLib.h"
#include <stdio.h>

//#define TESTING


const double RESISTOR_DES = 5630.0;

static double
simple_map(int resistance) {
        switch(resistance) {
                case 28146:
                        return -20.0;
                case 15873:
                        return -10.0;
                case 9256:
                        return 0.0;
                case 5572:
                        return 10.0;
                case 3448:
                        return 20.0;
                case 2830:
                        return 30.0;
                case 1443:
                        return 40.0;
                case 986:
                        return 50.0;
                case 660:
                        return 60.0;
                case 475:
                        return 70.0;
                case 327:
                        return 80.0;
                case 244:
                        return 90.0;
                case 175:
                        return 100.0;
                case 134:
                        return 110.0;
                case 99:
                        return 120.0;
                case 60:
                        return 140.0;
                case 47:
                        return 160.0;

        }

}

// ####################################################
// Name : flow_scaler
// Args : Analog Input 0-20mA 0-4096 12bit resolution
// Scope: PUBLIC
// Ret  : converted Analog input to flow rate
// ####################################################

double 
flow_scaler(AIN IN0X) {

	return (IN0X * FS_FLOW_RATE)/AIN_MAX_RES;
}


// ###################################################
// Name : temp_scaler
// Args : Analog Input 0-10V 0-4096 12bit resolution
// Scope: PUBLIC
// Ret  : converted Analog input to temp
// ###################################################

double 
temp_scaler(AIN IN0X) {
	
	double voltVal = (IN0X * AIN_MAX_VOLT)/AIN_MAX_RES; 

	double current = (12.0 - voltVal)/ RESISTOR_DES;
	int varRes = voltVal / current;
#ifdef TESTING
	printf("The variable Resistance value is : %d \n", varRes);
#endif	
	simple_map(varRes);
}


