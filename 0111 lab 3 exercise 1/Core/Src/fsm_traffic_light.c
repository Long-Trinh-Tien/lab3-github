/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */


#include "fsm_traffic_light.h"
#include "fsm_7seg_led.h"

static int mainRoadStatus=0;
static int otherRoadStatus=0;
int currentMainRoadTiming=0;
int currentOtherRoadTiming=0;

void offAllTrafficLight()
{
	HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, 0);
	HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, 0);
	HAL_GPIO_WritePin(RED_HOR_GPIO_Port, RED_HOR_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin, 0);
	HAL_GPIO_WritePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin, 0);
}

void offHORLight()
{
	HAL_GPIO_WritePin(RED_HOR_GPIO_Port, RED_HOR_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin, 0);
	HAL_GPIO_WritePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin, 0);
}

void offVERLight()
{
	HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, 0);
	HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, 0);
	HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, 0);
}

//vertical is main road, we works on main road
void fsm_traffic_light()
{
	switch(mainRoadStatus)
	{
	case 1://red
		HAL_GPIO_WritePin(RED_VER_GPIO_Port, RED_VER_Pin, 1);
		if(isTimerDone(2))
		{
			offVERLight();
			mainRoadStatus=3;
			currentMainRoadTiming=bufferForTrafficLight[2]*1000;
			setTimer(currentMainRoadTiming,2);
		}
		if(mode!=NORMAL_MODE)
		{
			mainRoadStatus=0;
		}
		break;
	case 2://yellow
		HAL_GPIO_WritePin(YELLOW_VER_GPIO_Port, YELLOW_VER_Pin, 1);
		if(isTimerDone(2))
		{
			offVERLight();
			mainRoadStatus=1;
			currentMainRoadTiming=bufferForTrafficLight[0]*1000;
			setTimer(currentMainRoadTiming,2);
		}
		if(mode!=NORMAL_MODE)
		{
			mainRoadStatus=0;
		}
		break;
	case 3://green
		HAL_GPIO_WritePin(GREEN_VER_GPIO_Port, GREEN_VER_Pin, 1);
		if(isTimerDone(2))
		{
			offVERLight();
			mainRoadStatus=2;
			currentMainRoadTiming=bufferForTrafficLight[1]*1000;
			setTimer(currentMainRoadTiming,2);
		}
		if(mode!=NORMAL_MODE)
		{
			mainRoadStatus=0;
		}
		break;
	default:
		if(mode==NORMAL_MODE)
		{
			currentMainRoadTiming=((bufferForTrafficLight[0])*1000);
			setTimer(currentMainRoadTiming,2);
			mainRoadStatus=1;//red
		}
		break;
	}

	//other road light
	switch(otherRoadStatus)
	{
	case 1://red
		HAL_GPIO_WritePin(RED_HOR_GPIO_Port, RED_HOR_Pin, 1);
		if(isTimerDone(3))
		{
			offHORLight();
			otherRoadStatus=3;
			currentOtherRoadTiming=bufferForTrafficLight[2]*1000;
			setTimer(currentOtherRoadTiming,3);
		}
		if(mode!=NORMAL_MODE)
		{
			otherRoadStatus=0;
		}
		break;
	case 2://yellow
		HAL_GPIO_WritePin(YELLOW_HOR_GPIO_Port, YELLOW_HOR_Pin, 1);
		if(isTimerDone(3))
		{
			offHORLight();
			otherRoadStatus=1;
			currentOtherRoadTiming=bufferForTrafficLight[0]*1000;
			setTimer(currentOtherRoadTiming,3);
		}
		if(mode!=NORMAL_MODE)
		{
			otherRoadStatus=0;
		}
		break;
	case 3://green
		HAL_GPIO_WritePin(GREEN_HOR_GPIO_Port, GREEN_HOR_Pin, 1);
		if(isTimerDone(3))
		{
			offHORLight();
			otherRoadStatus=2;
			currentOtherRoadTiming=bufferForTrafficLight[1]*1000;
			setTimer(currentOtherRoadTiming,3);
		}
		if(mode!=NORMAL_MODE)
		{
			otherRoadStatus=0;
		}
		break;
	default:
		if(mode==NORMAL_MODE)
		{
			currentOtherRoadTiming=bufferForTrafficLight[2]*1000;
			setTimer(currentOtherRoadTiming,3);
			otherRoadStatus=3;//green
		}
		break;
	}

}

