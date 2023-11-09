/*
 * global.c
 *
 *  Created on: Nov 4, 2023
 *      Author: ADMIN
 */

#include "global.h"


uint16_t modify_val = 1;
uint16_t status = INIT;
uint8_t led_duration[3] = {INIT_RED_DURA, INIT_YELLOW_DURA, INIT_GREEN_DURA};

uint8_t led_count1 = INIT_RED_DURA;
uint8_t led_count2 = INIT_GREEN_DURA;

uint8_t mode = 0;
uint8_t segth = 0;

uint8_t segments[11] = {
        0b0111111, // 0
        0b0000110, // 1
        0b1011011, // 2
        0b1001111, // 3
        0b1100110, // 4
        0b1101101, // 5
        0b1111101, // 6
        0b0000111, // 7
        0b1111111, // 8
        0b1101111, // 9
		0b1111001  // E
   };

void display7SEG(uint8_t num){
	    uint8_t displaySegments = segments[num];

		HAL_GPIO_WritePin(GPIOA, R1_A_Pin, (displaySegments & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, R1_B_Pin, ((displaySegments >> 1) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, R1_C_Pin, ((displaySegments >> 2) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, R1_D_Pin, ((displaySegments >> 3) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, R1_E_Pin, ((displaySegments >> 4) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, R1_F_Pin, ((displaySegments >> 5) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, R1_G_Pin, ((displaySegments >> 6) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }

void scan7SEG(uint8_t mode, uint8_t i){
	//for(int i = 0; i < 4; ++i){
		if(mode == 0){
			switch(i){
					case 0:
						HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 0);
						display7SEG(led_count1 / 10);
						break;
					case 1:
						HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 0);
						display7SEG(led_count1 % 10);
						break;
					case 2:
						HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG3_Pin, 0);
						display7SEG(led_count2 / 10);
						break;
					case 3:
						HAL_GPIO_WritePin(GPIOA, SEG3_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 0);
						display7SEG(led_count2 % 10);
						break;
					default:
						HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG3_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 0);
						display7SEG(10);
						break;
			}

		}
		else{
			switch(i){
					case 0:
						HAL_GPIO_WritePin(GPIOA, SEG3_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 0);
						display7SEG(modify_val / 10);
						break;
					case 1:
						HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 0);
						display7SEG(modify_val % 10);
						break;
					case 2:
						HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 1);
						HAL_GPIO_WritePin(GPIOA, SEG3_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 0);
						display7SEG(status - 10);
						display7SEG(status - 10);
						break;
					default:
						HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG3_Pin, 0);
						HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 0);
						display7SEG(10);
						break;
			}
		}
	//}

}

//void display7SEG(int num, GPIO_TypeDef* gpio, int special){
//	    uint8_t displaySegments = segments[num];
//
//	    if(gpio == GPIOA){
//	    	if(special){
//	    		HAL_GPIO_WritePin(gpio, R1_A1_Pin, (displaySegments & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_B1_Pin, ((displaySegments >> 1) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_C1_Pin, ((displaySegments >> 2) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_D1_Pin, ((displaySegments >> 3) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_E1_Pin, ((displaySegments >> 4) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_F1_Pin, ((displaySegments >> 5) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_G1_Pin, ((displaySegments >> 6) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//	    	}
//	    	else{
//	    		HAL_GPIO_WritePin(gpio, R1_A_Pin, (displaySegments & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_B_Pin, ((displaySegments >> 1) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_C_Pin, ((displaySegments >> 2) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_D_Pin, ((displaySegments >> 3) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_E_Pin, ((displaySegments >> 4) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_F_Pin, ((displaySegments >> 5) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//				HAL_GPIO_WritePin(gpio, R1_G_Pin, ((displaySegments >> 6) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//	    	}
//	    }
//	    else{
//	    	HAL_GPIO_WritePin(gpio, R2_A_Pin, (displaySegments & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//			HAL_GPIO_WritePin(gpio, R2_B_Pin, ((displaySegments >> 1) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//			HAL_GPIO_WritePin(gpio, R2_C_Pin, ((displaySegments >> 2) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//			HAL_GPIO_WritePin(gpio, R2_D_Pin, ((displaySegments >> 3) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//			HAL_GPIO_WritePin(gpio, R2_E_Pin, ((displaySegments >> 4) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//			HAL_GPIO_WritePin(gpio, R2_F_Pin, ((displaySegments >> 5) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//			HAL_GPIO_WritePin(gpio, R2_G_Pin, ((displaySegments >> 6) & 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//	    }
//  }

void write_led(uint16_t R1_LED, uint16_t R2_LED, int state){
	HAL_GPIO_WritePin(GPIOB, R1_LED, state);
	HAL_GPIO_WritePin(GPIOB, R2_LED, state);
}
