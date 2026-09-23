#include <stdio.h>

#define SIZE 5

void read_array(int *numbers, size_t size);
int *find_max(int *array, size_t size);

int main(void) {
  int numbers[SIZE];

  read_array(numbers, SIZE);

  int* max = find_max(numbers, SIZE);

  printf("The max value in the array is %d", *max);

  return 0;
}

void read_array(int *numbers, size_t size) {
  for (int *p = numbers; p < (numbers + size); ++p) {
    printf("Enter a number: ");
    scanf("%d", p);
  }
}

int *find_max(int *numbers, size_t size) {
  int *p_max = numbers;

  for (int *p = numbers; p < (numbers + size); ++p)
    if (*p > *p_max)
      p_max = p;

  return p_max;
}