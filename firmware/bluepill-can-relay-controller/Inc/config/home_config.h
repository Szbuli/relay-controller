/*
 * home_config.h
 *
 *  Created on: 2017. m�j. 23.
 *      Author: Szbuli
 */

#ifndef CONFIG_HOME_CONFIG_H_
#define CONFIG_HOME_CONFIG_H_

#include "cmsis_os.h"

#define ADDRESS_DEVICE_ID_PART_0 0
#define ADDRESS_DEVICE_ID_PART_1 1
#define ADDRESS_TAMPER 30

#define STM32_UUID_32 ((uint32_t *)0x1FFF7A10)
#define STM32_UUID_16 ((uint16_t *)0x1FFF7A10)

typedef struct {
	uint8_t listenForDeviceIdMode;
	uint8_t deviceLoaded;
	uint16_t deviceId;
	uint8_t tamper;
} HomeConfig;

typedef struct {
	uint16_t location;
	uint8_t data;
} ConfigEepromPair;

extern HomeConfig homeConfig;

void checkAndDoFactoryResetIfNeeded();
void readConfigOnStartup();
void factoryReset();
void configureTamper(uint8_t state);

#endif /* CONFIG_HOME_CONFIG_H_ */
