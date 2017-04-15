#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

typedef struct node {
  int row;
  int col;
  int value;
  struct node * next;
} node_t;

node_t * sparse_to_list(int M[ROWS][COLS]);
void print_nodes(node_t * ref);

int find(int row, int col, node_t * xs) {
  if (xs == NULL)
    return 0;

  do {
    if (xs->row == row && xs->col == col)
      return xs->value;
  } while ((xs = xs->next) != NULL);

  return 0;
}

int main() {
  int sparse[ROWS][COLS] = {
    {1, 0, 0},
    {0, 0, 1},
    {1, 0, 1}
  };

  node_t * xs = sparse_to_list(sparse);

  print_nodes(xs);

  printf("find(0, 0, xs) => %d\n", find(0, 0, xs));
  printf("find(0, 1, xs) => %d\n", find(0, 1, xs));
}

node_t * sparse_to_list(int M[ROWS][COLS]) {
  int i, j;
  node_t * head = malloc(sizeof(node_t));
  node_t * to_add;

  for (i = ROWS - 1; i >= 0; i--)
    for (j = COLS - 1; j >= 0; j--) {
      if (M[i][j] == 0) continue;
      to_add = malloc(sizeof(node_t));
      to_add->row = i;
      to_add->col = j;
      to_add->value = M[i][j];

      to_add->next = head->next;
      head->next = to_add;
    }

  return head->next;
}

void print_nodes(node_t * ref) {
  if (ref == NULL)
    return;

  do {
    printf("[(%d, %d) => %d] ", ref->row, ref->col, ref->value);
  } while ((ref = ref->next) != NULL);

  printf("\n");
}
