#include "../my_libs/display.h"
#include "../my_libs/pong_logics.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FIELD_Y 25 // middle at 40
#define FIELD_X 84 // middle at 13

// void measureDisplaySize(int *display_size_x, int *display_size_y, int
// *game_status);

int main(void) {
  int control_button = '\0';
  int ball_x = 75, ball_y = 15;
  int ball_direction = 5;
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
  keypad(stdscr, TRUE); // read special keys
  curs_set(0); // hide cursor
  noecho();
  //nodelay(stdscr, TRUE); 
  halfdelay(1);

  do {
    
    control_button = getch();
    
    getmaxyx(stdscr, display_size_y, display_size_x);
    
    while (display_size_y < FIELD_Y && display_size_x < FIELD_X) {
      measureDisplaySize(&display_size_x, &display_size_y, &game_status);
      refresh();
    }
    if (game_status == 0) {
      drawMenu(display_size_x, display_size_y, &game_status, control_button);
    }

    if (game_status == 2) {
      printw("%d %d", ball_x, ball_y);
      drawField(display_size_x, display_size_y, score, racket_left,
                racket_right, ball_x, ball_y);
                
      racketControl(&racket_left, &racket_right, control_button);
      ballControl(&ball_x, &ball_y, &ball_direction, racket_left, racket_right, score);
      
      if (control_button == 'q') {
        game_status = 0;
      } 

      if (game_status == 0) {
        ball_x = 40;
        ball_y = 13;
      }
    }
    sleep(0.6);
    refresh();
  } while (game_status != 100);
  
  
  endwin();
  return 0;
}
