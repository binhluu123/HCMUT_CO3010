/*
 * clock.c
 *
 *  Created on: Sep 14, 2025
 *      Author: ADMIN
 */

#include "clock.h"
#include "main.h"

int ledMask[12]={
		LED_12_Pin, LED_1_Pin, LED_2_Pin, LED_3_Pin, LED_4_Pin, LED_5_Pin,
		LED_6_Pin,  LED_7_Pin, LED_8_Pin, LED_9_Pin, LED_10_Pin, LED_11_Pin
};
int hour = 0;
int minute = 0;
int second = 0;
void setNumberOnClock(int num){
	//Dựa vào chỉ số của mảng để bật led
	GPIOA->BRR = ledMask[num];
}
void clearAllClock(){
	GPIOA->BSRR = LED_ALL;
}
void clearNumberOnClock(int num){
	//Dựa vào chỉ số của mảng để tắt led
	GPIOA->BSRR = ledMask[num];
}
void test_clock(){
	if(timer1_flag == 1){
		// Set flag = 0 và là khoảng thời gian sáng giữa 2 led
		setTimer1(5);

		// Quy trình test tuần tự led trong đồng hồ
		clearAllClock();
		setNumberOnClock(second);
		second++;
		if(second >= 12) second = 0;
	}
}
void clock(){
	if(timer1_flag == 1){
		setTimer1(5);

        //Chỉ số của 3 kim
		int pos_sec = second / 5;
		int pos_min = minute / 5;
		int pos_hour = hour  % 12;

        //Chỉ số đứng trước của 3 kim
		int prev_sec = (pos_sec + 11) % 12;
		int prev_min = (pos_min + 11) % 12;
		int prev_hour = (pos_hour + 11) % 12;

        //Điều kiện để xóa đi các led đã đi qua
		setNumberOnClock(pos_sec);
		if(prev_sec != pos_min && prev_sec != pos_hour){
		      clearNumberOnClock(prev_sec);
		}

        setNumberOnClock(pos_min);
        if(prev_min != pos_sec && prev_min != pos_hour){
              clearNumberOnClock(prev_min);
        }

        setNumberOnClock(pos_hour);
        if(prev_hour != pos_min && prev_hour != pos_sec){
              clearNumberOnClock(prev_hour);
        }

        //Quy trình chạy led của từng kim
		second++;
		if(second >= 60){
			second = 0;
			minute++;
			if(minute >= 60){
				minute = 0;
				hour++;
				if(hour >= 12) hour = 0;
			}
		}
	}
}
void led_blinky(){
	if(timer2_flag){
		HAL_GPIO_TogglePin(LED_BLINKY_GPIO_Port, LED_BLINKY_Pin);
		setTimer2(25);
	}
}
