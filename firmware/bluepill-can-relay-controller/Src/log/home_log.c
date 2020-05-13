#include "home_log.h"

#include <stdlib.h>

uint8_t home_debug_mode = 1;

char endChars[] = "\r\n";
char errorStart[] = "error code: ";
char warningStart[] = "warning: ";

void home_warning(char message[]) {
	writeOut(warningStart);
	writeOut(message);
	writeOut(endChars);
}
void home_error(uint16_t errorCode) {
	writeOut(errorStart);
	writeOutInt(errorCode);
	writeOut(endChars);
}

void home_log(char message[], uint8_t addEndLine) {
	writeOut(message);
	if (addEndLine != 0) {
		writeOut(endChars);
	}
}

void home_log_int(uint32_t message, uint8_t addEndLine) {
	writeOutInt(message);

	if (addEndLine != 0) {
		writeOut(endChars);
	}
}
void home_log_byte_hex(uint8_t message, uint8_t addEndLine) {
	writeOutByteInHex(message);
	if (addEndLine != 0) {
		writeOut(endChars);
	}
}

void writeOut(char * str) {
	while (*str != 0) {
		sendChar(*str);
		str++;
	}
}

void sendChar(char ch) {
	HAL_UART_Transmit(&huart1, (uint8_t *) &ch, 1, 100);
}

void writeOutInt(uint32_t message) {
	char buf[10];
	itoa(message, buf, 10);
	writeOut(buf);
}

void writeOutByteInHex(uint8_t hex) {
	char buf[2];
	prntnum(hex, 16, buf, 2);
	writeOut(buf);
}

void prntnum(uint32_t num, int base, char *outbuf, uint8_t size) {

	int i = size;
	int j = 0;

	do {
		outbuf[i] = "0123456789ABCDEF"[num % base];
		i--;
		num = num / base;
	} while (num > 0);

	while (i > 0) {
		outbuf[i] = '0';
		i--;
	}

	while (++i < size + 1) {
		outbuf[j++] = outbuf[i];
	}

	outbuf[j] = 0;

}
