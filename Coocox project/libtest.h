
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <time.h>
uint8_t pikachu[] = {136,136,136,136,136,136,136,136,136,136,136,136,104,104,72,108,113,113,113,113,113,112,76,40,72,140,212,212,244,244,248,248,248,248,248,248,248,248,248,244,212,208,172,136,100,100,100,104,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,104,72,108,113,113,113,112,112,112,112,112,112,112,112,112,112,112,112,112,112,112,108,108,108,108,108,144,180,212,212,216,216,212,212,212
		,136,136,136,136,136,136,136,136,136,136,136,136,104,100,72,108,113,113,113,113,113,112,76,72,36,104,176,212,244,244,248,248,248,248,248,248,248,248,248,248,245,245,208,176,136,100,100,104,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,104,72,108,113,113,112,112,112,112,112,112,112,112,112,112,112,112,112,108,108,108,108,108,144,144,180,212,213,217,216,216,216,212,212,212
		,136,136,136,136,136,136,136,136,136,136,136,136,104,68,104,113,113,113,113,113,112,112,112,76,72,72,144,212,244,248,248,248,248,248,248,248,248,248,248,248,248,249,245,213,208,140,136,104,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,72,76,112,112,112,112,112,112,112,112,112,112,112,112,112,108,76,108,108,108,144,176,180,213,213,217,216,216,216,248,248,244,212,212
		,136,136,136,136,136,136,136,136,136,136,136,104,104,72,108,113,113,113,113,112,112,113,112,108,72,72,140,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,249,245,208,172,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,72,72,112,112,112,112,112,112,112,112,112,112,112,108,108,108,108,108,144,176,180,212,217,217,248,248,248,248,248,248,244,244,244,244
		,136,136,136,136,136,136,136,136,136,136,136,104,104,72,108,113,113,113,113,112,112,113,112,112,108,72,108,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,245,245,212,172,140,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,72,72,108,112,112,112,112,112,112,112,112,108,108,108,108,144,144,180,213,213,217,216,248,248,248,248,248,248,248,244,244,244,244,244
		,136,136,136,136,136,136,136,136,136,136,136,104,72,104,109,113,113,113,113,112,112,112,112,112,108,104,104,140,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,245,212,176,172,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,72,108,112,144,144,144,112,108,108,108,108,144,144,176,212,212,217,249,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244
		,136,136,136,136,136,136,136,136,136,136,104,68,72,108,113,113,113,113,81,80,112,112,112,113,112,108,104,140,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,245,244,244,208,172,136,132,132,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,72,72,108,144,144,108,108,108,108,144,144,180,212,212,248,248,248,248,248,244,248,248,248,248,248,248,248,248,248,248,248,244,212
		,136,136,136,136,136,136,136,136,136,136,104,68,72,108,113,113,81,81,81,80,80,80,80,112,112,108,104,104,144,180,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,245,245,208,172,136,136,132,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,104,104,108,108,140,108,108,140,144,180,212,212,212,248,248,248,248,248,248,244,248,248,248,248,248,248,248,248,248,244,248,248,212
		,136,136,136,136,136,136,136,136,136,104,104,68,72,108,109,76,76,80,80,80,76,80,80,80,112,112,108,108,140,176,212,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,245,245,208,172,136,136,132,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,104,104,104,108,108,140,144,176,212,212,216,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,212
		,136,136,136,136,136,136,136,136,136,104,68,72,72,108,76,76,76,44,44,44,44,76,76,76,112,112,108,108,108,140,176,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,245,244,212,208,172,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,104,104,104,104,140,140,176,212,212,216,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,212
		,136,136,136,136,136,136,136,136,136,104,68,72,72,76,76,76,44,44,44,44,44,44,44,76,76,112,112,108,108,108,140,180,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,172,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,132,132,132,132,132,132,132,104,104,136,140,172,176,212,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,248,248,248,248,248,244,244,244,212,176
		,136,136,136,136,136,136,136,136,104,104,68,72,76,76,76,76,44,44,44,44,44,44,44,44,76,76,112,108,76,72,108,144,212,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,172,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,132,132,132,132,132,132,132,132,132,132,132,132,132,132,132,136,136,136,136,140,172,176,212,212,244,248,248,248,248,248,248,248,248,248,248,248,244,244,244,248,248,244,244,244,244,244,244,248,248,244,244,212,176
		,136,136,136,136,136,136,136,136,104,68,68,72,76,76,76,44,44,44,44,44,44,44,44,44,44,76,76,76,76,72,104,140,176,212,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,208,172,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,136,172,172,172,172,172,172,208,208,208,212,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,248,244,244,212,212,140
		,136,136,136,136,136,136,136,104,104,68,72,72,76,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,76,72,72,104,140,176,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,208,172,172,172,172,172,172,172,172,172,172,172,172,172,208,208,208,208,208,208,208,208,208,208,208,208,208,208,208,208,208,208,213,245,245,245,245,244,244,244,244,244,244,248,248,248,248,248,244,248,248,248,248,248,244,244,244,248,244,244,244,244,244,244,244,244,244,244,244,212,176,140
		,136,136,136,136,136,136,136,104,68,68,72,72,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,72,72,104,108,140,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,212,208,208,208,208,208,208,208,208,208,208,212,212,244,244,244,245,245,245,245,245,245,245,245,245,245,245,245,245,245,245,245,245,245,245,244,244,244,244,244,248,248,248,248,248,248,248,244,244,244,248,244,244,244,248,248,248,244,244,244,244,244,244,244,244,244,244,212,176,144,140
		,136,136,136,136,136,136,136,104,68,68,72,72,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,72,72,104,104,140,180,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,248,248,248,244,244,244,244,244,244,244,244,212,212,176,176,140,108
		,136,136,136,136,136,136,136,104,68,68,72,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,72,72,72,72,104,176,212,244,248,248,248,248,248,248,248,248,244,248,248,248,248,248,248,248,248,248,248,248,248,244,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,248,248,248,244,244,244,244,244,244,244,244,212,176,176,144,144,108
		,136,136,136,136,136,136,136,100,68,72,72,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,72,72,72,72,72,108,176,212,244,248,248,248,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,248,248,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,248,248,244,244,244,244,244,244,244,212,176,144,140,144,112,112
		,136,136,136,136,136,136,104,68,68,72,72,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,72,72,72,72,104,140,176,212,248,244,248,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,248,244,244,244,244,244,208,176,140,108,108,108,112,112
		,136,136,136,136,136,136,104,68,68,72,72,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,45,45,77,76,76,72,72,72,72,104,140,208,244,244,248,244,248,244,244,248,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,248,244,248,248,244,244,244,244,244,244,245,245,212,176,140,140,108,108,76,76,76,76
		,136,136,136,136,136,136,100,68,68,72,72,44,44,44,44,44,44,44,44,44,44,45,45,45,45,45,45,45,45,45,77,72,72,72,72,72,72,104,140,212,213,249,248,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,248,244,248,244,248,248,248,248,248,244,245,245,212,176,140,108,108,108,76,76,76,76,76
		,136,136,136,136,136,104,100,68,72,72,72,44,44,44,44,44,44,40,44,44,44,44,45,45,45,45,45,45,45,45,40,40,72,72,72,72,72,72,104,140,212,245,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,248,248,248,248,244,245,213,212,176,140,108,108,76,76,76,76,76,44,44
		,137,136,136,136,136,104,68,68,72,72,44,44,44,44,44,44,40,40,40,40,40,44,44,45,45,45,45,45,45,41,41,41,40,72,72,72,72,72,72,104,172,208,212,212,212,212,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,212,213,180,176,140,108,108,76,76,76,44,44,44,44,44
		,137,136,136,136,136,104,68,68,72,72,44,44,44,45,44,40,40,40,40,40,40,40,40,45,45,41,41,41,41,41,41,41,40,40,72,72,72,72,72,72,104,140,176,208,176,208,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,248,244,244,212,176,144,140,108,72,76,76,76,76,44,44,44,44,44
		,137,136,136,136,104,100,68,68,72,76,76,45,45,45,44,40,40,40,40,40,40,40,40,40,40,40,41,41,41,41,41,41,40,40,40,72,72,72,72,72,72,104,140,172,172,208,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,248,244,212,176,144,108,108,108,76,76,76,76,76,44,44,44,44,44
		,137,136,136,136,104,68,68,72,72,77,77,45,45,45,40,40,40,40,40,40,40,40,40,40,40,40,40,40,41,41,40,40,40,40,40,72,72,72,72,72,72,68,104,140,176,212,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,212,212,212,244,212,212,176,140,108,108,108,76,76,76,76,76,76,44,44,44,44,44
		,136,136,136,136,104,68,68,72,72,76,44,44,45,45,40,40,40,40,40,40,40,40,40,40,40,40,40,40,41,41,40,40,40,40,40,40,72,72,72,72,72,68,104,140,208,212,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,208,208,212,208,176,140,108,108,76,76,76,76,76,76,76,44,44,44,44,44,44
		,136,136,136,136,104,68,68,72,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,72,72,72,72,68,104,172,212,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,208,176,176,140,140,108,108,108,76,76,76,76,76,76,44,44,44,44,44,44,44
		,136,136,136,136,100,68,68,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,72,72,72,68,104,176,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,208,172,140,136,104,104,104,76,76,76,76,76,76,44,44,44,44,44,44,44,44
		,136,136,136,104,68,36,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,72,72,72,72,140,208,245,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,208,172,136,104,104,104,76,76,76,76,76,44,44,44,44,44,44,44,44,44,44
		,136,136,136,104,68,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,41,40,40,40,40,40,40,40,36,36,36,40,40,40,72,72,72,104,140,212,249,248,248,248,248,248,248,248,244,248,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,248,248,248,248,248,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,212,176,140,104,104,104,76,76,76,76,44,44,44,44,44,44,44,44,44,44,44
		,136,136,104,68,68,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,8,4,4,4,4,36,40,72,72,72,72,108,176,213,249,248,248,248,248,248,248,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,244,244,208,140,104,104,104,76,76,76,76,44,44,44,44,44,44,44,44,44,44,44
		,136,136,104,68,68,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,8,4,4,4,4,4,40,40,72,72,72,72,140,176,213,248,248,248,248,248,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,212,212,212,212,212,244,244,244,248,248,248,248,248,248,248,248,248,244,244,244,212,176,104,104,104,76,76,76,76,44,44,44,44,44,44,44,44,44,44,44
		,137,136,104,68,36,40,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,4,4,4,4,4,36,40,40,72,72,72,72,140,212,244,244,248,248,248,248,244,244,212,212,212,208,208,208,212,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,208,208,176,172,172,176,208,212,244,244,248,248,248,248,248,248,248,248,248,248,244,212,176,140,104,104,76,76,76,76,44,44,44,44,44,44,44,44,44,44,44
		,137,104,100,68,36,72,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,4,4,4,4,4,40,40,72,72,72,72,104,176,212,244,244,248,248,248,244,244,212,208,208,176,172,140,136,172,208,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,212,208,176,176,172,136,136,136,172,208,212,244,248,248,248,248,248,248,248,248,248,248,248,244,212,176,108,72,76,76,76,76,44,44,44,44,44,44,44,44,44,44,44
		,136,104,68,68,68,72,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,4,4,4,4,36,40,40,72,72,72,72,108,176,212,244,244,248,244,244,244,244,212,176,176,176,172,136,100,136,172,208,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,212,176,208,209,209,136,100,100,136,172,208,244,244,248,248,248,248,248,248,248,248,248,248,244,212,176,108,76,76,76,76,76,44,76,76,76,44,44,44,44,44,44,44
		,136,104,68,36,72,72,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,41,40,40,40,40,40,40,40,40,40,40,40,40,40,72,72,72,72,72,140,180,244,244,244,248,248,248,244,244,208,176,176,209,208,136,100,100,136,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,208,176,208,245,245,172,100,100,100,136,176,212,244,248,248,248,248,248,248,248,248,248,244,244,245,212,140,104,72,76,76,76,76,76,76,76,80,80,80,80,80,80,80
		,136,104,68,36,40,72,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,41,40,40,40,40,40,40,40,40,40,40,40,40,44,76,76,72,72,104,140,212,244,244,248,248,248,248,244,212,208,172,172,209,209,168,100,96,100,172,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,172,172,213,213,172,100,100,100,136,172,212,244,244,248,244,248,248,248,248,248,248,244,244,245,213,144,104,72,72,76,76,80,80,80,80,80,80,80,80,80,80,80
		,104,68,68,36,40,72,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,44,40,40,40,40,40,44,77,77,77,76,76,72,72,104,176,212,244,244,244,244,244,244,244,212,176,136,136,172,172,100,64,64,100,140,208,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,140,136,172,168,100,100,64,100,136,172,212,244,244,244,244,248,248,248,248,248,244,244,244,245,213,176,108,72,72,76,76,80,80,80,80,80,80,80,80,80,80,80
		,104,68,36,36,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,44,44,76,76,77,76,76,72,72,104,176,212,244,244,244,244,244,244,244,212,176,136,100,132,100,96,64,64,100,136,208,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,140,100,100,100,64,64,64,100,136,172,212,244,244,244,244,244,248,248,244,244,244,244,244,244,245,212,140,72,72,76,80,80,80,80,80,80,80,80,80,80,80,80
		,104,68,36,36,40,40,40,40,40,40,40,40,40,40,40,40,4,4,4,4,8,40,40,40,40,40,40,44,40,40,44,44,76,76,76,76,76,72,72,108,180,212,244,244,244,244,244,244,244,212,208,172,100,100,100,64,64,64,100,140,208,244,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,172,104,100,100,64,64,64,100,136,176,212,244,244,248,244,244,248,248,244,244,244,244,244,244,244,212,140,72,72,76,80,80,80,80,80,80,80,80,80,80,80,80
		,68,68,36,40,40,40,40,40,40,40,8,8,8,4,4,4,4,4,4,4,4,4,40,40,40,40,40,44,40,44,44,44,76,76,76,76,76,72,72,140,212,244,244,244,244,244,244,244,244,244,212,208,136,100,100,96,64,64,100,172,208,244,248,244,248,248,248,248,248,248,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,212,208,140,100,100,100,100,100,100,140,208,212,244,244,248,244,244,244,244,244,244,244,244,244,244,244,212,176,108,72,76,80,80,80,80,80,80,80,80,80,80,80,80
		,68,36,36,40,40,40,40,40,40,40,4,4,4,4,4,4,4,4,4,4,4,4,4,40,40,40,40,44,44,44,44,44,76,76,76,76,76,72,72,140,212,244,244,244,244,244,244,244,244,244,244,212,172,136,136,100,100,100,136,172,212,244,244,244,248,248,248,248,248,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,176,172,136,136,100,100,136,172,212,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,176,108,72,76,80,80,80,80,80,80,80,80,80,80,80,80
		,68,36,36,40,40,40,40,40,40,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,40,40,40,44,44,44,44,44,44,76,76,76,72,72,104,176,213,244,244,244,244,244,248,248,248,248,248,244,212,208,172,172,172,172,172,208,212,244,244,244,248,248,248,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,212,208,208,172,172,172,172,208,212,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,140,72,76,80,80,80,80,80,80,80,80,80,80,80,80
		,36,36,40,40,40,40,40,40,8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,40,40,44,44,44,44,44,44,44,76,76,76,72,72,108,176,245,244,244,244,244,244,244,248,248,248,248,244,244,244,212,208,208,208,208,212,244,244,248,248,248,244,244,244,212,208,212,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,212,208,208,212,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,140,104,76,112,80,80,80,80,80,80,80,80,80,80,80
		,36,36,40,40,40,40,40,40,8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,40,40,44,44,44,44,44,44,76,76,76,76,72,72,140,213,245,244,244,244,244,244,244,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,248,248,244,244,208,208,172,172,172,176,208,212,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,144,108,76,112,80,80,80,80,80,80,80,80,80,80,80
		,36,36,72,40,40,40,40,40,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,40,40,44,44,44,44,44,76,76,76,76,72,72,72,140,213,245,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,248,248,244,244,208,172,136,100,100,136,140,176,212,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,176,108,76,112,112,80,80,80,80,80,80,80,80,80,80
		,36,72,72,40,40,40,40,40,8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,40,40,44,44,44,44,44,76,76,76,76,72,72,104,140,209,208,244,244,245,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,212,176,136,100,100,100,136,172,212,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,244,176,108,108,112,112,80,80,80,80,80,80,80,80,80,80
		,36,72,72,40,40,40,40,40,40,4,4,4,4,4,4,4,4,4,4,4,4,4,4,40,40,40,44,44,44,44,44,76,76,76,76,72,72,104,136,172,204,204,208,240,240,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,212,208,172,172,136,172,176,212,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,240,240,240,240,240,240,244,244,244,244,244,244,244,244,212,140,108,112,112,80,80,80,80,80,80,80,80,80,80
		,40,72,76,44,44,40,40,40,40,8,8,4,4,4,4,4,4,4,4,4,4,4,4,40,40,44,44,44,45,45,76,76,76,76,76,72,68,68,100,132,164,168,168,204,204,240,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,208,208,208,212,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,240,240,208,204,204,204,204,204,208,240,244,244,244,244,244,244,244,212,144,108,108,112,112,80,80,80,80,80,80,80,80,80
		,72,72,76,44,44,40,40,40,40,40,8,8,8,8,4,4,4,4,4,4,8,8,40,40,44,44,44,44,45,77,77,76,76,76,72,68,68,64,100,132,132,132,164,168,168,204,208,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,208,204,172,168,204,200,200,168,204,204,208,244,244,244,244,244,244,212,144,108,76,112,112,112,80,80,80,80,80,80,80,80
		,72,76,44,44,44,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,44,44,76,76,76,77,77,76,76,76,76,72,68,68,100,132,164,164,164,164,164,168,168,204,240,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,240,204,168,168,168,200,200,200,200,200,200,204,208,244,244,244,244,244,212,176,108,76,108,112,80,80,80,80,80,80,80,80,80
		,72,76,76,44,44,44,40,40,40,40,40,40,40,40,45,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,76,76,76,76,72,68,100,136,168,200,200,200,200,168,168,168,204,208,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,244,244,244,244,244,240,204,200,168,200,200,200,200,200,168,168,172,208,244,244,244,244,244,212,180,108,76,108,112,80,80,80,80,80,80,80,80,80
		,72,76,44,44,44,44,44,45,45,45,45,45,45,45,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,76,76,76,76,72,68,100,136,168,200,200,200,200,200,200,168,172,208,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,244,244,244,244,244,208,204,200,200,200,200,200,200,200,200,168,168,204,208,244,244,244,244,212,212,144,108,108,112,112,80,80,80,80,80,80,80,80
		,72,76,44,44,44,44,44,45,45,45,45,45,45,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,77,76,76,76,72,68,68,100,168,168,200,200,200,200,200,200,168,204,208,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,245,245,245,244,244,245,245,245,245,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,244,244,244,244,240,204,200,200,200,200,200,200,200,200,200,168,168,172,208,244,244,244,244,244,212,144,108,76,80,112,80,80,80,80,80,80,80,80
		,40,76,44,44,44,44,44,44,44,45,45,45,45,45,45,45,45,45,44,44,44,77,77,77,77,77,77,77,77,76,76,76,76,72,68,68,100,168,200,200,200,200,200,200,200,200,204,208,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,245,245,241,240,240,240,240,240,240,245,245,244,244,244,244,244,248,248,248,248,248,248,248,248,244,244,244,244,244,240,204,200,200,200,200,200,200,200,200,200,200,168,172,208,244,244,244,244,244,212,180,108,76,76,80,80,80,80,80,80,80,80,80
		,40,44,44,44,44,44,44,44,44,45,45,45,45,45,45,45,44,44,44,44,44,77,77,77,77,77,77,77,76,76,76,76,76,72,36,68,100,168,168,200,200,200,200,200,200,200,204,208,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,208,208,204,172,172,172,172,172,204,204,208,240,240,244,244,244,244,248,248,248,248,248,248,248,248,244,244,244,244,244,240,204,168,200,200,200,200,200,200,200,200,200,168,168,208,244,244,244,244,244,212,180,140,72,76,76,80,80,80,80,80,80,80,80
		,40,44,44,44,44,44,44,44,44,44,44,44,45,45,44,44,44,44,44,44,44,44,77,77,77,77,77,77,77,76,76,76,76,40,36,68,100,136,168,200,200,200,200,200,200,200,204,240,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,212,208,172,136,132,132,132,132,168,168,168,168,172,204,204,208,240,244,244,248,248,248,244,244,248,248,248,244,244,244,244,244,240,204,200,200,200,200,200,200,200,200,200,200,168,172,208,244,244,244,244,244,212,212,144,108,76,76,76,80,80,80,80,80,80,80
		,40,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,45,77,77,77,77,77,77,77,77,76,76,40,36,68,100,136,168,200,200,200,200,200,200,200,204,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,244,244,208,172,136,100,100,132,132,168,204,204,204,204,168,168,204,204,208,244,244,244,244,248,248,248,248,248,248,244,244,244,244,244,240,204,200,200,200,200,200,200,200,200,200,200,168,204,208,244,244,244,244,244,212,212,176,108,76,76,76,76,80,80,80,80,80,48
		,40,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,76,76,72,40,68,104,104,136,168,168,200,200,200,200,200,204,240,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,244,244,208,168,132,100,132,168,204,204,237,237,236,204,204,204,204,204,208,244,244,244,244,248,248,248,248,248,248,248,244,244,244,244,244,208,204,200,200,200,200,200,200,200,200,200,200,204,240,244,244,244,244,244,212,212,176,108,72,76,76,76,76,80,80,80,80,76
		,76,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,40,40,72,104,140,136,168,164,164,168,168,168,168,204,240,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,136,100,132,168,204,205,241,241,241,241,241,241,236,204,204,204,208,244,244,244,244,248,248,248,248,248,244,244,244,244,244,244,240,204,200,200,200,200,200,200,200,200,200,204,208,244,244,244,244,244,244,244,213,213,140,72,76,76,76,76,80,80,80,80,80
		,76,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,40,72,140,177,172,168,168,168,168,168,172,204,208,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,136,132,132,168,205,241,241,241,241,241,241,241,241,204,204,204,208,244,244,244,244,244,248,248,244,244,244,244,244,244,244,244,240,208,204,168,200,200,200,200,200,200,204,204,240,244,244,244,244,244,244,244,212,213,144,104,76,76,76,80,80,80,80,80,80
		,77,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,40,40,72,140,209,213,208,204,204,204,204,208,240,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,208,168,132,168,204,205,241,241,241,237,241,241,241,241,204,204,204,208,244,244,244,244,244,248,248,244,244,244,244,244,244,244,244,244,240,208,204,204,204,204,204,204,204,204,240,244,244,244,244,244,244,244,244,248,213,176,108,76,108,80,80,80,80,80,80,80
		,77,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,40,40,72,108,213,245,245,241,240,240,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,208,172,136,168,204,241,241,241,241,237,241,241,241,241,204,204,204,208,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,208,240,240,240,240,240,240,240,244,244,244,244,244,244,244,244,244,248,249,212,140,108,108,112,80,80,80,80,80,80
		,76,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,40,40,72,108,177,245,245,245,245,245,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,212,172,168,168,204,241,241,241,241,241,241,241,241,241,204,204,204,208,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,244,249,213,144,108,108,112,112,80,80,80,80,80
		,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,40,40,72,104,177,213,245,245,245,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,168,168,204,209,241,241,241,241,241,241,241,241,204,204,204,208,244,244,244,244,244,244,244,244,244,244,244,244,244,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,244,244,212,176,104,108,112,112,80,80,80,80,80
		,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,72,140,213,213,245,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,208,172,168,168,204,205,237,241,241,241,241,241,204,204,204,204,208,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,244,244,244,176,108,108,112,112,80,80,80,80,80
		,76,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,40,40,72,108,176,213,245,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,172,168,168,204,204,237,237,237,241,204,204,168,172,204,240,244,244,248,244,244,244,248,248,248,248,244,244,244,244,244,244,244,244,248,244,248,244,244,244,244,244,244,244,244,244,244,248,248,248,248,244,244,244,176,140,108,108,112,112,80,80,80,76
		,77,76,76,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,76,72,72,104,144,213,245,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,172,172,168,168,168,204,200,200,168,168,168,172,208,244,244,244,248,244,244,244,248,248,248,248,248,244,248,248,244,244,248,244,248,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,244,244,244,212,140,108,108,112,80,80,80,76,76
		,77,76,76,76,44,77,77,44,44,44,44,44,44,44,44,44,44,44,44,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,76,72,72,140,180,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,208,208,204,172,168,168,168,168,168,172,172,208,240,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,144,104,76,108,76,76,76,76,76
		,76,76,44,44,44,76,77,81,81,77,76,44,44,44,76,80,81,81,81,81,81,81,81,81,80,80,80,80,80,80,80,80,80,80,76,76,72,108,176,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,208,208,208,208,204,204,208,208,208,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,176,108,76,76,76,76,76,76,76
		,44,44,44,44,44,44,77,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,80,80,80,80,80,80,112,112,108,76,104,140,176,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,212,176,108,76,76,76,76,76,76,76
		,40,40,44,44,44,44,77,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,81,80,80,80,80,80,80,80,80,112,113,112,108,72,108,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,248,248,248,248,248,248,244,244,244,244,244,244,244,244,212,176,108,76,76,76,76,76,76,76
		,40,40,40,40,44,44,44,76,80,81,81,81,81,81,81,81,81,81,81,81,81,80,80,80,80,80,80,80,80,80,80,80,80,80,80,76,76,76,104,140,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,208,140,104,76,76,76,76,76,76
		,40,40,40,40,44,44,44,44,76,80,80,81,81,81,81,81,81,81,81,81,81,80,80,80,80,80,80,80,80,80,80,80,80,76,76,76,76,76,104,140,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,244,244,248,248,248,248,248,248,248,244,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,212,140,104,76,76,76,76,76,76
		,40,40,40,40,44,44,44,44,44,44,44,44,44,76,81,81,81,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,76,76,44,76,76,76,104,140,176,212,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,212,140,104,76,76,76,76,76,76
		,40,40,40,40,44,44,44,44,44,44,44,44,44,44,44,44,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,76,44,44,44,76,76,108,108,140,208,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,244,248,248,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,212,176,108,72,76,76,76,76,76
		,40,40,40,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,80,80,80,80,80,80,80,80,80,80,80,80,80,80,76,76,44,76,76,108,108,108,140,176,212,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,244,244,244,244,244,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,248,244,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,244,244,244,244,212,176,108,72,76,76,76,76,76};
