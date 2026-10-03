#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

size_t count_if(const int *numbers, size_t size, bool (*predicate)(int value, void *context), void *context);
bool greater_than(int value, void *context);

int main(void) {
  int numbers[SIZE] = {2, 4, 7, 10, 13};
  int threshold = 5;

  printf("The numbers greater than %d are %zu.", threshold, count_if(numbers, SIZE, greater_than, &threshold));

  return 0;
}

size_t count_if(const int *numbers, size_t size, bool (*predicate)(int value, void *context), void *context) {
  size_t greater_than_counter = 0;
  
  for (size_t i = 0; i < size; ++i) {
    if (predicate(*(numbers + i), context))
      ++greater_than_counter;
  }

  return greater_than_counter;
}


bool greater_than(int value, void *context) {
  int threshold = *(int *)context;
  return value > threshold;
}