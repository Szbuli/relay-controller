/*
 * home_config.c
 *
 *  Created on: 2017. máj. 23.
 *      Author: Szbuli
 */

#include "home_config.h"
#include "can_support.h"
#include "eeprom.h"
#include "can-ids.h"
#include "gpio.h"

HomeConfig homeConfig;

void blinkRapid() {
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_RESET);
	osDelay(50);
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_SET);
	osDelay(50);
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_RESET);
	osDelay(50);
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_SET);
	osDelay(50);
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_RESET);
}

void checkAndDoFactoryResetIfNeeded() {
	GPIO_PinState factoryResetState = HAL_GPIO_ReadPin(FACTORY_RESET_GPIO_Port, FACTORY_RESET_Pin);
	if (factoryResetState == GPIO_PIN_RESET) {
		return;
	}
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_SET);
	osDelay(5000);
	factoryResetState = HAL_GPIO_ReadPin(FACTORY_RESET_GPIO_Port, FACTORY_RESET_Pin);
	if (factoryResetState == GPIO_PIN_RESET) {
		return;
	}
	blinkRapid();
	HAL_GPIO_WritePin(BUSY_LED_GPIO_Port, BUSY_LED_Pin, GPIO_PIN_SET);
	factoryReset();
	blinkRapid();
	HAL_NVIC_SystemReset();
}

void readConfigOnStartup() {
	homeConfig.deviceId = readByteEEPROM(ADDRESS_DEVICE_ID_PART_0) | readByteEEPROM(ADDRESS_DEVICE_ID_PART_1) << 8;
	homeConfig.tamper = readByteEEPROM(ADDRESS_TAMPER);
}

void factoryReset() {
	HAL_StatusTypeDef status = writeByteEEPROM(ADDRESS_DEVICE_ID_PART_0, 0xFF);
	status = writeByteEEPROM(ADDRESS_DEVICE_ID_PART_1, 0xFF);
	status = writeByteEEPROM(ADDRESS_TAMPER, 0);
}

void configureTamper(uint8_t state) {
	HAL_StatusTypeDef status = writeByteEEPROM(ADDRESS_TAMPER, state);

	osDelay(100);
	HAL_NVIC_SystemReset();
}
