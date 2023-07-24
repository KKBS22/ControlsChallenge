#include "controlLib.h"


// ############################################################################################
// Name : system_precheck
// Args : IN04        -> Input check if subsystems
//                       PLC, WP32 Pump, DCSB16 Radiator and Display are powered up
//        IN05        -> Level Switch
//        	         To check if coolant reservoir has the required capacity to run
//        flowRateAct -> Coolant flow rate in the system
//        		 Check if the required 80L/min flow rate is maintained for operation  
// Scope: PUBLIC
// Ret  : Return true if the preconditions are acheived to start the system
// ###########################################################################################

bool 
system_precheck(DIN IN04, 
		DIN IN05, 
		AIN flowRateAct) {



}

// ##########################################################################################
// Name : pump_speed_control
// Args : speedAct -> Actual speed of the pump
// 		      Proportional control
// Scope: PUBLIC
// Ret  : Required pump speedto maintain flowRate
// ##########################################################################################

double 
pump_speed_control(double speedAct) {


}

// ##########################################################################################
// Name : radiator_fan_control
// Args : tempAct -> Actual temperature of the coolant entering the Inverter
// Scope: PUBLIC
// Ret  : Speed need to maintain to increase flow of air to the radiator
// ##########################################################################################
 
double 
radiator_fan_control(double tempAct) {


}





