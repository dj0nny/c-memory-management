#include <stdio.h>

struct Person {
  char name[50];
  int age;
};

void birthday(struct Person *person);
void print_person(const struct Person *person);

int main(void) {
  struct Person myself = {.name = "Francesco", .age = 30};

  printf("I have %d years old\n", myself.age);
  birthday(&myself);
  printf("Now I have %d years old\n\n", myself.age);

  print_person(&myself);

  return 0;
}

void birthday(struct Person *person) {
  ++person->age;
}

void print_person(const struct Person *person) {
  printf("Name: %s\n", person->name);
  printf("Age: %d", person->age);
}