#include <stdio.h>
#define MEM_SIZE 10
#define FIRST 0
#define LAST 1
int deque[MEM_SIZE];

int front = -1, back = -1;

int insert(int x, int pointer) {
  int pos;

  if (pointer == LAST) {
    pos = (back + 1) % MEM_SIZE;

    if (pos == front) {
      printf("Overflow for %d\n", x);
      return 0;
    } else {
      back = pos;
      deque[back] = x;

      if (front == -1)
        front = back;

      return 1;
    }
  }

  if (front <= 0)
    pos = MEM_SIZE - 1;
  else
    pos = (front - 1) % MEM_SIZE;

  if (pos == back) {
    printf("Overflow for %d\n", x);
    return 0;
  } else {
    front = pos;
    deque[front] = x;

    if (back == -1)
      back = front;
  }

  return 1;
}

int pop(int pointer) {
  int pos;

  if (back == -1 && front == -1) {
    printf("Underflow\n");
    return 0;
  }

  if (back == front) {
    back = front = -1;
    return 1;
  }

  if (pointer == LAST) {
    pos = (back - 1) % MEM_SIZE;

    if (pos < 0)
      pos = MEM_SIZE - 1;

    back = pos;

    return 1;
  }

  pos = (front + 1) % MEM_SIZE;

  front = pos;

  return 1;
}

void print_deque() {
  int i = front;

  while (1) {
    printf("%d ", deque[i]);

    if (i == back)
      break;

    i = (i + 1) % MEM_SIZE;
  }

  printf("\n");
}

int main() {
  int i;

  i = 10;
  while (i <= 12)
    insert(i++, LAST);

  i = 3;
  while (i >= 1)
    insert(i--, FIRST);

  i = 0;
  while (i++ < 5)
    insert(1000, LAST); // One Overflow

  print_deque();

  i = 0;
  while (i++ < 11) // One Underflow
    pop(LAST);

  i = 0;
  while (i++ < 5)
    insert(1000, FIRST);

  i = 0;
  while (i++ < 5)
    pop(FIRST);

  print_deque(deque);

  return 0;
}
