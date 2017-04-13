#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node * next;
} node_t;

// This doesn't matter for the question:
void print_list(node_t * head);

node_t * push(int x, node_t * head) {
  node_t * ref = head;
  node_t * to_add = malloc(sizeof(node_t));
  to_add->value = x;
  to_add->next = NULL;

  while (ref->next != NULL)
   ref = ref->next;

  ref->next = to_add;

  return head;
}

// Yea mergesort, I'm looking to you.
node_t * sorted_merge(node_t * xs, node_t * ys) {
  node_t * head = malloc(sizeof(node_t));
  node_t * results = head;
  node_t * as = xs->next;
  node_t * bs = ys->next;

  while (as != NULL && bs != NULL) {
    if (as->value < bs->value) {
      results = push(as->value, results);
      as = as->next;
    } else {
      results = push(bs->value, results);
      bs = bs->next;
    }

    results = results->next;
  }

  if (as != NULL) {
    do {
      results = push(as->value, results);
      results = results->next;
    } while ((as = as->next) != NULL);
  }

  if (bs != NULL) {
    do {
      results = push(bs->value, results);
      results = results->next;
    } while ((bs = bs->next) != NULL);
  }

  return head;
}

int main() {
  node_t * xs = malloc(sizeof(node_t));
  node_t * ys = malloc(sizeof(node_t));

  xs = push(1, xs);
  xs = push(2, xs);
  xs = push(3, xs);
  xs = push(4, xs);
  xs = push(5, xs);
  xs = push(16, xs);
  xs = push(17, xs);
  xs = push(18, xs);
  xs = push(19, xs);
  xs = push(20, xs);

  ys = push(6, ys);
  ys = push(7, ys);
  ys = push(8, ys);
  ys = push(9, ys);
  ys = push(10, ys);
  ys = push(11, ys);
  ys = push(12, ys);
  ys = push(13, ys);
  ys = push(14, ys);
  ys = push(15, ys);
  ys = push(21, ys);
  ys = push(22, ys);
  ys = push(23, ys);
  ys = push(24, ys);
  ys = push(25, ys);

  print_list(xs);
  print_list(ys);

  node_t * zs = sorted_merge(xs, ys);

  print_list(zs);

  return 0;
}

void print_list(node_t * head) {
  node_t * ref = head;

  while ((ref = ref->next) != NULL)
    printf("%d ", ref->value);

  printf("\n");
}
