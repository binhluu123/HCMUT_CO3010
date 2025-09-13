/*
 * global.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "global.h"
int status_1 = 0;
int status_2 = 0;
void led_off(){
	HAL_GPIO_WritePin(GPIOA,
	        LED_RED_N_Pin|LED_YELLOW_N_Pin|LED_GREEN_N_Pin|
	        LED_RED_S_Pin|LED_YELLOW_S_Pin|LED_GREEN_S_Pin|
	        LED_RED_W_Pin|LED_YELLOW_W_Pin|LED_GREEN_W_Pin|
	        LED_RED_E_Pin|LED_YELLOW_E_Pin|LED_GREEN_E_Pin,
	        GPIO_PIN_SET);
}
void led7_off(){
	// LED 7 đoạn 1
	    HAL_GPIO_WritePin(LED7_1_a_GPIO_Port, LED7_1_a_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_1_b_GPIO_Port, LED7_1_b_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_1_c_GPIO_Port, LED7_1_c_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_1_d_GPIO_Port, LED7_1_d_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_1_e_GPIO_Port, LED7_1_e_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_1_f_GPIO_Port, LED7_1_f_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_1_g_GPIO_Port, LED7_1_g_Pin, GPIO_PIN_SET);

	    // LED 7 đoạn 2
	    HAL_GPIO_WritePin(LED7_2_a_GPIO_Port, LED7_2_a_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_2_b_GPIO_Port, LED7_2_b_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_2_c_GPIO_Port, LED7_2_c_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_2_d_GPIO_Port, LED7_2_d_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_2_e_GPIO_Port, LED7_2_e_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_2_f_GPIO_Port, LED7_2_f_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED7_2_g_GPIO_Port, LED7_2_g_Pin, GPIO_PIN_SET);
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
uint8_t segCode_1[10]={
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
uint8_t segCode_2[10]={
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

void LED_7SEG_1(int num){
	if(num > 9) return;
	uint8_t code = segCode_1[num];

	HAL_GPIO_WritePin(LED7_1_a_GPIO_Port, LED7_1_a_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_b_GPIO_Port, LED7_1_b_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_c_GPIO_Port, LED7_1_c_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_d_GPIO_Port, LED7_1_d_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_e_GPIO_Port, LED7_1_e_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_f_GPIO_Port, LED7_1_f_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_1_g_GPIO_Port, LED7_1_g_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);

}
void LED_7SEG_2(int num){
	if(num > 9) return;
	uint8_t code = segCode_2[num];

	HAL_GPIO_WritePin(LED7_2_a_GPIO_Port, LED7_2_a_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_2_b_GPIO_Port, LED7_2_b_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_2_c_GPIO_Port, LED7_2_c_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_2_d_GPIO_Port, LED7_2_d_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_2_e_GPIO_Port, LED7_2_e_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_2_f_GPIO_Port, LED7_2_f_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_2_g_GPIO_Port, LED7_2_g_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);

}
/* gọi LED_7SEG_1(num) và LED_7SEG_2(num) để thực sự hiển thị */
void display7SEG_1(void){
    if(timer3_flag){
        timer3_flag = 0;           // tiêu thụ flag
        if(timer_num > 0){
            timer_num--;          // giảm 1 giây
            LED_7SEG_1(timer_num);
            if(timer_num > 0){
                setTimer3(100);  // 100 ticks = 1s (với tick=10ms)
            }
        }
    }
}

void display7SEG_2(void){
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
}

