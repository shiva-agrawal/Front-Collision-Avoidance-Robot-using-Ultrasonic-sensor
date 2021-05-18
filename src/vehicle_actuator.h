#ifndef _VEHICLE_ACTUATOR_H
#define _VEHICLE_ACTUATOR_H

#include "std_int.h"

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

/*--------------------------------------------------------------------------------------
 * LOOK UP TABLE FOR MOTOR AND STEER DIRECTION CONTROL
 * -------------------------------------------------------------------------------------
 * FUCNTION               BIT SET (0b00000000)   
 * -------------------------------------------------------------------------------------
 * Steer right               1 (0b00000001)
 * Front motor reverse       2 (0b00000010)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * -------------------------------------------------------------------------------------
 */
 
typedef enum {FORWARD, FORWARD_LEFT, FORWARD_RIGHT, REVERSE, REVERSE_LEFT, REVERSE_RIGHT, STOP } vehicle_motion_t;

class vehicle_actuator
{
	private:
	
	uint8_t data;
	uint8_t clock;
	uint8_t latch;
	
	uint8_t getData(vehicle_motion_t);
	
	public:
	
    vehicle_actuator();
	void vehicleControl(vehicle_motion_t);
	
	};

#endif
