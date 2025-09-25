/*
 * global.h
 *
 *  Created on: Sep 12, 2025
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "main.h"

//Định nghĩa trạng thái
#define INIT             1
#define NS_RED_WE_GREEN  2
#define NS_RED_WE_YELLOW 3
#define NS_GREEN_WE_RED  4
#define NS_YELLOW_WE_RED 5

//Định nghĩa mask để dùng
#define LED_NS_GREEN   (LED_GREEN_N_Pin | LED_GREEN_S_Pin)
#define LED_NS_YELLOW  (LED_YELLOW_N_Pin | LED_YELLOW_S_Pin)
#define LED_NS_RED     (LED_RED_N_Pin   | LED_RED_S_Pin)

#define LED_WE_GREEN   (LED_GREEN_W_Pin | LED_GREEN_E_Pin)
#define LED_WE_YELLOW  (LED_YELLOW_W_Pin | LED_YELLOW_E_Pin)
#define LED_WE_RED     (LED_RED_W_Pin   | LED_RED_E_Pin)

#define LED_ALL (LED_NS_GREEN | LED_NS_YELLOW | LED_NS_RED | \
                 LED_WE_GREEN | LED_WE_YELLOW | LED_WE_RED)
// LED7 SEG 1
#define LED7_1_ALL   (LED7_1_a_Pin | LED7_1_b_Pin | LED7_1_c_Pin | \
                      LED7_1_d_Pin | LED7_1_e_Pin | LED7_1_f_Pin | LED7_1_g_Pin)

// LED7 SEG 2
#define LED7_2_ALL   (LED7_2_a_Pin | LED7_2_b_Pin | LED7_2_c_Pin | \
                      LED7_2_d_Pin | LED7_2_e_Pin | LED7_2_f_Pin | LED7_2_g_Pin)


extern int status_1;

void led_off();
void NS_red_WE_green();
void NS_red_WE_yellow();
void NS_green_WE_red();
void NS_yellow_WE_red();

#endif /* INC_GLOBAL_H_ */
