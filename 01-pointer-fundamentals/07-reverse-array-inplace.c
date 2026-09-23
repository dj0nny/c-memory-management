#include <stdio.h>

void read_array(int *numbers, size_t size);
void reverse_in_place(int *numbers, size_t size);
void swap(int *a, int *b);
void print_array(int *number, size_t size);

int main(void) {
  const size_t size = 5;
  int numbers[size];

  read_array(numbers, size);
  reverse_in_place(numbers, size);
  print_array(numbers, size);

  return 0;
}

void read_array(int *numbers, size_t size) {
  for (int *p = numbers; p < (numbers + size); ++p) {
    printf("Enter a number: ");
    scanf("%d", p);
  }
}

void reverse_in_place(int *numbers, size_t size) {
  size_t last_index = size - 1;
  for (int *p = numbers; p < (numbers + (size / 2)); ++p) {
    swap(p, numbers + last_index);
    --last_index;
  }
  
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print_array(int *number, size_t size) {
  printf("Reversed array in-place: ");
  for (int *p = number; p < (number + size); ++p)
    printf("%d ", *p);
}