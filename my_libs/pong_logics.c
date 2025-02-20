
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