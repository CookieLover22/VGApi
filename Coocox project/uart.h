#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "lcd.h"
#define CR 13 // carriage return char
#define LF 10 // linefeed char
#define BAUDRATE 115200


void UART_init(void);
void UART_INT_init(void);
void UART_putchar(char c);
void UART_puts(char *s);
