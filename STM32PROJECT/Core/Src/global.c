/*
 * global.c
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */
#include "global.h"
int status_1 = 0;
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

