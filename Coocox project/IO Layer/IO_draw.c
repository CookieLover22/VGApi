#include "IO_draw.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitmap.h"
#include "font8x8_basic.h"
//#include "aztech_font.h"
//#include "bubblesstandard_font.h"
#include "Minimum+1_font.h"
#include "stm32_ub_vga_screen.h"


int API_draw_bitmap(int x_lup, int y_lup, int bm_nr)
{
	  int k=0;
	  int i=0;
	  int j=0;
	  int hoogte = 78;
	  int breedte = 130;
	  //if(bm_nr ==0)

	  if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
		  return 1; //error outofbounce

	  if(bm_nr==1)
	  {
		  for(i=0;i<16;i++)
		  {
			  for(j=0;j<16;j++)
				  if(arrow[i][j])
					  UB_VGA_SetPixel((j+x_lup),(i+y_lup),arrow[i][j]);
		  }
	  }
	  else if(bm_nr==2)
	  {
		  for(i=0;i<16;i++)
		  {
			  for(j=15;j>=0;j--)
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
		  for(i=0;i<16;i++)
		  {
			  for(j=0;j<16;j++)
				  if(arrow[j][i])
					  UB_VGA_SetPixel((j+x_lup),(i+y_lup),arrow[j][i]);
		  }
	  }
	  else if(bm_nr==4)
	  {
		  for(i=15;i>=0;i--)
		  {
			  for(j=0;j<16;j++)
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
		  for(i=y_lup;i<(y_lup+hoogte);i++)
		  {
			  for(j=x_lup;j<(x_lup+breedte);j++)
			  {
				  UB_VGA_SetPixel(j,i,pikachu[k]);

				  if(k>sizeof(pikachu))
					  ;//doe niks
				  else
					  k++;
			  }
		  }
	  }
	  else
		  return 2; //no existing bitmap

	  return 0;
}

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
	  //if(dikte%2==0)
		//  dikte++;

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
	  return 0;
}


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

  return 0;
}

int	API_draw_line (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
  if(x_1>VGA_DISPLAY_X||x_1<0||y_1>VGA_DISPLAY_Y||y_1<0)
	  return 1; //error outofbounce
  if(x_2>VGA_DISPLAY_X||x_2<0||y_2>VGA_DISPLAY_Y||y_2<0)
	  return 1; //error outofbounce

  if(color>255||color<0)
	  return 3; //error color not existing

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
  return 0;
}

int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2)
{
	int i,j;

	if(x>VGA_DISPLAY_X||x<0||y>VGA_DISPLAY_Y||y<0)
	  return 1; //error outofbounce

	if(color>255||color<0)
	  return 3; //error color not existing

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
		return 123;
	return 0;
}

int API_clearscreen(int color)
{
	  if(color>255||color<0)
	    return 3; //error color not existing

	  uint16_t xp,yp;

	  for(yp=0;yp<VGA_DISPLAY_Y;yp++)
	  {
	    for(xp=0;xp<VGA_DISPLAY_X;xp++)
	    	UB_VGA_SetPixel(xp,yp,color);
	  }
	  return 0;
}

int API_draw_char (int x_lup, int y_lup, int color, char letter, char *fontname, int fontsize, int fontsytle, int reserved)
{
    int x,y;
    int set=0;
    char *bitmap;
    if(fontsytle==0)
    {
		bitmap = font8x8_basic[(int)letter];
    	if(fontsize==1)
    	{
			for (x=x_lup; x < (x_lup+8); x++)
			{
				for (y=y_lup; y < (y_lup+8); y++)
				{
					set = bitmap[(y-y_lup)] & 1 << (x-x_lup);
					if(set)
						UB_VGA_SetPixel(x,y,color);
				}
			}
			return 0;
    	}
    	else if(fontsize==2)
    	{
			for (x=x_lup; x < (x_lup+16); x++)
			{
				for (y=y_lup; y < (y_lup+16); y++)
				{
					if(y%2==0)
						set = bitmap[(y-y_lup)/2] & 1 << ((x-x_lup)/2);
					if(set)
						UB_VGA_SetPixel(x,y,color);
				}
			}
			return 0;
    	}
    }
    else if(fontsytle==1)
    {
    	letter-=32;
    	bitmap = minimum_font[(int)letter];
    	if(fontsize==1)
    	{
			for (x=x_lup; x < (x_lup+7); x++)
			{
				for (y=y_lup; y < (y_lup+7); y++)
				{
					set = bitmap[(x-x_lup)] & 1 << (y-y_lup);
					if(set)
						UB_VGA_SetPixel(x,y,color);
				}
			}
    	}
    	else if(fontsize==2)
    	{
			for (x=x_lup; x < (x_lup+14); x++)
			{
				for (y=y_lup; y < (y_lup+14); y++)
				{
					if(y%2==0)
							set = bitmap[(x-x_lup)/2] & 1 << ((y-y_lup)/2);
					if(set)
						UB_VGA_SetPixel(x,y,color);
				}
			}
			return 0;
    	}
    }
    return 0;
}

int API_draw_text (int x_lup, int y_lup, int color, char *text, char *fontname, int fontsize, int fontsytle, int reserved)
{
	if(color>255||color<0)
	  return 3; //error color not existing

	if(x_lup>VGA_DISPLAY_X||x_lup<0||y_lup>VGA_DISPLAY_Y||y_lup<0)
	  return 1; //error outofbounce

	int x = x_lup;
	int y = y_lup;
	char c[100];
	int i=0;
	strcpy(c, text);
	while (c[i] != 0)
	{
		API_draw_char (x, y, color, c[i], fontname, fontsize, fontsytle, reserved);
		i++;
		x += (8*fontsize); // 6 pixels wide	    x += 6;
		if ((x+(8*fontsize)) >= VGA_DISPLAY_X)
		{
			x=0;
			y += (8*fontsize);
			if((y+(8*fontsize))>VGA_DISPLAY_Y||y<0)
			  return 1; //error outofbounce
		}
	}
	return 0;
}

