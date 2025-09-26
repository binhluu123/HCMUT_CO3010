/*
 * clock.h
 *
 *  Created on: Sep 14, 2025
 *      Author: ADMIN
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_
#define LED_ALL (LED_1_Pin|LED_2_Pin|LED_3_Pin|LED_4_Pin| \
                 LED_5_Pin|LED_6_Pin|LED_7_Pin|LED_8_Pin| \
                 LED_9_Pin|LED_10_Pin|LED_11_Pin|LED_12_Pin)
#include "software_timer.h"

extern int hour;
extern int minute;
extern int second;
extern int status_0 ;
extern int status_1 ;
extern int status_2 ;
int ledMask[12];
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
void test_clock();
void clearAllClock();
void clock();
void led_blinky();
#endif /* INC_CLOCK_H_ */
