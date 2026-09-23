#include <stdio.h>

#define N_INCREMENTS 10
#define INCREMENT_VALUE 4

void increment(int *value);
void increment_by(int *value, int increment_number);

int main(void) {
  printf("Enter a number: ");
  int number;
  scanf("%d", &number);

  for (int i = 0; i < N_INCREMENTS; ++i)
    increment(&number);

  printf("Number after %d increments: %d\n", N_INCREMENTS, number);

  for (int i = 0; i < N_INCREMENTS; ++i)
    increment_by(&number, INCREMENT_VALUE);

  printf("Number after %d increments by %d: %d", N_INCREMENTS, INCREMENT_VALUE, number);

  return 0;
}

void increment(int *value) {
  ++(*value);
}

void increment_by(int *value, int increment_number) {
  *value += increment_number;
}