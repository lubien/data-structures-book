#include <stdio.h>

int search(int x, int xs[], int n) {
  int i = 0, found = -1;

  while (i <= n) {
    if (xs[i] == x) {
      found = i;
      i++;
    } else {
      i++;
    }
  }

  return found;
}

int main() {
  int i, n = 5, xs[] = {1, 2, 3, 4, 5};

  for (i = 0; i < 10; i++)
    printf("find(%d) => %2d\n", i, search(i, xs, n));
  return 0;
}
