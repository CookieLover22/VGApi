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
extern void HsvToRgb(double h, double S, double V, int* r, int* g, int* b);

int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_BLACK);
  UB_VGA_SetPixel(10,10,10);
  UB_VGA_SetPixel(100,100,10);

  int R;
  int G;
  int B;
  char RGB;
  double i;
  double j;

  while(1)
  {
	  for(j=0;j<1;j+=0.001)
	  {
		  for(i = 0; i<640; i ++)
		  {
			  HsvToRgb(i, j, 1, &R, &G, &B);
			  R >>= 5;
			  G >>= 5;
			  B >>= 6;
			  RGB = R;
			  RGB <<= 3;
			  RGB += G;
			  RGB <<= 2;
			  RGB += B;
			  //RGB = (R*6/256)*36 + (G*6/256)*6 + (B*6/256);
			  UB_VGA_SetPixel(i/2 ,j*240,RGB);
		  }
  	  }
	  while(1);
  }
}

