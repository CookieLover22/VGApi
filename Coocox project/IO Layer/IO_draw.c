#include "IO_draw.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <time.h>
#include <stdio.h>
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
	  /*else
	  {
		  for(i=y_lup;i<(y_lup+180);i++)
		  {
			  for(j=x_lup;j<(x_lup+240);j++)
			  {
				  UB_VGA_SetPixel(j,i,haunter[k]);

				  if(k>sizeof(haunter))
					  ;//doe niks
				  else
					  k++;
			  }
		  }
	  }*/
	  return 0;
}

int draw_lineX (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
	  double a;
	  int i=0;
	  int dikte = weight;
	  a = (y_2 - y_1) / (x_2 - x_1);
	  //double b = abs(a);
	  if(a!=0)
		 ;
	  else
	  {
		  a=0;
		  dikte = dikte/1.5;
		  //color = 10;
	  }
	  while (x_1 < x_2)
		{
		  UB_VGA_SetPixel(x_1,y_1,color);
		  if(dikte>1)
		  {
			  if(a==0)
			  {
				  for(i=1;i<=dikte;i++)
				  {
					  UB_VGA_SetPixel(x_1,y_1+i,color);
				  }
			  }
			  else
			  {
				  while(1)
				  {
					  if(i*2+2>dikte)
						  break;
					  if(y_2-y_1>0)
						  UB_VGA_SetPixel(x_1+(a*i),(y_1-a-(a*i)),color);
					  else
						  UB_VGA_SetPixel(x_1+(a*i),(y_1+a+(a*i)),color);
					  if(i*2+3>dikte)
						  break;
					  i++;
					  if(y_2-y_1>0)
						  UB_VGA_SetPixel(x_1+(a*i),(y_1-(a*i)),color);
					  else
						  UB_VGA_SetPixel(x_1+(a*i),(y_1+(a*i)),color);
				  }
			  }
			  i=0;
		  }
		  //for(i=0;i<=weight;i++)
		 // {
		//	if(i % 2 == 0)
		//		UB_VGA_SetPixel(x_1+(a*i),(y_1+a+(a*i)),color);
		//		//printf("%d is even.", number);
		//	else
		//		 UB_VGA_SetPixel(x_1+a,(y_1+a),color);
		//		//printf("%d is odd.", number);
		  //}
		  //UB_VGA_SetPixel(x_1,(y_1+a),color);
		  //UB_VGA_SetPixel(x_1+a,(y_1+a),color);
		  //UB_VGA_SetPixel(x_1+a,(y_1+a+a),color);
		 // UB_VGA_SetPixel(x_1+a+a,(y_1+a+a),color);
		  y_1 += a;
		  x_1++;
		}
	  return 0;
}


int draw_lineY (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
  double a;
  int i=0;
  int dikte = weight;
  a = (x_2 - x_1) / (y_2 - y_1);
  if(a!=0)
	  y_1 = a * y_1 + (y_1 - (a * x_1));
  else
  {
	  a=0;
	  dikte = dikte/1.5;
	  //color = 10;
  }
  while (y_1 < y_2)
    {
	  UB_VGA_SetPixel(x_1,y_1,color);
	  if(dikte>1)
	  {
		  if(a==0)
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
				  if(y_2-y_1>0)
					  UB_VGA_SetPixel(x_1-a-(a*i),(y_1+(a*i)),color);
				  else
					  UB_VGA_SetPixel(x_1+a+(a*i),(y_1+(a*i)),color);
				  if(i*2+3>dikte)
					  break;
				  i++;
				  if(y_2-y_1>0)
					  UB_VGA_SetPixel(x_1-(a*i),(y_1+(a*i)),color);
				  else
					  UB_VGA_SetPixel(x_1+(a*i),(y_1+(a*i)),color);
			  }
		  }
		  i=0;
	  }
      x_1 += a;
      y_1++;
    }
  return 0;
}

int	API_draw_line (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved)
{
  if (abs(x_2 - x_1) >= abs(y_2 - y_1))
    if (x_2 >= x_1)
      draw_lineX(x_1, y_1, x_2, y_2, color, weight, reserved);
    else
      draw_lineX(x_2, y_2, x_1, y_1, color, weight, reserved);
  else
    if (y_2 >= y_1)
      draw_lineY(x_1, y_1, x_2, y_2, color, weight, reserved);
    else
      draw_lineY(x_2, y_2, x_1, y_1, color, weight, reserved);
  return 0;
}

int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2)
{
	int i,j;
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
    int mask;
    int ord;
    char *bitmap;
    if(fontsytle==0)
    {
    	bitmap = font8x8_basic[letter];
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
    else if(fontsytle==1)
    {
    	bitmap = minimum_font[letter-32];
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
		}
	}
}

