/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: tirua
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include  "button.h"
#include  "software_timer.h"
#include  "main.h"

#define INIT 			0
#define AUTO_RESET		1
#define AUTO_INC		2
#define AUTO_DEC		3
#define SUB_COUNT		4

extern int status    ;
extern int count_num ;

#endif /* INC_GLOBAL_H_ */
