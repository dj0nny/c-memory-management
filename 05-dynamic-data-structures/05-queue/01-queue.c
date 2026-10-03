#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int value;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

struct Queue *queue_create(void);

bool queue_enqueue(struct Queue *queue, int value);
bool queue_dequeue(struct Queue *queue, int *out_value);
bool queue_peek(const struct Queue *queue, int *out_value);
bool queue_is_empty(const struct Queue *queue);

void queue_reverse(struct Queue *queue);
void queue_print(const struct Queue *queue);
void queue_destroy(struct Queue *queue);

int main(void) {
  struct Queue *queue = queue_create();

  queue_enqueue(queue, 10);
  queue_enqueue(queue, 20);
  queue_enqueue(queue, 30);
  queue_enqueue(queue, 40);
  queue_enqueue(queue, 50);

  queue_print(queue);

  int dequeue_value;
  if (queue_dequeue(queue, &dequeue_value))
    printf("Dequeue: %d\n", dequeue_value);

  int peek_value;
  if (queue_peek(queue, &peek_value))
    printf("Peek: %d\n", peek_value);

  queue_print(queue);
  queue_reverse(queue);
  queue_print(queue);
  queue_destroy(queue);

  return 0;
}

struct Queue *queue_create(void) {
  struct Queue *queue = malloc(sizeof(struct Queue));

  if (queue == NULL)
    return NULL;

  queue->front = NULL;
  queue->rear = NULL;

  return queue;
}

bool queue_enqueue(struct Queue *queue, int value) {
  struct Node *new_node = malloc(sizeof(struct Node));

  if (new_node == NULL)
    return false;

  new_node->value = value;
  new_node->next = NULL;

  if (queue->rear == NULL) {
    queue->rear = new_node;
    queue->front = new_node;
    return true;
  }

  queue->rear->next = new_node;
  queue->rear = new_node;

  return true;
}

bool queue_dequeue(struct Queue *queue, int *out_value) {
  if (queue_is_empty(queue))
    return false;

  *out_value = queue->front->value;

  struct Node *next = queue->front->next;
  free(queue->front);

  if (next != NULL)
    queue->front = next;
  else {
    queue->front = NULL;
    queue->rear = NULL;
  }

  return true;
}

bool queue_peek(const struct Queue *queue, int *out_value) {
  if (queue_is_empty(queue))
    return false;

  *out_value = queue->front->value;

  return true;
}

bool queue_is_empty(const struct Queue *queue) {
  return queue->front == NULL && queue->rear == NULL;
}

void queue_reverse(struct Queue *queue) {
  struct Node *previous_node = NULL;
  struct Node *current_node = queue->front;
  struct Node *next_node;

  while (current_node != NULL) {
    next_node = current_node->next;
    current_node->next = previous_node;
    previous_node = current_node;
    current_node = next_node;
  }

  struct Node *temp_front = queue->front;
  queue->front = queue->rear;
  queue->rear = temp_front; 
}

void queue_print(const struct Queue *queue) {
  const struct Node *current = queue->front;

  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }

  printf("NULL\n");
}

void queue_destroy(struct Queue *queue) {
  while (queue->front != NULL) {
    struct Node *next = queue->front->next;
    free(queue->front);
    queue->front = next;
  }

  free(queue);
}