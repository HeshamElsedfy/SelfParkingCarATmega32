
#include "Ultrasonic.h"

void ULT_init(void) {
	SET_BIT (ULT_SENS_DDR,TRIG_PIN);
	CLEAR_BIT (ULT_SENS_DDR,ECHO_PIN);
	CLEAR_BIT (ULT_SENS_PORT,TRIG_PIN);
}

uint16 ULT_calc_dis(void) {
	uint16 distance = 0, a=0,b=0;
	SET_BIT (ULT_SENS_PORT,TRIG_PIN);
	_delay_us(50);
	CLEAR_BIT (ULT_SENS_PORT,TRIG_PIN);

	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler 1100 0001 */
	while ((TIFR&(1<<ICF1)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler 1000 0001 */
	while ((TIFR&(1<<ICF1)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<ICF1);  	/* Clear ICF flag */
	TCNT1=0;
	TCCR1B = 0;  		/* Stop the timer */

	distance = (((b-a)*34600)/(F_CPU*2));
	return distance;
}
