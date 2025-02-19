#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FIELD_Y 25 // middle at 40
#define FIELD_X 81 // middle at 13

// #include "../my_libs/display.h"

void measureDisplaySize(int *display_size_x, int *display_size_y,
                        int *game_status);
// void drawField(int *game_status, int display_size_x, int display_size_y);

int main(void) {
  char control_button = '\0';
  // int *ball_x = 0, *ball_y = 0;
  // int *racket_left = 0, *racket_right = 0;

  int display_size_x = 0, display_size_y = 0;

  // score and players_name- array of two elements 0 - left, 1 - right
  // int score[2];
  // char players_name[2] = {0};

  int game_status = 0;
  /*
  Game status:
   99 - display error
    0 - menu
    1 - enter players names
    2 - play game
    3 - hall of fame
    4 - settings
    5 - about
 */

  // ncurses initialization & setup
  initscr();
  // how to hide cursor?
  noecho();

  while (control_button != 'q') {

    measureDisplaySize(&display_size_x, &display_size_y, &game_status);

    control_button = getch();
  }
  endwin();
  return 0;
}

void measureDisplaySize(int *display_size_x, int *display_size_y,
                        int *game_status) {
  clear();
  // read size of display
  getmaxyx(stdscr, *display_size_y, *display_size_x);

  printw("\n%d %d\n", *display_size_x, *display_size_y);
  printw("%d %d", FIELD_X, FIELD_Y);
  
  if (*display_size_y < FIELD_Y && *display_size_x < FIELD_X) {
    *game_status = 99;
    move(*display_size_y / 2, (*display_size_x / 2) - 20);
    printw("Make window BIGGER! or press q for exit...");

  } else {
    *game_status = 0;
    printw("\nOK");
    
  }

  refresh();
}

/*
void drawField(int *game_status, int display_size_x, int display_size_y) {

  // calculate draw field
  int border_left = (display_size_x / 2) - (FIELD_X / 2) - 1;
  int border_right = (display_size_x / 2) + (FIELD_X / 2) + 1;

  int border_top = (display_size_y / 2) - (FIELD_Y / 2) - 1;
  int border_bottom = (display_size_y / 2) + (FIELD_Y / 2) + 1;

  for (int y = 0; y < FIELD_Y + 2; y++) {
    for (int x = 0; x < FIELD_X + 2; x++) {
      move(border_top + y, border_left + x);
      if (y == 0 || y + 1 == FIELD_Y || x == 0 || x + 1 == FIELD_X) {
        printw("#");
      }
    }
  }

  refresh();
}

*/
