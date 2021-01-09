/*
 * tamper.c
 *
 *  Created on: 2020.05.13.
 *      Author: Szbuli
 */

#include "gpio.h"
#include "can_support.h"
#include "tamper.h"
#include "home_config.h"

TaskHandle_t switchTask = NULL;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (homeConfig.deviceLoaded != 1 || homeConfig.tamper == 0) { // TODO might be better to disable interrupt
		return;
	}

	if (GPIO_Pin == TAMPER_Pin) {
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
		vTaskNotifyGiveFromISR(switchTask, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
}

HAL_StatusTypeDef initTamper() {

	switchTask = xTaskGetCurrentTaskHandle();

	return HAL_OK;
}

void processTamperEvents() {
	for (;;) {
		ulTaskNotifyTake( pdTRUE, portMAX_DELAY);
		osDelay(debounceTimeMs);

		GPIO_PinState tamper_state = HAL_GPIO_ReadPin(TAMPER_GPIO_Port, TAMPER_Pin);

		if (tamper_state == GPIO_PIN_RESET) {
			putCanMessageToQueue(RELAY_CONTROLLER_TAMPER, NULL, 0, CAN_RTR_REMOTE);
		}

	}
}
