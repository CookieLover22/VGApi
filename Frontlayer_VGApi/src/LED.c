/*
 * LED.c
 *
 *  Created on: 11 May 2019
 *      Author: Mauricio Paulusma
 */

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

void LED_INITTER(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitTypeDef GPIO_INIT_STRUCT;
	GPIO_INIT_STRUCT.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_INIT_STRUCT.GPIO_OType = GPIO_OType_PP;
	GPIO_INIT_STRUCT.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_INIT_STRUCT.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_INIT_STRUCT.GPIO_Speed = GPIO_High_Speed;

	GPIO_Init(GPIOD, &GPIO_INIT_STRUCT);

}



