/*
 * global.h
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "main.h"

#define INIT             1
#define NS_RED_WE_GREEN  2
#define NS_RED_WE_YELLOW 3
#define NS_GREEN_WE_RED  4
#define NS_YELLOW_WE_RED 5

extern int status;
uint8_t segCode[10] = {
	0x3F, // 0: 0111111
	0x06, // 1: 0000110
	0x5B, // 2: 1011011
	0x4F, // 3: 1001111
	0x66, // 4: 1100110
	0x6D, // 5: 1101101
	0x7D, // 6: 1111101
	0x07, // 7: 0000111
	0x7F, // 8: 1111111
	0x6F  // 9: 1101111
};

void led_off();
void NS_red_WE_green();
void NS_red_WE_yellow();
void NS_green_WE_red();
void NS_yellow_WE_red();
#endif /* INC_GLOBAL_H_ */
