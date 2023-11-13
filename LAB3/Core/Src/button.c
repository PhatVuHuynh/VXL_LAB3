/*
 * button.c
 *
 *  Created on: Nov 3, 2023
 *      Author: ADMIN
 */
#include "button.h"

int key_flag[3] = {0, 0, 0};

int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int preState[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress = 200;

void subKeyProcess(int id){
	//HAL_GPIO_TogglePin(GPIOA, A5_Pin);
	key_flag[id] = 1;
}

int is_Pressed(int id){
	if(key_flag[id]){
		key_flag[id] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(int id, uint16_t BUTTON){
	keyReg0[id] = keyReg1[id];
	keyReg1[id] = keyReg2[id];
	keyReg2[id] = HAL_GPIO_ReadPin(GPIOB, BUTTON);

	if(keyReg0[id] == keyReg1[id] && keyReg1[id] == keyReg2[id]){
		if(keyReg2[id] != preState[id]){
			preState[id] = keyReg2[id];

			if(keyReg2[id] == PRESS_STATE){
				subKeyProcess(id);
				//TimerForKeyPress = 200;
				TimerForKeyPress = 50;
			}
		}
		else{
			--TimerForKeyPress;
			if(TimerForKeyPress <= 0){
				if(keyReg2[id] == PRESS_STATE){
					subKeyProcess(id);
				}
				//TimerForKeyPress = 200;
				TimerForKeyPress = 50;
			}
		}
	}
};
