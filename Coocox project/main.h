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
#include <stdlib.h>
#include <LogicLayer.h>
#include <IO_draw.h>
#include <stdlib.h>
#include <math.h>
#include "stm32_ub_vga_screen.h"
#include <string.h>
#include <time.h>
//--------------------------------------------------------------
// Variables
//--------------------------------------------------------------

//!
Q_INFO front_to_logic_Q;



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
