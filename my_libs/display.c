#include <ncurses.h>

#define FIELD_Y 25 // middle at 40
#define FIELD_X 83 // middle at 13

void measureDisplaySize(int *display_size_x, int *display_size_y,
                        int *game_status) {
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

void drawField(int display_size_x, int display_size_y, int *score,
               int racket_left, int racket_right, int ball_x, int ball_y) {
  int border_left = display_size_x / 2 - FIELD_X / 2;
  int border_top = display_size_y / 2 - FIELD_Y / 2;

  for (int y = 0; y < FIELD_Y; y++) {
    for (int x = 0; x < FIELD_X; x++) {
      move(border_top + y, border_left + x);
      if (y == 24 || y == 0) {
        printw("#");
      } else if (x == 0 || x == FIELD_X - 1) {
        printw("#");
      } else if (y != 0 && y != FIELD_Y && x == 41) {
        printw("|");
      } else if ((y == racket_left || y == racket_left - 1 ||
                  y == racket_left - 2) &&
                 x == 2) {
        printw("|");
      } else if ((y == racket_right || y == racket_right - 1 ||
                  y == racket_right - 2) &&
                 x == FIELD_X - 3) {
        printw("|");

      } else if (y == ball_y && x == ball_x) {
        printw("o");
      }
    }
  }

  move(border_top, border_left + 10);
  printw(" %d ", score[0]);
  move(border_top, border_left + 67);
  printw(" %d ", score[1]);
  refresh();
}

void drawMenu(int display_size_x, int display_size_y, int *game_status,
              int control_button) {
  clear();
  int border_left = display_size_x / 2 - FIELD_X / 2;
  int border_top = display_size_y / 2 - FIELD_Y / 2;
  static int menu_navigation_status = 0;

  if (control_button == KEY_DOWN) {
    if (menu_navigation_status == 4) {
        menu_navigation_status = 0;
    } else {
        menu_navigation_status++;
    }
} else if (control_button == KEY_UP) {
    if (menu_navigation_status == 0) {
        menu_navigation_status = 4;
    } else {
        menu_navigation_status--;
    }
}

  printw("%d",menu_navigation_status);

  for (int y = 0; y < FIELD_Y; y++) {
    for (int x = 0; x < FIELD_X; x++) {
      move(border_top + y, border_left + x);
      if (y == 24 || y == 0) {
        printw("*");
      } else if (x == 0 || x == FIELD_X - 1) {
        printw("*");
      }
    }
  }

printw("%d", *game_status);

  move(border_top + 17, border_left + 30);
  printw(menu_navigation_status == 0 ? ">  START GAME  <  " : "   START GAME  ");

  move(border_top + 18, border_left + 26);
  printw(menu_navigation_status == 1 ? ">  Enter Players Names  <" : "   Enter Players Names ");

  move(border_top + 19, border_left + 29);
  printw(menu_navigation_status == 2 ? ">  Hall of Fame  <" : "   Hall of Fame");

  move(border_top + 20, border_left + 30);
  printw(menu_navigation_status == 3 ? ">  About Game  <" : "   About Game");

  move(border_top + 21, border_left + 33);
  printw(menu_navigation_status == 4 ? ">  Exit  <" : "   Exit");
    
  
  refresh();
}