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
		status = NS_RED_WE_GREEN;
		setTimer1(300);
		break;
	case NS_RED_WE_GREEN:
		NS_red_WE_green();
		if(timer1_flag == 1){
			status = NS_RED_WE_YELLOW;
			setTimer1(200);
		}
		break;
	case NS_RED_WE_YELLOW:
		NS_red_WE_yellow();
		if(timer1_flag == 1){
			status = NS_GREEN_WE_RED;
			setTimer1(300);
		}
		break;
	case NS_GREEN_WE_RED:
		NS_green_WE_red();
		if(timer1_flag == 1){
			status = NS_YELLOW_WE_RED;
			setTimer1(200);
		}
		break;
	case NS_YELLOW_WE_RED:
	    NS_yellow_WE_red();
	    if(timer1_flag == 1){
		    status = NS_RED_WE_GREEN;
			setTimer1(300);
		}
		break;
	default:
		break;
	}
}

