/*
 * clock.c
 *
 *  Created on: Sep 14, 2025
 *      Author: ADMIN
 */

#include "clock.h"
#include "main.h"


int static_num = 0;

void led_clock(int num){

	//TODO
	    HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, (num == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, (num == 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, (num == 2) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, (num == 3) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, (num == 4) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, (num == 5) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, (num == 6) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, (num == 7) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, (num == 8) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, (num == 9) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, (num == 10) ? GPIO_PIN_RESET : GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, (num == 11) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void test_clock(){
	if(timer1_flag == 1){
		setTimer1(100);
		led_clock(static_num);
		static_num++;
		if(static_num >= 12) static_num = 0;
	}
}
