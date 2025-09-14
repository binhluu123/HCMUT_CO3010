/*
 * software_timer.c
 */
#include "software_timer.h"

volatile int timer1_counter = 0;
volatile int timer1_flag = 0;

volatile int timer2_counter = 0;
volatile int timer2_flag = 0;

volatile int timer3_counter = 0;
volatile int timer3_flag = 0;

volatile int timer4_counter = 0;
volatile int timer4_flag = 0;

/* Các biến countdown hiển thị (của bạn) */
volatile int timer_num = 0;       // cho NS
volatile int timer_num_WE = 0;    // cho WE

void setTimer1(int duration){      // duration: ticks (1 tick = 10ms)
    timer1_counter = duration;
    timer1_flag = 0;
}

void setTimer2(int duration){
    timer2_counter = duration;
    timer2_flag = 0;
}

void setTimer3(int duration){
    timer3_counter = duration;
    timer3_flag = 0;
}

void setTimer4(int duration){
    timer4_counter = duration;
    timer4_flag = 0;
}

/* timerRun: gọi từ TIM ISR, giảm counter; KHÔNG tự reload
   Khi counter xuống 0 -> chỉ set flag, không nạp lại.
*/
void timerRun(void){
    if(timer1_counter > 0){
        timer1_counter--;
        if(timer1_counter == 0) timer1_flag = 1;
    }
    if(timer2_counter > 0){
        timer2_counter--;
        if(timer2_counter == 0) timer2_flag = 1;
    }
    if(timer3_counter > 0){
        timer3_counter--;
        if(timer3_counter == 0) timer3_flag = 1;
    }
    if(timer4_counter > 0){
        timer4_counter--;
        if(timer4_counter == 0) timer4_flag = 1;
    }
}
