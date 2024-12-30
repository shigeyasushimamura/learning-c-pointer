#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _person{
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
}Person;

void deallocatePerson(Person *person){
    free(person->firstName);
    free(person->lastName);
    free(person->title);
}

void initializePerson(Person *person, const char* fn, const char* ln, const char* title, unsigned int age){
    person->firstName = (char*)malloc(strlen(fn)+1);
    strcpy(person->firstName,fn);
    person->lastName = (char*)malloc(strlen(ln)+1);
    strcpy(person->lastName,ln);
    person->title = (char*)malloc(strlen(title)+1);
    strcpy(person->title,title);
    person->age = age;
}

void processPerson(){
    Person person;
    initializePerson(&person, "John","Smith", "Manager",55);
    printf("person: %s, age: %u\n", person.firstName, person.age);
    deallocatePerson(&person);
}



int main(void){
    processPerson();

    return 0;
}