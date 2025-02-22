#ifndef PONG_LOG
#define PONG_LOG

void racketControl(int *racket_left, int *racket_right, int control_button);
void ballControl(int *ball_x, int *ball_y, int *ball_direction, int racket_left, int racket_right, int *score);

#endif