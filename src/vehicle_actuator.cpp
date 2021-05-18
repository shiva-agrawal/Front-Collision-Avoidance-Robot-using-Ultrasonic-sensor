#include <wiringPi.h>
#include <stdio.h>
#include "vehicle_actuator.h"

/*-----------------------------------------------------------------------------------------------------------------------------------
 * header pin number        WiringPi number    function    Motor shield IC pin number        Motor Shield header pin number
 * ----------------------------------------------------------------------------------------------------------------------------------
 *     04                        NA              5V              NA                                  JP3 - 3 (opposite side)
 *     06                        NA              GND             NA                                  GND (near D13)
 *     11                        0               CLOCK           11 (74HCT595N)                      D4  / 4
 *     12                        1               LATCH           12 (74HCT595N)                      D12 / 12
 *     13                        2               DATA (8 bits)   14 (74HCT595N)                      D8  / 8
 *     14                        NA              Enable (GND)    13 (74HCT595N)                      D7  / 7
 *     15                        3               PWM_F_Motor     PWM_0A (M4) (IC2 - L293D)           D6  / 6
 *     16                        4               PWM_R_Motor     PWM_2B (M2) (IC1 - L293D)           D3  / 3
 *     18                        5               PWM_STEER       PWM_0B (M3) (IC2 - L293D)           D5  / 5
 * ---------------------------------------------------------------------------------------------------------------------------------   
 */

vehicle_actuator::vehicle_actuator()
{

    
    // setting pin modes
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT); 
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	
	//assigning default values
	digitalWrite(0, LOW);  
	digitalWrite(1, LOW);
	digitalWrite(2, LOW);   
	
	digitalWrite(3, HIGH);  
	digitalWrite(4, HIGH);
	digitalWrite(5, HIGH);
	

	
}

uint8_t vehicle_actuator::getData(vehicle_motion_t motion)
{
	uint8_t value = 0b00000000;
		
	switch(motion)
	{
		case FORWARD:
		{
			value = 0b00010001;
			break;
		}
		case FORWARD_LEFT:
		{
			value = 0b00110001;
			break;
		}
		
		case FORWARD_RIGHT:
		{
			value = 0b10010001;
			break;
		}
		
		case REVERSE:
		{
			value = 0b01000010;
			break;
		}
		case REVERSE_LEFT:
		{
			value = 0b01100010;
			break;
		}
		
		case REVERSE_RIGHT:
		{
			value = 0b11000010;
			break;
		}
		case STOP:
		{
		    value = 0b00000000;
			break;	
		
		}
		default:
			{}
		
	}
	return value;
}


void vehicle_actuator::vehicleControl(vehicle_motion_t motion)
{
		
		uint8_t data = getData(motion);
	    
		digitalWrite(0, LOW); // clock low
		digitalWrite(1, LOW); // latch low
		
	for (uint8_t i = 0; i< 8; i++)
		{
			if ((data << i) & 0b10000000)
			{
			   digitalWrite(2, HIGH); 
			   printf("%d -> %d \n",i,1);
			}
			else
			{
				digitalWrite(2, LOW); 
				printf("%d -> %d \n",i,0);
			}
			
		digitalWrite(0, HIGH); // clock high
		digitalWrite(0, LOW); // clock low
		}
	
	digitalWrite(1, HIGH); // latch high
	
	
}
