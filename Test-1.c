
#include "Test-1.h"

uint8 F_Obstacle, B_Obstacle;

int main (void) {
	CLEAR_BIT(Switch_DDR,Switch_Pin);
	LCD_init();
	IRinit();
	init_motors();
	ULT_init();
	Timer2_OV_init ();
	while(1){
		if (BIT_IS_CLEAR(Switch_Port,Switch_Pin)){
			CheckPark();
		}
		else {
			LCD_clearScreen();
			LCD_displayString("Waiting...");
		}
	}
}

static uint8 CheckPark(void) {
	uint8 park_dist = 0;
	uint16 count = 0;
	LCD_clearScreen();
	LCD_displayString("Find Park space");
	_delay_ms(1000);
	MOV_FWR();
	for (count = 0; count< ITERATIONS; count++) {
		if (ULT_calc_dis()> PARKING_DEPTH){
			if(++park_dist > PARKING_DISTANCE) {
				LCD_clearScreen();
				LCD_displayString("Parking...");
				Park();
				return 1;
			}
			_delay_ms(100); /* 1 step forward */
			LCD_goToRowColumn(1,0);
			LCD_displayString("distance = ");
			LCD_intgerToString(park_dist);
		}
		else {
			park_dist = 0;
		}
	}
	LCD_clearScreen();
	LCD_displayString("No Park space ");
	LCD_goToRowColumn(1,0);
	LCD_displayString("available");
	STP();
	_delay_ms(1000);
	return 0;
}

static void Park(void) {
	MOV_FWR();
	_delay_ms(4000);
	STP();
	LCD_goToRowColumn(1,0);
	LCD_displayString("Parking...");
	MOV_LEF_BCK();
	int i = 0;
	while (i < 100) { //100 need change on hardware
		if (F_Obstacle != 0 && B_Obstacle != 0) { //no Obstacle behind or in front of the car depending on the IR sensors
			MOV_LEF_BCK();
			i++;
		}
		else {
			STP();
		}
		_delay_ms(100); /* 1 step back */
	}
	/* MOV_BCK(); we can put it in case needed in hardware
	 * _delay_ms(2000) */
	MOV_Ri_BCK();
	while (i < 100) { //100 need change on hardware
		if (F_Obstacle != 0 && B_Obstacle != 0) {
			MOV_Ri_BCK();
			i++;
		}
		else {
			STP();
		}
		_delay_ms(100);
	}
	STP();
	LCD_clearScreen();
	LCD_displayString("*****Parked*****");
}

void Timer2_OV_init (void) {				/* overflow every 32msec */
	TCNT2 = 0;
	TCCR2 = (1<<CS20)|(1<<CS21)|(1<<CS22);	/* Initialize timer2 in overflow mode with prescaler 1024 */
	SET_BIT(TIMSK,TOIE2);					/* Enable timer2 overflow Interrupt */
}

ISR(TIMER2_OVF_vect) {
	if (frontIRread()) {
		F_Obstacle = 1;
	}
	else {
		F_Obstacle = 0;
	}
	if (backIRread()) {
		B_Obstacle = 1;
	}
	else {
		B_Obstacle = 0;
	}
}
