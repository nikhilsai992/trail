/*
 * 	CaseStudy
 *	main.c
 *  Created on: July 21, 2021
 *  Author: Cuddapah Nikhil Sai
 */

#include<string.h>
#include "stm32f407xx.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW
int count = 0;

void ignition_on(void);
void ignition_on_seatbelt_not_fastened(void);
void ignition_on_crash_detected_seatbelt_not_fastened(void);
void ignition_on_crash_detected_seatbelt_fastened(void);	

void delay(void)
{
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}


void ignition_on()
{
	for(uint32_t i=0; i<250;i++)
{
	    
		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
		delay();
		
		

		if(count==1)
		{
		ignition_on_seatbelt_not_fastened();
		}
	}
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	while(1)
	{
	if(count==1)
	{
		ignition_on_seatbelt_not_fastened();
	}
	}
}

void ignition_on_seatbelt_not_fastened()
{
	count=0;
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_14);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
	delay();
		if(count==2)
		{
			ignition_on_crash_detected_seatbelt_not_fastened();
		}		
	}
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
	while(1)
	{	
		if(count==2)
		{
			ignition_on_crash_detected_seatbelt_not_fastened();
		}
	}
}

void ignition_on_crash_detected_seatbelt_not_fastened()
{
	count=0;
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
	for(uint32_t i = 0 ; i < 3000 ; i ++){
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_14);
	     delay();
		if(count==3)
		{
			ignition_on_crash_detected_seatbelt_fastened();
		}		
	}
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	while(1)
	{	
		if(count==3)
		{
			ignition_on_crash_detected_seatbelt_fastened();
		}
	}
}

void ignition_on_crash_detected_seatbelt_fastened()
{
	count=0;
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_15,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_13,GPIO_PIN_RESET);
	while(1)
	{    GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
	     delay();
		
		if(count==4)
		{
			ignition_on_crash_detected_seatbelt_fastened();
		}
	}
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_14,GPIO_PIN_RESET);
	if(count==4)
	{
		ignition_on_crash_detected_seatbelt_not_fastened();
	}
	ignition_on();
}



int main(void)
{

	GPIO_Handle_t LED_Green, LED_Red,GpioLedOrange, GpioLedBlue,BUTTON_Blue;

	//this is Green led gpio configuration
	LED_Green.pGPIOx = GPIOD;
	LED_Green.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	LED_Green.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	LED_Green.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	LED_Green.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	LED_Green.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&LED_Green);
	
	//this is Red led gpio configuration
	LED_Red.pGPIOx = GPIOD;
	LED_Red.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	LED_Red.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	LED_Red.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	LED_Red.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	LED_Red.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&LED_Red);

//this is led gpio orange led configuration
	GpioLedOrange.pGPIOx = GPIOD;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLedOrange);

	//this is led gpio blue led configuration
	GpioLedBlue.pGPIOx = GPIOD;
	GpioLedBlue.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLedBlue.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedBlue.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedBlue.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLedBlue.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLedBlue);



	//this is btn gpio configuration
	BUTTON_Blue.pGPIOx = GPIOA;
	BUTTON_Blue.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	BUTTON_Blue.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	BUTTON_Blue.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	BUTTON_Blue.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA,ENABLE);

	GPIO_Init(&BUTTON_Blue);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI0);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);
	
	
	ignition_on();
}


void EXTI0_IRQHandler(void)
{
	count = GPIO_IRQHandling(GPIO_PIN_NO_0,count);
}
