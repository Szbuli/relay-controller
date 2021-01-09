/*
 * relay.c
 *
 *  Created on: 2020.05.13.
 *      Author: Szbuli
 */

#include "relay.h"
#include "can-ids.h"
#include "gpio.h"

#define RELAY_1_Pin GPIO_PIN_1
#define RELAY_1_GPIO_Port GPIOA

void handleRelayEvent(uint16_t typeId, uint8_t state) {
	GPIO_PinState pinState;
	if (state == 0) {
		pinState = GPIO_PIN_RESET;
	} else {
		pinState = GPIO_PIN_SET;
	}

	if (typeId == RELAY_CONTROLLER_SET_RELAY_1) {
		HAL_GPIO_WritePin(RELAY_1_GPIO_Port, RELAY_1_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_2) {
		HAL_GPIO_WritePin(RELAY_2_GPIO_Port, RELAY_2_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_3) {
		HAL_GPIO_WritePin(RELAY_3_GPIO_Port, RELAY_3_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_4) {
		HAL_GPIO_WritePin(RELAY_4_GPIO_Port, RELAY_4_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_5) {
		HAL_GPIO_WritePin(RELAY_5_GPIO_Port, RELAY_5_Pin, pinState);
	}
}
