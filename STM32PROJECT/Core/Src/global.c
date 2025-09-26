/*
 * global.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "global.h"
int status_1 = 0;
int status_2 = 0;
void led_blinky(){
	if(timer5_flag){
		HAL_GPIO_TogglePin(LED_BLINKY_GPIO_Port, LED_BLINKY_Pin);
		setTimer5(100);
	}
}
void led_off(){
	GPIOA->BSRR = LED_ALL;
}
void led7_off(){
	GPIOA->BSRR = LED7_1_ALL;
	GPIOA->BSRR = LED7_2_ALL;
}
// NS xanh, WE đỏ
void NS_green_WE_red(){
    GPIOA->BRR  = LED_NS_GREEN | LED_WE_RED;
    GPIOA->BSRR = LED_NS_YELLOW | LED_NS_RED |
                  LED_WE_GREEN | LED_WE_YELLOW;
}

// NS vàng, WE đỏ
void NS_yellow_WE_red(){
    GPIOA->BRR  = LED_NS_YELLOW | LED_WE_RED;
    GPIOA->BSRR = LED_NS_GREEN | LED_NS_RED |
                  LED_WE_GREEN | LED_WE_YELLOW;
}


// NS đỏ, WE xanh
void NS_red_WE_green(){
    GPIOA->BRR  = LED_NS_RED | LED_WE_GREEN;
    GPIOA->BSRR = LED_NS_GREEN | LED_NS_YELLOW |
                  LED_WE_YELLOW | LED_WE_RED;
}


// NS đỏ, WE vàng
void NS_red_WE_yellow(){
    GPIOA->BRR  = LED_NS_RED | LED_WE_YELLOW;
    GPIOA->BSRR = LED_NS_GREEN | LED_NS_YELLOW |
                  LED_WE_GREEN | LED_WE_RED;
}

//Mảng số từ 1-9 đã mã hóa từ nhị phân sang hex
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

//Hàm nhảy số tuần tự của led 7 đoạn
void display7SEG_1(void){
    if(timer3_flag){
        timer3_flag = 0;
        if(timer_num > 0){
            LED_7SEG_1(timer_num);
            timer_num--;
            if(timer_num > 0){
                setTimer3(100);
            }
        }
    }
}

void display7SEG_2(void){
    if(timer4_flag){
        timer4_flag = 0;
        if(timer_num_WE > 0){
            LED_7SEG_2(timer_num_WE);
            timer_num_WE--;
            if(timer_num_WE > 0){
                setTimer4(100);
            }
        }
    }
}

