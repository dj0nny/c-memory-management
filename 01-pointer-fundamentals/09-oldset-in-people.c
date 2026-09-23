#include <stdio.h>

#define SIZE 5

struct Person {
  char name[50];
  int age;
};

struct Person* find_oldest(struct Person *people, size_t size);

int main(void) {
  struct Person people[SIZE] = {{"John", 21}, {"Karen", 11}, {"Philip", 54}, {"Lucy", 18}, {"Max", 27}};

  struct Person *oldest_person = find_oldest(people, SIZE);
  printf("The oldest person is %s with %d years", oldest_person->name, oldest_person->age);
  return 0;
}

struct Person* find_oldest(struct Person *people, size_t size) {
  struct Person *temp_oldest_person = people;

  for (struct Person *p = people; p < (people + size); ++p)
    if (temp_oldest_person->age < p->age)
      temp_oldest_person = p;

  return temp_oldest_person;
}

