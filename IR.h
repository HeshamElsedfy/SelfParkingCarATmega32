
#ifndef IR_H_
#define IR_H_

#include <avr/io.h>

/* Pins can change on hardware implementation */
#define IR_SEN_DDR 			DDRD
#define IR_SEN_PORT 		PORTD
#define IR_SEN_PIN 			PIND
#define IR_FRONT_SEN_PIN 	PD4
#define IR_BACK_SEN_PIN 	PD2

void IRinit();
char frontIRread(void);
char backIRread(void);

#endif /* IR_H_ */
