/*
 * relay.h
 *
 *  Created on: 2020.05.13.
 *      Author: Szbuli
 */

#ifndef RELAY_RELAY_H_
#define RELAY_RELAY_H_

#include "cmsis_os.h"

void handleRelayEvent(uint16_t typeId, uint8_t state);

#endif /* RELAY_RELAY_H_ */
