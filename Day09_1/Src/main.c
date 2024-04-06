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
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lis3dsh.h"
#include "i2c_lcd.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str1[32];
	char str2[32];
		int ret;
		LcdInit();
		LIS_Data val;
		SystemInit();
		
		
		LIS_Init();
		DelayMs(1000);
		while(1) {
			ret = LIS_DRdy();
			if(ret) {
				val = LIS_GetData();
				sprintf(str1, "X=%d,Y=%d", val.x, val.y);
				sprintf(str2, "Z=%d", val.z);
				LcdPuts(LCD_LINE1,str1);
				LcdPuts(LCD_LINE2,str2);
				DelayMs(1000);
			}
		}
	return 0;
}
