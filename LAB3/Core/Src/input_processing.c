/*
* input_processing.c
*
*  Created on: Nov 1, 2023
*      Author: ADMIN
*/

#include "input_processing.h"

void fsm_for_normal (){
	switch(status){
			case INIT:
				write_led(R1_RED_Pin, R2_RED_Pin, 1);			//RED LEDs OFF
				write_led(R1_YELLOW_Pin, R2_YELLOW_Pin, 1);		//YELLOW LEDs OFF
				write_led(R1_GREEN_Pin, R2_GREEN_Pin, 1);		//GREEN LEDs OFF
				write_led(SEG1_Pin, SEG2_Pin, 1);				//4 7SEG OFF
				write_led(SEG3_Pin, SEG4_Pin, 1);

				status = RED_GREEN;
				setTimer(1, 0);								//Timer for every second
				setTimer(led_duration[GREEN_DURA], 1);	//Timer for led duration
				setTimer(0.24, 2);								//Timer for scan 7SEG
				break;
			case RED_GREEN:
				if(timer_flag[1]){
//					if(led_count1 < led_count2){				//If red = 0 and green > 0, wait till green = 0
//						setTimer(led_count2 * 100, 1);			//else change to state RED_YELLOW
//					}
//					else{

						led_count2 = led_duration[YELLOW_DURA];
						++led_count1;
						++led_count2;
						status = RED_YELLOW;
						write_led(R1_RED_Pin, R2_GREEN_Pin, 1);
						setTimer(led_duration[YELLOW_DURA], 1);
					//}

				}
				else{
					write_led(R1_RED_Pin, R2_GREEN_Pin, 0);		//ROAD1: RED ON, ROAD2: GREEN ON

					if(timer_flag[2]) {
						scan7SEG(mode, segth++);									//display 4 7SEG count
						segth %= 4;
						setTimer(0.24, 2);
					}
				}


				if(is_Pressed(BUTTON1)){						//If BUTTON1 is pressed, change to MODIFY_RED state
					status = MODIFY_RED;						//and set timer for every 0.5 sec
					write_led(R1_RED_Pin, R2_GREEN_Pin, 1);
					mode = 1;
					setTimer(0.5, 0);
				}
				break;
			case RED_YELLOW:
				if(timer_flag[1]){
//					if(led_count1 < led_count2){
//						setTimer(led_count2 * 100, 1);
//					}
//					else{

						led_count1 = led_duration[GREEN_DURA];
						led_count2 = led_duration[RED_DURA];
						++led_count1;
						++led_count2;
						status = GREEN_RED;
						write_led(R1_RED_Pin, R2_YELLOW_Pin, 1);
						setTimer(led_duration[GREEN_DURA], 1);
					//}
				}
				else{
					write_led(R1_RED_Pin, R2_YELLOW_Pin, 0);

					if(timer_flag[2]) {
						scan7SEG(mode, segth++);									//display 4 7SEG count
						segth %= 4;
						setTimer(0.24, 2);
					}
				}

				if(is_Pressed(BUTTON1)){
					status = MODIFY_RED;
					write_led(R1_RED_Pin, R2_YELLOW_Pin, 1);
					mode = 1;
					setTimer(0.5, 0);
				}
				break;
			case GREEN_RED:
				if(timer_flag[1]){
//					if(led_count2 < led_count1){
//						setTimer(led_count1 * 100, 1);
//					}
//					else{

						led_count1 = led_duration[YELLOW_DURA];
						++led_count1;
						++led_count2;
						status = YELLOW_RED;
						write_led(R1_GREEN_Pin, R2_RED_Pin, 1);
						setTimer(led_duration[YELLOW_DURA], 1);
					//}
				}
				else{
					write_led(R1_GREEN_Pin, R2_RED_Pin, 0);

					if(timer_flag[2]) {
						scan7SEG(mode, segth++);									//display 4 7SEG count
						segth %= 4;
						setTimer(0.24, 2);
					}
				}

				if(is_Pressed(BUTTON1)){
					status = MODIFY_RED;
					write_led(R1_GREEN_Pin, R2_RED_Pin, 1);
					mode = 1;
					setTimer(0.5, 0);
				}
				break;
			case YELLOW_RED:
				if(timer_flag[1]){
//					if(led_count2 < led_count1){
//						setTimer(led_count1 * 100, 1);
//					}
//					else{

						led_count1 = led_duration[RED_DURA];
						led_count2 = led_duration[GREEN_DURA];
						++led_count1;
						++led_count2;
						status = RED_GREEN;
						write_led(R1_YELLOW_Pin, R2_RED_Pin, 1);
						setTimer(led_duration[GREEN_DURA], 1);
					//}
				}
				else{
					write_led(R1_YELLOW_Pin, R2_RED_Pin, 0);

					if(timer_flag[2]) {
						scan7SEG(mode, segth++);									//display 4 7SEG count
						segth %= 4;
						setTimer(0.24, 2);
					}
				}

				if(is_Pressed(BUTTON1)){
					status = MODIFY_RED;
					write_led(R1_YELLOW_Pin, R2_RED_Pin, 1);
					mode = 1;
					setTimer(0.5, 0);
				}
				break;
		}

		if(timer_flag[0] && mode == 0){						//Every second, decrease led count
			if(led_count1 > 0) --led_count1;
			if(led_count2 > 0) --led_count2;
			setTimer(1, 0);
		}
}

void fsm_for_modify(){
	switch(status){
			case MODIFY_RED:
				if(timer_flag[2]) {
					scan7SEG(mode, segth++);					//Display modified value and number of MODE
					segth %= 3;
					setTimer(0.24, 2);
				}

				if(timer_flag[0]){
					HAL_GPIO_TogglePin(GPIOB, R1_RED_Pin | R2_RED_Pin);	//Red Leds blink every 0.5 sec
					setTimer(0.5, 0);
				}

				if(is_Pressed(BUTTON1)){								//If BUTTON1 is pressed, change to MODIFY_YELLOW state
					status = MODIFY_YELLOW;
					write_led(R1_RED_Pin, R2_RED_Pin, 1);
					break;
				}

				if(is_Pressed(BUTTON3)){								//If BUTTON3 is pressed, RED LEDs' duration = modify_val
					led_duration[RED_DURA] = modify_val;
				}
				break;
			case MODIFY_YELLOW:
				if(timer_flag[2]) {
					scan7SEG(mode, segth++);					//Display modified value and number of MODE
					segth %= 3;
					setTimer(0.24, 2);
				}

				if(timer_flag[0]){
					HAL_GPIO_TogglePin(GPIOB, R1_YELLOW_Pin | R2_YELLOW_Pin);
					setTimer(0.5, 0);
				}

				if(is_Pressed(BUTTON1)){
					status = MODIFY_GREEN;
					write_led(R1_YELLOW_Pin, R2_YELLOW_Pin, 1);
					break;
				}

				if(is_Pressed(BUTTON3)){
					led_duration[YELLOW_DURA] = modify_val;
				}
				break;
			case MODIFY_GREEN:
				if(timer_flag[2]) {
					scan7SEG(mode, segth++);					//Display modified value and number of MODE
					segth %= 3;
					setTimer(0.24, 2);
				}

				if(timer_flag[0]){
					HAL_GPIO_TogglePin(GPIOB, R1_GREEN_Pin | R2_GREEN_Pin);
					setTimer(0.5, 0);
				}

				if(is_Pressed(BUTTON1)){
					status = RED_GREEN;
					write_led(R1_GREEN_Pin, R2_GREEN_Pin, 1);
					mode = 0;

					if(led_duration[RED_DURA] != led_duration[GREEN_DURA] + led_duration[YELLOW_DURA]){
						led_duration[RED_DURA] = INIT_RED_DURA;			//if red_duration != yellow_duration + green_duration
						led_duration[YELLOW_DURA] = INIT_YELLOW_DURA;	//set all led duration to init_duration
						led_duration[GREEN_DURA] = INIT_GREEN_DURA;		//and change to state INIT
						status = ERR;
						mode = 1;
					}

					led_count1 = led_duration[RED_DURA];
					led_count2 = led_duration[GREEN_DURA];
//					++led_count1;
//					++led_count2;

					setTimer(led_duration[GREEN_DURA], 1);
					setTimer(1, 0);
					break;
				}

				if(is_Pressed(BUTTON3)){
					led_duration[GREEN_DURA] = modify_val;
				}
				break;
			case ERR:							//ERR state
				if(timer_flag[2]) {
					scan7SEG(mode, 10);		//Display letter 'E'
					setTimer(0.24, 2);
				}

				if(timer_flag[0]) {
					status = INIT;
					mode = 0;
					setTimer(led_duration[GREEN_DURA], 1);
					setTimer(1, 0);
				}
				break;
		}
	if(is_Pressed(BUTTON2) && mode == 1){					//If BUTTON2 is pressed, increase modify_val by 1
		++modify_val;
		if(modify_val == 100) modify_val = 1;
	}

}

//void fsm_for_7LEDs(){
//	switch(status){
//		case INIT:
//			HAL_GPIO_WritePin(GPIOA, A0_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A1_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A2_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A3_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A4_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//			status = A0_Pin;
//			break;
//		case A0_Pin:
//			HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A1_Pin;
//			}
//			break;
//		case A1_Pin:
//			HAL_GPIO_WritePin(GPIOA, A0_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A2_Pin;
//			}
//			break;
//		case A2_Pin:
//			HAL_GPIO_WritePin(GPIOA, A1_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A3_Pin;
//			}
//			break;
//		case A3_Pin:
//			HAL_GPIO_WritePin(GPIOA, A2_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A4_Pin;
//			}
//			break;
//		case A4_Pin:
//			HAL_GPIO_WritePin(GPIOA, A3_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A5_Pin;
//			}
//			break;
//		case A5_Pin:
//			HAL_GPIO_WritePin(GPIOA, A4_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A6_Pin;
//			}
//			break;
//		case A6_Pin:
//			HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A7_Pin;
//			}
//			break;
//		case A7_Pin:
//			HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, status, 0);
//
//			if(is_Pressed()){
//				status = A0_Pin;
//			}
//			break;
//	}
//}

//void fsm_for_manual_processing (){
//	switch(status){
//			case MAN_RED:
//				HAL_GPIO_WritePin(GPIOA, A5_Pin, 0);
//				HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//				HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//
//				if(timer_flag){
//					status = AUTO_RED;
//					setTimer(500);
//				}
//
//				if(is_Pressed()){
//					status = MAN_GREEN;
//					setTimer(500);
//				}
//				break;
//			case MAN_YELLOW:
//				HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//				HAL_GPIO_WritePin(GPIOA, A6_Pin, 0);
//				HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//
//				if(timer_flag){
//					status = AUTO_YELLOW;
//					setTimer(200);
//				}
//
//				if(is_Pressed()){
//					status = MAN_RED;
//					setTimer(500);
//				}
//				break;
//			case MAN_GREEN:
//				HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//				HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//				HAL_GPIO_WritePin(GPIOA, A7_Pin, 0);
//
//				if(timer_flag){
//					status = AUTO_GREEN;
//					setTimer(300);
//				}
//
//				if(is_Pressed()){
//					status = MAN_YELLOW;
//					setTimer(500);
//				}
//				break;
//		}
//
//}

//void fsm_for_auto_processing (){
//	switch(status){
//		case INIT:
//			HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//			status = AUTO_RED;
//			setTimer(500);
//			break;
//		case AUTO_RED:
//			HAL_GPIO_WritePin(GPIOA, A5_Pin, 0);
//			HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//
//			if(timer_flag){
//				status = AUTO_GREEN;
//				setTimer(300);
//			}
//
//			if(is_Pressed()){
//				status = MAN_RED;
//				setTimer(500);
//			}
//			break;
//		case AUTO_YELLOW:
//			HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A6_Pin, 0);
//			HAL_GPIO_WritePin(GPIOA, A7_Pin, 1);
//
//			if(timer_flag){
//				status = AUTO_RED;
//				setTimer(500);
//			}
//
//			if(is_Pressed()){
//				status = MAN_YELLOW;
//				setTimer(500);
//			}
//			break;
//		case AUTO_GREEN:
//			HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//			HAL_GPIO_WritePin(GPIOA, A7_Pin, 0);
//
//			if(timer_flag){
//				status = AUTO_YELLOW;
//				setTimer(200);
//			}
//
//			if(is_Pressed()){
//				status = MAN_GREEN;
//				setTimer(500);
//			}
//			break;
//	}
//}


//#include "main.h"
//#include "timer.h"
//#include "input_reading.h"
//
//enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED ,BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
//enum ButtonState buttonState = BUTTON_RELEASED ;
//
//uint32_t count = 20000;
//
//void fsm_for_input_processing ( void ) {
//	switch ( buttonState ){
//		case BUTTON_RELEASED :
//			if( is_button_pressed (0) ) {
//				buttonState = BUTTON_PRESSED ;
//				// INCREASE VALUE OF PORT A BY ONE UNIT
////				HAL_GPIO_WritePin(GPIOA, A5_Pin, 0);
//				HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//			}
//			//else HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//			break ;
//		case BUTTON_PRESSED :
//			if (! is_button_pressed (0) ) {
//				buttonState = BUTTON_RELEASED ;
////				HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//				HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//			}
//			else {
//				if( is_button_pressed_1s (0) ) {
//					buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
//					HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//					//HAL_GPIO_WritePin(GPIOA, A5_Pin, 0);
////					setTimer(1000);
//					count = 20000;
//				}
//			}
//			break ;
//		case BUTTON_PRESSED_MORE_THAN_1_SECOND :
//			if (! is_button_pressed (0) ) {
//				buttonState = BUTTON_RELEASED ;
//				HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
//				//HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//			}
//			// todo
//			else{
//				--count;
//				if(count == 0){
//					HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//					//HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
//					count = 20000;
//				}
////				if(timer_flag == 1){
////					HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//////					HAL_GPIO_WritePin(GPIOA, A6_Pin, 1);
////					setTimer(1000);
////				}
//			}
//			break ;
//	}
//}
