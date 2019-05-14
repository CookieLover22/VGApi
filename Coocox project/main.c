//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <time.h>
//#include <IO_draw.h>

int main(void)
{
	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	API_Qinit(&front_to_logic_Q, 20); //Q initialiseren

	UB_VGA_Screen_Init(); // Init VGA-Screen


	UB_VGA_FillScreen(VGA_COL_BLACK);





	while(1)
	{

	}
}
