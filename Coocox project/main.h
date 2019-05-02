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


extern void HsvToRgb(float h, float S, float V, int* r, int* g, int* b);
extern void dither (int x, int y, int *R, int *G, int *B, char * RGB);
extern void ditherbuffercleaner();

#define INTERLACELINES 1 //1 = no interlace

