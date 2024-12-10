/*
 * can_utils.h
 *
 *  Created on: Dec 10, 2024
 *      Author: motii
 */

#ifndef INC_CAN_UTILS_H_
#define INC_CAN_UTILS_H_

#include <stdint.h>
#include "main.h"

void CAN_TX(uint32_t id, uint8_t *txBuf)
{
	CAN_TxHeaderTypeDef TxHeader;
	TxHeader.StdId = id;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.DLC = 8;
	TxHeader.TransmitGlobalTime = DISABLE;
	uint32_t TxMailBox;
}


#endif /* INC_CAN_UTILS_H_ */
