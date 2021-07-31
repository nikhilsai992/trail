/*
 * Case study
 *
 *  Created on: July 31, 2019
 *      Author: Nikhil Sai
 */

#include<string.h>
#include<stdio.h>
#include "stm32f407xx.h"

#define HIGH 1
#define LOW 0
#define BTN_PRESSED LOW

void delay(void)
{
	// this will introduce ~200ms delay when system clock is 16MHz
	for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}
int count=0;
void igition_on_setbelt_not_fastned()
{   
  	while(1){
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_14);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_15);
	delay();

}
}

void ignition_on()
{

for(uint32_t i=0; i<1000;i++)
{
	    
		GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);
		delay();
		
		
}
}
int main(void)
{

	GPIO_Handle_t GpioLedGreen,GpioLedOrange,GpioLedRed,GpioLedBlue, GPIOBtn;

	//this is led gpio green led configuration
	GpioLedGreen.pGPIOx = GPIOD;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLedGreen.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLedGreen);

		//this is led gpio orange led configuration
	GpioLedOrange.pGPIOx = GPIOD;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLedOrange.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLedOrange);

		//this is led gpio red led configuration
	GpioLedRed.pGPIOx = GPIOD;
	GpioLedRed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLedRed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLedRed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLedRed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLedRed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOD,ENABLE);

	GPIO_Init(&GpioLedRed);

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
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOA,ENABLE);

	GPIO_Init(&GPIOBtn);

	GPIO_WriteToOutputPin(GPIOD,GPIO_PIN_NO_12,GPIO_PIN_RESET);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0,NVIC_IRQ_PRI0);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0,ENABLE);
    ignition_on();
    
    while(1);

}


void EXTI0_IRQHandler(void)
{   int count=0;
   
	count= GPIO_IRQHandling(GPIO_PIN_NO_0,count);
    igition_on_setbelt_not_fastned();
	

	 
	
}
