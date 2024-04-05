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

#include "i2c_lcd.h"
#include "led.h"
#include "timer.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

	int main(void)
     {
    	    SystemInit();
		    char str[20];
		    LcdInit();
		    count = 0;
		     int ret;
		     ret = LcdInit();
		     TimerInit(1000);
		     while(1)
		     {
		    	 if(ret)
		    	 {
		    		 sprintf(str, "Count = %d", count);
		    		 LcdPuts(LCD_LINE1, str);
		    		 //LcdWrite(LCD_CMD, LCD_CLEAR);
		    	 }
		     }
		return 0;
	}
