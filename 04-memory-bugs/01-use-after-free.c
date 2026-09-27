#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
  int *numbers = malloc(sizeof(int) * SIZE);

  if (numbers == NULL)
    return 1;

  int *p = numbers;

  for (int i = 0;p < (numbers + SIZE); ++p, ++i)
    *p = i;

  for (p = numbers; p < (numbers + SIZE); ++p)
    printf("%d ", *p);

  free(numbers);

  printf("\n%d", *(numbers + 2)); // -> undefined behaviour

  return 0;
}