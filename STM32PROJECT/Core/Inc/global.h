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

#define INIT        1
#define AUTO_RED    2
#define AUTO_YELLOW 3
#define AUTO_GREEN  4

extern int status;

void led_blinky();
void led_off();
void led_red_on();
void led_yellow_on();
void led_green_on();
#endif /* INC_GLOBAL_H_ */
