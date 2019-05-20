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



	int state = 0;
	int error = 0;
	while(1)
	{
		//if (!GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_11)) DELAY_us(28);
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
			//if(error)UART_putint(error);


			//LCD_putint(error);
			//if(error) while(1);
			//DELAY_ms(50);
			//DELAY_us(10000);
			//GPIO_ResetBits(GPIOE, GPIO_Pin_7);

		}
	}

}



