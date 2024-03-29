/**
  ******************************************************************************
  * @file    Project/STM32F0xx_StdPeriph_Templates/main.c 
  * @author  MCD Application Team
  * @version V1.6.0
  * @date    13-October-2021
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2014 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"


#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
	

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  /* Loop until transmit data register is empty */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}

  return ch;
}


static void 			Delay_Ms(uint16_t time);

static uint16_t		_countReloadCounter = 0;

int main(void){
//	uint8_t i=0;
	USART_Config();
	LCD_BEGIN();	
	LCD_INIT_MODE();
	LCD_Init_PWEN();
	SPI_Config();
	printf("Start");
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_256);
	IWDG_SetReload(3125);
	IWDG_ReloadCounter();
	IWDG_Enable();
	
  while (1){
		if(_countReloadCounter == 5000){
			printf("S\n");
			LCD_Save_WS();
			IWDG_ReloadCounter();
			_countReloadCounter = 0;
		}
		//LCD_Press_BTEN();
	//	LCD_Toggle_PWEN();
		//Delay_Ms(1);
		//LCD_ABNORMAL_OVERVOLTAGE_MODE();
		//LCD_INIT_MODE();
		//Delay_Ms(3);
		//LCD_NORMAL_LOADING_MODE();
		//Delay_Ms(3);
		//LCD_STANBY_MODE();
		//LCD_RESET_MODE();
		//LCD_ABNORMAL_OVERLOAD_MODE();
				//LCD_ABNORMAL_UNDERVOLTAGE_MODE();
		//LCD_ABNORMAL_OVERVOLTAGE_MODE();
	//	LCD_NORMAL_OVERLOAD_MODE();
		//LCD_NORMAL_UNDERVOLTAGE_MODE();
		LCD_INIT_MODE();
		Delay_Ms(3000);
	/*LCD_NORMAL_OVERVOLTAGE_MODE();//
		 LCD_Set_Voltage_In(28);// in man hinh dien ap vao
		LCD_Set_Voltage_Out2(45);// in ra man hinh dien ap ra 2
		LCD_Set_Voltage_Out1(15);//in ra man hinh dien ap ra 1
		LCD_Set_Amp_In(9999);
		LCD_Set_Wattage(215);
		while(true)
		{LCD_Set_Frequence(98);//in ra man hinh tan so
			Delay_Ms(1000);
			LCD_Set_Temperature(59);// in ra man hinh nhiet do
			Delay_Ms(1000);
		}
		Delay_Ms(3000);*/
	
		/*LCD_NORMAL_UNDERVOLTAGE_MODE();
		Delay_Ms(3000);
	LCD_NORMAL_OVERLOAD_MODE();
		Delay_Ms(3000);
		LCD_ABNORMAL_OVERVOLTAGE_MODE();
		Delay_Ms(3000);
		LCD_ABNORMAL_UNDERVOLTAGE_MODE();
		Delay_Ms(3000);
		LCD_ABNORMAL_OVERLOAD_MODE();
		Delay_Ms(3000);
		LCD_STANBY_MODE();
		Delay_Ms(3000);
		LCD_RESET_MODE();
		Delay_Ms(3000);
		*/
		
  }
}


void Delay_Ms(uint16_t time){
	uint32_t time_n=  time*1600;
	while(time_n != 0)	{time_n--;}

}
