#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]) {
  int i, len = strlen(str);

  for (i = 0; i < len; i++)
    if (str[i] != str[len - i - 1])
      return 0;

  return 1;
}

int main() {
  char foo[] = "blue";
  char bar[] = "racecar";

  printf("%s => %i\n", foo, is_palindrome(foo));
  printf("%s => %i\n", bar, is_palindrome(bar));
}
