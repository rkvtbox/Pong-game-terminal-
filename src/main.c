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
  int control_button = '\0';
  int ball_x = 24, ball_y = 7;
  int racket_left = 8, racket_right = 12;

  int display_size_x = 0, display_size_y = 0;

  // score and players_name- array of two elements 0 - left, 1 - right
  int score[2] = {0};
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
    100 - exit
 */

  // ncurses initialization & setup
  initscr();
  keypad(stdscr, TRUE);
  curs_set(0); // hide cursor
  noecho();

  do {
    refresh();

    getmaxyx(stdscr, display_size_y, display_size_x);

    while (display_size_y < FIELD_Y && display_size_x < FIELD_X) {
      measureDisplaySize(&display_size_x, &display_size_y, &game_status);
      refresh();
    }
    if (game_status == 0) {
      drawMenu(display_size_x, display_size_y, &game_status, control_button);
    }
    if (game_status == 2) {
      drawField(display_size_x, display_size_y, score, racket_left,
                racket_right, ball_x, ball_y);
    }
  } while ((control_button = getch()) != 'q');
  
  endwin();
  return 0;
}
