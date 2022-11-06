/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: tirua
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


#include "main.h"

extern int timer1_flag;
extern int timer2_flag;

extern int timer1_counter;
extern int timer2_counter;


void setTimer_1(int duration);
void setTimer_2(int duration);


void timerRun();

void clearTimer();


#endif /* INC_SOFTWARE_TIMER_H_ */
