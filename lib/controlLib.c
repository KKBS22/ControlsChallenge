#include "controlLib.h"

// ############################################################################################
// Name : system_precheck
// Args : IN04        -> Digital Input
// 			 Input check if subsystems
//                       PLC, WP32 Pump, DCSB16 Radiator and Display are powered up
//        IN05        -> Digital Input
//        		 Level Switch
//        	         To check if coolant reservoir has the required capacity to run
//        flowRateAct -> Coolant flow rate in the system
//        		 Check if the required 80LPM flow rate is maintained for operation  
// Scope: PUBLIC
// Ret  : Return true if the preconditions are acheived to start the system
// ###########################################################################################

bool 
system_precheck(DIN    IN04, 
		DIN    IN05, 
		AIN    IN01) {
	
	double flowRateAct = flow_scaler(IN01);

	bool flowCheck = flowRateAct < MIN_FLOW ? false : true;
	// TODO : On Delay Timer
	{
		if (IN04 & !IN05 & flowCheck) {
			return true;
		} else {
			return false;
		}
	}

}

// ##########################################################################################
// Name : pump_speed_control
// Args : IN01     -> Analog Input 0-20mA
// 		      Measuring the Flow rate of the system
// 	  speedAct -> Actual speed of the pump
// 		      Proportional control
// Scope: PUBLIC
// Ret  : Required pump speed to maintain flowRate of 80LPM
// ##########################################################################################

double 
pump_speed_control(AIN    IN01,
	           double speedAct) {
	double flowAct = flow_scaler(IN01);
	// Proportional logic:
	// y = m[1]X[Delta=(RefSpeed-speedAct) ] + c[2300]
	
	return (1*(REF_SPEED-speedAct)) + REF_SPEED;
}

// ##########################################################################################
// Name : radiator_fan_control
// Args : IN02    -> Analog Input 0-10V
// 		     Measuring the temperature of the coolant entering the inverter
// Scope: PUBLIC
// Ret  : PWM output in duty cycle Speed need to maintain to coolant temp with radiator 
//        fan control
// Assumption : 1. Inverter during full load capacity will disspiate heat equivalent
//                 30 deg C of heat which raises the coolant temperature to 80 deg C.
// 	        2. So Coolant is maintained at 50 deg C before entering the Inverter
// 	        3. The Radiator is able to reject heat equivalent to 30 deg C by controlling
// 	           fan speed and at rated flow of 80 LPM.
// 	        4. We will maintain coolant temp between 40 - 60 deg C by controlling the
// 	           radiator fan speed
// ##########################################################################################
 
int
radiator_fan_control(AIN IN02) {
	double tempAct = temp_scaler(IN02);

	double tempOut = (1*(tempAct-REF_TEMP)) + REF_TEMP;

	if (tempOut < MIN_TEMP) {
		tempOut = MIN_TEMP; 
	} else if (tempOut > MAX_TEMP) {
		tempOut = MAX_TEMP;
	}

	int dutCycle;

	dutCycle = ((tempOut - MIN_TEMP)/(MAX_TEMP - MIN_TEMP))*100;

	return dutCycle;
}



