/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: tirua
 */


#include "software_timer.h"

int timer1_flag = 0;
int timer2_flag = 0;



int timer1_counter = 0;
int timer2_counter = 0;


// SET TIMER 1
void setTimer_1(int duration){
	timer1_counter = duration;
	timer1_flag  = 0;
}
void timerRun(){
	// Timer 1
	if(timer1_counter>0){
		timer1_counter --;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
	// Timer 2
	if(timer2_counter>0){
			timer2_counter --;
			if(timer2_counter<= 0){
				timer2_flag = 1;
			}
		}

}
// SET TIMER 2
void setTimer_2(int duration){
	timer2_counter = duration;
	timer2_flag  = 0;
}



void clearTimer(){
	}
