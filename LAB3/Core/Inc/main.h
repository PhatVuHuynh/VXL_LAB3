/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define R1_A1_Pin GPIO_PIN_0
#define R1_A1_GPIO_Port GPIOA
#define R1_B1_Pin GPIO_PIN_1
#define R1_B1_GPIO_Port GPIOA
#define R1_C1_Pin GPIO_PIN_2
#define R1_C1_GPIO_Port GPIOA
#define R1_D1_Pin GPIO_PIN_3
#define R1_D1_GPIO_Port GPIOA
#define R1_E1_Pin GPIO_PIN_4
#define R1_E1_GPIO_Port GPIOA
#define R1_F1_Pin GPIO_PIN_5
#define R1_F1_GPIO_Port GPIOA
#define R1_G1_Pin GPIO_PIN_6
#define R1_G1_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOB
#define BUTTON3_Pin GPIO_PIN_2
#define BUTTON3_GPIO_Port GPIOB
#define R2_B_Pin GPIO_PIN_10
#define R2_B_GPIO_Port GPIOB
#define R2_C_Pin GPIO_PIN_11
#define R2_C_GPIO_Port GPIOB
#define R2_D_Pin GPIO_PIN_12
#define R2_D_GPIO_Port GPIOB
#define R2_E_Pin GPIO_PIN_13
#define R2_E_GPIO_Port GPIOB
#define R2_F_Pin GPIO_PIN_14
#define R2_F_GPIO_Port GPIOB
#define R2_G_Pin GPIO_PIN_15
#define R2_G_GPIO_Port GPIOB
#define R1_A_Pin GPIO_PIN_9
#define R1_A_GPIO_Port GPIOA
#define R1_B_Pin GPIO_PIN_10
#define R1_B_GPIO_Port GPIOA
#define R1_C_Pin GPIO_PIN_11
#define R1_C_GPIO_Port GPIOA
#define R1_D_Pin GPIO_PIN_12
#define R1_D_GPIO_Port GPIOA
#define R1_E_Pin GPIO_PIN_13
#define R1_E_GPIO_Port GPIOA
#define R1_F_Pin GPIO_PIN_14
#define R1_F_GPIO_Port GPIOA
#define R1_G_Pin GPIO_PIN_15
#define R1_G_GPIO_Port GPIOA
#define R1_RED_Pin GPIO_PIN_3
#define R1_RED_GPIO_Port GPIOB
#define R1_YELLOW_Pin GPIO_PIN_4
#define R1_YELLOW_GPIO_Port GPIOB
#define R1_GREEN_Pin GPIO_PIN_5
#define R1_GREEN_GPIO_Port GPIOB
#define R2_RED_Pin GPIO_PIN_6
#define R2_RED_GPIO_Port GPIOB
#define R2_YELLOW_Pin GPIO_PIN_7
#define R2_YELLOW_GPIO_Port GPIOB
#define R2_GREEN_Pin GPIO_PIN_8
#define R2_GREEN_GPIO_Port GPIOB
#define R2_A_Pin GPIO_PIN_9
#define R2_A_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/