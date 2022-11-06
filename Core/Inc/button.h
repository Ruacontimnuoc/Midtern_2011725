/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: tirua
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"
#include "software_timer.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


extern int button1_fag ;
extern int button2_fag ;
extern int button3_fag ;


extern int LongPressed_fag ;
extern int LongPressed1_fag;


extern int TimerForKeyPress_1 ;
extern int TimerForKeyPress_2 ;
extern int TimerForKeyPress_3 ;

int isButton_RESET();
int isButton_INC();
int isButton_DEC();

void getKeyInput();


#endif /* INC_BUTTON_H_ */
