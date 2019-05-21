/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "main.h"
#include "delay.h"
void LED_INITTER(void);
//volatile char com_flag = 0;
volatile int glob = 0;
int main(void)
{
	DELAY_init();
	LED_INITTER();

	UART_init();
	UART_INT_init();
	char* hello = "Hello";
	UART_puts(hello);

//	LCD_init();
//	LCD_clear();
//	LCD_cursor_home();
//	LCD_put("Mauricio");
	while(1)
	{
	}
}
