/*
 * fsm_automatic.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TODO
		led_off();
		status = AUTO_RED;
		setTimer1(500);
		break;
	case AUTO_RED:
		led_red_on();
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(300);
		}
		break;
	case AUTO_GREEN:
		led_green_on();
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		led_yellow_on();
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(500);
		}
		break;
	default:
		break;
	}
}

