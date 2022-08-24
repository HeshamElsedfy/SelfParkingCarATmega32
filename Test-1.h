
#ifndef TEST_1_H_
#define TEST_1_H_

#define ITERATIONS			250
#define PARKING_DEPTH		20
#define PARKING_DISTANCE	40

/* Pins can change on hardware implementation */
#define Switch_Pin PB0
#define Switch_Port PORTB
#define Switch_DDR DDRB

#include "IR.h"
#include "LCD.h"
#include "motors.h"
#include "Ultrasonic.h"

static uint8 CheckPark(void);
static void Park(void);
void Timer2_OV_init (void);

#endif /* TEST_1_H_ */
