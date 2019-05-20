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
#include <IO_draw.h>
//#include "uart.h"

int main(void)
{
  SystemInit(); // System speed to 168MHz

  //UART_init();
  //UART_INT_init();
  UB_VGA_Screen_Init(); // Init VGA-Screen

  API_clearscreen(0);

  API_draw_line(50,50,70,150,10,20,0);
  API_draw_line(150,150,100,100,40,1,0);

  API_draw_line(50,150,100,100,80,1,0);
  API_draw_line(150,50,100,100,120,1,0);

  API_draw_line(50,100,100,100,160,1,0);
  API_draw_line(150,100,100,100,200,1,0);

  API_draw_line(100,50,100,100,240,1,0);
  API_draw_line(100,150,100,100,255,1,0);

  API_draw_line(0,0,10,100,120,1,0);


  API_draw_bitmap(180,70,5);
  API_draw_bitmap(180,0,4);
  API_draw_bitmap(220,160,0);
  API_draw_bitmap(240,160,1);
  API_draw_bitmap(260,160,2);
  API_draw_bitmap(280,160,3);

  API_draw_rectangle(150,150,50,50,25,0,0,25);

  char c = 'C';
  API_draw_char(20,100,254,c,"arial",1,0,0);
  char *text = "WAT EEN HOEREN OPDRACHT !@#$%^&*() gaat deze zin verder op de volgende regel?";

  API_draw_text(0,180,232,text,"arial",2,0,0);
  text = "Mooi dat doet tie. Nou blij?";
  API_draw_text(0,216,232,text,"consolas",1,1,0);
 // API_draw_rectangle(0,0,50,50,10,1,0,0);

  API_draw_circle(50,50,15,25,0);
  API_draw_figure (25, 25, 50, 25, 70, 35, 50, 50, 25, 50, 30, 0);
  while(1)
  {
	  //
  }
}
