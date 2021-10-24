/*
 * ha_auto_discovery.c
 *
 *  Created on: 2021.01.03.
 *      Author: Szbuli
 */

#include "home_config.h"
#include "can_support.h"
#include "can-ids.h"

void sendAutoDiscoveryMessage(uint16_t configTopicId, uint16_t stateTopicId, uint8_t data[]) {
	data[4] = stateTopicId >> 8;
	data[5] = stateTopicId;
	putCanMessageToQueue(configTopicId, data, 8, CAN_RTR_DATA);
}

void sendAutoDiscoveryMessageWithoutAvailability(uint16_t configTopicId, uint16_t stateTopicId, uint8_t data[]) {
  data[4] = stateTopicId >> 8;
  data[5] = stateTopicId;
  putCanMessageToQueue(configTopicId, data, 6, CAN_RTR_DATA);
}

void publishConfigForAutoDiscovery() {
	if (homeConfig.listenForDeviceIdMode == 0) {
		uint8_t data[] = { VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, DEVICE_TYPE_ID_ALARM_CONTROLLER, 0, 0,
		RELAY_CONTROLLER_HEARTBEAT >> 8, RELAY_CONTROLLER_HEARTBEAT };

		sendAutoDiscoveryMessageWithoutAvailability(RELAY_CONTROLLER_HA_STATUS_CONFIG, RELAY_CONTROLLER_HEARTBEAT, data);

		sendAutoDiscoveryMessage(RELAY_CONTROLLER_HA_SENSOR_CONFIG, RELAY_CONTROLLER_SET_RELAY_1, data);
		sendAutoDiscoveryMessage(RELAY_CONTROLLER_HA_SENSOR_CONFIG, RELAY_CONTROLLER_SET_RELAY_2, data);
		sendAutoDiscoveryMessage(RELAY_CONTROLLER_HA_SENSOR_CONFIG, RELAY_CONTROLLER_SET_RELAY_3, data);
		sendAutoDiscoveryMessage(RELAY_CONTROLLER_HA_SENSOR_CONFIG, RELAY_CONTROLLER_SET_RELAY_4, data);
		sendAutoDiscoveryMessage(RELAY_CONTROLLER_HA_SENSOR_CONFIG, RELAY_CONTROLLER_SET_RELAY_5, data);
	}
}
