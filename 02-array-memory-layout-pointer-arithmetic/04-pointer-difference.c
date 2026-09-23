#include <stdio.h>
#include <stddef.h>

#define SIZE 10

int main(void) {
  int numbers[SIZE] = {-5, 101, -67, 3, 14, 57, 0, 33, -1100, 5};

  int *p_start = numbers + 3;
  int *p_end = numbers + 8;

  size_t distance = p_end - p_start;
  printf("Distance: %zu\n", distance);
  
  ptrdiff_t byte_distance = (char *)p_end - (char *)p_start; // scale to 1 byte
  printf("Distance in bytes: %td\n", byte_distance);

  printf("Address start: %p / Address end: %p\n", p_start, p_end);

  printf("Elements in between: \n");
  for (int *p = p_start + 1; p < p_end; ++p)
    printf("%d ", *p);


  return 0;
}