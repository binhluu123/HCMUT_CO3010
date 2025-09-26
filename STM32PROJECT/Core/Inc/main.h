/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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
#define LED_RED_N_Pin GPIO_PIN_1
#define LED_RED_N_GPIO_Port GPIOA
#define LED_YELLOW_N_Pin GPIO_PIN_2
#define LED_YELLOW_N_GPIO_Port GPIOA
#define LED_GREEN_N_Pin GPIO_PIN_3
#define LED_GREEN_N_GPIO_Port GPIOA
#define LED_RED_S_Pin GPIO_PIN_4
#define LED_RED_S_GPIO_Port GPIOA
#define LED_YELLOW_S_Pin GPIO_PIN_5
#define LED_YELLOW_S_GPIO_Port GPIOA
#define LED_GREEN_S_Pin GPIO_PIN_6
#define LED_GREEN_S_GPIO_Port GPIOA
#define LED_RED_W_Pin GPIO_PIN_7
#define LED_RED_W_GPIO_Port GPIOA
#define LED7_1_a_Pin GPIO_PIN_0
#define LED7_1_a_GPIO_Port GPIOB
#define LED7_1_b_Pin GPIO_PIN_1
#define LED7_1_b_GPIO_Port GPIOB
#define LED7_1_c_Pin GPIO_PIN_2
#define LED7_1_c_GPIO_Port GPIOB
#define LED7_2_d_Pin GPIO_PIN_10
#define LED7_2_d_GPIO_Port GPIOB
#define LED7_2_e_Pin GPIO_PIN_11
#define LED7_2_e_GPIO_Port GPIOB
#define LED7_2_f_Pin GPIO_PIN_12
#define LED7_2_f_GPIO_Port GPIOB
#define LED7_2_g_Pin GPIO_PIN_13
#define LED7_2_g_GPIO_Port GPIOB
#define LED_YELLOW_W_Pin GPIO_PIN_8
#define LED_YELLOW_W_GPIO_Port GPIOA
#define LED_GREEN_W_Pin GPIO_PIN_9
#define LED_GREEN_W_GPIO_Port GPIOA
#define LED_RED_E_Pin GPIO_PIN_10
#define LED_RED_E_GPIO_Port GPIOA
#define LED_YELLOW_E_Pin GPIO_PIN_11
#define LED_YELLOW_E_GPIO_Port GPIOA
#define LED_GREEN_E_Pin GPIO_PIN_12
#define LED_GREEN_E_GPIO_Port GPIOA
#define LED_BLINKY_Pin GPIO_PIN_13
#define LED_BLINKY_GPIO_Port GPIOA
#define LED7_1_d_Pin GPIO_PIN_3
#define LED7_1_d_GPIO_Port GPIOB
#define LED7_1_e_Pin GPIO_PIN_4
#define LED7_1_e_GPIO_Port GPIOB
#define LED7_1_f_Pin GPIO_PIN_5
#define LED7_1_f_GPIO_Port GPIOB
#define LED7_1_g_Pin GPIO_PIN_6
#define LED7_1_g_GPIO_Port GPIOB
#define LED7_2_a_Pin GPIO_PIN_7
#define LED7_2_a_GPIO_Port GPIOB
#define LED7_2_b_Pin GPIO_PIN_8
#define LED7_2_b_GPIO_Port GPIOB
#define LED7_2_c_Pin GPIO_PIN_9
#define LED7_2_c_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
