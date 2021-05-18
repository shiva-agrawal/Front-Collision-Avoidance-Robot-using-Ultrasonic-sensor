#ifndef _ULTRASONIC_SENSOR_H
#define _ULTRASONIC_SENSOR_H

#include "std_int.h"
/*-----------------------------------------------------------------------------------------------------------------------------------
 * header pin number        WiringPi number    function       ULTRASONIC SENSOR (HC-SR04)
 * ----------------------------------------------------------------------------------------------------------------------------------
 *     38                        28              TRIGGER        trigger pin   
 *     40                        29              ECHO           Echo pin
 *     2                         NA              5V             Vcc
 *     20                        NA              GND            GND
 * ---------------------------------------------------------------------------------------------------------------------------------   
 */
 
class ultrasonic_sensor
{
	private:
	
	uint32_t SOUND_SPEED_IN_AIR_IN_CM_PER_SEC ;
	
	public:
	
 	ultrasonic_sensor();
 	float_t calculateDistanceInCm();
		
};


#endif
