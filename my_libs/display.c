#include <ncurses.h>

#define FIELD_Y 25 // middle at 40
#define FIELD_X 81 // middle at 13


void measureDisplaySize(int *display_size_x, int *display_size_y, int *game_status) {
clear();
// read size of display
getmaxyx(stdscr, *display_size_y, *display_size_x);


if (*display_size_y < FIELD_Y && *display_size_x < FIELD_X) {
*game_status = 99;
move(*display_size_y / 2, (*display_size_x / 2) - 20);
printw("Make window BIGGER! or press q for exit...");

} else {
*game_status = 0;


}

refresh();
}

void drawBorder(int display_size_x, int display_size_y, int *score) {
  int border_left = display_size_x/2 - FIELD_X/2;
  int border_top = display_size_y/2 - FIELD_Y/2;

  for (int y = 0; y < FIELD_Y; y++) {
    for (int x = 0; x < FIELD_X; x++) {
      move(border_top + y, border_left+x);
      if (y == 24 || y == 0) {
        printw("#");
      } else if (x == 0 || x == 80) {
        printw("#");
      } else if (y != 0 && y != 81 && x == 40) {
        printw("|");
      }

    }
  }
  
  move(border_top, border_left+10);
  printw(" %d ", score[0]);
  move(border_top, border_left+67);
  printw(" %d ", score[1]);

}


