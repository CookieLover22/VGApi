#define UART 1

#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "uart.h"
#include "lcd.h"

void LED_INITTER(void);

extern COMMAND commands[];
extern unsigned int Com_cnt_front;
extern unsigned int Com_cnt_logic;
