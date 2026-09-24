#include <stdio.h>
#include <stdlib.h>

void read_array(const int *dynamic_array, size_t size);
void print_array(const int *dynamic_array, size_t size);
int calculate_sum(const int *dynamic_array, size_t size);

int main(void) {
  printf("How many int(s) do you want to store? ");
  int size;
  scanf("%d", &size);

  if (size > 0) {
    int *dynamic_array = malloc(sizeof(int) * size);

    read_array(dynamic_array, size);
    print_array(dynamic_array, size);

    int array_sum = calculate_sum(dynamic_array, size);

    printf("The sum of the elements is: %d\n", array_sum);
    printf("The average is: %.2lf\n", (double) array_sum / size);

    free(dynamic_array);

  } else
    printf("Invalid size");

  

  return 0;
}

void read_array(const int *dynamic_array, size_t size) {
  for (const int *p = dynamic_array; p < (dynamic_array + size); ++p) {
    printf("Enter a number: ");
    scanf("%d", p);
  }
}

void print_array(const int *dynamic_array, size_t size) {
  printf("\nElements of the array: ");
  for (const int *p = dynamic_array; p < (dynamic_array + size); ++p)
    printf("%d ", *p);
}

int calculate_sum(const int *dynamic_array, size_t size) {
  int sum = 0;

  for (const int *p = dynamic_array; p < (dynamic_array + size); ++p)
    sum += *p;

  return sum;
}