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

#include <main.h>
#include "uart.h"



int main(void)
{
	SystemInit(); // System speed to 168MHz

	UB_VGA_Screen_Init(); // Init VGA-Screen

	DELAY_init();
	LCD_init();
	UART_init();
	UART_INT_init();

	LCD_clear();			// Start with a clear display
	LCD_XY(0,0);			// Shift one spot

	//LCD_put("pretest");

	LCD_putint(API_Qinit(&front_to_logic_Q, 20)); //Q initialiseren

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(0);

	//COMMAND write_struct;
	//COMMAND read_struct;

	//char errorstring [20];
	/*
	int i;

	strcpy(write_struct.arg[0].text, "rechthoek");
	strcpy(write_struct.arg[1].text, "100");
	strcpy(write_struct.arg[2].text, "100");
	strcpy(write_struct.arg[3].text, "20");
	strcpy(write_struct.arg[4].text, "30");
	strcpy(write_struct.arg[5].text, "blauw");
	strcpy(write_struct.arg[6].text, "1");
	strcpy(write_struct.arg[7].text, "1");
	strcpy(write_struct.arg[8].text, "0");

	for (i = 0; i < 3; i++)
	{

		API_Qwriter(&front_to_logic_Q, &write_struct);
	}
	*/

	//API_draw_rectangle(100,100,20,30,3,1,1,0);
	//if(LOGIC_functionpicker(write_struct)) UB_VGA_SetPixel(10,10,20);
	//char error[] = "G";
	//error[0] = LOGIC_functionpicker(&write_struct)+48;

	//API_draw_text(20,20, 20, error,errorstring,0,0,0);



	while(1)
	{
		//API_Qreader(&front_to_logic_Q, &read_struct);
		LCD_clear();
		int error = 0;
		error = API_perform(&front_to_logic_Q);
		//error = LOGIC_functionpicker(&write_struct);
		LCD_putint(error);
		if(error) UART_putint(error);
		//if(error) while(1);
		//DELAY_ms(100);
	}
}



