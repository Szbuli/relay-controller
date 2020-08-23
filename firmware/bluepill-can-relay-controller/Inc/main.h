/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#define BUSY_LED_Pin GPIO_PIN_13
#define BUSY_LED_GPIO_Port GPIOC
#define FACTORY_RESET_Pin GPIO_PIN_14
#define FACTORY_RESET_GPIO_Port GPIOC
#define RELAY_1_Pin GPIO_PIN_1
#define RELAY_1_GPIO_Port GPIOA
#define RELAY_2_Pin GPIO_PIN_2
#define RELAY_2_GPIO_Port GPIOA
#define RELAY_3_Pin GPIO_PIN_3
#define RELAY_3_GPIO_Port GPIOA
#define RELAY_4_Pin GPIO_PIN_4
#define RELAY_4_GPIO_Port GPIOA
#define RELAY_5_Pin GPIO_PIN_5
#define RELAY_5_GPIO_Port GPIOA
#define RELAY_6_Pin GPIO_PIN_6
#define RELAY_6_GPIO_Port GPIOA
#define RELAY_7_Pin GPIO_PIN_7
#define RELAY_7_GPIO_Port GPIOA
#define RELAY_8_Pin GPIO_PIN_0
#define RELAY_8_GPIO_Port GPIOB
#define RELAY_9_Pin GPIO_PIN_1
#define RELAY_9_GPIO_Port GPIOB
#define RELAY_10_Pin GPIO_PIN_10
#define RELAY_10_GPIO_Port GPIOB
#define RELAY_11_Pin GPIO_PIN_11
#define RELAY_11_GPIO_Port GPIOB
#define RELAY_12_Pin GPIO_PIN_12
#define RELAY_12_GPIO_Port GPIOB
#define RELAY_13_Pin GPIO_PIN_13
#define RELAY_13_GPIO_Port GPIOB
#define RELAY_14_Pin GPIO_PIN_14
#define RELAY_14_GPIO_Port GPIOB
#define RELAY_15_Pin GPIO_PIN_15
#define RELAY_15_GPIO_Port GPIOB
#define RELAY_16_Pin GPIO_PIN_8
#define RELAY_16_GPIO_Port GPIOA
#define TAMPER_Pin GPIO_PIN_5
#define TAMPER_GPIO_Port GPIOB
#define TAMPER_EXTI_IRQn EXTI9_5_IRQn
#define I2C_SCL_Pin GPIO_PIN_6
#define I2C_SCL_GPIO_Port GPIOB
#define I2C_SDA_Pin GPIO_PIN_7
#define I2C_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
