#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
  int *numbers = malloc(sizeof(int) * SIZE);

  if (numbers == NULL)
    return 1;

  int *p = numbers;

  for (int i = 0; p < (numbers + SIZE); ++p, ++i)
    *p = i;

  int *copy = malloc(sizeof(int) * SIZE);

  if (copy == NULL)
    return 1;

  for (int i = 0; i < SIZE; ++i)
    *(copy + i) = *(numbers + i);

  free(numbers);

  printf("%d", *(copy + 3));

  // memory leak, copy is still allocted

  return 0;
}