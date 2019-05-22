/**
 * File     : IO_draw.c
 * Datum    : 22.05.2019
 * Version  : 1.0
 * Autor    : Dani�l Boon
 * CPU      : STM32F4
 * IDE      : CooCox CoIDE 1.7.8
 * Module   : CMSIS_BOOT, M4_CMSIS_CORE
 * Function : drawing figures with UB_VGA_SetPixel()
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "IO_draw.h"
#include "stm32_ub_vga_screen.h"
#include "bitmap.h"
#include "font8x8_basic.h"
#include "Minimum+1_font.h"
#include "main.h"

#define ARROW_LENGTH 	16
#define SMILEY_LENGTH 	100
#define PIKACHU_WITH 	130
#define PIKACHU_LENGTH 	78
#define FONT_LENGTH 	8

/**
 * API_draw_bitmap
 *
 * @param x_lup, y_lup Tekent bitmap vanaf x_lup (left up) en y_lup (left up).
 *
 * @param bm_nr beschikbare bitmaps:
 * 		bm_nr 0 --> pijl naar rechts
 * 		bm_nr 1 --> pijl naar links
 * 		bm_nr 2 --> pijl naar beneden
 * 		bm_nr 3 --> pijl naar boven
 * 		bm_nr 4 --> verbaasde pikachu (meme)
 * 		bm_nr 5 --> blije smiley
 *
 * Bitmaps zelf zitten in 'bitmap.h', bestaande uit drie bitmaps:
 * 		Pijl naar rechts (deze wordt gedraaid voor andere richtingen)
 * 		Blije smiley
 * 		Verbaasde Pikachu
 *
 * converter van afbeelding naar bitmap: https://www.digole.com/tools/PicturetoC_Hex_converter.php
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINED_BITMAP_NR
 */
int API_draw_bitmap(int x_lup, int y_lup, int bm_nr)
{
	  int k=0;
	  int i=0;
	  int j=0;

	  if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
		  return OUT_OF_BOUNDS; //error out of bounds

	  if(bm_nr==0)
	  {
		  for(i=0;i<ARROW_LENGTH;i++)
		  {
			  for(j=0;j<ARROW_LENGTH;j++)
				  if(arrow[i][j])
					  UB_VGA_SetPixel((j+x_lup),(i+y_lup),arrow[i][j]);
		  }
	  }
	  else if(bm_nr==1)
	  {
		  for(i=0;i<ARROW_LENGTH;i++)
		  {
			  for(j=(ARROW_LENGTH-1);j>=0;j--)
			  {
				  if(arrow[i][j])
					  UB_VGA_SetPixel((k+x_lup),(i+y_lup),arrow[i][j]);
				  k++;
			  }
			  k=0;
		  }
	  }
	  else if(bm_nr==2)
	  {
		  for(i=0;i<ARROW_LENGTH;i++)
		  {
			  for(j=0;j<ARROW_LENGTH;j++)
				  if(arrow[j][i])
					  UB_VGA_SetPixel((j+x_lup),(i+y_lup),arrow[j][i]);
		  }
	  }
	  else if(bm_nr==3)
	  {
		  for(i=(ARROW_LENGTH-1);i>=0;i--)
		  {
			  for(j=0;j<ARROW_LENGTH;j++)
			  {
				  if(arrow[j][i])
					  UB_VGA_SetPixel((j+x_lup),(k+y_lup),arrow[j][i]);
			  }
			  k++;
		  }
		  k=0;
	  }
	  else if(bm_nr==4)
	  {
		  for(i=y_lup;i<(y_lup+PIKACHU_LENGTH);i++)
		  {
			  for(j=x_lup;j<(x_lup+PIKACHU_WITH);j++)
			  {
				  UB_VGA_SetPixel(j,i,pikachu[k]);
				  if(k<sizeof(pikachu))
					  k++;
			  }
		  }
	  }
	  else if(bm_nr==5)
	  {
		  for(i=y_lup;i<(y_lup+SMILEY_LENGTH);i++)
		  {
			  for(j=x_lup;j<(x_lup+SMILEY_LENGTH);j++)
			  {
				  UB_VGA_SetPixel(j,i,smiley[k]);
				  if(k<sizeof(smiley))
					  k++;
			  }
		  }
	  }
	  else
		  return UNDEFINED_BITMAP_NR; //no existing bitmap


	  return NOERROR;
}

/**
 * draw_lineX
 *
 * @param x_1,y_1,x_2,y_2 functie voor lijnen tekenen in horizontale richting tussen co�rdinaten (x_1,y_1) en (x_2,y_2).
 *
 * Deze functie is onderdeel van de 'Bresenham's line algorithm' die gebruikt wordt in API_draw_line.
 *
 * Gelieve deze functie niet oproepen voor lijnen tekenen anders dan de functie API_draw_line,
 * met de reden dat de grootste errorhandling door API_draw_line gedaan wordt.
 */
int draw_lineX (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
	  int dikte = weight;
	  double dx,dy;
	  dx = x_2-x_1;
	  dy = y_2-y_1;

	  int y = y_1;

	  int x,i,D,D2;
	  i=0;
	  int x2 = x_1;
	  int yi = 1;
	  if (dy < 0)
	  {
	    yi = -1;
	    dy = abs(dy);
	  }
	  D = 2*dy - dx;
	  D2 = D;
	  y = y_1;
	  dikte=dikte*2;
	  dikte--;

	  for(x=x_1; x<x_2; x++)
	  {
		UB_VGA_SetPixel((int)x,(int)y,color);

		if(dikte>1)
		{
	    	D2 = D;
	    	x2 = x;
			for(i=0;i<=dikte;i++)
			{
				if(i!=dikte)
				{
					UB_VGA_SetPixel((int)x2,(int)(y-i),color);
					UB_VGA_SetPixel((int)(x2),(int)(y-i+1),color);
				}

				if(D2 > 0)
				{
				   x2 = x2 + yi;
				   D2 = D2 - (2*dx);
				}
				D2 = D2 + 2*dy;
			}
		}

	    if(D > 0)
	    {
	       y = y + yi;
	       D = D - (2*dx);
	    }
	    D = D + 2*dy;
	  }
	  return NOERROR;
}

/**
 * draw_lineY
 *
 * @param x_1,y_1,x_2,y_2 functie voor lijnen tekenen in verticale richting tussen co�rdinaten (x_1,y_1) en (x_2,y_2).
 *
 * Deze functie is onderdeel van de 'Bresenham's line algorithm' die gebruikt wordt in API_draw_line.
 *
 * Gelieve deze functie niet oproepen voor lijnen tekenen anders dan de functie API_draw_line,
 * met de reden dat de grootste errorhandling door API_draw_line gedaan wordt.
 */
int draw_lineY (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
	  int dikte = weight;
	  double dx,dy;
	  dx = x_2-x_1;
	  dy = y_2-y_1;

	  int y = y_1;
	  int x,y2,i,D,D2;
	  i=0;

	  int xi = 1;
	  if (dx < 0)
	  {
	    xi = -1;
	    dx = abs(dx);
	  }
	  D = 2*(int)dx - (int)dy;
	  D2 = D;
	  x = x_1;
	  y2 = y_1;
	  dikte=dikte*2;
	  dikte--;

	  for(y=y_1; y<y_2; y++)
	  {
		UB_VGA_SetPixel((int)x,(int)y,color);

		if(dikte>1)
		{
			D2 = D;
			y2 = y;
			for(i=0;i<=dikte;i++)
			{
				if(i!=dikte)
				{
					UB_VGA_SetPixel((int)x-i,(int)(y2),color);
					UB_VGA_SetPixel((int)(x-i-1),(int)(y2),color);
				}

				if(D2 > 0)
				{
				   y2 = y2 + xi;
				   D2 = D2 - (2*dy);
				}
				D2 = D2 + 2*dx;
			}
		}

	    if(D > 0)
	    {
	       x = x + xi;
	       D = D - (2*dy);
	    }
	    D = D + 2*dx;
	  }

  return NOERROR;
}

/**
 * API_draw_line
 *
 * Deze functie maakt gebruik van de 'Bresenham's line algorithm' met gebtuik van functie drawlineX of drawlineY
 *
 * @param x_1,y_1,x_2,y_2 functie voor lijnen tekenen tussen co�rdinaten (x_1,y_1) en (x_2,y_2)
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * @param weight weight is het aantal pixels breedte voor de lijn (is weight een negatieve waarde, wordt deze positief gemaakt)
 *
 * @param reserved de variabele reserved heeft geen functionaliteit en wordt genegeerd
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINEDCOLOR
 */
int	API_draw_line (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
  if(x_1>VGA_DISPLAY_X||x_1<0||y_1>VGA_DISPLAY_Y||y_1<0)
	  return OUT_OF_BOUNDS; //error out of bounds
  if(x_2>VGA_DISPLAY_X||x_2<0||y_2>VGA_DISPLAY_Y||y_2<0)
	  return OUT_OF_BOUNDS; //error out of bounds

  if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

  if(x_1 == x_2 && y_1 == y_2)
  {
	  UB_VGA_SetPixel(x_1,y_1,color);
	  return 0;
  }

  weight = abs(weight);

  if (abs(x_2 - x_1) >= abs(y_2 - y_1))
    if (x_2 > x_1)
      draw_lineX(x_1, y_1, x_2, y_2, color, weight, reserved);
    else
      draw_lineX(x_2, y_2, x_1, y_1, color, weight, reserved);
  else
    if (y_2 > y_1)
      draw_lineY(x_1, y_1, x_2, y_2, color, weight, reserved);
    else
      draw_lineY(x_2, y_2, x_1, y_1, color, weight, reserved);
  return NOERROR;
}

/**
 * API_draw_rectangle
 *
 * @param x,y functie voor rechthoekenen tekenen vanaf co�rdinaten (x,y) als hoek linksboven
 *
 * @param width width is de breedte in aantal pixels van de rechthoek naar rechts
 *
 * @param height height is de hoogte in aantal pixels van de rechthoek naar beneden
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * @param filled filled bij 0 wordt er een rechthoek getekend zonder opvulling
 * filled bij 1 wordt er een rechthoek getekend met wel opgevult is
 *
 * @param reserved1 reserved1 is de breedte in aantal pixels van de border lijnen wanneer filled 0 is (anders wordt deze waarde genegeerd)
 *
 * @param reserved2 de variabele reserved2 heeft geen functionaliteit en wordt genegeerd
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINEDCOLOR
 * 		FILLED_NOT_0_OR_1
 */
int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2)
{
	int i,j;

	if(x>VGA_DISPLAY_X||x<0||y>VGA_DISPLAY_Y||y<0)
	  return OUT_OF_BOUNDS; //error out of bounds

	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	width = abs(width);
	height = abs(height);
	if(filled==1)
	{
	  for(i=y;i<=(y+height);i++)
	  {
		  for(j=x;j<=(x+width);j++)
			  UB_VGA_SetPixel(j,i,color);
	  }
	}
	else if(filled==0)
	{
		API_draw_line(x,y,(x+width+1),y,color,reserved1,reserved2);
		API_draw_line((x+width),y,(x+width),(y+height+1),color,reserved1,reserved2);
		if(reserved1>1)
		{
			API_draw_line((x+width),(y+height-1),x,(y+height-1),color,reserved1,reserved2);
			API_draw_line(x,(y+height+1),x,(y-reserved1),color,reserved1,reserved2);
		}
		else
		{
			API_draw_line((x+width),(y+height),x,(y+height),color,reserved1,reserved2);
			API_draw_line(x,(y+height),x,(y),color,reserved1,reserved2);
		}
	}
	else
		return FILLED_NOT_0_OR_1; //filled not 0 or 1

	return NOERROR;
}
/**
 * API_clearscreen
 *
 * @param color functie voor scherm volledig met een kleur 8 bit op te vullen met de variabele color
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		UNDEFINEDCOLOR
 */
int API_clearscreen(int color)
{
	  if(color>255||color<0)
	    return UNDEFINEDCOLOR; //error color not existing

	  uint16_t xp,yp;

	  for(yp=0;yp<VGA_DISPLAY_Y;yp++)
	  {
	    for(xp=0;xp<VGA_DISPLAY_X;xp++)
	    	UB_VGA_SetPixel(xp,yp,color);
	  }
	  return NOERROR;
}

/**
 * API_draw_char
 *
 * @param x_lup,y_lup functie voor tekenen van iduviduele letters vanaf de co�rdinaten (x_lup,y_lup) met 8x8 fonts
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * @param letter letter is de char waarde van de gewenste getekende letter (128 ASCII mogelijkheden)
 *
 * @param fontname fontname is een string waarin "arial" en "consolas" mogelijke keuzes zijn
 *
 * @param fontsize fontsize kan de groote van de letters aanpassen.
 * 		De waarde 1 is de orginele 8x8 font
 * 		De waarde 2 wordt de 8x8 font twee keer zo groot
 *
 * @param fontsytle fontsytle bij 0 maakt de char normaal, bij 1 cursief, bij 2 vetgedrukt ('fontsytle' is niet als 'fontstyle' geschreven omdat Michiel Scager deze typefout in het protocole heeft gemaakt en hieraan gehouden moet worden)
 *
 * @param reserved de variabele reserved heeft geen functionaliteit en wordt genegeerd
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		UNDEFINEDCOLOR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINEDFONTSTYLE
 * 		FONTSIZE_NOT_EXISTING
 * 		UNDEFINED_FONTNAME
 */
int API_draw_char (int x_lup, int y_lup, int color, char letter, char *fontname, int fontsize, int fontsytle, int reserved)
{
	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
	  return OUT_OF_BOUNDS; //error out of bounds

    int x,y;
    int i = 0;
    int set=0;
    char *bitmap;

    if(strcmp(fontname,"arial")==0)
    {
		bitmap = font8x8_basic[(int)letter];
    	if(fontsize==1)
    	{
			for (x=x_lup; x < (x_lup+FONT_LENGTH); x++)
			{
				for (y=y_lup; y < (y_lup+FONT_LENGTH); y++)
				{
					set = bitmap[(y-y_lup)] & 1 << (x-x_lup);
					if(set)
					{
						if(fontsytle==0)
							UB_VGA_SetPixel(x,y,color);
						else if(fontsytle==1)
						{
							UB_VGA_SetPixel(x-i,y,color);
						}
						else if(fontsytle==2)
						{
							UB_VGA_SetPixel(x,y,color);
							UB_VGA_SetPixel(x+1,y,color);
						}
						else
							return ONLY_FONTSTYLE_NORMAL_AVAILIBLE;
					}
					i++;
				}
				i=0;
			}
			return NOERROR;
    	}
    	else if(fontsize==2)
    	{
			for (x=x_lup; x < (x_lup+(FONT_LENGTH*2)); x++)
			{
				for (y=y_lup; y < (y_lup+(FONT_LENGTH*2)); y++)
				{
					if(y%2==0)
						set = bitmap[(y-y_lup)/2] & 1 << ((x-x_lup)/2);
					if(set)
					{
						if(fontsytle==0)
							UB_VGA_SetPixel(x,y,color);
						else if(fontsytle==1)
						{
							UB_VGA_SetPixel(x-i,y,color);
						}
						else if(fontsytle==2)
						{
							UB_VGA_SetPixel(x,y,color);
							UB_VGA_SetPixel(x+1,y,color);
						}
						else
							return ONLY_FONTSTYLE_NORMAL_AVAILIBLE;
					}
					i++;
				}
				i=0;
			}
			return NOERROR;
    	}
    	else
    		return FONTSIZE_NOT_EXISTING; //fontsize not existing
    }
    else if(strcmp(fontname,"consolas")==0)
    {
    	letter-=32;
    	bitmap = minimum_font[(int)letter];
    	if(fontsize==1)
    	{
			for (x=x_lup; x < (x_lup+(FONT_LENGTH-1)); x++)
			{
				for (y=y_lup; y < (y_lup+(FONT_LENGTH-1)); y++)
				{
					set = bitmap[(x-x_lup)] & 1 << (y-y_lup);
					if(set)
					{
						if(fontsytle==0)
							UB_VGA_SetPixel(x,y,color);
						else if(fontsytle==1)
						{
							UB_VGA_SetPixel(x-i,y,color);
						}
						else if(fontsytle==2)
						{
							UB_VGA_SetPixel(x,y,color);
							UB_VGA_SetPixel(x+1,y,color);
						}
						else
							return ONLY_FONTSTYLE_NORMAL_AVAILIBLE;
					}
						//UB_VGA_SetPixel(x,y,color);
					i++;
				}
				i=0;
			}
    	}
    	else if(fontsize==2)
    	{
			for (x=x_lup; x < (x_lup+((FONT_LENGTH-1)*2)); x++)
			{
				for (y=y_lup; y < (y_lup+((FONT_LENGTH-1)*2)); y++)
				{
					if(y%2==0)
							set = bitmap[(x-x_lup)/2] & 1 << ((y-y_lup)/2);
					if(set)
					{
						if(fontsytle==0)
							UB_VGA_SetPixel(x,y,color);
						else if(fontsytle==1)
						{
							UB_VGA_SetPixel(x-i,y,color);
						}
						else if(fontsytle==2)
						{
							UB_VGA_SetPixel(x,y,color);
							UB_VGA_SetPixel(x+1,y,color);
						}
						else
							return ONLY_FONTSTYLE_NORMAL_AVAILIBLE;
					}
					i++;
						//UB_VGA_SetPixel(x,y,color);
				}
				i=0;
			}
			return NOERROR;
    	}
    	else
    		return FONTSIZE_NOT_EXISTING; //fontsize not existing
    }
    else
    	return UNDEFINED_FONTNAME;

    return NOERROR;
}

/**
 * API_draw_text
 *
 * @param x_lup,y_lup functie voor tekenen van string met behulp van API_draw_char vanaf de co�rdinaten (x_lup,y_lup) met 8x8 fonts
 * als een woord niet buiten het scherm valt in de horizontale richting, begint dit woord op de volgende regel
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * @param text text is de string die getekend moet worden (128 ASCII mogelijkheden)
 *
 * @param fontname fontname is een string waarin "arial" en "consolas" mogelijke keuzes zijn
 *
 * @param fontsize fontsize kan de groote van de letters aanpassen.
 * 		De waarde 1 is de orginele 8x8 font
 * 		De waarde 2 wordt de 8x8 font twee keer zo groot
 *
 * @param fontsytle fontsytle bij 0 maakt de char normaal, bij 1 cursief, bij 2 vetgedrukt ('fontsytle' is niet als 'fontstyle' geschreven omdat Michiel Scager deze typefout in het protocole heeft gemaakt en hieraan gehouden moet worden)
 *
 * @param reserved de variabele reserved heeft geen functionaliteit en wordt genegeerd
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		UNDEFINEDCOLOR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINEDFONTSTYLE
 * 		FONTSIZE_NOT_EXISTING
 * 		UNDEFINED_FONTNAME
 */
int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname, int fontsize, int fontsytle, int reserved)
{
	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
	  return OUT_OF_BOUNDS; //error out of bounds


	int x = x_lup;
	int y = y_lup;
	char c[100];
	int i = 0;
	int j = 0;
	int error = 0;
	strcpy(c, text);
	while (c[i] != 0)
	{
		error = API_draw_char(x, y, color, c[i], fontname, fontsize, fontsytle, reserved);
		if(error)
			return error;
		i++;
		x += (FONT_LENGTH*fontsize);
		if(c[i]==' ')
		{
			j=0;
			while(1)
			{
				j++;
				if ((x+(FONT_LENGTH*fontsize)+((FONT_LENGTH*fontsize)*j)) >= VGA_DISPLAY_X)
				{
					i++;
					x=x_lup;
					y += (FONT_LENGTH*fontsize);
					if((y+(FONT_LENGTH*fontsize))>VGA_DISPLAY_Y||y<0)
					  return OUT_OF_BOUNDS; //error out of bounds
					break;
				}
				if((c[j+i]==' ')||(c[j+i]=='\0'))
					break;
			}
		}
		else if ((x+(FONT_LENGTH*fontsize)) >= VGA_DISPLAY_X)
		{
			x=x_lup;
			y += (FONT_LENGTH*fontsize);
			if((y+(FONT_LENGTH*fontsize))>VGA_DISPLAY_Y||y<0)
			  return OUT_OF_BOUNDS; //error out of bounds
		}
	}
	return NOERROR;
}

/**
 * drawCircle
 *
 * Deze functie is onderdeel van de 'Bresenham's circle algorithm' die gebruikt wordt in API_draw_circle.
 *
 * @param xc,yc Co�rdinaten van middelpunt circel
 *
 * @param x,y verschil afstand tussen middelpunt en waar pixels moet komen voor tekenen van circel delen
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * Gelieve deze functie niet oproepen voor cicels tekenen anders dan de functie API_draw_circle,
 * met de reden dat de errorhandling door API_draw_circle gedaan wordt.
 */
void drawCircle(int xc, int yc, int x, int y, int color)
{
	UB_VGA_SetPixel(xc+x, yc+y, color);
	UB_VGA_SetPixel(xc-x, yc+y, color);
	UB_VGA_SetPixel(xc+x, yc-y, color);
	UB_VGA_SetPixel(xc-x, yc-y, color);
	UB_VGA_SetPixel(xc+y, yc+x, color);
	UB_VGA_SetPixel(xc-y, yc+x, color);
	UB_VGA_SetPixel(xc+y, yc-x, color);
	UB_VGA_SetPixel(xc-y, yc-x, color);
}

/**
 * API_draw_circle
 *
 * Deze functie maakt gebruik van de 'Bresenham's circle algorithm' met gebtuik van functie drawCircle
 *
 * @param xc,yc Co�rdinaten van middelpunt circel
 *
 * @param r r is de straal van de circel
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINEDCOLOR
 */
int API_draw_circle (int xc, int yc, int r, int color, int reserved)
{
	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(xc>VGA_DISPLAY_X||xc<0||yc>VGA_DISPLAY_Y||yc<0)
	  return OUT_OF_BOUNDS; //error out of bounds

    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y, color);
    while (y >= x)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y, color);
    }
    return NOERROR;
}

/**
 * API_draw_figure
 *
 * functie voor tekenen van een lijnenfiguur tussen de gewenste co�rdinaten met behulp van de functie API_draw_line
 *
 * @param x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4,x_5,y_5 de co�rdinaten waartussen getekend moet worden
 *
 * @param color color is in 8bit kleur (0 tot 255; 0x00 tot 0xFF)
 *
 * @param reserved reserved is de dikte van de lijnen die getekend moeten worden
 *
 * Mogelijk optreedbare errors:
 * 		NOERROR
 * 		OUT_OF_BOUNDS
 * 		UNDEFINEDCOLOR
 */
int API_draw_figure (int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4, int x_5, int y_5, int color, int reserved)
{
	int error=0;
	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(	x_1>VGA_DISPLAY_X||x_1<0||y_1>VGA_DISPLAY_Y||y_1<0||
		x_2>VGA_DISPLAY_X||x_2<0||y_2>VGA_DISPLAY_Y||y_2<0||
		x_3>VGA_DISPLAY_X||x_3<0||y_3>VGA_DISPLAY_Y||y_3<0||
		x_4>VGA_DISPLAY_X||x_4<0||y_4>VGA_DISPLAY_Y||y_4<0||
		x_5>VGA_DISPLAY_X||x_5<0||y_5>VGA_DISPLAY_Y||y_5<0)
	  return OUT_OF_BOUNDS; //error out of bounds

	error = API_draw_line (x_1, y_1, x_2, y_2, color, reserved, 0);
	if(error)
		return error;
	error = API_draw_line (x_2, y_2, x_3, y_3, color, reserved, 0);
	if(error)
		return error;
	error = API_draw_line (x_3, y_3, x_4, y_4, color, reserved, 0);
	if(error)
		return error;
	error = API_draw_line (x_4, y_4, x_5, y_5, color, reserved, 0);
	if(error)
		return error;
	error = API_draw_line (x_5, y_5, x_1, y_1, color, reserved, 0);
	if(error)
		return error;

	return NOERROR;
}


