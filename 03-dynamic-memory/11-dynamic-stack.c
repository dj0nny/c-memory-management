#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DynamicStack {
  int *data;
  size_t size;
  size_t capacity;
};

struct DynamicStack *stack_create(size_t initial_capacity);

void stack_destroy(struct DynamicStack *p_stack);
void print_stack(const struct DynamicStack *p_stack);

size_t stack_size(const struct DynamicStack *p_stack);
size_t stack_capacity(const struct DynamicStack *p_stack);

bool stack_push(struct DynamicStack *p_stack, int value);
bool stack_pop(struct DynamicStack *p_stack, int *pop_value);
bool stack_peek(const struct DynamicStack *p_stack, int *peek_value);
bool stack_is_empty(const struct DynamicStack *p_stack);


int main(void) {
  printf("Enter the initial capacity of the stack: ");
  int inital_capacity;
  scanf("%d", &inital_capacity);

  if (inital_capacity < 0) {
    printf("Invalid capacity.");
    return 1;
  }

  struct DynamicStack *dynamic_stack = stack_create((size_t) inital_capacity);
  
  if (dynamic_stack == NULL) {
    printf("Failted to create the dynamic stack.");
    return 1;
  }

  stack_push(dynamic_stack, 10);
  stack_push(dynamic_stack, 20);
  stack_push(dynamic_stack, 30);
  stack_push(dynamic_stack, 40);
  stack_push(dynamic_stack, 50);

  int stack_peek_value = 0;
  stack_peek(dynamic_stack, &stack_peek_value);
  printf("Stack peek: %d\n", stack_peek_value);

  int stack_pop_value = 0;
  stack_pop(dynamic_stack, &stack_pop_value);
  printf("Pop: %d\n", stack_pop_value);
  stack_pop(dynamic_stack, &stack_pop_value);
  printf("Pop: %d\n", stack_pop_value);
  stack_pop(dynamic_stack, &stack_pop_value);
  printf("Pop: %d\n", stack_pop_value);


  stack_peek(dynamic_stack, &stack_peek_value);
  printf("Stack peek: %d\n", stack_peek_value);

  stack_push(dynamic_stack, 100);
  stack_push(dynamic_stack, 200);

  print_stack(dynamic_stack);

  stack_destroy(dynamic_stack);
  
  return 0;
}

struct DynamicStack *stack_create(size_t initial_capacity) {
  struct DynamicStack *temp_dynamic_stack = malloc(sizeof(struct DynamicStack));

  if (temp_dynamic_stack == NULL)
    return NULL;

  int *temp_dynamic_stack_data = calloc(initial_capacity, sizeof(int));

  if (temp_dynamic_stack_data == NULL) {
    free(temp_dynamic_stack);
    return NULL;
  }

  temp_dynamic_stack->data = temp_dynamic_stack_data;
  temp_dynamic_stack->size = 0;
  temp_dynamic_stack->capacity = initial_capacity;

  return temp_dynamic_stack;
}

void stack_destroy(struct DynamicStack *p_stack) {
  free(p_stack->data);
  free(p_stack);

  printf("Dynamic stack deallocated.");
}

bool stack_push(struct DynamicStack *p_stack, int value) {
  if (stack_capacity(p_stack) == 0) {
    int *temp_p_stack_data = realloc(p_stack->data, sizeof(int));

    if (temp_p_stack_data == NULL)
      return false;

    p_stack->data = temp_p_stack_data;
    p_stack->capacity = 1;
  }

  if (stack_capacity(p_stack) > stack_size(p_stack)) {
    *(p_stack->data + p_stack->size) = value;
    ++(p_stack->size);
  } else {
    size_t new_capacity = p_stack->capacity * 2;
    int *temp_realloc_p_stack_data = realloc(p_stack->data, sizeof(int) * new_capacity);

    if (temp_realloc_p_stack_data == NULL)
      return false;

    p_stack->data = temp_realloc_p_stack_data;
    p_stack->capacity = new_capacity;

    *(p_stack->data + stack_size(p_stack)) = value;
    ++(p_stack->size);
  }

  return true;
}

bool stack_pop(struct DynamicStack *p_stack, int *pop_value) {
  if (stack_is_empty(p_stack))
    return false;

  size_t last_index = --(p_stack->size);
  *(pop_value) = *(p_stack->data + last_index);
  p_stack->size = last_index;

  return true;
}

bool stack_peek(const struct DynamicStack *p_stack, int *peek_value) {
  if (stack_is_empty(p_stack))
    return false;

  *(peek_value) = *(p_stack->data + (stack_size(p_stack) - 1));
  return true;
}

bool stack_is_empty(const struct DynamicStack *p_stack) {
  return stack_size(p_stack) == 0;
}

size_t stack_size(const struct DynamicStack *p_stack) {
  return p_stack->size;
}

size_t stack_capacity(const struct DynamicStack *p_stack) {
  return p_stack->capacity;
}

void print_stack(const struct DynamicStack *p_stack) {
  if (stack_is_empty(p_stack))
    printf("The stack in empty\n");
  else {
    printf("Stack values: ");
    for (int *p = p_stack->data; p < (p_stack->data + stack_size(p_stack)); ++p)
      printf("%d ", *p);

    printf("\nSize: %zu\n", stack_size(p_stack));
    printf("Capacity: %zu\n", p_stack->capacity);
  }
}