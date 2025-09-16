/*
 * fsm_automatic.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status_1){
	case INIT:
		//TODO
		led_off();
		status_1 = NS_RED_WE_GREEN;
		setTimer1(300);
		break;
	case NS_RED_WE_GREEN:
		NS_red_WE_green();
		if(timer1_flag == 1){
			status_1 = NS_RED_WE_YELLOW;
			setTimer1(200);
		}
		break;
	case NS_RED_WE_YELLOW:
		NS_red_WE_yellow();
		if(timer1_flag == 1){
			status_1 = NS_GREEN_WE_RED;
			setTimer1(300);
		}
		break;
	case NS_GREEN_WE_RED:
		NS_green_WE_red();
		if(timer1_flag == 1){
			status_1 = NS_YELLOW_WE_RED;
			setTimer1(200);
		}
		break;
	case NS_YELLOW_WE_RED:
	    NS_yellow_WE_red();
	    if(timer1_flag == 1){
		    status_1 = NS_RED_WE_GREEN;
			setTimer1(300);
		}
		break;
	default:
		break;
	}
}
void fsm_led7_run(void){
    // Luôn refresh LED (gọi liên tục để hiển thị)
    LED_7SEG_1(timer_num);
    LED_7SEG_2(timer_num_WE);
    // Phụ trách đếm số
    display7SEG_1();
    display7SEG_2();

    switch(status_2){
    case INIT:
        led7_off();
        status_2 = NS_RED_WE_GREEN;

        //Phục vụ việc hiển thị số của led7_NS mỗi số cách nhau mỗi giây
        timer_num = 5;          // NS RED 5s
        setTimer3(100);

        //Phục vụ việc hiển thị số của led7_WE mỗi số cách nhau mỗi giây
        timer_num_WE = 3;       // WE GREEN 3s
        setTimer4(100);

        //Phục vụ kiểm soát thời gian chính để điều khiển led7 theo status
        setTimer2(300);         // WE green 3s
        break;

    case NS_RED_WE_GREEN:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_RED_WE_YELLOW;

            //Phục vụ việc hiển thị số của led7_WE mỗi số cách nhau mỗi giây
            timer_num_WE = 2;   // WE yellow 2s
            setTimer4(100);

            //Phục vụ kiểm soát thời gian chính để điều khiển led7 theo status
            setTimer2(200);
        }
        break;

    case NS_RED_WE_YELLOW:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_GREEN_WE_RED;

            //Phục vụ việc hiển thị số của led7_NS mỗi số cách nhau mỗi giây
            timer_num = 3;      // NS green 3s
            setTimer3(100);

            //Phục vụ việc hiển thị số của led7_WE mỗi số cách nhau mỗi giây
            timer_num_WE = 5;   // WE red 5s
            setTimer4(100);
            //Phục vụ kiểm soát thời gian chính để điều khiển led7 theo status
            setTimer2(300);
        }
        break;

    case NS_GREEN_WE_RED:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_YELLOW_WE_RED;

            //Phục vụ việc hiển thị số của led7_NS mỗi số cách nhau mỗi giây
            timer_num = 2;      // NS yellow 2s
            setTimer3(100);

            //Phục vụ kiểm soát thời gian chính để điều khiển led7 theo status
            setTimer2(200);
        }
        break;

    case NS_YELLOW_WE_RED:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_RED_WE_GREEN;

            //Phục vụ việc hiển thị số của led7_NS mỗi số cách nhau mỗi giây
            timer_num = 5;      // NS red 5s
            setTimer3(100);

            //Phục vụ việc hiển thị số của led7_WE mỗi số cách nhau mỗi giây
            timer_num_WE = 3;   // WE green 3s
            setTimer4(100);

            //Phục vụ kiểm soát thời gian chính để điều khiển led7 theo status
            setTimer2(300);
        }
        break;
    default:
        break;
    }
}
