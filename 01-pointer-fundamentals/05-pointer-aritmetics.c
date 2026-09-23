#include <stdio.h>

int main(void) {
  int numbers[] = {10, 20, 30, 40, 50};

  const size_t count = sizeof(numbers) / sizeof(numbers[0]);

  for (int *i = numbers; i < numbers + count; ++i)
    printf("%d ", *i);

  return 0;
}