/*
 * command_parser.c
 *
 *  Created on: Dec 2, 2022
 *      Author: ASUS
 */

#include "command_parser.h"


void command_parser_fsm()
{
	switch(command_praser_fsm_case)
	{
		case WAITING_FOR_R:
			if(temp == 'R')
			{
				HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			}
			break;
		case WAITING_FOR_S:
			break;
		case WAITING_FOR_T:
			break;
		case WAITING_FOR_O:
			break;
		case WAITING_FOR_K:
			break;
	}
}


