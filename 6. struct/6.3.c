#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LIST_SIZE 10

typedef struct _person{
    char* firstName;
    char* lastName;
    char* title;
    unsigned int age;
} Person;

Person* list[LIST_SIZE];

void initializeList(){
    for(int i=0;i<LIST_SIZE;i++){
        list[i] = NULL;
    }
}


Person *getPerson(){
    for(int i=0;i<LIST_SIZE;i++){
        if(list[i] != NULL){
            Person *ptr = list[i];
            list[i] = NULL;
            return ptr;
        }
    }
    Person *person = (Person*)malloc(sizeof(Person));
    return person;
}


void deallocatePerson(Person *person){
    free(person->firstName);
    free(person->lastName);
    free(person->title);
}

void initializePerson(Person *person, const char* fn,const char* ln, const char*title, unsigned int age){
    person->firstName = (char*)malloc(sizeof(fn)+1);
    strcpy(person->firstName,fn);
    person->lastName = (char*)malloc(sizeof(ln)+1);
    strcpy(person->lastName,ln);
    person->title = (char*)malloc(sizeof(title)+1);
    strcpy(person->title,title);
    person->age = age;
}



Person *returnPerson(Person *person){
    for(int i=0;i<LIST_SIZE;i++){
        if(list[i] == NULL){
            list[i] = person;
            return person;
        }
    }
    deallocatePerson(person);
    free(person);
    return NULL;
}


void displayPerson(Person person){
    printf("%p %s %s %d\n",&person, person.firstName,person.lastName,person.age);
    printf("%s\n",person.firstName);

}


int main(void){
    initializeList();
    Person *ptrPerson;

    ptrPerson = getPerson();
    initializePerson(ptrPerson, "Ralph", "lauren", "Mr.", 33);
    displayPerson(*ptrPerson);
    returnPerson(ptrPerson);

    return 0;
}