#include <stdio.h>
#include <string.h>

// Known issue:
// You can only have (sizeof(alphabet)) intermediate values without
// messing the output.
int current_char = 'a';

int is_var(char c) {
  return c >= 'A' && c <= 'Z';
}

char evaluate(char exp[]) {
  int size = strlen(exp);
  char child_a[size - 1];
  char child_b[size - 1];
  char op = exp[0];
  char lhs, rhs;
  char result;

  if (is_var(exp[1])) {
    lhs = exp[1];
  } else {
    memmove(child_a, exp + 1, size);
    lhs = evaluate(child_a);
    memmove(exp + 1, child_a, size);
  }

  if (is_var(exp[2])) {
    rhs = exp[2];
  } else {
    memmove(child_b, exp + 2, size);
    rhs = evaluate(child_b);
    memmove(exp + 2, child_b, size);
  }

  if (rhs && lhs) {
    result = current_char++;
    printf("%c = %c %c %c\n", result, lhs, op, rhs);
    memset(exp, result, 1);
    memmove(&exp[1], &exp[2], size - 1);
    memmove(&exp[1], &exp[2], size - 1);
  }

  return result;
}

int main() {
  /* char exp[] = "+AC"; */
  /* char exp[] = "+*ABC"; */
  char exp[] = "+*A/BC*DE";

  printf("Input: %s\n", exp);
  evaluate(exp);
  printf("Result: %s\n", exp);
}
