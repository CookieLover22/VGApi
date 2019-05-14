//--------------------------------------------------------------
// File     : main.h
//--------------------------------------------------------------
#include <LogicLayer.h>
//--------------------------------------------------------------
#ifndef __STM32F4_UB_MAIN_H
#define __STM32F4_UB_MAIN_H

//--------------------------------------------------------------
// Variables
//--------------------------------------------------------------

//!
UART_Q_info front_to_logic_Q;

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"
#include <stdlib.h>



//--------------------------------------------------------------
#endif // __STM32F4_UB_MAIN_H

//--------------------------------------------------------------
// Error codes
//--------------------------------------------------------------

enum error
{
	//! Geeft aan dat er niks aan de hand is (is altijd 0)
	NOERROR = 0,
	//! De gegeven Qsize is te klein!
	QSIZEERROR,
	//! De Queue is al helemaal uitgelezen
	EMPTYQ,
	//! De Queue is vol
	FULLQ,
	//! Het gestuurde commando wordt niet herkend
	COMMANDERROR

};
