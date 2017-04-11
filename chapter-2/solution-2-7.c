#include <stdio.h>
#include <math.h>

#define MEM_SIZE 10
#define A 0
#define B 1
#define TOP 0
#define START 1
#define FIRST_INDEX 2
#define DIRECTION 3
#define LIMIT 4

int mem[MEM_SIZE], stack[2][5];

int out_of_mem_range(int index) {
  return index >= MEM_SIZE || index < 0;
}

int insert(int x, int S) {
  int pos;

  if (out_of_mem_range(stack[S][TOP]) &&
      out_of_mem_range(stack[S][START])
     ) {
    pos = stack[S][FIRST_INDEX];
    stack[S][TOP] = stack[S][START] = pos;
    mem[pos] = x;

    return 1;
  }

  pos = stack[S][TOP] + stack[S][DIRECTION];

  if (pos == stack[S][LIMIT]) {
    printf("Overflow for %d\n", x);
    return 0;
  }

  stack[S][TOP] = pos;
  mem[stack[S][TOP]] = x;

  return 1;
}

int pop(int S) {
  if (out_of_mem_range(stack[S][TOP]) ||
      out_of_mem_range(stack[S][START])
     ) {
    printf("Undeflow\n");

    return 0;
  }

  mem[stack[S][TOP]] = 0;
  stack[S][TOP] -= stack[S][DIRECTION];

  if (stack[S][TOP] == stack[S][FIRST_INDEX] - stack[S][DIRECTION])
    stack[S][START] = stack[S][FIRST_INDEX] - stack[S][DIRECTION];

  return 1;
}

void printf_mem() {
  int i = 0;
  while (i < 10)
    printf("%2d ", mem[i++]);

  printf("\n");
}

int main() {
  stack[A][TOP] = -1;
  stack[A][START] = -1;
  stack[A][FIRST_INDEX] = 0;
  stack[A][DIRECTION] = 1;
  stack[A][LIMIT] = floor(MEM_SIZE / 2);
  stack[B][TOP] = MEM_SIZE;
  stack[B][START] = MEM_SIZE;
  stack[B][FIRST_INDEX] = MEM_SIZE - 1;
  stack[B][DIRECTION] = -1;
  stack[B][LIMIT] = floor(MEM_SIZE / 2) - 1;

  int i;

  i = 10;
  while (i <= 16) // Overflow
    insert(i++, A);

  i = 1;
  while (i <= 6) // Overflow
    insert(i++, B);

  printf_mem();

  i = 1;
  while (i++ <= 6) // Underflow
    pop(A);

  i = 1;
  while (i++ <= 6) // Underflow
    pop(B);

  printf_mem();

  return 0;
}
