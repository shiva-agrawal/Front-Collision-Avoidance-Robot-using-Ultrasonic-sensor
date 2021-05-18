/* 
 * Author : Shiva Agrawal
 * Date   : 07.06.2018
 * Version: 1.0
 * Description : test file for front collision avoidance using ultrasonic sensor
 */
 
 
#include <wiringPi.h>
#include "vehicle_actuator.h"
#inlcude "ultrasonic_sensor.h"
#include "std_int.h"


int main()
{
	// to activate the wiringPi based pin convention for Raspberry pi 3 Model B
	wiringPiSetup();
    
    // object for DC motor controller driver is created. this also leads to initilization
    // of the pins
    vehicle_actuator my_vehicle;
	
	// object for ultrasonic sensor is created. this also leads to initilization
    // of the pins
	ultrasonic_sensor front_sensor;
	
	// distance measurement in cm
	float_t distance;
    
    while(1)
    {
		distance = front_sensor.calculateDistanceInCm();
		if (distance <= 50)
		{
			my_vehicle.vehicleControl(STOP);
		}
		else
		{
			my_vehicle.vehicleControl(FORWARD);
		}
		delay(1500);
	}
	retunr 0;
	
}