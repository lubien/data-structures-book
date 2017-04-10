#include <stdio.h>
#define M 10

// Ignore the search algorithm in this case
int search(int x, int xs[], int n);

void insert(int x, int xs[], int * n) {
  if (*n < M) {
    if (search(x, xs, *n)) {
      xs[*n] = x;
      *n = *n + 1;
    } else {
      printf("Element already in the array\n");
    }
  } else {
    printf("Overflow\n");
  }
}

int main() {
  int i, n = 5, xs[M];

  for (i = 0; i < 5; ++i)
    xs[i] = i + 1;

  insert(10, xs, &n);
  insert(100, xs, &n);
  insert(1000, xs, &n);
  insert(10000, xs, &n);
  insert(100000, xs, &n);
  insert(1000000, xs, &n); // overflow

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
