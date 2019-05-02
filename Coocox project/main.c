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
  float i;
  float j;
  float k;
  float interlace;


  while(1)
  {

	  for (k = 1; k > 0; k-=0.001)
	  {
		  if (interlace > INTERLACELINES) interlace = 0;
		  else interlace++;
		  for(j=interlace;j<240;j+=(1.0*INTERLACELINES))
		  {
			  for(i = 0; i<320; i ++)
			  {
				  //if(fmod(i, 1)<1)
				  {
					  HsvToRgb(i/320*360, j/240, k, &R, &G, &B);
					  dither (i, j, &R, &G, &B, &RGB);
				  }
				  UB_VGA_SetPixel(i ,j,RGB);
			  }
		  }
		  //while(1); //hierdoor stopt ie meteen met tekenen
  	  }
  }
}

