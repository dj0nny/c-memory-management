#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DynamicArray {
  int *data;
  size_t size;
  size_t capacity;
};

struct DynamicArray *dynamic_array_create(size_t initial_capacity);
void dynamic_array_destroy(struct DynamicArray *d_a);
bool dynamic_array_push(struct DynamicArray *d_a, int value);
void dynamic_array_print(struct DynamicArray *d_a);
bool dynamic_array_pop(struct DynamicArray *d_a, int *out_value);

int main(void) {
  printf("Enter array capacity: ");
  int initial_capacity;
  scanf("%d", &initial_capacity);

  if (initial_capacity < 0 ) {
    printf("Invalid array capacity.");
    return 1;
  }

  struct DynamicArray *dynamic_array = dynamic_array_create((size_t) initial_capacity);

  if (dynamic_array == NULL) {
    printf("Failed to allocate DynamicArray");
    return 1;
  }

  dynamic_array_push(dynamic_array, 5);
  dynamic_array_push(dynamic_array, 10);
  dynamic_array_push(dynamic_array, 2);

  dynamic_array_print(dynamic_array);

  int pop_value;
  dynamic_array_pop(dynamic_array, &pop_value);

  dynamic_array_destroy(dynamic_array);

  return 0;
}

struct DynamicArray *dynamic_array_create(size_t initial_capacity) {
  struct DynamicArray *p_dynamic_array = malloc(sizeof(struct DynamicArray));

  if (p_dynamic_array == NULL) {
    printf("Cannot allocate memory for DynamicArray");
    return NULL;
  }

  int *p_dynamic_array_data = calloc(initial_capacity, sizeof(int));

  if (p_dynamic_array_data == NULL) {
    printf("Cannot allocate memory for DynamicArray data");
    free(p_dynamic_array);
    return NULL;
  }

  p_dynamic_array->data = p_dynamic_array_data;
  p_dynamic_array->size = 0;
  p_dynamic_array->capacity = initial_capacity;

  return p_dynamic_array;
}

void dynamic_array_destroy(struct DynamicArray *d_a) {
  free(d_a->data);
  free(d_a);
}

bool dynamic_array_push(struct DynamicArray *d_a, int value) {
  if (d_a->size < d_a->capacity) {
    *(d_a->data + d_a->size) = value;
    ++(d_a->size);
  } else {
    size_t new_capacity = d_a->capacity + 1;
    int *temp_data_array = realloc(d_a->data, sizeof(int) * new_capacity);

    if (temp_data_array == NULL) {
      printf("Cannot reallocate memory");
      free(d_a->data);
      d_a->data = NULL;
      d_a->capacity = 0;
      d_a->size = 0;
      return false;
    } 

    d_a->data = temp_data_array;
    d_a->capacity = new_capacity;

    *(d_a->data + d_a->size) = value;
    ++(d_a->size);

  }

  return true;
}

void dynamic_array_print(struct DynamicArray *d_a) {
  printf("\n\n\nArray size: %zu\n", d_a->size);
  printf("Array capacity: %zu\n", d_a->capacity);
  printf("Array elements: ");
  for (int *p = d_a->data; p < (d_a->data + d_a->size); ++p)
    printf("%d ", *p);
}

bool dynamic_array_pop(struct DynamicArray *d_a, int *out_value) {
  if (d_a->size == 0) {
    printf("The array is empty.");
    return false;
  }

}