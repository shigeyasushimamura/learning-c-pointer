#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _person {
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
}Person;


int main(void){
    Person person;
    person.firstName = (char*)malloc(strlen("Emm")+1);
    strcpy(person.firstName,"Emm");
    person.age = 23;

    Person *ptrPerson;
    ptrPerson = (Person*)malloc(sizeof(Person));
    ptrPerson->firstName = (char*)malloc(strlen("ham")+1);
    strcpy(ptrPerson->firstName,"hmm");
    ptrPerson->age = 33;

    // 構造体の内容を出力
    printf("person: %s, age: %u\n", person.firstName, person.age);
    printf("ptrPerson: %s, age: %u\n", ptrPerson->firstName, ptrPerson->age);

    free(person.firstName);
    free(ptrPerson->firstName);
    free(ptrPerson);


    return 0;   
}