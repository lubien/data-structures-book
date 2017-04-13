#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node * next;
} node_t;

// This doesn't matter for the question:
void unshift(int x, node_t ** head);
void print_list(node_t * head);

node_t * merge(node_t * xs, node_t * ys) {
  node_t * head = malloc(sizeof(node_t));
  node_t * results = head;
  node_t * to_add;
  node_t * ref;

  ref = xs;
  int finished_lists = 0;

  while (1) {
    ref = ref->next;

    if (ref == NULL) {
      ++finished_lists;

      if (finished_lists < 2)
        ref = ys;
      else
        break;
    } else {
      to_add = malloc(sizeof(node_t));
      to_add->value = ref->value;
      results->next = to_add;

      results = results->next;
    }
  }

  return head;
}

int main() {
  int i;

  node_t * xs = malloc(sizeof(node_t));
  node_t * ys = malloc(sizeof(node_t));

  i = 0;
  while (i++ < 3)
    unshift(i, &xs);

  i = 0;
  while (i++ < 3)
    unshift(i + 10, &ys);

  print_list(xs);
  print_list(ys);

  node_t * zs = merge(xs, ys);

  print_list(zs);

  return 0;
}

void unshift(int x, node_t ** head) {
  node_t * ref = (*head)->next;

  node_t * to_add = malloc(sizeof(node_t));
  to_add->value = x;
  to_add->next = ref;

  (*head)->next = to_add;
}

void print_list(node_t * head) {
  node_t * ref = head;

  while ((ref = ref->next) != NULL)
    printf("%d ", ref->value);

  printf("\n");
}
