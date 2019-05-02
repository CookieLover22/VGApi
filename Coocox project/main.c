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
extern void HsvToRgb(float h, float S, float V, int* r, int* g, int* b);

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

  while(1)
  {
	  for (k = 1; k > 0; k-=0.2)
	  {

		  for(j=0;j<1;j+=(1.0/240))
		  {
			  for(i = 0; i<360; i += 0.89)
			  {
				  //if(fmod(i, 1)<1)
				  {
					  HsvToRgb(i, j, k, &R, &G, &B);

					  //eve interpoleren(ofzo)
					  if (R%32 <16 && fmod(j*240+fmod(i,2)-0.5,2)>1 && R>16) R-=16;
					  if (G%32 <16 && fmod(j*240+fmod(i,2)-0.5,2)>1 && G>16) G-=16;
					  if (B%64 <32 && fmod(j*240+fmod(i,2)-0.5,2)>1 && B>32) B-=32;

					  //de test hier onder werkt niet zo goed
					  //if (fmod(j*240,R%32)<1 && R>16) R-=16;
					  //if (fmod(j*240,G%32)<1 && G>16) G-=16;
					  //if (fmod(j*240,B%64)<1 && B>32) B-=32;

					  R >>= 5;
					  G >>= 5;
					  B >>= 6;
					  RGB = R;
					  RGB <<= 3;
					  RGB += G;
					  RGB <<= 2;
					  RGB += B;
					  //RGB = (R*6/256)*36 + (G*6/256)*6 + (B*6/256);
				  }
				  UB_VGA_SetPixel(i*0.89 ,j*240,RGB);
			  }
		  }
		  while(1); //hierdoor stopt ie meteen met tekenen
  	  }
  }
}

