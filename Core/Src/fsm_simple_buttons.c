/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: tirua
 */

#include "fsm_simple_buttons.h"
#include "global.h"
#include "display7SEG.h"
#include "button.h"

void fsm_simple_buttons_run(){
	switch(status){
		case INIT:
			//TODO
			// Khi count_num SEG to ve 0
			if(count_num >9){
				count_num = 0;
			}
			if (count_num < 0){
				count_num = 9;
			};
			// Dat so cho LED 7 doan
			display7SEG(count_num);
			// Kiem tra dieu kien co phai RESET
			if(isButton_RESET() == 1){
				status = AUTO_RESET;
				setTimer_2(1000);
			}
			// Kiem tra dieu kien co phai INC
			if (isButton_INC() == 1){
							status = AUTO_INC;
							setTimer_2(1000);
						}
			// Kiem tra dieu kien co phai DEC

			if (isButton_DEC() == 1){
				status = AUTO_DEC;
				setTimer_2(1000);
			}
			// Truyen tin hieu cho LED_RED
			if (timer1_flag == 1){
				setTimer_1(100);
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			}
			// Khong bam
			if (isButton_DEC()== 0 && isButton_INC()== 0 && isButton_RESET() ==0){
				if (timer2_flag == 1){
					setTimer_2(500);;
					if(count_num == 0){
						status = INIT;
					}else {
						status = SUB_COUNT;
					}
				}
			}
			else {
				setTimer_2(1000);
			}
			break;
		case AUTO_RESET:
			//TODO
			count_num = 0;
			status = INIT;
			break;
		case AUTO_INC:
			//TODO
			count_num =count_num+1;
			status = INIT;
			break;
		case AUTO_DEC:
			//TODO
			count_num =count_num-1;
			status = INIT;
			break;
		case SUB_COUNT:
			count_num =count_num-1;
			status = INIT;
			break;
		default:
			break;
	}
}
