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

int main() {
  int sparse[ROWS][COLS] = {
    {1, 0, 0},
    {0, 0, 1},
    {1, 0, 1}
  };

  print_nodes(sparse_to_list(sparse));
}
