/*
 * fsm_7seg_led.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */

#include "fsm_7seg_led.h"
#include "led7.h"
#define LED_7SEG_BLINK_PERIOD	1000//1Hz for 4 led
//vertical is main road, we works on main road
int bufferFor7SEG[4]={0,0,0,0};//mode1-2 then set value 1-2
int bufferForTrafficLight[3]={5,2,3};//start with 5s Red

void OffAllLed()
{
	HAL_GPIO_WritePin(MODE_LED_GPIO_Port, MODE_LED_Pin, 0);
	HAL_GPIO_WritePin(MODE_LED_2_GPIO_Port, MODE_LED_2_Pin, 0);
	HAL_GPIO_WritePin(SET_VALUE_LED_GPIO_Port, SET_VALUE_LED_Pin, 0);
	HAL_GPIO_WritePin(SET_VALUE_LED_2_GPIO_Port, SET_VALUE_LED_2_Pin, 0);
}

void modeLedRun()
{
	display7SEG(bufferFor7SEG[0]);
	HAL_GPIO_WritePin(MODE_LED_GPIO_Port, MODE_LED_Pin, 1);
}

void modeLed2Run()
{
	display7SEG(bufferFor7SEG[1]);
	HAL_GPIO_WritePin(MODE_LED_2_GPIO_Port, MODE_LED_2_Pin, 1);
}

void setValueLedRun()
{
	display7SEG(bufferFor7SEG[2]);
	HAL_GPIO_WritePin(SET_VALUE_LED_GPIO_Port, SET_VALUE_LED_Pin, 1);
}

void setValue2LedRun()
{
	display7SEG(bufferFor7SEG[3]);
	HAL_GPIO_WritePin(SET_VALUE_LED_2_GPIO_Port, SET_VALUE_LED_2_Pin, 1);
}

void fsm_7seg_led ()
  {
		switch (led7SEGindex)
		{
		case MODE_LED:
			if(isTimerDone(1))
			{
				setTimer(LED_7SEG_BLINK_PERIOD/4,1);
				led7SEGindex=MODE_LED_2;
				OffAllLed();
			}
			modeLedRun();

			break;
		case MODE_LED_2:
			if(isTimerDone(1))
			{
				setTimer(LED_7SEG_BLINK_PERIOD/4,1);
				led7SEGindex=SET_VALUE_LED;
				OffAllLed();
			}
			modeLed2Run();
			break;
		case SET_VALUE_LED:
			if(isTimerDone(1))
			{
				setTimer(LED_7SEG_BLINK_PERIOD/4,1);
				led7SEGindex=SET_VALUE_LED_2;
				OffAllLed();
			}
			setValueLedRun();
			break;
		case SET_VALUE_LED_2:
			if(isTimerDone(1))
			{
				setTimer(LED_7SEG_BLINK_PERIOD/4,1);
				led7SEGindex=MODE_LED;
				OffAllLed();
			}
			setValue2LedRun();

			break;
		default:
			break;
		}
  }

void updateBufferFor7SEG()
{

}









