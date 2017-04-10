#include <stdio.h>

int search(int x, int xs[], int n) {
  int i = 0;

  xs[n] = x;

  while (xs[i] != x)
    ++i;

  if (i != n)
    return i;

  return -1;
}

int main() {
  int i, n = 5, xs[] = {1, 2, 3, 4, 5};

  for (i = 0; i < 10; i++)
    printf("find(%d) => %2d\n", i, search(i, xs, n));
  return 0;
}
