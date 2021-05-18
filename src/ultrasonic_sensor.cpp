#include <wiringPi.h>
#include "ultrasonic_sensor.h"
#include <stdio.h>


ultrasonic_sensor::ultrasonic_sensor()
{ 
	SOUND_SPEED_IN_AIR_IN_CM_PER_SEC = 34300;
	// pin modes
	pinMode(28, OUTPUT);   // header pin 38 connected to trigger of sensor
	pinMode(29, INPUT);   // header pin 40 connected to echo of the sensor
	
	// set trigger pin as low by default
	digitalWrite(28, LOW);
	delay(1000);  // 1 sec time to settle the sensoR
	
	}


float_t ultrasonic_sensor::calculateDistanceInCm()
{
    uint32_t pulse_start = 0;
	uint32_t pulse_end = 0;
	uint32_t pulse_duration = 0;
	float_t distanceInCm = 0;
	
    printf("\n\nDistance measurement in progress.....\n");
	//measurement process
	
	digitalWrite(28, HIGH); //set trigger high
	delayMicroseconds(10);  // keep trigger high for 10 microseconds
	digitalWrite(28, LOW);  // set trigger low
	
	// sense the high time of the echo pulse 
	
	while(digitalRead(29)==0)
	{
		pulse_start = micros();
		}
		
	while(digitalRead(29)==1)
	{
		pulse_end = micros();
		}
	
	printf("pulse_start time (ms) %d \n",pulse_start);
	printf("pulse end time (ms) %d \n",pulse_start);	
	
	// distance calculation
	
	pulse_duration = pulse_end - pulse_start;
	printf("pulse duration (ms) %d \n",pulse_duration);
	
	
	distanceInCm = pulse_duration*0.000001 * SOUND_SPEED_IN_AIR_IN_CM_PER_SEC/2;
	
	return distanceInCm;
}
