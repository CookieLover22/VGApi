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
	  double a;
	  int i=0;
	  int dikte = weight;
	  //a = (y_2 - y_1) / (x_2 - x_1);
	  double dy,dx;
	  dy = y_2-y_1;
	  dx = x_2-x_1;
	  if(dy!=0)
		  a = dx/dy;
	  else
		  a=0;
	  double x,y;
	  x = (double)x_1;
	  y = (double)y_1;
	  if(a==0)
	  {
		  //a=0;
		  dikte = dikte/1.5;
	  }
	  while ((int)x < x_2)
		{
		  UB_VGA_SetPixel((int)x,(int)y,color);
		  if(dikte>1)
		  {
			  if(a==0)
			  {
				  for(i=1;i<=dikte;i++)
					  UB_VGA_SetPixel(x,y+i,color);
			  }
			  else
			  {
				  while(1)
				  {
					  if(i*2+2>dikte)
						  break;
					  if(y_2-y_1>0)
						  UB_VGA_SetPixel(x+(1*i),(y-1-(1*i)),color);
					  else
						  UB_VGA_SetPixel(x+(1*i),(y+1+(1*i)),color);
					  if(i*2+3>dikte)
						  break;
					  i++;
					  if(y_2-y_1>0)
						  UB_VGA_SetPixel(x+(1*i),(y-(1*i)),color);
					  else
						  UB_VGA_SetPixel(x+(1*i),(y+(1*i)),color);
				  }
			  }
			  i=0;
		  }

		  y = y + a;
		  x=x+1;
		}
	  return 0;
}


int draw_lineY (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
  double a;
  int i=0;
  int dikte = weight;
  //a = ((double)x_2 - (double)x_1) / ((double)y_2 - (double)y_1);
  double dy,dx;
  dy = y_2-y_1;
  dx = x_2-x_1;
  a = dx/dy;
  double x,y;
  x = (double)x_1;
  y = (double)y_1;
  if(a!=0)
	  ;//y_1 = a * y + (y - (a * x));
  else
  {
	  //a=0;
	  dikte = dikte/1.5;
	  //color = 10;
  }
  while (((int)y) < y_2)
    {
	  UB_VGA_SetPixel((int)x,(int)y,color);
	  if(dikte>1)
	  {
		  if((a-0.1)<0)
		  {
			  for(i=1;i<=dikte;i++)
			  {
				  UB_VGA_SetPixel(x_1+i,y_1,color);
			  }
		  }
		  else
		  {
			  while(1)
			  {
				  if(i*2+2>dikte)
					  break;
				  if(y_2-y>0)
					  UB_VGA_SetPixel(x-a-(a*i),(y+(a*i)),color);
				  else
					  UB_VGA_SetPixel(x+a+(a*i),(y+(a*i)),color);
				  if(i*2+3>dikte)
					  break;
				  i++;
				  if(y_2-y>0)
					  UB_VGA_SetPixel(x-(a*i),(y+(a*i)),color);
				  else
					  UB_VGA_SetPixel(x+(a*i),(y+(a*i)),color);
			  }
		  }
		  i=0;
	  }
      x += (int)a;
      y=y+1;
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

  double dx,dy,a,error,D;
  dx = x_2-x_1;
  dy = y_2-y_1;

  a = abs(dy/dx);
  error = 0;

  int y = y_1;
  int x;

  double yi = 1;
  if (dy < 0)
  {
    yi = -1;
    dy = abs(dy);
  }
  D = 2*dy - dx;
  y = y_1;

  for(x=x_1; x<x_2; x++)
  {
	UB_VGA_SetPixel((int)x,(int)y,color);
    if(D > 0)
    {
       y = y + yi;
       D = D - (2*dx);
    }
    D = D + 2*dy;
  }

  /*
  if (abs(x_2 - x_1) >= abs(y_2 - y_1))
    if (x_2 >= x_1)
      draw_lineX(x_1, y_1, x_2, y_2, color, weight, reserved);
    else
      draw_lineX(x_2, y_2, x_1, y_1, color, weight, reserved);
  else
    if (y_2 >= y_1)
      draw_lineY(x_1, y_1, x_2, y_2, color, weight, reserved);
    else
      draw_lineY(x_2, y_2, x_1, y_1, color, weight, reserved);*/
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
		API_draw_line(x,y,(x+width),y,color,reserved1,reserved2);
		if(reserved1>1)
			API_draw_line((x+width),y,(x+width),(y+height+reserved1-1),color,reserved1,reserved2);
		else
			API_draw_line((x+width),y,(x+width),(y+height+reserved1),color,reserved1,reserved2);
		API_draw_line((x+width),(y+height),x,(y+height),color,reserved1,reserved2);
		API_draw_line(x,(y+height),x,y,color,reserved1,reserved2);
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
    int set;
    char *bitmap;
    if(fontsytle==0)
    {
		bitmap = font8x8_basic[(int)letter];
    	if(fontsize==0)
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
    	/*else
    	{
			for (x=x_lup; x < (x_lup+(8*(fontsize+1))); x++)
			{
				for (y=y_lup; y < (y_lup*(fontsize+1); y++)
				{
					set = bitmap[(y-y_lup)] & 1 << (x-x_lup);
					if(set)
						UB_VGA_SetPixel(x,y,color);
				}
			}
			return 0;
    	}*/
    }
    else if(fontsytle==1)
    {
    	letter-=32;
    	bitmap = minimum_font[(int)letter];
    }
    else
    	return 1;

    for (x=x_lup; x < (x_lup+7); x++)
    {
        for (y=y_lup; y < (y_lup+7); y++)
        {
            set = bitmap[(x-x_lup)] & 1 << (y-y_lup);
            if(set)
            	UB_VGA_SetPixel(x,y,color);
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
		x += 8; // 6 pixels wide	    x += 6;
		if ((x+8) >= VGA_DISPLAY_X)
		{
			x=0;
			y += 8;
			if(y_lup>VGA_DISPLAY_Y||y_lup<0)
			  return 1; //error outofbounce
		}
	}
	return 0;
}

