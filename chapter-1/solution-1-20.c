#include <stdio.h>

int fib(int n) {
  int last[] = {1, 1};

  int i, tmp;
  for (i = 2; i <= n; i++) {
    tmp = last[0];
    last[0] = last[1];
    last[1] = tmp + last[0];
  }

  return last[1];
}

int main() {
  int i;
  for (i = 0; i < 20; i++)
    printf("Fib %2d => %4d\n", i, fib(i));

  return 0;
}
