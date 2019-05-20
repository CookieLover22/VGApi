


int API_draw_bitmap(int x_lup, int y_lup, int bm_nr);
int API_draw_text (int x_lup, int y_lup, int color, char text[100], char *fontname, int fontsize, int fontsytle, int reserved);
int API_draw_char (int x_lup, int y_lup, int color, char letter, char *fontname, int fontsize, int fontsytle, int reserved);
int draw_lineX (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);
int draw_lineY (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);
int API_draw_line (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);
int API_draw_rectangle(int x, int y, int width, int height, int color, int filled, int reserved1, int reserved2);
int API_draw_circle (int xc, int yc, int r, int color, int reserved);
void drawCircle(int xc, int yc, int x, int y, int color);
int API_draw_figure (int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4, int x_5, int y_5, int color, int reserved);
int API_clearscreen(int color);


