#include <stdio.h>

int ord_arr_search(int x, int xs[], int n) {
  int i = 0;

  xs[n] = i;
  while (x > xs[i])
    i++;

  if (i < n && xs[i] == x)
    return i;

  return -1;
}

int ord_arr_insert(int x, int xs[], int n) {
  int index = 0, i;

  while (x > xs[index])
    index++;

  if (index > n)
    index = n;

  for (i = n; i > index; i--)
    xs[i] = xs[i - 1];

  xs[index] = x;
  return index;
}

int ord_arr_remove(int x, int xs[], int n) {
  int index = ord_arr_search(x, xs, n), i;

  if (index != -1) {
    for (i = index; i < n; i++)
      xs[i] = xs[i + 1];

    return index;
  }

  return -1;
}

void print(int xs[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", xs[i]);

  printf("\n");
}

int main() {
  int xs[10], i;

  for (i = 0; i < 10; i++)
    xs[i] = i + 1;

  print(xs, 10);
  ord_arr_remove(4, xs, 10);
  print(xs, 9);
  ord_arr_insert(11, xs, 9);
  print(xs, 10);

  return 0;
}
