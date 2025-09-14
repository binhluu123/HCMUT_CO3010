/*
 * software_timer.h
 *
 *  Created on: Sep 11, 2025
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern volatile int timer1_flag;
extern volatile int timer2_flag;
extern volatile int timer3_flag;
extern volatile int timer4_flag;

extern volatile int timer_num;
extern volatile int timer_num_WE;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
int isTimerExpired(int index);
void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
