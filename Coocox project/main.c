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
  int richting = 0;
  /*for(i=startpunt[0];i<eindpunt[0];i++)
  {
	  for(j=0;j<breedte;j++)
	  {
		  UB_VGA_SetPixel(j+startpunt[1],i,kleur);
	  }
  }*/
  API_clearscreen(0);
  char b = 'C';
  API_draw_char(20,100,254,b,0,0,0,0);
  char *text = "WAT EEN HOERE OPDRACHT !@#$%^&*() gaat deze zin verder op de volgende regel?";

  API_draw_text(0,200,232,text,0,0,0,0);
  text = "Mooi dat doet tie. Nou blij?";
  API_draw_text(0,216,232,text,0,0,1,0);
  API_draw_rectangle(0,0,50,50,10,0,0,0);

  API_draw_line(50,50,100,100,10,32,0);
  API_draw_line(150,150,100,100,40,0,0);

  API_draw_line(50,150,100,100,80,0,0);
  API_draw_line(150,50,100,100,120,0,0);

  API_draw_line(50,100,100,100,160,0,0);
  API_draw_line(150,100,100,100,200,0,0);

  API_draw_line(100,50,100,100,240,0,0);
  API_draw_line(100,150,100,100,255,0,0);

  API_draw_bitmap(180,30,1);

  while(1)
  {
	  //
  }
  /*while(1)
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
	  //UB_VGA_FillScreen(VGA_COL_BLACK);
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
		  if((startpunt[1]+breedte)>VGA_DISPLAY_X)
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
		  k=0;*/
	  //int kleur = 255;
	  //API_draw_bitmap(startpunt[1],30,0);

	  //uint16_t blub;

	  //char * blub ="nog eens blub";
	  //sprintf();
	  /*for(i=startpunt[0];i<eindpunt[0];i++)
	  {
		  for(j=0;j<breedte;j++)
		  {
			  UB_VGA_SetPixel(j+startpunt[1],i,k);
		  }
	  }*/


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
	  }

  }*/
}
