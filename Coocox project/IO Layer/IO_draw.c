/**
 * File     : IO_draw.c
 * Datum    : 17.05.2019
 * Version  : 0.1
 * Autor    : Daniël Boon
 * CPU      : STM32F4
 * IDE      : CooCox CoIDE 1.7.8
 * Module   : CMSIS_BOOT, M4_CMSIS_CORE
 * Function : drawing figures with UB_VGA_SetPixel()
 */

#include "IO_draw.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitmap.h"
#include "font8x8_basic.h"
#include "Minimum+1_font.h"
#include "stm32_ub_vga_screen.h"

#include "main.h"


#define ARROW_LENGTH 16
#define SMILEY_LENGTH 100
#define PIKACHU_WITH 130
#define PIKACHU_LENGTH 78
#define FONT_LENGTH 8

/**
 * tekent bitmap vanaf x_lup (left up) en y_lup (left up). beschikbare bitmaps:
 * bm_nr 1 --> pijl naar links
 * bm_nr 2 --> pijl naar rechts
 * bm_nr 3 --> pijl naar boven
 * bm_nr 4 --> pijl naar beneden
 * bm_nr 5 --> verbaasde pikachu (meme)
 * bm_nr 6 --> blije smiley
 */
int API_draw_bitmap(int x_lup, int y_lup, int bm_nr)
{
	  int k=0;
	  int i=0;
	  int j=0;

	  if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
		  return OUT_OF_BAUNCE; //error outofbounce

	  if(bm_nr==1)
	  {
		  for(i=0;i<ARROW_LENGTH;i++)
		  {
			  for(j=0;j<ARROW_LENGTH;j++)
				  if(arrow[i][j])
					  UB_VGA_SetPixel((j+x_lup),(i+y_lup),arrow[i][j]);
		  }
	  }
	  else if(bm_nr==2)
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
	  else if(bm_nr==3)
	  {
		  for(i=0;i<ARROW_LENGTH;i++)
		  {
			  for(j=0;j<ARROW_LENGTH;j++)
				  if(arrow[j][i])
					  UB_VGA_SetPixel((j+x_lup),(i+y_lup),arrow[j][i]);
		  }
	  }
	  else if(bm_nr==4)
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
	  else if(bm_nr==5)
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
	  else if(bm_nr==6)
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
 * functie voor lijnen tekenen met een meer horizontale richting
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
 * functie voor lijnen tekenen met een meer verticale richting
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
 * functie voor bepalen van gebruik van drawlineX of drawlineY
 */
int	API_draw_line (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
  if(x_1>VGA_DISPLAY_X||x_1<0||y_1>VGA_DISPLAY_Y||y_1<0)
	  return OUT_OF_BAUNCE; //error outofbounce
  if(x_2>VGA_DISPLAY_X||x_2<0||y_2>VGA_DISPLAY_Y||y_2<0)
	  return OUT_OF_BAUNCE; //error outofbounce

  if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

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
 * functie voor rechthoekenen tekenen
 */
int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2)
{
	int i,j;

	if(x>VGA_DISPLAY_X||x<0||y>VGA_DISPLAY_Y||y<0)
	  return OUT_OF_BAUNCE; //error outofbounce

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
	else return FILLED_NOT_0_OR_1; //filled not 0 or 1

	return NOERROR;
}
/**
 * functie voor scherm volledig met een kleur op te vullen
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
 * functie voor tekenen van iduviduele letters
 */
int API_draw_char (int x_lup, int y_lup, int color, char letter, char *fontname, int fontsize, int fontsytle, int reserved)
{
    int x,y;
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
						UB_VGA_SetPixel(x,y,color);
				}
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
						UB_VGA_SetPixel(x,y,color);
				}
			}
			return NOERROR;
    	}
    	else return FONTSIZE_NOT_EXISTING; //fontsize not existing

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
						UB_VGA_SetPixel(x,y,color);
				}
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
						UB_VGA_SetPixel(x,y,color);
				}
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
 * functie voor tekenen van string met behulp van API_draw_char
 */
int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname, int fontsize, int fontsytle, int reserved)
{
	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
	  return OUT_OF_BAUNCE; //error outofbounce


	if(fontname)
	  return 4; //fonttype feature not existing

	int x = x_lup;
	int y = y_lup;
	char c[100];
	int i = 0;
	int error = 0;
	strcpy(c, text);
	while (c[i] != 0)
	{
		error = API_draw_char(x, y, color, c[i], fontname, fontsize, fontsytle, reserved);
		if(error)
			return error;
		i++;
		x += (FONT_LENGTH*fontsize);
		if ((x+(FONT_LENGTH*fontsize)) >= VGA_DISPLAY_X)
		{
			x=x_lup;
			y += (8*fontsize);
			if((y+(8*fontsize))>VGA_DISPLAY_Y||y<0)
			  return OUT_OF_BAUNCE; //error outofbounce
		}
	}
	return NOERROR;
}

/**
 * tekenen van circel delen
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
 * functie van circel met behulp van drawCircle (kan niet opgevuld worden)
 */
int API_draw_circle (int xc, int yc, int r, int color, int reserved)
{

	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(xc>VGA_DISPLAY_X||xc<0||yc>VGA_DISPLAY_Y||yc<0)
	  return OUT_OF_BAUNCE; //error outofbounce

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
 * functie voor tekenen van een figuur met de gewenste hoekpunten
 */
int API_draw_figure (int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4, int x_5, int y_5, int color, int reserved)
{
	int error=0;
	if(color>255||color<0)
	  return UNDEFINEDCOLOR; //error color not existing

	if(x_1>VGA_DISPLAY_X||x_1<0||y_1>VGA_DISPLAY_Y||y_1<0||x_2>VGA_DISPLAY_X||x_2<0||y_2>VGA_DISPLAY_Y||y_2<0||x_3>VGA_DISPLAY_X||x_3<0||y_3>VGA_DISPLAY_Y||y_3<0||x_4>VGA_DISPLAY_X||x_4<0||y_4>VGA_DISPLAY_Y||y_4<0||x_5>VGA_DISPLAY_X||x_5<0||y_5>VGA_DISPLAY_Y||y_5<0)
	  return OUT_OF_BAUNCE; //error outofbounce

	error = API_draw_line (x_1, y_1, x_2, y_2, color, 1, 0);
	if(error)
		return error;
	error = API_draw_line (x_2, y_2, x_3, y_3, color, 1, 0);
	if(error)
		return error;
	error = API_draw_line (x_3, y_3, x_4, y_4, color, 1, 0);
	if(error)
		return error;
	error = API_draw_line (x_4, y_4, x_5, y_5, color, 1, 0);
	if(error)
		return error;
	error = API_draw_line (x_5, y_5, x_1, y_1, color, 1, 0);
	if(error)
		return error;

	return NOERROR;
}


