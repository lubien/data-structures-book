#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node * next;
} node_t;

typedef struct doubly_node {
  int value;
  struct doubly_node * prev;
  struct doubly_node * next;
} doubly_node_t;

void print_list(node_t * xs);
void unshift(int x, node_t ** head);
void push(int x, node_t ** head);

node_t * move_first_to_last(node_t * xs) {
  int first = xs->value;
  xs = xs->next;

  node_t * results = NULL;
  push(xs->value, &results);
  node_t * head = results;

  while ((xs = xs->next) != NULL) {
    push(xs->value, &results);
    results = results->next;
  }

  push(first, &results);

  return head;
}

node_t * reverse(node_t * xs) {
  node_t * results = NULL;

  while (xs != NULL) {
    unshift(xs->value, &results);
    xs = xs->next;
  }

  return results;
}

node_t * sum_opposites(node_t * xs) {
  node_t * results = malloc(sizeof(node_t));
  node_t * head = results;

  doubly_node_t * top = malloc(sizeof(doubly_node_t));
  doubly_node_t * bottom = top;
  doubly_node_t * doubly_to_add;

  while (xs != NULL) {
    doubly_to_add = malloc(sizeof(doubly_node_t));
    doubly_to_add->prev = bottom;
    doubly_to_add->value = xs->value;
    bottom->next = doubly_to_add;

    xs = xs->next;
    bottom = bottom->next;
  }

  doubly_node_t * helper = top->next;
  free(top);
  top = helper;

  while (top != NULL) {
    push(top->value + bottom->value, &results);

    bottom = bottom->prev;
    free(bottom->next);
    bottom->next = NULL;

    helper = top->next;
    free(top);
    top = helper;
    /* top->prev = NULL; */ // not sure if I must

    results = results->next;
  }

  return head->next;
}

int main() {
  node_t * xs = NULL;

  push(1, &xs);
  push(2, &xs);
  push(3, &xs);
  push(4, &xs);
  push(5, &xs);
  push(6, &xs);
  push(7, &xs);
  push(8, &xs);
  push(9, &xs);
  push(10, &xs);

  print_list(xs);

  node_t * first = move_first_to_last(xs);

  print_list(first);

  node_t * second = reverse(xs);

  print_list(second);

  node_t * third = sum_opposites(xs);

  print_list(third);

  return 0;
}

void print_list(node_t * xs) {
  while (xs != NULL) {
    printf("%d ", xs->value);
    xs = xs->next;
  }

  printf("\n");
}

void unshift(int x, node_t ** head) {
  node_t * ref = *head;

  node_t * to_add = malloc(sizeof(node_t));
  to_add->value = x;
  to_add->next = ref;

  *head = to_add;
}

void push(int x, node_t ** head) {
  node_t * ref = *head;
  node_t * to_add = malloc(sizeof(node_t));
  to_add->value = x;
  to_add->next = NULL;

  if (ref == NULL) {
    *head = to_add;
    return;
  }

  while (ref->next != NULL)
    ref = ref->next;

  ref->next = to_add;
}
