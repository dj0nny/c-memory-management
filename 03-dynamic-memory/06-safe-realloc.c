#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

void read_array(int *ptr, size_t capacity);
void print_array(int *ptr, size_t capacity);
void initialize_realloc_values(int *begin_ptr, size_t length);
void clean_buffer();

int main(void) {
  int *d_array_ptr = malloc(sizeof(int) * INITIAL_CAPACITY);

  printf("Initial array size: %d\n", INITIAL_CAPACITY);
  read_array(d_array_ptr, INITIAL_CAPACITY);
  clean_buffer();
  print_array(d_array_ptr, INITIAL_CAPACITY);

  printf("\n\nEnter the array new capacity: ");
  int capacity;
  scanf("%d", &capacity);

  clean_buffer();

  if (capacity < 0) {
    printf("Invalid capacity");
    return 1;
  }

  int *temp = realloc(d_array_ptr, capacity * sizeof(int));

  if (temp == NULL) {
    printf("Cannot reallocate memory");
    free(d_array_ptr);
    return 1;
  }

  d_array_ptr = temp;

  if (capacity > INITIAL_CAPACITY)
    initialize_realloc_values(d_array_ptr + INITIAL_CAPACITY, capacity - INITIAL_CAPACITY);

  print_array(d_array_ptr, capacity);

  free(d_array_ptr);

  return 0;
}

void read_array(int *ptr, size_t capacity) {
  printf("Enter the numbers: ");

  int *p = ptr;
  while (p < (ptr + capacity)) {
    if (scanf("%d", p) != 1)
      break;
    
    ++p;
  }
}

void print_array(int *ptr, size_t capacity) {
  for (int *p = ptr; p < (ptr + capacity); ++p)
    printf("%d ", *p);
}

void clean_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void initialize_realloc_values(int *begin_ptr, size_t length) {
  for (int *p = begin_ptr; p < (begin_ptr + length); ++p)
    *p = 0;
}