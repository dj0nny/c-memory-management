#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char name[32];
  int age;
};

int person_compare(const void *a, const void *b);

int main(void) {
  struct Person people[] = {
    {"John", 32},
    {"Lucy", 20},
    {"Anne", 27},
    {"Julia", 20},
  };

  size_t people_size = sizeof(people) / sizeof(*people);

  qsort(people, people_size, sizeof(struct Person), person_compare);

  for (size_t i = 0; i < people_size; ++i)
    printf("%s %d\n", (people + i)->name, (people + i)->age);

  return 0;
}

int person_compare(const void *a, const void *b) {
  const struct Person *p_1 = (const struct Person *) a;
  const struct Person *p_2 = (const struct Person *) b;

  if (p_1->age != p_2->age)
    return p_1->age > p_2->age ? 1 : -1;

  return strcmp(p_1->name, p_2->name);
}