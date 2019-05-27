/**@file Uart.c
* @author Mauricio Paulusma
*
* Deze file definieert functies voor de Frontlayer van het VGApi project
*
* Gebruik: Om de frontlayer te activeren en te gebruiken, volg de volgende stappen:
*
*          1. Roep de functie UART_init(); aan
*          2. Roep de functie UART_INT_init(); aan
*
*/

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "uart.h"
#include <stdio.h>
#include <stdlib.h>
#include "misc.h"


/* Defines -------------------------------------------------------------------*/



/* Global variables ----------------------------------------------------------*/

/// Deze structure wordt gebruikt om de argumenten in de ontvangen string te structureren zodat ze in de command queue kunnen worden geplaatst.
COMMAND received;
/// Deze variabele wordt gebruikt door USART2_IRQHandler() om de characters in het juiste plekje van de struct te zetten.
volatile unsigned int Char_cnt = 0;
/// Deze variabele wordt gebruikt door USART2_IRQHandler() om de argumenten in het juiste plekje van de struct te zetten.
volatile unsigned int Arg_cnt = 0;
volatile int i;

typedef __SIZE_TYPE__ size_t;

/* Function definitions ------------------------------------------------------*/

/*!
*   @brief	Deze functie initialiseert de UART (onderdeel van de frontlayer)
*
*			Gebruik:
*				- Roep UART_init(); aan in de main.
*
*
*	@param void, deze functie verwacht geen input
*
*	@return void, deze functie stuurt geen waarde terug.
*
*/
void UART_init(void)
{

  /* --------------------------- System Clocks Configuration -----------------*/
  /* USART2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  /* GPIOA clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  GPIO_InitTypeDef GPIO_InitStructure;

  /*-------------------------- GPIO Configuration ----------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Connect USART pins to AF */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);   // USART2_TX
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);  // USART2_RX

  USART_InitTypeDef USART_InitStructure;

/* USARTx configuration ------------------------------------------------------*/
/* USARTx configured as follow:
      - BaudRate = 115200 baud
      - Word Length = 8 Bits
      - One Stop Bit
      - No parity
      - Hardware flow control disabled (RTS and CTS signals)
      - Receive and transmit enabled
*/
USART_InitStructure.USART_BaudRate = BAUDRATE;
USART_InitStructure.USART_WordLength = USART_WordLength_8b;
USART_InitStructure.USART_StopBits = USART_StopBits_1;
USART_InitStructure.USART_Parity = USART_Parity_No;
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

USART_Init(USART2, &USART_InitStructure);
USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);

USART_Cmd(USART2, ENABLE);

}

/*!
*   @brief	Deze functie stuurt een character naar de UART (onderdeel van de frontlayer)
*
*			Gebruik:
*				- Deze functie wordt in dit project gebruikt door UART_puts()
*
*
*	@param char c, het character dat naar de UART verstuurd wordt
*
*	@return void, deze functie stuurt geen waarde terug.
*
*/
void UART_putchar(char c)
{
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET); // Wait for Empty
		USART_SendData(USART2, c);

}

/*!
*   @brief	Deze functie stuurt een string naar de UART (onderdeel van de frontlayer)
*
*			Gebruik:
*				- Deze functie wordt in dit project gebruikt door USART2_IRQHandler()
*
*
*	@param char* s, de string die naar de UART wordt verstuurd
*
*	@return void, deze functie stuurt geen waarde terug.
*
*/
void UART_puts(char* s)
{
	volatile unsigned int i;
	for (i=0; s[i]; i++)
	{
		UART_putchar(s[i]);
		//while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET); // Wait for Empty
		//USART_SendData(USART2, s[i]);
	}
}

/*!
*   @brief	Deze functie initialiseert de UART (onderdeel van de frontlayer)
*
*			Gebruik:
*				- Roep UART_INT_init(); aan in de main.
*
*
*	@param void, deze functie verwacht geen input
*
*	@return void, deze functie stuurt geen waarde terug.
*
*/
void UART_INT_init(void)
{
	NVIC_InitTypeDef   NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 10;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


//haalt spaties vooraf en achteraf weg. courtesy of Dave Gray
// Stores the trimmed input string into the given output buffer, which must be
// large enough to store the result.  If it is too small, the output is
// truncated.
size_t trimwhitespace(char *out, size_t len, const char *str)
{
  if(len == 0)
    return 0;

  const char *end;
  size_t out_size;

  // Trim leading space
  while(*str == ' ') str++;

  if(*str == 0)  // All spaces?
  {
    *out = 0;
    return 1;
  }

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && *end == ' ') end--;
  end++;

  // Set output size to minimum of trimmed string length and buffer size minus 1
  out_size = (end - str) < len-1 ? (end - str) : len-1;

  // Copy trimmed string and add null terminator
  memcpy(out, str, out_size);
  out[out_size] = 0;

  return out_size;
}

/*!
*	@brief Deze functie zorgt voor de Frontlayer functionaliteit. Indien een commando via de UART binnenkomt wordt bij elk ontvangen character van het commando deze interrupt handler geactiveerd. Deze functie zorgt er dan voor dat het commando d.m.v. een structure in de commando queue wordt geplaatst.
*
*		Gebruik:
*			- Deze functie wordt aangeroepen door de USART interrupt
*
*	@param void, deze functie verwacht geen input
*
*	@return void, deze functie stuurt geen waarde terug.
*
*/

void USART2_IRQHandler(void)
{
	if( USART_GetITStatus(USART2, USART_IT_RXNE)) // check if the USART2 receive interrupt flag was set
	{
		USART_ClearITPendingBit(USART2, USART_IT_RXNE); // if flag was set, clear the flag for the next time the interrupt will be set

		char c = USART2->DR & 0xFF; // acquire the received character

		if(c > 64 && c < 91) // convert upper-case letters to lower-case letters
			c += 32;

		if(c <= 13) // end of string character received
		{
			if (!Arg_cnt && !Char_cnt) return;
			received.arg[Arg_cnt].text[Char_cnt] = '\0';

			//spatie padding weg halen
			trimwhitespace(received.arg[Arg_cnt].text, ARGLENGTH, received.arg[Arg_cnt].text);

			Arg_cnt = 0;
			Char_cnt = 0;
			int error_code = API_Qwriter(&front_to_logic_Q,&received);
			//UART_puts("\nQueued\n");
			if(error_code == FULLQ) UART_puts("FULLQ");
		}
		else if(c == ',') // end of argument character received
		{

			c = '\0';
			received.arg[Arg_cnt].text[Char_cnt] = c;

			//spatie padding weg halen
			trimwhitespace(received.arg[Arg_cnt].text, ARGLENGTH, received.arg[Arg_cnt].text);

			if (Arg_cnt >= ARGAMOUNT-1) {UART_puts("com full"); return;}
			Arg_cnt++;
			Char_cnt = 0;

		}
		else
		{
			if(Char_cnt >= ARGLENGTH)
			{
				UART_puts("arg full\n");
				return;
			}

			received.arg[Arg_cnt].text[Char_cnt] = c;
			Char_cnt++;


		}
		while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET); // Wait for Empty


	}
}
