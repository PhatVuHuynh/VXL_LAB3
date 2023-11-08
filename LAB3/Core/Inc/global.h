/*
 * global.h
 *
 *  Created on: Nov 4, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "button.h"
#include "main.h"

#define INIT 	0
#define RED_GREEN	1
#define RED_YELLOW	2
#define GREEN_RED	3
#define YELLOW_RED	4

#define MODIFY_RED	12
#define MODIFY_YELLOW	13
#define MODIFY_GREEN	14

#define R1 0
#define R2 1

#define BUTTON1		0
#define BUTTON2		1
#define BUTTON3		2

#define RED_DURA	0
#define YELLOW_DURA	1
#define GREEN_DURA	2

extern uint16_t status;
extern uint16_t modify_val;
extern uint8_t led_count1;
extern uint8_t led_count2;

extern uint8_t mode;
extern uint8_t segth;

extern uint8_t led_duration[3];
extern uint8_t segments[10];

void display7SEG(uint8_t num);
void scan7SEG(uint8_t mode, uint8_t i);
void write_led(uint16_t R1_LED, uint16_t R2_LED, int state);

#endif /* INC_GLOBAL_H_ */
