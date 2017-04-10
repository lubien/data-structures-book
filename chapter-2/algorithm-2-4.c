#include <stdio.h>
#include <math.h>

int search(int x, int xs[], int n) {
  int low = 0, high = n - 1, mid, found = -1;

  while (low <= high) {
    mid = floor((low + high) / 2);

    if (xs[mid] == x) {
      found = mid;
      low = high + 1;
    } else if (xs[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
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
