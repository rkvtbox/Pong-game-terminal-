#ifndef DISPLAY_H
#define DISPLAY_H



void measureDisplaySize(int *display_size_x, int *display_size_y, int *game_status);
void drawField(int display_size_x, int display_size_y, int *score, int racket_left, int racket_right, int ball_x, int ball_y);
void drawMenu(int display_size_x, int display_size_y, int *game_status, int control_button);

#endif