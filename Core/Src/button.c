/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: tirua
 */
#include "button.h"


int button1_fag = 0 ;
int button2_fag = 0 ;
int button3_fag = 0 ;

int KeyReg0[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[4] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int LongPressed_fag = 0 ;
int LongPressed1_fag= 0;

int TimerForKeyPress_1 = 300;
int TimerForKeyPress_2 = 300;
int TimerForKeyPress_3 = 300;

void subKeyProcess_RESET(){
	//TODO
	button1_fag = 1;
}
void subKeyProcess_INC(){
	//TODO
	button2_fag = 1;
}
void subKeyProcess_DEC(){
	//TODO
	button3_fag = 1;
}
void getKeyInput(){
	// Nut RESET
	KeyReg0[0]=KeyReg0[1];
	KeyReg0[1]=KeyReg0[2];
	KeyReg0[2]= HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
		if(KeyReg0[0] == KeyReg0[1] && KeyReg0[1] == KeyReg0[2]){
			if(KeyReg0[3]!= KeyReg0[2]){
				KeyReg0[3]=KeyReg0[2];

				if(KeyReg0[2]== PRESSED_STATE){
					subKeyProcess_RESET();
					TimerForKeyPress_1 = 300;
				}
			}
			else {
				TimerForKeyPress_1--;
				if(TimerForKeyPress_1 <= 0){
					KeyReg0[3] = NORMAL_STATE;
				}
			}
		}
	// Nut INC
	KeyReg1[0]=KeyReg1[1];
	KeyReg1[1]=KeyReg1[2];
	KeyReg1[2]= HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);

	if(KeyReg1[0] == KeyReg1[1] && KeyReg1[1] == KeyReg1[2]){
		if(KeyReg1[3]!= KeyReg1[2]){
			KeyReg1[3]=KeyReg1[2];
				if(KeyReg1[2]== PRESSED_STATE){
					subKeyProcess_INC();
						if(LongPressed_fag == 1){
							TimerForKeyPress_2 = 100;
						}else {
							TimerForKeyPress_2 = 300;
						}
				}else {
					// Dat co lai so khi nhan giu ba lan 3s
					LongPressed_fag = 0;
					TimerForKeyPress_2 = 300;
				}
			}
		else {
				TimerForKeyPress_2--;
				if(TimerForKeyPress_2<=0){
				KeyReg1[3] = NORMAL_STATE;
				LongPressed_fag = 1;
				}
			}
		}
	// Nut DEC
	KeyReg2[0]=KeyReg2[1];
	KeyReg2[1]=KeyReg2[2];
	KeyReg2[2]= HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);

		if(KeyReg2[0] == KeyReg2[1] && KeyReg2[1] == KeyReg2[2]){

			if(KeyReg2[3]!= KeyReg2[2]){
				KeyReg2[3]=KeyReg2[2];
				if(KeyReg2[2]== PRESSED_STATE){

					subKeyProcess_DEC();

						if (LongPressed1_fag == 1){
							TimerForKeyPress_3 = 100;
						}
						else{
							TimerForKeyPress_3 = 300;
						}
				}else{
					LongPressed1_fag = 0;
					TimerForKeyPress_3 = 300;
				}
			}
			else {
				TimerForKeyPress_3 --;
				if(TimerForKeyPress_3 <= 0){
					KeyReg2[3] = NORMAL_STATE;
					LongPressed1_fag = 1;
					}
			}
		}
}
int isButton_RESET(){
	if(button1_fag ==1){
		button1_fag =0;
		return 1;
	}
	return 0;
};
int isButton_INC(){
	if(button2_fag == 1){
		button2_fag =0;
		return 1;
	}
	return 0;
}
int isButton_DEC(){
	if(button3_fag == 1){
		button3_fag = 0;
		return 1;
	}
	return 0;
}
