/*
 * global.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "global.h"
int status = 0;
void led_off(){
	HAL_GPIO_WritePin(GPIOA,
	        LED_RED_N_Pin|LED_YELLOW_N_Pin|LED_GREEN_N_Pin|
	        LED_RED_S_Pin|LED_YELLOW_S_Pin|LED_GREEN_S_Pin|
	        LED_RED_W_Pin|LED_YELLOW_W_Pin|LED_GREEN_W_Pin|
	        LED_RED_E_Pin|LED_YELLOW_E_Pin|LED_GREEN_E_Pin,
	        GPIO_PIN_SET);
}
// NS xanh, WE đỏ
void NS_green_WE_red(){
    HAL_GPIO_WritePin(GPIOA,
        LED_GREEN_N_Pin | LED_GREEN_S_Pin |
        LED_RED_W_Pin   | LED_RED_E_Pin,
        GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,
        LED_YELLOW_N_Pin | LED_YELLOW_S_Pin |
        LED_YELLOW_W_Pin | LED_YELLOW_E_Pin |
        LED_RED_N_Pin    | LED_RED_S_Pin    |
        LED_GREEN_W_Pin  | LED_GREEN_E_Pin,
        GPIO_PIN_SET);
}

// NS vàng, WE đỏ
void NS_yellow_WE_red(){
    HAL_GPIO_WritePin(GPIOA,
        LED_YELLOW_N_Pin | LED_YELLOW_S_Pin |
        LED_RED_W_Pin    | LED_RED_E_Pin,
        GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,
        LED_GREEN_N_Pin  | LED_GREEN_S_Pin  |
        LED_GREEN_W_Pin  | LED_GREEN_E_Pin  |
        LED_RED_N_Pin    | LED_RED_S_Pin    |
        LED_YELLOW_W_Pin | LED_YELLOW_E_Pin,
        GPIO_PIN_SET);
}

// NS đỏ, WE xanh
void NS_red_WE_green(){
    HAL_GPIO_WritePin(GPIOA,
        LED_RED_N_Pin   | LED_RED_S_Pin   |
        LED_GREEN_W_Pin | LED_GREEN_E_Pin,
        GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,
        LED_GREEN_N_Pin  | LED_GREEN_S_Pin  |
        LED_YELLOW_N_Pin | LED_YELLOW_S_Pin |
        LED_YELLOW_W_Pin | LED_YELLOW_E_Pin |
        LED_RED_W_Pin    | LED_RED_E_Pin,
        GPIO_PIN_SET);
}

// NS đỏ, WE vàng
void NS_red_WE_yellow(){
    HAL_GPIO_WritePin(GPIOA,
        LED_RED_N_Pin     | LED_RED_S_Pin   |
        LED_YELLOW_W_Pin  | LED_YELLOW_E_Pin,
        GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOA,
        LED_GREEN_N_Pin   | LED_GREEN_S_Pin  |
        LED_YELLOW_N_Pin  | LED_YELLOW_S_Pin |
        LED_GREEN_W_Pin   | LED_GREEN_E_Pin  |
        LED_RED_W_Pin     | LED_RED_E_Pin,
        GPIO_PIN_SET);
}
uint8_t segCode[10]={
		0xC0, // 0
		0xF9, // 1
		0xA4, // 2
		0xB0, // 3
		0x99, // 4
		0x92, // 5
		0x82, // 6
		0xF8, // 7
		0x80, // 8
		0x90  // 9
};

void LED_7SEG(int num){
	if(num > 9) return;
	uint8_t code = segCode[num];

	HAL_GPIO_WritePin(LED7_1_a_GPIO_Port, LED7_1_a_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_b_GPIO_Port, LED7_1_b_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_c_GPIO_Port, LED7_1_c_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_d_GPIO_Port, LED7_1_d_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_e_GPIO_Port, LED7_1_e_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_f_GPIO_Port, LED7_1_f_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_g_GPIO_Port, LED7_1_g_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);

}
void display7SEG(){
	static uint8_t i = 0;
	LED_7SEG(i);
    i++;
	if (i >= 10) i = 0;
}
