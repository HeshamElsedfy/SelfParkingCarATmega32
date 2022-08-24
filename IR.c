
#include "IR.h"

void IRinit(void) {
	IR_SEN_DDR  &= ~((1<< IR_FRONT_SEN_PIN )|(1<< IR_BACK_SEN_PIN ));		/* Set sensors pins to input */
	IR_SEN_PORT |= ((1<< IR_FRONT_SEN_PIN )||(1<< IR_BACK_SEN_PIN ));		/* Activate pull up for sensors pins {} */
}

char frontIRread(void) {
	if (IR_SEN_PIN & (1<<IR_FRONT_SEN_PIN)) {
		return 1;
	}
	else
		return 0;
}

char backIRread(void) {
	if (IR_SEN_PIN & (1<<IR_BACK_SEN_PIN)) {
		return 1;
	}
	else
		return 0;
}
