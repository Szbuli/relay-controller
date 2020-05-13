/*
 * can_support.h
 *
 *  Created on: 2017. jan. 4.
 *      Author: Szbuli
 */

#ifndef CAN_CAN_SUPPORT_H_
#define CAN_CAN_SUPPORT_H_

#include "can-ids.h"
#include "cmsis_os.h"
#include "stm32f1xx_hal.h"
#include "can.h"

#define MY_CAN hcan

void putCanMessageToQueue(uint32_t stdId, uint8_t *dataArray, uint8_t dataLength, uint8_t RTR);
void putCanMessageToQueueFromInterrupt(uint32_t stdId, uint8_t *dataArray, uint8_t dataLength, uint8_t RTR);
HAL_StatusTypeDef initCan(osMessageQId canQueueHandleArgument, osMessageQId CAN_RECEIVE_QUEUEHandleArgument);
void sendCANMessageFromQueue();
void receiveCANMessageFromQueue();

typedef struct {
	uint8_t *data;
	uint32_t topicId;
	uint8_t DLC;
	uint8_t RTR;
} CAN_OBJECT;

typedef struct {
	uint8_t data0;
	uint8_t data1;
	uint8_t data2;
	uint8_t data3;
	uint8_t data4;
	uint8_t data5;
	uint8_t data6;
	uint8_t data7;
	uint32_t id;
	uint8_t DLC;
	uint8_t RTR;
} RECEIVED_CAN_OBJECT;

#endif /* CAN_CAN_SUPPORT_H_ */
