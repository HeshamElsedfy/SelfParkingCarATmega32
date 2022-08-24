
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "common_macros.h"
#include "std_types.h"

/* Pins can change on hardware implementation */
#define ULT_SENS_DDR DDRD
#define	ULT_SENS_PORT PORTD
#define ULT_SENS_PIN PIND
#define TRIG_PIN PD7
#define ECHO_PIN PD6

void ULT_init(void);
uint16 ULT_calc_dis(void);


#endif /* ULTRASONIC_H_ */
