/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "can_support.h"
#include "home_log.h"
#include "home_config.h"
#include "relay.h"
#include "tamper.h"
#include "ha_auto_discovery.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId canSendTaskHandle;
osThreadId canReceiveTaskHandle;
osThreadId tamperTaskHandle;
osThreadId initTaskHandle;
osThreadId heartbeatTaskHandle;
osMessageQId CAN_SEND_QUEUEHandle;
osMessageQId CAN_RECEIVE_QUEUEHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartCanTask(void const *argument);
void StartCanReceiveTask(void const *argument);
void StartTamperTask(void const *argument);
void StartInitTask(void const *argument);
void StartHeartbeatTask(void const *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
		uint32_t *pulIdleTaskStackSize);

/* USER CODE BEGIN PREPOSTSLEEP */
__weak void PreSleepProcessing(uint32_t *ulExpectedIdleTime) {
	/* place for user code */
}

__weak void PostSleepProcessing(uint32_t *ulExpectedIdleTime) {
	/* place for user code */
}
/* USER CODE END PREPOSTSLEEP */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
		uint32_t *pulIdleTaskStackSize) {
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
	*ppxIdleTaskStackBuffer = &xIdleStack[0];
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
	/* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void) {
	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* Create the queue(s) */
	/* definition and creation of CAN_SEND_QUEUE */
	osMessageQDef(CAN_SEND_QUEUE, 40, CAN_OBJECT*);
	CAN_SEND_QUEUEHandle = osMessageCreate(osMessageQ(CAN_SEND_QUEUE), NULL);

	/* definition and creation of CAN_RECEIVE_QUEUE */
	osMessageQDef(CAN_RECEIVE_QUEUE, 40, RECEIVED_CAN_OBJECT);
	CAN_RECEIVE_QUEUEHandle = osMessageCreate(osMessageQ(CAN_RECEIVE_QUEUE), NULL);

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* definition and creation of canSendTask */
	osThreadDef(canSendTask, StartCanTask, osPriorityAboveNormal, 0, 128);
	canSendTaskHandle = osThreadCreate(osThread(canSendTask), NULL);

	/* definition and creation of canReceiveTask */
	osThreadDef(canReceiveTask, StartCanReceiveTask, osPriorityNormal, 0, 128);
	canReceiveTaskHandle = osThreadCreate(osThread(canReceiveTask), NULL);

	/* definition and creation of tamperTask */
	osThreadDef(tamperTask, StartTamperTask, osPriorityIdle, 0, 128);
	tamperTaskHandle = osThreadCreate(osThread(tamperTask), NULL);

	/* definition and creation of initTask */
	osThreadDef(initTask, StartInitTask, osPriorityRealtime, 0, 128);
	initTaskHandle = osThreadCreate(osThread(initTask), NULL);

	/* definition and creation of heartbeatTask */
	osThreadDef(heartbeatTask, StartHeartbeatTask, osPriorityIdle, 0, 128);
	heartbeatTaskHandle = osThreadCreate(osThread(heartbeatTask), NULL);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartCanTask */
/**
 * @brief  Function implementing the canSendTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartCanTask */
void StartCanTask(void const *argument) {
	/* USER CODE BEGIN StartCanTask */
	xTaskNotifyWait(0x00, 0x00, NULL, portMAX_DELAY);
	//infinite loop inside
	sendCANMessageFromQueue();
	/* USER CODE END StartCanTask */
}

/* USER CODE BEGIN Header_StartCanReceiveTask */
/**
 * @brief Function implementing the canReceiveTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartCanReceiveTask */
void StartCanReceiveTask(void const *argument) {
	/* USER CODE BEGIN StartCanReceiveTask */
	xTaskNotifyWait(0x00, 0x00, NULL, portMAX_DELAY);
	//infinite loop inside
	receiveCANMessageFromQueue();
	/* USER CODE END StartCanReceiveTask */
}

/* USER CODE BEGIN Header_StartTamperTask */
/**
 * @brief Function implementing the tamperTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartTamperTask */
void StartTamperTask(void const *argument) {
	/* USER CODE BEGIN StartTamperTask */
	xTaskNotifyWait(0x00, 0x00, NULL, portMAX_DELAY);
	initTamper();
	processTamperEvents();
	/* USER CODE END StartTamperTask */
}

/* USER CODE BEGIN Header_StartInitTask */
/**
 * @brief Function implementing the initTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartInitTask */
void StartInitTask(void const *argument) {
	/* USER CODE BEGIN StartInitTask */
	portDISABLE_INTERRUPTS();

	checkAndDoFactoryResetIfNeeded();

	readConfigOnStartup();

	if (homeConfig.deviceId == 0x0000 || homeConfig.deviceId == 0xFFFF) {
		homeConfig.listenForDeviceIdMode = 1;
	}

	if (initCan(CAN_SEND_QUEUEHandle, CAN_RECEIVE_QUEUEHandle) != HAL_OK) {
		home_error(CAN_INIT_FAILED);
		return;
	}

	xTaskNotify(canSendTaskHandle, 0, eNoAction);	//must be first
	xTaskNotify(canReceiveTaskHandle, 0, eNoAction);

	if (homeConfig.listenForDeviceIdMode == 0) {
		xTaskNotify(heartbeatTaskHandle, 0, eNoAction);
		xTaskNotify(tamperTaskHandle, 0, eNoAction);

		homeConfig.deviceLoaded = 1;
	}

	portENABLE_INTERRUPTS();

	publishConfigForAutoDiscovery();

	vTaskDelete(NULL);
	/* USER CODE END StartInitTask */
}

/* USER CODE BEGIN Header_StartHeartbeatTask */
/**
 * @brief Function implementing the heartbeatTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartHeartbeatTask */
void StartHeartbeatTask(void const *argument) {
	/* USER CODE BEGIN StartHeartbeatTask */
	xTaskNotifyWait(0x00, 0x00, NULL, portMAX_DELAY);

	uint8_t heartbeat = { 0 };
	uint8_t i = 29;
	for (;;) {
		osDelay(1000);
		if (homeConfig.heartbeat != 0) {
			HAL_GPIO_TogglePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin);
		}
		if (i == 29) {
			putCanMessageToQueue(RELAY_CONTROLLER_HEARTBEAT, &heartbeat, 1, CAN_RTR_DATA);
			i = 0;
		}

		i++;
	}
	/* USER CODE END StartHeartbeatTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
