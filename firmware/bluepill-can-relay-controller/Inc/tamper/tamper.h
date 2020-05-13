/*
 * tamper.h
 *
 *  Created on: 2020. máj. 13.
 *      Author: Szbuli
 */

#ifndef TAMPER_TAMPER_H_
#define TAMPER_TAMPER_H_

#include "cmsis_os.h"

#define debounceTimeMs 50

void processTamperEvents();
HAL_StatusTypeDef initTamper();

#endif /* TAMPER_TAMPER_H_ */
