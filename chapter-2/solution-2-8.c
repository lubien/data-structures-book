#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node * next;
} node_t;

node_t * head;

void find(int x, node_t ** previous, node_t ** found) {
  head->value = x;

  node_t * prev = head;
  node_t * ref = head->next;

  while (ref->value < x) {
    prev = ref;
    ref = ref->next;
  }

  *previous = prev;
  *found = ref;
}

int insert(int x) {
  node_t * to_add = malloc(sizeof(node_t));
  to_add->value = x;

  if (head->next == NULL) {
    to_add->next = head;
    head->next = to_add;
    return 1;
  }

  head->value = x;

  node_t * prev;
  node_t * ref;
  find(x, &prev, &ref);

  prev->next = to_add;
  to_add->next = ref;
  return 1;
}

int pop(int x) {
  if (head->next == NULL) {
    printf("Underflow\n");
    return 0;
  }

  head->value = x;

  node_t * prev;
  node_t * ref;
  find(x, &prev, &ref);

  if (ref->value == x) {
    prev->next = ref->next;
    free(ref);
    return 1;
  }

  printf("Key %d not found\n", x);

  return 0;
}

void print_list() {
  node_t * ref = head;

  while ((ref = ref->next) != head)
    printf("%d ", ref->value);

  printf("\n");
}

int main() {
  head = malloc(sizeof(node_t));
  insert(10);
  insert(1);
  insert(11);

  print_list();

  pop(10);
  pop(1);
  pop(11);

  print_list();

  return 0;
}
