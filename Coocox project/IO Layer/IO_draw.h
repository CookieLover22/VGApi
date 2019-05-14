int API_draw_bitmap(int x_lup, int y_lup, int bm_nr);
int API_draw_text (int x_lup, int y_lup, int color, char text[100], char *fontname, int fontsize, int fontsytle, int reserved);
int API_draw_char (int x_lup, int y_lup, int color, char letter, char *fontname, int fontsize, int fontsytle, int reserved);
int draw_lineX (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);
int draw_lineY (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);
int API_draw_line (int x_1, int y_1, int x_2, int y_2, int color, int weight, int reserved);
int API_draw_rectangle(int x_lup, int y_lup, int x_rdown, int y_rdown, int color, int style, int reserved1, int reserved2);
int API_clearscreen(int color);


