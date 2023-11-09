/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "input_reading.h"
#include "input_processing.h"
//#include "global.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
int LED = 0;
int SEG = 1;
int MATRIX = 2;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//
//const int MAX_LED_MATRIX = 8;
//int index_led_matrix = 0;
//uint8_t matrix_buffer[8] = //{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
//		{0xE7, 0xDB, 0xBD, 0xBD, 0x81, 0xBD, 0xBD, 0xBD};//A
//
//
//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer[4] = {0, 0, 0, 0};
//int hour = 15, min = 8, sec = 50;
//
//void updateClockBuffer(){
//	led_buffer[0] = hour / 10;
//	led_buffer[2] = min / 10;
//	led_buffer[1] = hour % 10;
//	led_buffer[3] = min % 10;
//	++clock_buffer[2];
//	if(clock_buffer[2] == 60){
//	  ++clock_buffer[1];
//	  clock_buffer[2] = 0;
//	}
//	if(clock_buffer[1] == 60){
//	  ++clock_buffer[0];
//	  clock_buffer[1] = 0;
//	}
//	if(clock_buffer[0] == 24){
//	  clock_buffer[0] = 0;
//	}
//}

//void update7SEG(int id){
//	switch(id){
//		case 0: {
//		  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_RESET);
//		  HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
//		  display7SEG(led_buffer[id]);
//		  break;
//		}
//		case 1: {
//			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
//		  display7SEG(led_buffer[id]);
//		  break;
//		}
//		case 2: {
//			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
//		  display7SEG(led_buffer[id]);
//		  break;
//		}
//		case 3: {
//			HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
//		  display7SEG(led_buffer[id]);
//		  break;
//		}
//		default:{
//		  HAL_GPIO_WritePin(dot_GPIO_Port, dot_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(en0_GPIO_Port, en2_Pin, GPIO_PIN_SET);
//		  HAL_GPIO_WritePin(en1_GPIO_Port, en3_Pin, GPIO_PIN_SET);
//		  break;
//		}
//	}
//}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


//  setTimer(50, id);
//  HAL_GPIO_WritePin(dot_GPIO_Port, dot_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, GPIO_PIN_SET);
//  setTimer(100, SEG);
//  setTimer(100, LED);
//  setTimer(1, MATRIX);
//
//  int seg = 0;
//  int id = 0;
//  int led = 1;

//  HAL_GPIO_WritePin(GPIOA, A5_Pin, 1);
  //HAL_GPIO_WritePin(GPIOB, BUTTON1_Pin, 1);

setTimer(50, 0);
setTimer(100, 1);
setTimer(24, 2);
status = INIT;
//HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 1);
//int c = 0;
  while (1){

//	  HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 0);
//	  if(timer_flag[2]) {
//		  HAL_GPIO_TogglePin(GPIOB, R1_RED_Pin);
//		scan7SEG(1, 11);		//Display letter 'E'
//		setTimer(24, 2);
//	}


//	  HAL_GPIO_TogglePin(SEG1_GPIO_Port, SEG1_Pin);
//	  HAL_GPIO_TogglePin(SEG1_GPIO_Port, R1_A_Pin);
//
//	  HAL_GPIO_TogglePin(GPIOB, R1_RED_Pin);
//	  HAL_Delay(250);
//	  if(timer_flag[0]){
	  fsm_for_normal();
	  fsm_for_modify();
//	  write_led(R1_RED_Pin, R2_GREEN_Pin, 0);

//	display7SEG(led_count[R1], GPIOA);
//	display7SEG(led_count[R2], GPIOB);
//
//	if(timer_flag[1]){
//		led_count[R1] = 9;
//		led_count[R2] = 9;
//		status = RED_YELLOW;
//		HAL_GPIO_TogglePin(GPIOA, R1_RED_Pin);
//		HAL_GPIO_TogglePin(GPIOA, R2_GREEN_Pin);
//		setTimer(300, 1);
//	}
//	if(timer_flag[0]){
////	display7SEG(c++, GPIOA);
////	c %= 10;
//		--led_count[0];
//		--led_count[1];
//	  setTimer(100, 0);
//	}


//	  fsm_for_auto_processing();
//	  fsm_for_manual_processing();

//	  if(is_Pressed() == 1){
//		  HAL_GPIO_TogglePin(GPIOA, A5_Pin);
//	  }

	  //HAL_GPIO_WritePin(GPIOA, A5_Pin, HAL_GPIO_ReadPin(GPIOB, BUTTON_1_Pin));
	  //fsm_for_input_processing();

//	  if(timer_flag[LED] == 1){
//		  switch(led){
//		  	  case 1:{
//		  		  HAL_GPIO_WritePin(dot_GPIO_Port, dot_Pin, GPIO_PIN_SET);
//		  		  led = 0;
//		  		  break;
//		  	  }
//		  	  default:{
//		  		  HAL_GPIO_WritePin(dot_GPIO_Port, dot_Pin, GPIO_PIN_RESET);
//		  		  led = 1;
//		  	  }
//		  }
//
//		  shiftLeft(matrix_buffer);
//		  setTimer(100, LED);
//	  }
//
//	  if(timer_flag[MATRIX] == 1){
//
//		  updateLEDMatrix(matrix_buffer, id++);
//			if (id> 7) {
//				id= 0;
//			}
//
//		  setTimer(1, MATRIX);
//	  }
//	  if(timer_flag[SEG] == 1){
//
//		  updateClockBuffer();
//		  seg = seg % MAX_LED;
//		  update7SEG(seg++);
//		  ++sec;
//
//
////		  switch(seg){
////			  case 1: {
////				  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, (seg == 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, (seg == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, (seg == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, (seg == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
////				  display7SEG(seg);
////				  seg = 2;
////				  break;
////			  }
////			  case 2: {
////				  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, (seg == 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, (seg == 2) ? GPIO_PIN_RESET : GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, (seg == 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, (seg == 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
////				  display7SEG(seg);
////				  seg = 3;
////				  break;
////			  }
////			  case 3: {
////				  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, (seg == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, (seg == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, (seg == 3) ? GPIO_PIN_RESET : GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, (seg == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
////				  display7SEG(seg);
////				  seg = 4;
////				  break;
////			  }
////			  case 4: {
////				  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, (seg == 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, (seg == 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en2_GPIO_Port, en2_Pin, (seg == 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
////				  HAL_GPIO_WritePin(en3_GPIO_Port, en3_Pin, (seg == 4) ? GPIO_PIN_RESET : GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
////				  display7SEG(seg - 4);
////				  seg = 1;
////				  break;
////			  }
////			  default:{
////				  HAL_GPIO_WritePin(dot_GPIO_Port, dot_Pin, GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en0_GPIO_Port, en0_Pin, GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en1_GPIO_Port, en1_Pin, GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en0_GPIO_Port, en2_Pin, GPIO_PIN_SET);
////				  HAL_GPIO_WritePin(en1_GPIO_Port, en3_Pin, GPIO_PIN_SET);
////				  seg = 1;
////				  break;
////			  }
////		  }
//
//
//
//		  //setTimer(50, id);
//		  setTimer(100, SEG);
	  //}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin
                          |R1_A_Pin|R1_B_Pin|R1_C_Pin|R1_D_Pin
                          |R1_E_Pin|R1_F_Pin|R1_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, R1_RED_Pin|R1_YELLOW_Pin|R1_GREEN_Pin|R2_RED_Pin
                          |R2_YELLOW_Pin|R2_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SEG1_Pin SEG2_Pin SEG3_Pin SEG4_Pin
                           R1_A_Pin R1_B_Pin R1_C_Pin R1_D_Pin
                           R1_E_Pin R1_F_Pin R1_G_Pin */
  GPIO_InitStruct.Pin = SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin
                          |R1_A_Pin|R1_B_Pin|R1_C_Pin|R1_D_Pin
                          |R1_E_Pin|R1_F_Pin|R1_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON1_Pin BUTTON2_Pin BUTTON3_Pin */
  GPIO_InitStruct.Pin = BUTTON1_Pin|BUTTON2_Pin|BUTTON3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : R1_RED_Pin R1_YELLOW_Pin R1_GREEN_Pin R2_RED_Pin
                           R2_YELLOW_Pin R2_GREEN_Pin */
  GPIO_InitStruct.Pin = R1_RED_Pin|R1_YELLOW_Pin|R1_GREEN_Pin|R2_RED_Pin
                          |R2_YELLOW_Pin|R2_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
//  int counter = 100;
//  void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	  --counter;
//	  if(counter <= 0){
//		  counter = 100;
//		  HAL_GPIO_TogglePin(GPIOA, R1_RED_Pin);
//	  }
//  }

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	timerRun();
	timerRun(0);
	timerRun(1);
	timerRun(2);
	getKeyInput(BUTTON1, BUTTON1_Pin);
	getKeyInput(BUTTON2, BUTTON2_Pin);
	getKeyInput(BUTTON3, BUTTON3_Pin);
	//if(htim->Instance == TIM2) {
	//		  button_reading () ;
	//}
	//	  timerRun(LED);
	//	  timerRun(SEG);
	//	  timerRun(MATRIX);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
