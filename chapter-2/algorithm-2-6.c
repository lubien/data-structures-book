#include <stdio.h>
#define M 10

// Ignore the search algorithm in this case
int search(int x, int xs[], int n);

int dropAt(int x, int xs[], int * n) {
  int i, index = search(x, xs, *n), recovered;

  if (n != 0) {
    if (index != -1) {
      recovered = xs[index];

      for (i = index; i < *n - 1; ++i)
        xs[i] = xs[i + 1];

      *n = *n - 1;

      return recovered;
    } else {
      printf("Element is not in the array\n");
    }
  } else {
    printf("Underflow\n");
  }
}

int main() {
  int i, n = 10, xs[M];

  for (i = 0; i < n; ++i)
    xs[i] = i + 1;

  for (i = 5; i <= M; ++i)
    dropAt(i, xs, &n);

  printf("%d\n", n);
  for (i = 0; i < n; ++i)
    printf("%d ", xs[i]);

  printf("\n");

  return 0;
}

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
