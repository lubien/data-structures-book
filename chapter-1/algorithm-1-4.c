#include <stdio.h>

void hanoi(int n, int A[], int B[], int C[]) {
  if (n > 0) {
    hanoi(n - 1, A, C, B);

    int temp = A[n - 1];
    A[n - 1] = 0;
    B[n - 1] = temp;

    hanoi(n - 1, C, B, A);
  }
}

int main() {
  int A[] = {1, 2, 3};
  int B[] = {0, 0, 0};
  int C[] = {0, 0, 0};

  hanoi(3, A, B, C);

  int i;
  for (i = 0; i < 3; i++)
    printf("%d %d %d\n", A[i], B[i], C[i]);

  return 0;
}
