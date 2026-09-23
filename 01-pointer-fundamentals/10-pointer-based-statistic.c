#include <stdio.h>

void read_array(int *numbers, size_t size);
void statistics(const int *numbers, size_t size, int *min, int *max, double *average);

int main(void) {
  const size_t size = 5;
  int numbers[size];

  read_array(numbers, size);
  int max, min;
  double average;

  statistics(numbers, size, &min, &max, &average);

  printf("The minimum number is %d\n", min);
  printf("The maximum number is %d\n", max);
  printf("The average is %.2lf\n", average);

  return 0;
}

void read_array(int *numbers, size_t size) {
  for (int *p = numbers; p < (numbers + size); ++p) {
    printf("Enter a number: ");
    scanf("%d", p);
  }
}

void statistics(const int *numbers, size_t size, int *min, int *max, double *average) {
  *min = *numbers;
  *max = *numbers;

  int temp_sum = 0;

  for (const int *p = numbers; p < (numbers + size); ++p) {
    if (*max < *p)
      *max = *p;
    
    if (*min > *p)
      *min = *p;

    temp_sum += *p;
  }

  *average = (double) temp_sum / size;
}