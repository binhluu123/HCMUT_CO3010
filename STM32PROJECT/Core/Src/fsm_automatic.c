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

    // Xử lý countdown NS (one-shot): khi flag lên -> giảm 1, nếu vẫn >0 thì set lại 1s
    if(timer3_flag){
        timer3_flag = 0;           // tiêu thụ flag
        if(timer_num > 0){
            timer_num--;          // giảm 1 giây
            LED_7SEG_1(timer_num); // update ngay
            if(timer_num > 0){
                setTimer3(100);  // nạp lại 1s (100 ticks)
            }
        }
    }

    // Xử lý countdown WE (one-shot)
    if(timer4_flag){
        timer4_flag = 0;
        if(timer_num_WE > 0){
            timer_num_WE--;
            LED_7SEG_2(timer_num_WE);
            if(timer_num_WE > 0){
                setTimer4(100);
            }
        }
    }

    // Phần trạng thái (giữ y nguyên logic của bạn, chỉ đảm bảo setTimer3/4 khi cài mới)
    switch(status_2){
    case INIT:
        led7_off();
        status_2 = NS_RED_WE_GREEN;

        timer_num = 5;          // NS RED 5s
        setTimer3(100);         // reload mỗi 1s (100 ticks)

        timer_num_WE = 3;       // WE GREEN 3s
        setTimer4(100);

        setTimer2(300);         // WE green 3s (state timer)
        break;

    case NS_RED_WE_GREEN:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_RED_WE_YELLOW;

            timer_num_WE = 2;   // WE yellow 2s
            setTimer4(100);

            setTimer2(200);
        }
        break;

    case NS_RED_WE_YELLOW:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_GREEN_WE_RED;

            timer_num = 3;      // NS green 3s
            setTimer3(100);

            timer_num_WE = 5;   // WE red 5s
            setTimer4(100);

            setTimer2(300);
        }
        break;

    case NS_GREEN_WE_RED:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_YELLOW_WE_RED;

            timer_num = 2;      // NS yellow 2s
            setTimer3(100);

            setTimer2(200);
        }
        break;

    case NS_YELLOW_WE_RED:
        if(timer2_flag){
            timer2_flag = 0;
            status_2 = NS_RED_WE_GREEN;

            timer_num = 5;      // NS red 5s
            setTimer3(100);

            timer_num_WE = 3;   // WE green 3s
            setTimer4(100);

            setTimer2(300);
        }
        break;
    default:
        break;
    }
}
