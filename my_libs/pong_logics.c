
void racketControl(int *racket_left, int *racket_right, int control_button) {
  if (control_button == 'a' && *racket_left > 3) {
    --(*racket_left);
  } else if (control_button == 'z' && *racket_left < 23) {
    ++(*racket_left);
  }

  if (control_button == 'k' && *racket_right > 3) {
    --(*racket_right);
  } else if (control_button == 'm' && *racket_right < 23) {
    ++(*racket_right);
  }
}

void ballControl(int *ball_x, int *ball_y, int *ball_direction, int racket_left,
                 int racket_right, int *score) {

  if (*ball_x == 1 || *ball_x == 2) {
    score[1]++;
    *ball_x = 41;
    *ball_y = 13;
    *ball_direction = -2;
  }

  if (*ball_x == 81 || *ball_x == 82) {
    score[0]++;
    *ball_x = 10;
    *ball_y = 13;
    *ball_direction = 4;
  }

  if (*ball_direction == -5 && *ball_y == 1) {
    *ball_direction = -1;
  } else if (*ball_direction == -5 && *ball_x == 3 && *ball_y == racket_left) {
    *ball_direction = 5;
  } else if (*ball_direction == -5 && *ball_x == 3 &&
             *ball_y == racket_left - 1) {
    *ball_direction = 4;
  } else if (*ball_direction == -5 && *ball_x == 3 &&
             *ball_y == racket_left - 2) {
    *ball_direction = 5;
  } else if (*ball_direction == -5) {
    *ball_x -= 1;
    *ball_y -= 1;
  }

  if (*ball_direction == -4 && (*ball_x == 3 || *ball_x == 4) &&
      *ball_y == racket_left) {
    *ball_direction = 5;
  } else if (*ball_direction == -4 && (*ball_x == 3 || *ball_x == 4) &&
             *ball_y == racket_left - 1) {
    *ball_direction = 4;
  } else if (*ball_direction == -4 && (*ball_x == 3 || *ball_x == 4) &&
             *ball_y == racket_left - 2) {
    *ball_direction = 5;
  } else if (*ball_direction == -4 && *ball_y == 1) {
    *ball_direction = -2;
  } else if (*ball_direction == -4) {
    *ball_x -= 2;
    *ball_y -= 1;
  }

  if (*ball_direction == -3 && *ball_x == 3 && *ball_y == racket_left) {
    *ball_direction = 2;
  } else if (*ball_direction == -3 && *ball_x == 3 &&
             *ball_y == racket_left - 1) {
    *ball_direction = 3;
  } else if (*ball_direction == -3 && *ball_x == 3 &&
             *ball_y == racket_left - 2) {
    *ball_direction = 4;
  } else if (*ball_direction == -3) {
    *ball_x -= 1;
  }
  if (*ball_direction == -2 && (*ball_x == 3 || *ball_x == 4) &&
      *ball_y == racket_left) {
    *ball_direction = 1;
  } else if (*ball_direction == -2 && (*ball_x == 3 || *ball_x == 4) &&
             *ball_y == racket_left - 1) {
    *ball_direction = 2;
  } else if (*ball_direction == -2 && (*ball_x == 3 || *ball_x == 4) &&
             *ball_y == racket_left - 2) {
    *ball_direction = 1;
  } else if (*ball_direction == -2 && *ball_y == 23) {
    *ball_direction = -4;
  } else if (*ball_direction == -2) {
    *ball_x -= 2;
    *ball_y += 1;
  }

  if (*ball_direction == -1 && *ball_x == 3 && *ball_y == racket_left) {
    *ball_direction = 1;
  } else if (*ball_direction == -1 && *ball_x == 3 &&
             *ball_y == racket_left - 1) {
    *ball_direction = 2;
  } else if (*ball_direction == -1 && *ball_x == 3 &&
             *ball_y == racket_left - 2) {
    *ball_direction = 1;
  } else if (*ball_direction == -1 && *ball_y == 23) {
    *ball_direction = -5;
  } else if (*ball_direction == -1) {
    *ball_x -= 1;
    *ball_y += 1;
  }

  if (*ball_direction == 5 && *ball_x == 79 && *ball_y == racket_right) {
    *ball_direction = -5;
  } else if (*ball_direction == 5 && *ball_x == 79 &&
             *ball_y == racket_right - 1) {
    *ball_direction = -4;
  } else if (*ball_direction == 5 && *ball_x == 79 &&
             *ball_y == racket_right - 2) {
    *ball_direction = -5;
  } else if (*ball_direction == 5 && *ball_y == 1) {
    *ball_direction = 1;

  } else if (*ball_direction == 5) {
    *ball_x += 1;
    *ball_y -= 1;
  }

  if (*ball_direction == 4 && (*ball_x == 79 || *ball_x == 78) &&
      *ball_y == racket_right) {
    *ball_direction = -5;
  } else if (*ball_direction == 4 && (*ball_x == 79 || *ball_x == 78) &&
             *ball_y == racket_right - 1) {
    *ball_direction = -4;
  } else if (*ball_direction == 4 && (*ball_x == 79 || *ball_x == 78) &&
             *ball_y == racket_right - 2) {
    *ball_direction = -5;
  } else if (*ball_direction == 4 && *ball_y == 1) {
    *ball_direction = 2;
  } else if (*ball_direction == 4) {
    *ball_x += 2;
    *ball_y -= 1;
  }

  if (*ball_direction == 3 && *ball_x == 79 && *ball_y == racket_right) {
    *ball_direction = -4;
  } else if (*ball_direction == 3 && *ball_x == 79 &&
             *ball_y == racket_right - 1) {
    *ball_direction = -3;
  } else if (*ball_direction == 3 && *ball_x == 79 &&
             *ball_y == racket_right - 2) {
    *ball_direction = -2;
  } else if (*ball_direction == 3) {
    *ball_x += 1;
  }

  if (*ball_direction == 2 && (*ball_x == 79 || *ball_x == 78) &&
      *ball_y == racket_right) {
    *ball_direction = -1;
  } else if (*ball_direction == 2 && (*ball_x == 79 || *ball_x == 78) &&
             *ball_y == racket_right - 1) {
    *ball_direction = -2;
  } else if (*ball_direction == 2 && (*ball_x == 79 || *ball_x == 78) &&
             *ball_y == racket_right - 2) {
    *ball_direction = -1;
  } else if (*ball_direction == 2 && *ball_y == 23) {
    *ball_direction = 4;
  } else if (*ball_direction == 2) {
    *ball_x += 2;
    *ball_y += 1;
  }

  if (*ball_direction == 1 && *ball_x == 79 && *ball_y == racket_right) {
    *ball_direction = -1;
  } else if (*ball_direction == 1 && *ball_x == 79 &&
             *ball_y == racket_right - 1) {
    *ball_direction = -2;
  } else if (*ball_direction == 1 && *ball_x == 79 &&
             *ball_y == racket_right - 2) {
    *ball_direction = -1;
  } else if (*ball_direction == 1 && *ball_y == 23) {
    *ball_direction = 5;
  } else if (*ball_direction == 1) {
    *ball_x += 1;
    *ball_y += 1;
  }
}