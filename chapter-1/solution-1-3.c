#include <stdio.h>

int factorial(int n) {
  int acc, i;

  for (i = acc = 1; i <= n; i++)
    acc *= i;

  return acc;
}

int main() {
  int i;

  for (i = 0; i < 10; i++)
    printf("%d => %6d\n", i, factorial(i));

  return 0;
}
