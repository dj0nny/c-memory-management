#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void) {
  int numbers[] = {42, 7, 19, 3, 100, 25};
  size_t size = sizeof(numbers) / sizeof(*numbers);

  qsort(numbers, size, sizeof(int), compare);

  for (size_t i = 0; i < size; ++i)
    printf("%d ", *(numbers + i));

  return 0;
}

int compare(const void *a, const void *b) {
  int x = *(const int *)a;
  int y = *(const int *)b;

  if (x < y)
    return -1;
  if (x > y)
    return 1;
  
  return 0;
}