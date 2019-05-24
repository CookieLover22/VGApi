
#include "lvgl/lvgl.h"

/***********************************************************************************
 * arial.ttf 8 px Font in U+0020 ( ) .. U+007f ()  range with 1 bpp
***********************************************************************************/

/*Store the image of the letters (glyph)*/
static const uint8_t Arial Bold.c_glyph_bitmap[] = 
{
  /*Unicode: U+0020 ( ) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0021 (!) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+0022 (") , Width: 2 */
  0x00,  //.. 
  0xc0,  //%% 
  0xc0,  //%% 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0023 (#) , Width: 4 */
  0x00,  //.... 
  0x50,  //.%.% 
  0xf0,  //%%%% 
  0x00,  //.... 
  0xf0,  //%%%% 
  0xa0,  //%.%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0024 ($) , Width: 3 */
  0x00,  //... 
  0x60,  //.%% 
  0x40,  //.%. 
  0x60,  //.%% 
  0xe0,  //%%% 
  0xc0,  //%%. 
  0x40,  //.%. 
  0x00,  //... 


  /*Unicode: U+0025 (%) , Width: 6 */
  0x00,  //...... 
  0x48,  //.%..%. 
  0xf0,  //%%%%.. 
  0x78,  //.%%%%. 
  0x3c,  //..%%%% 
  0x28,  //..%.%. 
  0x00,  //...... 
  0x00,  //...... 


  /*Unicode: U+0026 (&) , Width: 5 */
  0x00,  //..... 
  0x70,  //.%%%. 
  0x50,  //.%.%. 
  0x60,  //.%%.. 
  0x90,  //%..%. 
  0x68,  //.%%.% 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0027 (') , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+0028 (() , Width: 3 */
  0x00,  //... 
  0x40,  //.%. 
  0x40,  //.%. 
  0x80,  //%.. 
  0x80,  //%.. 
  0x40,  //.%. 
  0x40,  //.%. 
  0x00,  //... 


  /*Unicode: U+0029 ()) , Width: 2 */
  0x00,  //.. 
  0x80,  //%. 
  0x80,  //%. 
  0x40,  //.% 
  0x40,  //.% 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 


  /*Unicode: U+002a (*) , Width: 3 */
  0x00,  //... 
  0x40,  //.%. 
  0x40,  //.%. 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+002b (+) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x40,  //.%. 
  0xe0,  //%%% 
  0x40,  //.%. 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+002c (,) , Width: 1 */
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 


  /*Unicode: U+002d (-) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0xc0,  //%% 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+002e (.) , Width: 1 */
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x00,  //. 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+002f (/) , Width: 2 */
  0x00,  //.. 
  0x40,  //.% 
  0x40,  //.% 
  0x00,  //.. 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0030 (0) , Width: 4 */
  0x00,  //.... 
  0xf0,  //%%%% 
  0x90,  //%..% 
  0x90,  //%..% 
  0x90,  //%..% 
  0xf0,  //%%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0031 (1) , Width: 2 */
  0x00,  //.. 
  0x40,  //.% 
  0x40,  //.% 
  0x40,  //.% 
  0x40,  //.% 
  0x40,  //.% 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0032 (2) , Width: 4 */
  0x00,  //.... 
  0xe0,  //%%%. 
  0x10,  //...% 
  0x20,  //..%. 
  0x40,  //.%.. 
  0xf0,  //%%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0033 (3) , Width: 4 */
  0x00,  //.... 
  0xe0,  //%%%. 
  0x10,  //...% 
  0x30,  //..%% 
  0x10,  //...% 
  0xe0,  //%%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0034 (4) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x40,  //.%. 
  0xc0,  //%%. 
  0xe0,  //%%% 
  0x40,  //.%. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0035 (5) , Width: 4 */
  0x00,  //.... 
  0x70,  //.%%% 
  0x40,  //.%.. 
  0xf0,  //%%%% 
  0x10,  //...% 
  0xe0,  //%%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0036 (6) , Width: 4 */
  0x00,  //.... 
  0x70,  //.%%% 
  0x80,  //%... 
  0xf0,  //%%%% 
  0x90,  //%..% 
  0x60,  //.%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0037 (7) , Width: 3 */
  0x00,  //... 
  0xe0,  //%%% 
  0x20,  //..% 
  0x40,  //.%. 
  0x40,  //.%. 
  0x40,  //.%. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0038 (8) , Width: 4 */
  0x00,  //.... 
  0x60,  //.%%. 
  0x90,  //%..% 
  0x60,  //.%%. 
  0x90,  //%..% 
  0x60,  //.%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0039 (9) , Width: 4 */
  0x00,  //.... 
  0x60,  //.%%. 
  0x90,  //%..% 
  0xf0,  //%%%% 
  0x10,  //...% 
  0xe0,  //%%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+003a (:) , Width: 1 */
  0x00,  //. 
  0x00,  //. 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+003b (;) , Width: 1 */
  0x00,  //. 
  0x00,  //. 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 


  /*Unicode: U+003c (<) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x20,  //..% 
  0xc0,  //%%. 
  0x20,  //..% 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+003d (=) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0xe0,  //%%% 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+003e (>) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x80,  //%.. 
  0x60,  //.%% 
  0x80,  //%.. 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+003f (?) , Width: 4 */
  0x00,  //.... 
  0xf0,  //%%%% 
  0x10,  //...% 
  0x20,  //..%. 
  0x00,  //.... 
  0x20,  //..%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0040 (@) , Width: 6 */
  0x00,  //...... 
  0x78,  //.%%%%. 
  0xfc,  //%%%%%% 
  0xdc,  //%%.%%% 
  0xd4,  //%%.%.% 
  0xfc,  //%%%%%% 
  0x78,  //.%%%%. 
  0x00,  //...... 


  /*Unicode: U+0041 (A) , Width: 5 */
  0x00,  //..... 
  0x20,  //..%.. 
  0x70,  //.%%%. 
  0x70,  //.%%%. 
  0x50,  //.%.%. 
  0x88,  //%...% 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0042 (B) , Width: 3 */
  0x00,  //... 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0043 (C) , Width: 4 */
  0x00,  //.... 
  0x60,  //.%%. 
  0x90,  //%..% 
  0x80,  //%... 
  0x90,  //%..% 
  0x60,  //.%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0044 (D) , Width: 3 */
  0x00,  //... 
  0xc0,  //%%. 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xc0,  //%%. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0045 (E) , Width: 4 */
  0x00,  //.... 
  0xf0,  //%%%% 
  0x80,  //%... 
  0xf0,  //%%%% 
  0x80,  //%... 
  0xf0,  //%%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0046 (F) , Width: 2 */
  0x00,  //.. 
  0xc0,  //%% 
  0x80,  //%. 
  0xc0,  //%% 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0047 (G) , Width: 5 */
  0x00,  //..... 
  0x70,  //.%%%. 
  0x80,  //%.... 
  0x98,  //%..%% 
  0x88,  //%...% 
  0x70,  //.%%%. 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0048 (H) , Width: 3 */
  0x00,  //... 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0049 (I) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+004a (J) , Width: 3 */
  0x00,  //... 
  0x20,  //..% 
  0x20,  //..% 
  0x20,  //..% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+004b (K) , Width: 4 */
  0x00,  //.... 
  0x80,  //%... 
  0x80,  //%... 
  0xc0,  //%%.. 
  0xa0,  //%.%. 
  0x90,  //%..% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+004c (L) , Width: 3 */
  0x00,  //... 
  0x80,  //%.. 
  0x80,  //%.. 
  0x80,  //%.. 
  0x80,  //%.. 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+004d (M) , Width: 5 */
  0x00,  //..... 
  0xd8,  //%%.%% 
  0xd8,  //%%.%% 
  0xd8,  //%%.%% 
  0xf8,  //%%%%% 
  0xa8,  //%.%.% 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+004e (N) , Width: 3 */
  0x00,  //... 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0xe0,  //%%% 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+004f (O) , Width: 4 */
  0x00,  //.... 
  0x60,  //.%%. 
  0x90,  //%..% 
  0x90,  //%..% 
  0x90,  //%..% 
  0x60,  //.%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0050 (P) , Width: 3 */
  0x00,  //... 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x80,  //%.. 
  0x80,  //%.. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0051 (Q) , Width: 4 */
  0x00,  //.... 
  0x60,  //.%%. 
  0x90,  //%..% 
  0x90,  //%..% 
  0xa0,  //%.%. 
  0x70,  //.%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0052 (R) , Width: 4 */
  0x00,  //.... 
  0xe0,  //%%%. 
  0xa0,  //%.%. 
  0xe0,  //%%%. 
  0xa0,  //%.%. 
  0x80,  //%... 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0053 (S) , Width: 5 */
  0x00,  //..... 
  0x70,  //.%%%. 
  0x88,  //%...% 
  0x30,  //..%%. 
  0x88,  //%...% 
  0x70,  //.%%%. 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0054 (T) , Width: 5 */
  0x00,  //..... 
  0xf8,  //%%%%% 
  0x20,  //..%.. 
  0x20,  //..%.. 
  0x20,  //..%.. 
  0x20,  //..%.. 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0055 (U) , Width: 3 */
  0x00,  //... 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xc0,  //%%. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0056 (V) , Width: 5 */
  0x00,  //..... 
  0x88,  //%...% 
  0x50,  //.%.%. 
  0x50,  //.%.%. 
  0x50,  //.%.%. 
  0x20,  //..%.. 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0057 (W) , Width: 7 */
  0x00,  //....... 
  0x92,  //%..%..% 
  0xaa,  //%.%.%.% 
  0xaa,  //%.%.%.% 
  0xee,  //%%%.%%% 
  0x44,  //.%...%. 
  0x00,  //....... 
  0x00,  //....... 


  /*Unicode: U+0058 (X) , Width: 5 */
  0x00,  //..... 
  0x88,  //%...% 
  0x50,  //.%.%. 
  0x20,  //..%.. 
  0x50,  //.%.%. 
  0x88,  //%...% 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0059 (Y) , Width: 5 */
  0x00,  //..... 
  0x88,  //%...% 
  0x50,  //.%.%. 
  0x20,  //..%.. 
  0x20,  //..%.. 
  0x20,  //..%.. 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+005a (Z) , Width: 4 */
  0x00,  //.... 
  0xf0,  //%%%% 
  0x00,  //.... 
  0x40,  //.%.. 
  0x80,  //%... 
  0xf0,  //%%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+005b ([) , Width: 2 */
  0x00,  //.. 
  0xc0,  //%% 
  0x80,  //%. 
  0x80,  //%. 
  0x80,  //%. 
  0x80,  //%. 
  0xc0,  //%% 
  0x00,  //.. 


  /*Unicode: U+005c (\) , Width: 2 */
  0x00,  //.. 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 
  0x40,  //.% 
  0x40,  //.% 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+005d (]) , Width: 2 */
  0x00,  //.. 
  0xc0,  //%% 
  0x40,  //.% 
  0x40,  //.% 
  0x40,  //.% 
  0x40,  //.% 
  0xc0,  //%% 
  0x00,  //.. 


  /*Unicode: U+005e (^) , Width: 3 */
  0x00,  //... 
  0x40,  //.%. 
  0x40,  //.%. 
  0xa0,  //%.% 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+005f (_) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0x00,  //.... 
  0xf0,  //%%%% 
  0x00,  //.... 


  /*Unicode: U+0060 (`) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0061 (a) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0xf0,  //%%%% 
  0x70,  //.%%% 
  0x90,  //%..% 
  0xf0,  //%%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0062 (b) , Width: 3 */
  0x00,  //... 
  0x80,  //%.. 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0063 (c) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x70,  //.%%% 
  0x80,  //%... 
  0x80,  //%... 
  0x70,  //.%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0064 (d) , Width: 3 */
  0x00,  //... 
  0x20,  //..% 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0065 (e) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x40,  //.%. 
  0xe0,  //%%% 
  0x80,  //%.. 
  0x60,  //.%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0066 (f) , Width: 3 */
  0x00,  //... 
  0x20,  //..% 
  0xc0,  //%%. 
  0x40,  //.%. 
  0x40,  //.%. 
  0x40,  //.%. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0067 (g) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0xe0,  //%%% 
  0x00,  //... 


  /*Unicode: U+0068 (h) , Width: 4 */
  0x00,  //.... 
  0x80,  //%... 
  0xe0,  //%%%. 
  0x90,  //%..% 
  0x90,  //%..% 
  0x90,  //%..% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0069 (i) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+006a (j) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+006b (k) , Width: 3 */
  0x00,  //... 
  0x80,  //%.. 
  0xa0,  //%.% 
  0xc0,  //%%. 
  0xc0,  //%%. 
  0xa0,  //%.% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+006c (l) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+006d (m) , Width: 5 */
  0x00,  //..... 
  0x00,  //..... 
  0xf0,  //%%%%. 
  0xa8,  //%.%.% 
  0xa8,  //%.%.% 
  0xa8,  //%.%.% 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+006e (n) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0xe0,  //%%%. 
  0x90,  //%..% 
  0x90,  //%..% 
  0x90,  //%..% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+006f (o) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x60,  //.%%. 
  0x90,  //%..% 
  0x90,  //%..% 
  0x60,  //.%%. 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0070 (p) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x80,  //%.. 
  0x00,  //... 


  /*Unicode: U+0071 (q) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xe0,  //%%% 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x20,  //..% 
  0x00,  //... 


  /*Unicode: U+0072 (r) , Width: 2 */
  0x00,  //.. 
  0x00,  //.. 
  0xc0,  //%% 
  0x80,  //%. 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 
  0x00,  //.. 


  /*Unicode: U+0073 (s) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x60,  //.%% 
  0xc0,  //%%. 
  0x60,  //.%% 
  0xc0,  //%%. 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0074 (t) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x00,  //. 
  0x00,  //. 


  /*Unicode: U+0075 (u) , Width: 4 */
  0x00,  //.... 
  0x00,  //.... 
  0x90,  //%..% 
  0x90,  //%..% 
  0x90,  //%..% 
  0x70,  //.%%% 
  0x00,  //.... 
  0x00,  //.... 


  /*Unicode: U+0076 (v) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xa0,  //%.% 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0077 (w) , Width: 5 */
  0x00,  //..... 
  0x00,  //..... 
  0xa8,  //%.%.% 
  0xf8,  //%%%%% 
  0xf8,  //%%%%% 
  0x70,  //.%%%. 
  0x00,  //..... 
  0x00,  //..... 


  /*Unicode: U+0078 (x) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xa0,  //%.% 
  0x40,  //.%. 
  0x40,  //.%. 
  0xa0,  //%.% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+0079 (y) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xa0,  //%.% 
  0xe0,  //%%% 
  0x40,  //.%. 
  0x40,  //.%. 
  0xc0,  //%%. 
  0x00,  //... 


  /*Unicode: U+007a (z) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0xe0,  //%%% 
  0x40,  //.%. 
  0x40,  //.%. 
  0xe0,  //%%% 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+007b ({) , Width: 3 */
  0x00,  //... 
  0x60,  //.%% 
  0x40,  //.%. 
  0x80,  //%.. 
  0x40,  //.%. 
  0x40,  //.%. 
  0x60,  //.%% 
  0x00,  //... 


  /*Unicode: U+007c (|) , Width: 1 */
  0x00,  //. 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 
  0x80,  //% 


  /*Unicode: U+007d (}) , Width: 2 */
  0x00,  //.. 
  0x80,  //%. 
  0x80,  //%. 
  0x40,  //.% 
  0x80,  //%. 
  0x80,  //%. 
  0x80,  //%. 
  0x00,  //.. 


  /*Unicode: U+007e (~) , Width: 3 */
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 
  0xc0,  //%%. 
  0x60,  //.%% 
  0x00,  //... 
  0x00,  //... 
  0x00,  //... 


  /*Unicode: U+007f () , Width: 5 */
  0x00,  //..... 
  0x00,  //..... 
  0x00,  //..... 
  0x00,  //..... 
  0x00,  //..... 
  0x00,  //..... 
  0x00,  //..... 
  0x00,  //..... 


};


/*Store the glyph descriptions*/
static const lv_font_glyph_dsc_t Arial Bold.c_glyph_dsc[] = 
{
  {.w_px = 3,	.glyph_index = 0},	/*Unicode: U+0020 ( )*/
  {.w_px = 1,	.glyph_index = 8},	/*Unicode: U+0021 (!)*/
  {.w_px = 2,	.glyph_index = 16},	/*Unicode: U+0022 (")*/
  {.w_px = 4,	.glyph_index = 24},	/*Unicode: U+0023 (#)*/
  {.w_px = 3,	.glyph_index = 32},	/*Unicode: U+0024 ($)*/
  {.w_px = 6,	.glyph_index = 40},	/*Unicode: U+0025 (%)*/
  {.w_px = 5,	.glyph_index = 48},	/*Unicode: U+0026 (&)*/
  {.w_px = 1,	.glyph_index = 56},	/*Unicode: U+0027 (')*/
  {.w_px = 3,	.glyph_index = 64},	/*Unicode: U+0028 (()*/
  {.w_px = 2,	.glyph_index = 72},	/*Unicode: U+0029 ())*/
  {.w_px = 3,	.glyph_index = 80},	/*Unicode: U+002a (*)*/
  {.w_px = 3,	.glyph_index = 88},	/*Unicode: U+002b (+)*/
  {.w_px = 1,	.glyph_index = 96},	/*Unicode: U+002c (,)*/
  {.w_px = 2,	.glyph_index = 104},	/*Unicode: U+002d (-)*/
  {.w_px = 1,	.glyph_index = 112},	/*Unicode: U+002e (.)*/
  {.w_px = 2,	.glyph_index = 120},	/*Unicode: U+002f (/)*/
  {.w_px = 4,	.glyph_index = 128},	/*Unicode: U+0030 (0)*/
  {.w_px = 2,	.glyph_index = 136},	/*Unicode: U+0031 (1)*/
  {.w_px = 4,	.glyph_index = 144},	/*Unicode: U+0032 (2)*/
  {.w_px = 4,	.glyph_index = 152},	/*Unicode: U+0033 (3)*/
  {.w_px = 3,	.glyph_index = 160},	/*Unicode: U+0034 (4)*/
  {.w_px = 4,	.glyph_index = 168},	/*Unicode: U+0035 (5)*/
  {.w_px = 4,	.glyph_index = 176},	/*Unicode: U+0036 (6)*/
  {.w_px = 3,	.glyph_index = 184},	/*Unicode: U+0037 (7)*/
  {.w_px = 4,	.glyph_index = 192},	/*Unicode: U+0038 (8)*/
  {.w_px = 4,	.glyph_index = 200},	/*Unicode: U+0039 (9)*/
  {.w_px = 1,	.glyph_index = 208},	/*Unicode: U+003a (:)*/
  {.w_px = 1,	.glyph_index = 216},	/*Unicode: U+003b (;)*/
  {.w_px = 3,	.glyph_index = 224},	/*Unicode: U+003c (<)*/
  {.w_px = 3,	.glyph_index = 232},	/*Unicode: U+003d (=)*/
  {.w_px = 3,	.glyph_index = 240},	/*Unicode: U+003e (>)*/
  {.w_px = 4,	.glyph_index = 248},	/*Unicode: U+003f (?)*/
  {.w_px = 6,	.glyph_index = 256},	/*Unicode: U+0040 (@)*/
  {.w_px = 5,	.glyph_index = 264},	/*Unicode: U+0041 (A)*/
  {.w_px = 3,	.glyph_index = 272},	/*Unicode: U+0042 (B)*/
  {.w_px = 4,	.glyph_index = 280},	/*Unicode: U+0043 (C)*/
  {.w_px = 3,	.glyph_index = 288},	/*Unicode: U+0044 (D)*/
  {.w_px = 4,	.glyph_index = 296},	/*Unicode: U+0045 (E)*/
  {.w_px = 2,	.glyph_index = 304},	/*Unicode: U+0046 (F)*/
  {.w_px = 5,	.glyph_index = 312},	/*Unicode: U+0047 (G)*/
  {.w_px = 3,	.glyph_index = 320},	/*Unicode: U+0048 (H)*/
  {.w_px = 1,	.glyph_index = 328},	/*Unicode: U+0049 (I)*/
  {.w_px = 3,	.glyph_index = 336},	/*Unicode: U+004a (J)*/
  {.w_px = 4,	.glyph_index = 344},	/*Unicode: U+004b (K)*/
  {.w_px = 3,	.glyph_index = 352},	/*Unicode: U+004c (L)*/
  {.w_px = 5,	.glyph_index = 360},	/*Unicode: U+004d (M)*/
  {.w_px = 3,	.glyph_index = 368},	/*Unicode: U+004e (N)*/
  {.w_px = 4,	.glyph_index = 376},	/*Unicode: U+004f (O)*/
  {.w_px = 3,	.glyph_index = 384},	/*Unicode: U+0050 (P)*/
  {.w_px = 4,	.glyph_index = 392},	/*Unicode: U+0051 (Q)*/
  {.w_px = 4,	.glyph_index = 400},	/*Unicode: U+0052 (R)*/
  {.w_px = 5,	.glyph_index = 408},	/*Unicode: U+0053 (S)*/
  {.w_px = 5,	.glyph_index = 416},	/*Unicode: U+0054 (T)*/
  {.w_px = 3,	.glyph_index = 424},	/*Unicode: U+0055 (U)*/
  {.w_px = 5,	.glyph_index = 432},	/*Unicode: U+0056 (V)*/
  {.w_px = 7,	.glyph_index = 440},	/*Unicode: U+0057 (W)*/
  {.w_px = 5,	.glyph_index = 448},	/*Unicode: U+0058 (X)*/
  {.w_px = 5,	.glyph_index = 456},	/*Unicode: U+0059 (Y)*/
  {.w_px = 4,	.glyph_index = 464},	/*Unicode: U+005a (Z)*/
  {.w_px = 2,	.glyph_index = 472},	/*Unicode: U+005b ([)*/
  {.w_px = 2,	.glyph_index = 480},	/*Unicode: U+005c (\)*/
  {.w_px = 2,	.glyph_index = 488},	/*Unicode: U+005d (])*/
  {.w_px = 3,	.glyph_index = 496},	/*Unicode: U+005e (^)*/
  {.w_px = 4,	.glyph_index = 504},	/*Unicode: U+005f (_)*/
  {.w_px = 2,	.glyph_index = 512},	/*Unicode: U+0060 (`)*/
  {.w_px = 4,	.glyph_index = 520},	/*Unicode: U+0061 (a)*/
  {.w_px = 3,	.glyph_index = 528},	/*Unicode: U+0062 (b)*/
  {.w_px = 4,	.glyph_index = 536},	/*Unicode: U+0063 (c)*/
  {.w_px = 3,	.glyph_index = 544},	/*Unicode: U+0064 (d)*/
  {.w_px = 3,	.glyph_index = 552},	/*Unicode: U+0065 (e)*/
  {.w_px = 3,	.glyph_index = 560},	/*Unicode: U+0066 (f)*/
  {.w_px = 3,	.glyph_index = 568},	/*Unicode: U+0067 (g)*/
  {.w_px = 4,	.glyph_index = 576},	/*Unicode: U+0068 (h)*/
  {.w_px = 1,	.glyph_index = 584},	/*Unicode: U+0069 (i)*/
  {.w_px = 1,	.glyph_index = 592},	/*Unicode: U+006a (j)*/
  {.w_px = 3,	.glyph_index = 600},	/*Unicode: U+006b (k)*/
  {.w_px = 1,	.glyph_index = 608},	/*Unicode: U+006c (l)*/
  {.w_px = 5,	.glyph_index = 616},	/*Unicode: U+006d (m)*/
  {.w_px = 4,	.glyph_index = 624},	/*Unicode: U+006e (n)*/
  {.w_px = 4,	.glyph_index = 632},	/*Unicode: U+006f (o)*/
  {.w_px = 3,	.glyph_index = 640},	/*Unicode: U+0070 (p)*/
  {.w_px = 3,	.glyph_index = 648},	/*Unicode: U+0071 (q)*/
  {.w_px = 2,	.glyph_index = 656},	/*Unicode: U+0072 (r)*/
  {.w_px = 3,	.glyph_index = 664},	/*Unicode: U+0073 (s)*/
  {.w_px = 1,	.glyph_index = 672},	/*Unicode: U+0074 (t)*/
  {.w_px = 4,	.glyph_index = 680},	/*Unicode: U+0075 (u)*/
  {.w_px = 3,	.glyph_index = 688},	/*Unicode: U+0076 (v)*/
  {.w_px = 5,	.glyph_index = 696},	/*Unicode: U+0077 (w)*/
  {.w_px = 3,	.glyph_index = 704},	/*Unicode: U+0078 (x)*/
  {.w_px = 3,	.glyph_index = 712},	/*Unicode: U+0079 (y)*/
  {.w_px = 3,	.glyph_index = 720},	/*Unicode: U+007a (z)*/
  {.w_px = 3,	.glyph_index = 728},	/*Unicode: U+007b ({)*/
  {.w_px = 1,	.glyph_index = 736},	/*Unicode: U+007c (|)*/
  {.w_px = 2,	.glyph_index = 744},	/*Unicode: U+007d (})*/
  {.w_px = 3,	.glyph_index = 752},	/*Unicode: U+007e (~)*/
  {.w_px = 5,	.glyph_index = 760},	/*Unicode: U+007f ()*/
};

lv_font_t Arial Bold.c = 
{
    .unicode_first = 32,	/*First Unicode letter in this font*/
    .unicode_last = 127,	/*Last Unicode letter in this font*/
    .h_px = 8,				/*Font height in pixels*/
    .glyph_bitmap = Arial Bold.c_glyph_bitmap,	/*Bitmap of glyphs*/
    .glyph_dsc = Arial Bold.c_glyph_dsc,		/*Description of glyphs*/
    .glyph_cnt = 96,			/*Number of glyphs in the font*/
    .unicode_list = NULL,	/*Every character in the font from 'unicode_first' to 'unicode_last'*/
    .get_bitmap = lv_font_get_bitmap_continuous,	/*Function pointer to get glyph's bitmap*/
    .get_width = lv_font_get_width_continuous,	/*Function pointer to get glyph's width*/
    .bpp = 1,				/*Bit per pixel*/
    .monospace = 0,				/*Fix width (0: if not used)*/
    .next_page = NULL,		/*Pointer to a font extension*/
};