#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Stack {
  struct Node *top;
};

struct Stack *stack_create(void);

bool stack_push(struct Stack *stack, int value);
bool stack_pop(struct Stack *stack, int *out_value);
bool stack_peek(const struct Stack *stack, int *out_value);

bool stack_is_empty(const struct Stack *stack);

void print_stack(struct Stack *stack);
void stack_destroy(struct Stack *stack);

int main(void) {
  struct Stack *stack = stack_create();

  stack_push(stack, 10);
  stack_push(stack, 20);
  stack_push(stack, 30);

  int pop_value;
  if (stack_pop(stack, &pop_value))
    printf("Pop: %d\n", pop_value);

  int peek_value; 
  if (stack_peek(stack, &peek_value))
    printf("Peek: %d\n", peek_value);

  print_stack(stack);
  stack_destroy(stack);

  return 0;
}

struct Stack *stack_create(void) {
  struct Stack *new_stack = malloc(sizeof(struct Stack));

  if (new_stack == NULL)
    return NULL;

  new_stack->top = NULL;

  return new_stack;
}

bool stack_push(struct Stack *stack, int value) {
  struct Node *new_stack_node = malloc(sizeof(struct Node));

  if (new_stack_node == NULL)
    return false;

  new_stack_node->value = value;

  new_stack_node->next = stack->top;
  stack->top = new_stack_node;

  return true;
}

bool stack_pop(struct Stack *stack, int *out_value) {
  if (stack->top == NULL)
    return false;

  struct Node *next = stack->top->next;
  *out_value = stack->top->value;
  free(stack->top);
  stack->top = next;

  return true;
}

bool stack_is_empty(const struct Stack *stack) {
  return stack->top == NULL;
}

bool stack_peek(const struct Stack *stack, int *out_value) {
  if (stack_is_empty(stack))
    return false;

  *out_value = stack->top->value;
  return true;
}

void print_stack(struct Stack *stack) {
  const struct Node *current = stack->top;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}

void stack_destroy(struct Stack *stack) {
  while (stack->top != NULL) {
    struct Node *next_top = stack->top->next;
    free(stack->top);
    stack->top = next_top;
  }

  free(stack);
}