/*
 * software_timer.h
 *
 *  Created on: Sep 25, 2023
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer_counter[3];
extern int timer_flag[3];

void setTimer(int duration, int id);
void timerRun(int id);
//void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim );

//extern int timer_counter;
//extern int timer_flag;
//
//void setTimer(int duration);
//void timerRun();
//void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim );



#endif /* INC_TIMER_H_ */
