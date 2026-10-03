#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum SortField {
  SORT_BY_NAME,
  SORT_BY_AGE
};

struct Person {
  char name[32];
  int age;
};

void compare_people_by(struct Person *people, size_t size, size_t type_size, int (*sort_method)(const void *a, const void *b));
int sort_by_age(const void *a, const void *b);
int sort_by_name(const void *a, const void *b);

int main(void) {
  struct Person people[] = {
    {"John", 32},
    {"Lucy", 20},
    {"Josh", 55},
    {"Anne", 27},
    {"Julia", 20},
    {"Joe", 5},
  };

  size_t people_array_size = sizeof(people) / sizeof(*people);

  printf("Enter the sort method code (0 = sort by name, 1 = sort by age): ");
  enum SortField sort_by_code;
  scanf("%d", &sort_by_code);

  switch (sort_by_code) {
    case SORT_BY_NAME:
      compare_people_by(people, people_array_size, sizeof(struct Person), sort_by_name);
      break;
    case SORT_BY_AGE:
      compare_people_by(people, people_array_size, sizeof(struct Person), sort_by_age);
      break;
    default:
      printf("Invalid sort method\n");
  }

  for (size_t i = 0; i < people_array_size; ++i)
    printf("%s %d\n", (people + i)->name, (people + i)->age);

  return 0;
}

int sort_by_age(const void *a, const void *b) {
  const struct Person *p_1 = (const struct Person *) a;
  const struct Person *p_2 = (const struct Person *) b;

  if (p_1->age > p_2->age)
    return 1;
  else if (p_1->age < p_2->age)
    return -1;

  return 0;
}

int sort_by_name(const void *a, const void *b) {
  const struct Person *p_1 = (const struct Person *) a;
  const struct Person *p_2 = (const struct Person *) b;

  return strcmp(p_1->name, p_2->name);
}

void compare_people_by(struct Person *people, size_t size, size_t type_size, int (*sort_method)(const void *a, const void *b)) {
  qsort(people, size, type_size, sort_method);
}