#ifndef PROCESS_ERRORS_H_
#define PROCESS_ERRORS_H_

#include "usart.h"

#define NO_ERRORS 0
#define CAN_INIT_FAILED 5
#define CAN_TX_QUEUE_CANNOT_BE_CREATED 13
#define CAN_RX_QUEUE_CANNOT_BE_CREATED 14
#define CAN_TX_QUEUE_FULL 16
#define CAN_RX_QUEUE_FULL 17
#define CAN_FAILED_RX 21

extern uint8_t home_debug_mode;

void home_warning(char message[]);
void home_error(uint16_t errorCode);
void home_log(char message[], uint8_t addEndLine);
void home_log_int(uint32_t message, uint8_t addEndLine);
void home_log_byte_hex(uint8_t message, uint8_t addEndLine);

void writeOut(char * str);
void writeOutInt(uint32_t message);
void writeOutByteInHex(uint8_t hex);

void sendChar(char ch);

void prntnum(uint32_t num, int base, char *outbuf, uint8_t size);

#endif
