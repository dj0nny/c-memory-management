#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER_SIZE 100

struct Buffer {
  char *data;
  size_t size;
};

void buffer_destroy(struct Buffer *p_buffer);

bool buffer_resize(struct Buffer *p_buffer, size_t new_size);

struct Buffer *buffer_create(size_t size);
struct Buffer *buffer_clone(const struct Buffer *p_buffer);
struct Buffer *buffer_move(struct Buffer **pp_buffer);

int main(void) {
  struct Buffer *buffer = buffer_create(BUFFER_SIZE);

  if (buffer == NULL) {
    printf("Failed to allocate the buffer.");
    return 1;
  }

  if (buffer_resize(buffer, BUFFER_SIZE * 2))
    printf("Buffer resized successfully.\n");
  else
    printf("Cannot resize the buffer.\n");

  struct Buffer *buffer_cloned = buffer_clone(buffer);

  if (buffer_cloned == NULL)
    printf("Failed to clone the buffer");

  struct Buffer* transferred_buffer = buffer_move(&buffer); 

  if (transferred_buffer == NULL)
    printf("Failed to transfer the ownership");

  buffer_destroy(transferred_buffer);
  buffer_destroy(buffer_cloned);  
  buffer_destroy(buffer);

  return 0;
}

struct Buffer *buffer_create(size_t size) {
  struct Buffer *temp_buffer = malloc(sizeof(struct Buffer));

  if (temp_buffer == NULL)
    return NULL;

  char *temp_buffer_data = calloc(size, sizeof(char));

  if (temp_buffer_data == NULL) {
    free(temp_buffer);
    temp_buffer = NULL;
    return NULL;
  }
  
  temp_buffer->data = temp_buffer_data;
  temp_buffer->size = size;

  return temp_buffer;
}

void buffer_destroy(struct Buffer *p_buffer) {
  if (p_buffer != NULL) {
    free(p_buffer->data);
    free(p_buffer);

    printf("Buffer deallocated.\n");
  } else
    printf("The buffer is NULL.\n");

}

bool buffer_resize(struct Buffer *p_buffer, size_t new_size) {
  if (p_buffer->data == NULL)
    return false;

  char *temp_new_buffer_data = realloc(p_buffer->data, sizeof(char) * new_size);

  if (temp_new_buffer_data == NULL)
    return false;

  p_buffer->data = temp_new_buffer_data;
  p_buffer->size = new_size;

  return true;
}

struct Buffer *buffer_clone(const struct Buffer *p_buffer) {
  if (p_buffer == NULL)
    return NULL;

  struct Buffer *p_buffer_clone = malloc(sizeof(struct Buffer));

  if (p_buffer_clone == NULL)
    return NULL;

  char *p_buffer_clone_data = malloc(sizeof(char) * p_buffer->size);

  if (p_buffer_clone_data == NULL) {
    free(p_buffer_clone);
    p_buffer_clone = NULL;
    return NULL;
  }

  p_buffer_clone->data = p_buffer_clone_data;
  p_buffer_clone->size = p_buffer->size;

  memcpy(p_buffer_clone->data, p_buffer->data, p_buffer->size * sizeof(char));

  return p_buffer_clone;
}

struct Buffer *buffer_move(struct Buffer **buffer) {
  if (buffer == NULL)
    return NULL;

  struct Buffer *temp_transferred_buffer = *buffer;
  *buffer = NULL;

  return temp_transferred_buffer;
}