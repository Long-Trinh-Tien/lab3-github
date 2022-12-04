/*
 * global.h
 *
 *  Created on: Dec 4, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "command_parser.h"
#include "stdint.h"
#include "main.h"
#include "timerRun.h"
#define MAX_BUFFER_SIZE 30

//command fsm case
#define WAITING_FOR_R	1
#define WAITING_FOR_S	2
#define WAITING_FOR_T	3

#define WAITING_FOR_O	4
#define WAITING_FOR_K	5


extern int command_praser_fsm_case;
extern int buffer_flag ;
extern uint8_t temp ;
#endif /* INC_GLOBAL_H_ */
