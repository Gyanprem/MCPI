/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "uart.h"



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32];
	int choice;

	SystemInit();
	UartInit(BAUD_9600);
	LedInit(LED_BLUE);
	LedInit(LED_RED);
	do
	{
		UartPuts("enter choice\r\n");
		UartPuts("1 red led on\r\n");
		UartPuts("2 red led off\r\n");
		UartPuts("3 blue led on\r\n");
		UartPuts("4 blue led off\r\n");
	   UartGets(str);
	sscanf(str, "%d",&choice);
	switch(choice)
	{
	case 1 :
		LedOn(LED_RED);
		break;
	case 2 :
		LedOff(LED_RED);
		  break;
	case 3 :
		LedOn(LED_BLUE);
	      break;
	case 4 :
		LedOff(LED_BLUE);
		  break;
	}
	}
	while(choice!=0);
	return 0;
}
