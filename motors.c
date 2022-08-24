#include "motors.h"

void init_motors(void)
{
	MOTORS_DDR = 0xFF;
}

void STP(void)
{
	MOTORS_PORT = 0x00;
}

void MOV_FWR(void)
{
	MOTORS_PORT  = (1<<F_R_A)|(1<<F_L_A)|(1<<B_R_A)|(1<<B_L_A);
}

void MOV_BCK(void)
{
	MOTORS_PORT  = (1<<F_R_C)|(1<<F_L_C)|(1<<B_R_C)|(1<<B_L_C);
}

void MOV_Ri_FWR(void)
{
	MOTORS_PORT  = (1<<F_L_A)|(1<<B_L_A);
	//MOTORS_PORT  = (1<<F_L_A);
}

void MOV_LEF_FWR(void)
{
	MOTORS_PORT  = (1<<F_R_A)|(1<<B_R_A);
}

void MOV_Ri_BCK(void)
{
	MOTORS_PORT  = (1<<F_L_C)|(1<<B_L_C);
}

void MOV_LEF_BCK(void)
{
	MOTORS_PORT  = (1<<F_R_C)|(1<<B_R_C);
}
