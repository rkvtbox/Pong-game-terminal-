#include "../my_libs/display.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FIELD_Y 25 // middle at 40
#define FIELD_X 81 // middle at 13

// void measureDisplaySize(int *display_size_x, int *display_size_y, int
// *game_status);

int main(void) {
  char control_button = '\0';
  // int *ball_x = 0, *ball_y = 0;
  // int *racket_left = 0, *racket_right = 0;

  int display_size_x = 0, display_size_y = 0;

  // score and players_name- array of two elements 0 - left, 1 - right
  int score[2] = {0};
  // char players_name[2] = {0};

  int game_status = 99;
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
  curs_set(0); // hide cursor
  noecho();

  while (control_button != 'q') {
    
      measureDisplaySize(&display_size_x, &display_size_y, &game_status);
      if (game_status != 99) {
      drawBorder(display_size_x, display_size_y, score);
      }
    control_button = getch();
  }
  endwin();
  return 0;
}


