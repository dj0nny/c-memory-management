#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int *find_int(const int *numbers, size_t size, int target);
int compare(const void *a, const void *b);

int main(void) {
  int numbers[] = {3, 7, 12, 18, 25, 31, 42};
  size_t numbers_size = sizeof(numbers) / sizeof(*numbers);

  int searched_number;
  printf("Enter a number to search: ");
  scanf("%d", &searched_number);

  const int *found_element = find_int(numbers, numbers_size, searched_number);
  found_element == NULL ? printf("Element not found") : printf("Element found");

  return 0;
}

const int *find_int(const int *numbers, size_t size, int target) {
  const int *f_el = (const int *) bsearch(&target, numbers, size, sizeof(int), compare);

  return f_el;
}

int compare(const void *a, const void *b) {
  int x = *(const int *) a;
  int y = *(const int *) b;

  if (x < y)
    return -1;
  if (x > y)
    return 1;
  
  return 0;
}