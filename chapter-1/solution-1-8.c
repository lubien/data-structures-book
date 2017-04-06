#include <stdio.h>
#include <math.h>
#define LEFT 0
#define RIGHT 1

int Ts[3][3] = {
  {1, 2, 3},
  {0, 0, 0},
  {0, 0, 0}
};

int top(int i) {
  int j;
  for (j = 0; j < 3; j++)
    if (Ts[i][j] > 0)
      return j;

  return 2;
}

int blank_top(int i) {
  int j;
  for (j = 2; j > -1; j--)
    if (Ts[i][j] == 0)
      return j;

  return 2;
}

int valid_move_between(int topmost_i, int topmost_j) {
  if (topmost_j == 0) {
    return RIGHT;
  } else if (topmost_i == 0) {
    return LEFT;
  } else if (topmost_i < topmost_j) {
    return RIGHT;
  }
  return LEFT;
}

void move(int i, int j) {
  int top_i = top(i), top_j = top(j);
  int topmost_i = Ts[i][top_i], topmost_j = Ts[j][top_j];
  int direction = valid_move_between(topmost_i, topmost_j);

  int to;
  if (direction == RIGHT) {
    to = blank_top(j);
    Ts[j][to] = topmost_i;
    Ts[i][top_i] = 0;
  } else {
    to = blank_top(i);
    Ts[i][to] = topmost_j;
    Ts[j][top_j] = 0;
  }
}

void print() {
  int i;
  for (i = 0; i < 3; i++)
    printf("%d %d %d\n", Ts[0][i], Ts[1][i], Ts[2][i]);
  printf("\n");
}

int main() {
  int steps = pow(2, 3) - 1;
  int current_op = 1;

  while(steps-- > 0) {
    switch(current_op++) {
      case 1:
        printf("A -> B\n");
        move(0, 1);
        print();
        break;

      case 2:
        printf("A -> C\n");
        move(0, 2);
        print();
        break;

      case 3:
        printf("B -> C\n");
        move(1, 2);
        print();
    }

    // current_op++;
    if (current_op > 3)
      current_op = 1;
  }

  return 0;
}
