
#ifndef _MOTORS_H
#define _MOTORS_H

#include <avr/io.h>

/* Pins can change on hardware implementation */
#define MOTORS_DDR DDRA
#define MOTORS_PORT PORTA

#define F_R_C 0			//front right motor clockwise is enabled by pin 0
#define F_R_A 1			//front right motor anti-clockwise is enabled by pin 1
#define F_L_C 2			//front left motor clockwise is enabled by pin 2
#define F_L_A 3			//front left motor anti-clockwise is enabled by pin 3
#define B_R_C 4			//back right motor clockwise is enabled by pin 4
#define B_R_A 5			//back right motor anti-clockwise is enabled by pin 5
#define B_L_C 6			//back left motor clockwise is enabled by pin 6
#define B_L_A 7			//back left motor anti-clockwise is enabled by pin 7

void init_motors(void);
void MOV_FWR(void);
void MOV_BCK(void);
void STP(void);
void MOV_Ri_FWR(void);
void MOV_LEF_FWR(void);
void MOV_Ri_BCK(void);
void MOV_LEF_BCK(void);

#endif
