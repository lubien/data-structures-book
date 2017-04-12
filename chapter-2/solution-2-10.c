#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  // Yea, this question requires the field below :/
  int info;
  struct node * next;
} node_t;

node_t * head;

// These functions from the previous solution.
// Their implementations does not concern this solution.
void find(int x, node_t ** previous, node_t ** found);
int insert(int x, int info);

void print_list() {
  node_t * ref = head;

  while ((ref = ref->next) != head)
    printf("[%d] => %d\n", ref->value, ref->info);

  printf("\n");
}

void update_key(int x, int to_key) {
  node_t * prev;
  node_t * ref;
  find(x, &prev, &ref);

  if (ref != head && ref->value == x) {
    prev->next = ref->next;
    insert(to_key, ref->info);
    free(ref);
  } else {
    printf("Value %d not found\n", x);
  }
}

int main() {
  head = malloc(sizeof(node_t));

  insert(10, 1000);
  insert(11, 1001);
  insert(12, 1002);

  print_list();

  update_key(11, 1);
  update_key(12, 21);
  update_key(13, 23); // Not found

  print_list();

  return 0;
}

// You may ignore below

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

int insert(int x, int info) {
  node_t * to_add = malloc(sizeof(node_t));
  to_add->value = x;
  to_add->info = info;

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
