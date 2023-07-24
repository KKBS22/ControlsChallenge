#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdbool.h>

#include "../lib/controlLib.h"

// Test structures
typedef struct _tTemp {
	int vInADC;
	double tempOut;
}TestTemp;


typedef struct _tSystemPrecheck {
	bool in4;
	bool in5;
	int  in1;
	bool out;
}TestSystem;


typedef struct _tflowRate {
	int fInADC;
	double flowOut;
}TestFlow;


typedef struct _tPumpControl {
	int in1;
	double speedAct;
	double speedCnt;	
}PumpControl;

typedef struct _tfanControl {
	int in2;
	int dutCyc;
}FanControl;


// Creating test vector
TestTemp tempVect[] = { {733 , 50.0},
                        {270 , 80.0},
                        {1867 , 20.0}};

TestSystem sysVect[] = { {1, 1, 4096,0},
                         {1, 0, 2048,1},
                         {1, 0, 1024,0}};

TestFlow flowVect[] = { {2048, 60.0},
			{1024, 30.0},
   			{512 , 15.0}};

PumpControl pumpControlVect[] = { {2048, 1725.00, 2875.00},
				  {1024,  862.50, 3737.50},
				  {512 ,  431.25, 4168.75}};

FanControl fanControlVect[] = { {733 , 50},
			        {270 , 100},
				{1867, 0}};


size_t testVectorTemp = sizeof(tempVect) / sizeof(TestTemp);
size_t testVectorSyst = sizeof(sysVect) / sizeof(TestSystem);
size_t testVectorFlow = sizeof(flowVect) / sizeof(TestFlow);
size_t testVectorPumpCont = sizeof(pumpControlVect) / sizeof(PumpControl);
size_t testVectorFanCont = sizeof(fanControlVect) / sizeof(FanControl);


void 
test_system_pre_check() {
	for (int i = 0 ; i < testVectorSyst ; i++) {
        	bool reTest = system_precheck(sysVect[i].in4, sysVect[i].in5, sysVect[i].in1);
#ifdef TESTING
		printf("The val is %d \n", reTest);
#endif	
		int retCmp = reTest ? 1 : 0;
		assert_int_equal(retCmp, sysVect[i].out);	
	}
}

void 
test_temp_scale() {
	for (int i = 0 ; i < testVectorTemp ; i++) {
        	double tempVal = temp_scaler(tempVect[i].vInADC);
#ifdef TESTING
		printf("The temp val is %f \n", tempVal);
#endif	
		assert_float_equal(tempVal, tempVect[i].tempOut, 2);
	}

}

void 
test_flow_scale() {
	for (int i = 0 ; i < testVectorFlow ; i++) {
        	double flowRateVal = flow_scaler(flowVect[i].fInADC);
#ifdef TESTING
		printf("The flow val is %f \n", flowRateVal);
#endif
		assert_float_equal(flowRateVal, flowVect[i].flowOut, 2);
	}
}

void 
test_pump_control() {
	for (int i = 0 ; i < testVectorPumpCont ; i++) {
                double pumpSpeed = pump_speed_control(pumpControlVect[i].in1, pumpControlVect[i].speedAct);
#ifdef TESTING
                printf("The pump speed val is %f \n", pumpSpeed);
#endif
                assert_float_equal(pumpSpeed, pumpControlVect[i].speedCnt, 2);
        }

}

void 
test_fan_control() {
	for (int i = 0 ; i < testVectorPumpCont ; i++) {
                int fanDuty = radiator_fan_control(fanControlVect[i].in2);
#ifdef TESTING
                printf("The duty cycle val is %d \n", fanDuty);
#endif
                assert_int_equal(fanDuty, fanControlVect[i].dutCyc);
        }
}


int 
main() {

	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_system_pre_check),
		cmocka_unit_test(test_temp_scale),
		cmocka_unit_test(test_flow_scale),
		cmocka_unit_test(test_pump_control),
		cmocka_unit_test(test_fan_control)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
