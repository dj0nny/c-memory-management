#include <stdio.h>

#define SIZE 5

int main(void) {
  int numbers[SIZE] = {0, 1, 2, 3, 4}; // 0 -> 4
  int *one_past_the_end = numbers + SIZE; // 5

  for (int *p = numbers; p < one_past_the_end; ++p)
    printf("%d ", *p);

  return 0;
}