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

	UART_puts("Ready to receive.");

	LCD_clear();			// Start with a clear display
	LCD_XY(0,0);			// Shift one spot

	//Q initialiseren
	front_to_logic_Q.Q_size = QLENGTH;
	front_to_logic_Q.last_written_Q_member = 0;
	front_to_logic_Q.last_read_Q_member = 0;


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

	//DELAY_s(10);

	int state = 0;
	int error = 0;
	while(1)
	{
		//if (!GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12)) DELAY_us(31);
		//het volgende state machientje zorgt ervoor dat de loop één keer doorlopen wordt tijdens Vsync
		if( GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12)) state = 0;
		if(!GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) && state == 0) state = 1;
		if(state == 1)
		{

			//GPIO_SetBits(GPIOE, GPIO_Pin_7);
			state = 2;
			//API_Qreader(&front_to_logic_Q, &read_struct);
			//LCD_clear();

			error = API_perform(&front_to_logic_Q);
			//error = LOGIC_functionpicker(&write_struct);

			//if(error && error != EMPTYQ)UART_putint(error);
			//LCD_putint(error);
			//if(error) while(1);
			//DELAY_ms(50);
			//GPIO_ResetBits(GPIOE, GPIO_Pin_7);
			DELAY_ms(17);
		}
	}
}



