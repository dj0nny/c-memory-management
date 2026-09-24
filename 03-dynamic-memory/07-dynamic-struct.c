#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Person {
  char *name;
  int age;
};

bool alloc_person_name(char *name);

int main(void) {
  struct Person *person = malloc(sizeof(struct Person));

  if (person == NULL) {
    printf("Cannot allocate memory");
    return 1;
  }

  char *p_name = malloc(sizeof(char));

  if (p_name == NULL) {
    printf("Cannot allocate the name");
    return 1;
  }

  person->name = p_name;

  alloc_person_name(person->name);

  printf("Enter the age: ");
  scanf("%d", &(person->age));

  printf("Name: %s\n", person->name);
  printf("Age: %d", person->age);

  free(person);

  return 0;
}

bool alloc_person_name(char *name) {
  printf("Enter your name: ");
  size_t length = 0;
  char ch;
  
  while ((ch = getchar()) != '\n' && ch != EOF) {
    ++length;
    char *temp_name = realloc(name, sizeof(char) * (length + 1));

    if (temp_name == NULL) {
      printf("Cannot reallocate memory");
      free(name);
      return false;
    }

    name = temp_name;

    *(temp_name + (length - 1)) = ch;
  }

  *(name + length) = '\0';

  return true;
}