
#include <main.h>
#include "uart.h"



int main(void)
{
	SystemInit(); // System speed to 168MHz

	UART_init();
	UART_INT_init();

	DELAY_init();

	//Q initialiseren
	front_to_logic_Q.Q_size = QLENGTH;
	front_to_logic_Q.last_written_Q_member = 0;
	front_to_logic_Q.last_read_Q_member = 0;

	UART_puts("Ready to receive.");

	UB_VGA_Screen_Init(); // Init VGA-Screen

	UB_VGA_FillScreen(0);

	int state = 0;
	int error = 0;
	while(1)
	{
		//het volgende state machientje zorgt ervoor dat de loop ��n keer doorlopen wordt tijdens Vsync
		if( GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12)) state = 0;
		else
		{
			state ++;
			if(state == 1)
			{
				error = API_perform(&front_to_logic_Q);

				LOGIC_errorhandler(error);
			}
		}
	}

}



