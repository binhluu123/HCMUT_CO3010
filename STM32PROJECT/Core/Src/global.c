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
