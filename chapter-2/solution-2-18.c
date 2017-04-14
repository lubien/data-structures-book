#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct term {
  int coefficient;
  int degree;
  struct term * next;
} polynomial;

void add_term(int deg, int coe, polynomial * head) {
  polynomial * ref = head;

  while (ref->next != NULL && ref->next->degree > deg)
    ref = ref->next;

  if (ref->next != NULL && ref->next->degree == deg) {
    ref->coefficient += coe;
  } else {
    polynomial * to_add = malloc(sizeof(polynomial));
    to_add->coefficient = coe;
    to_add->degree = deg;
    to_add->next = ref->next;

    ref->next = to_add;
  }
}

int calculate(int x, polynomial * p) {
  int sum = 0;

  while ((p = p->next) != NULL)
    sum += p->coefficient * ((int) pow(x, p->degree));

  return sum;
}

void print_polynomial(polynomial * head) {
  int put_plus = 0;

  while ((head = head->next) != NULL) {
    if (put_plus++)
      printf(" + ");

    if (head->degree > 1)
      if (head->coefficient > 1)
        printf("%dx^%d", head->coefficient, head->degree);
      else
        printf("x^%d", head->degree);

    else if (head->degree == 1)
      if (head->coefficient > 1)
        printf("%dx", head->coefficient);
      else
        printf("x");

    else
      printf("%d", head->coefficient);
  }

  printf("\n");
}

polynomial * merge_polynomial(polynomial * P, polynomial * Q) {
  polynomial * xs = P->next;
  polynomial * ys = Q->next;
  polynomial * head = malloc(sizeof(polynomial));
  polynomial * result = head;

  while (xs != NULL || ys != NULL) {
    if (result->next == NULL) {
      result->next = malloc(sizeof(polynomial));
    }

    if (xs != NULL && (ys == NULL || xs->degree >= ys->degree)) {
      if (result->next->degree == xs->degree) {
        result->next->coefficient += xs->coefficient;
      } else {
        result->next->degree = xs->degree;
        result->next->coefficient = xs->coefficient;
      }

      xs = xs->next;
    } else {
      if (result->next->degree == ys->degree) {
        result->next->coefficient += ys->coefficient;
      } else {
        result->next->degree = ys->degree;
        result->next->coefficient = ys->coefficient;
      }

      ys = ys->next;
    }

    if ((xs == NULL || xs->degree != result->next->degree) &&
        (ys == NULL || ys->degree != result->next->degree))
      result = result->next;
  }

  return head;
}

int main() {
  polynomial * P = malloc(sizeof(polynomial));
  polynomial * Q = malloc(sizeof(polynomial));

  add_term(0, 5, P); // 5
  add_term(1, 2, P); // 2x
  add_term(2, 1, P); // x^2
  add_term(3, 2, P); // 2x^3
  add_term(4, 7, P); // 7x^4
  add_term(5, 2, P); // 2x^5

  add_term(1, 1, Q); // x
  add_term(2, 7, Q); // 7x^2
  add_term(3, 1, Q); // x^3
  add_term(4, 4, Q); // 4x^4

  printf("P(x)        = ");
  print_polynomial(P);
  printf("Q(x)        = ");
  print_polynomial(Q);

  printf("P(10)       = %d\n", calculate(10, P));
  printf("Q(10)       = %d\n", calculate(10, Q));

  printf("P(x) + Q(x) = ");
  print_polynomial(merge_polynomial(P, Q));

  return 0;
}
