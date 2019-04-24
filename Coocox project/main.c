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

int main(void)
{

	//  uint32_t n;

	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

  UB_VGA_FillScreen(VGA_COL_BLACK);
  //UB_VGA_SetPixel(10,10,10);
  //UB_VGA_SetPixel(100,100,10);
  //srand (time(NULL));
  int getalX = rand() % VGA_DISPLAY_X;
  int getalY = rand() % VGA_DISPLAY_Y;
  int i=0;
  int j=0;
  int k=0;
  int l=0;
  int startpunt[] = {10,100};
  int eindpunt[] = {100,100};
  int breedte = 100;
  int kleur = 255;
  int richting =0;
  /*for(i=startpunt[0];i<eindpunt[0];i++)
  {
	  for(j=0;j<breedte;j++)
	  {
		  UB_VGA_SetPixel(j+startpunt[1],i,kleur);
	  }
  }*/

  while(1)
  {
	  while(1)
	  {
		  l++;
		  if(l>500000)
		  {
			  l=0;
			  break;
		  }
	  }
	  UB_VGA_FillScreen(VGA_COL_BLACK);
	  while(1)
	  {
		  l++;
		  if(l>500000)
		  {
			  l=0;
			  break;
		  }
	  }
	  k++;
	  if(richting == 0)
	  {
		  if((startpunt[1]-breedte)>VGA_DISPLAY_X)
			  richting =1;
		  else
	  	  startpunt[1]++;

	  }
	  else
	  {
		  if(startpunt[1]<0)
			  richting =0;
		  else
			  startpunt[1]--;
	  }
	  if(k>255)
		  k=0;
	  //int kleur = 255;
	  for(i=startpunt[0];i<eindpunt[0];i++)
	  {
		  for(j=0;j<breedte;j++)
		  {
			  UB_VGA_SetPixel(j+startpunt[1],i,k);
		  }
	  }


	  /*getalX = rand() % VGA_DISPLAY_X;
	  getalY = rand() % VGA_DISPLAY_Y;
	  UB_VGA_SetPixel(getalX,getalY,10);
	  while(1)
	  {
		  i++;
		  if(i>1000)
		  {
			  i=0;
			  break;
		  }
	  }*/

  }
}
