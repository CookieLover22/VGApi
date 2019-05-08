//--------------------------------------------------------------
// File     : main.h
//--------------------------------------------------------------

//--------------------------------------------------------------
#ifndef __STM32F4_UB_MAIN_H
#define __STM32F4_UB_MAIN_H


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"



//--------------------------------------------------------------
#endif // __STM32F4_UB_MAIN_H

//!hier onder is de uart struct gedeclareert. Deze struct verbind de front en de logic layer
typedef struct command
{
	char arg[8][20];

} UART_struct;

//! dit is de declaratie van de buffer zelf
UART_struct bericht[10];

//! dit is de variabele die aan geeft waar in de Q het nieuwste lid zit (++ bij schrijven Q)
int first_in_Q_member = 0;
//! dit is de variabele die aan geeft waar in de Q het oudste lid zit (++ bij lezen Q)
int first_out_Q_member = 0;
