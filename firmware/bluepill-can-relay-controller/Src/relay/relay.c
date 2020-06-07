/*
 * relay.c
 *
 *  Created on: 2020. máj. 13.
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
		pinState = GPIO_PIN_SET;
	} else {
		pinState = GPIO_PIN_RESET;
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
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_6) {
		HAL_GPIO_WritePin(RELAY_6_GPIO_Port, RELAY_6_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_7) {
		HAL_GPIO_WritePin(RELAY_7_GPIO_Port, RELAY_7_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_8) {
		HAL_GPIO_WritePin(RELAY_8_GPIO_Port, RELAY_8_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_9) {
		HAL_GPIO_WritePin(RELAY_9_GPIO_Port, RELAY_9_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_10) {
		HAL_GPIO_WritePin(RELAY_10_GPIO_Port, RELAY_10_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_11) {
		HAL_GPIO_WritePin(RELAY_11_GPIO_Port, RELAY_11_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_12) {
		HAL_GPIO_WritePin(RELAY_12_GPIO_Port, RELAY_12_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_13) {
		HAL_GPIO_WritePin(RELAY_13_GPIO_Port, RELAY_13_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_14) {
		HAL_GPIO_WritePin(RELAY_14_GPIO_Port, RELAY_14_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_15) {
		HAL_GPIO_WritePin(RELAY_15_GPIO_Port, RELAY_15_Pin, pinState);
	} else if (typeId == RELAY_CONTROLLER_SET_RELAY_16) {
		HAL_GPIO_WritePin(RELAY_16_GPIO_Port, RELAY_16_Pin, pinState);
	}
}
