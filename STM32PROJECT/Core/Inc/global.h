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

void led_off();
void NS_red_WE_green();
void NS_red_WE_yellow();
void NS_green_WE_red();
void NS_yellow_WE_red();
#endif /* INC_GLOBAL_H_ */
