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
	//! Het gestuurde commando wordt niet herkend (LOGIC_functionpicker)
	COMMANDERROR,
	//! Geeft aan dat het meegegeven argument geen (gedefinieerde) kleur is (LOGIC_colorpicker)
	UNDEFINEDCOLOR,
	//! IO Layer --> Out of bounce
	OUT_OF_BOUNDS,
	//! IO Layer --> Bitmap Nr not existing
	UNDEFINED_BITMAP_NR,
	//! IO Layer --> no Bold or Italic functionality availible
	ONLY_FONTSTYLE_NORMAL_AVAILIBLE,
	//! IO Layer --> Fontname not existing
	UNDEFINED_FONTNAME,
	//! IO Layer --> Fontsize not existing
	FONTSIZE_NOT_EXISTING,
	//! IO Layer --> Filled not 0 or 1
	FILLED_NOT_0_OR_1
};
