#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DynamicArray {
  int *data;
  size_t size;
  size_t capacity;
};

struct DynamicArray *dynamic_array_create(size_t capacity);
void dynamic_array_destroy(struct DynamicArray *array);
bool dynamic_array_push(struct DynamicArray *array, int value);
bool dynamic_array_pop(struct DynamicArray *array, int *out_value);

int main(void) {
  struct DynamicArray *array = dynamic_array_create(2);

  if (array == NULL)
    return 1;

  dynamic_array_push(array, 10);
  dynamic_array_push(array, 20);
  dynamic_array_push(array, 30);

  int value;

  if (dynamic_array_pop(array, &value))
    printf("Popped: %d\n", value);

  dynamic_array_destroy(array);

  return 0;
}

struct DynamicArray *dynamic_array_create(size_t capacity) {
  struct DynamicArray *array = malloc(sizeof(struct DynamicArray));

  if (array == NULL)
    return NULL;

  array->data = malloc(sizeof(int) * capacity);

  if (array->data == NULL) // memory leak, array not deallocated
    return NULL;

  array->size = 0;
  array->capacity = capacity;

  return array;
}

bool dynamic_array_push(struct DynamicArray *array, int value) {
  // not checked if capacity == 0
  if (array->size == array->capacity) {
    array->capacity *= 2; // if realloc fail, wrong capacity

    int *temp = realloc(
      array->data,
      sizeof(int) * array->capacity // if capacity 0 -> allocate 0 elements
    );

    if (temp == NULL)
      return false;

    array->data = temp;
  }

  array->data[array->size] = value;
  array->size++;

  return true;
}

bool dynamic_array_pop(struct DynamicArray *array, int *out_value) {
  if (array->size == 0)
    return false;

  *out_value = array->data[array->size]; // out of range

  array->size--;

  return true;
}

void dynamic_array_destroy(struct DynamicArray *array) {
  // wrong order
  free(array);
  free(array->data);
}