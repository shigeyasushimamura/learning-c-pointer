#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _employee{
    char name[32];
    unsigned char age;
}Employee;

int compareEmployee(Employee *e1, Employee *e2){
    return strcmp(e1->name,e2->name);
}
void displayEmployee(Employee* employee){
    printf("%s\t%d\n", employee->name, employee->age);
}

typedef struct _node {
    void *data;
    struct _node *next;
}Node;

typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
}LinkedList;


void initializeList(LinkedList *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(LinkedList *list, void*data){
    Node *node = (Node*) malloc (sizeof(Node));
    node->data  = data;
    if(list->head==NULL){
        list->tail = node;
        node->next = NULL;
    }else {
        node -> next = list->head;
    }
    list->head = node;
}

void addTail(LinkedList *list, void* data){
    Node * node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if(list->head == NULL){
        list->head = node;
    }else {
        list -> tail -> next = node;
    }
    list -> tail = node;
}

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*,void*);

Node *getNode(LinkedList * list ,COMPARE compare, void * data ){
    Node *node = list -> head;
    while (node != NULL){
        if(compare(node->data, data) == 0){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void delete(LinkedList *list, Node *node){
    if(node == list -> head){
        if(list->head->next==NULL){
            list->head = list -> tail = NULL;
        }else {
            list -> head = list ->head->next;
        }
    }else {
        Node *tmp = list->head;
        while (tmp != NULL && tmp -> next  != node){
            tmp  = tmp->next;
        }
        if(tmp != NULL){
            tmp -> next = node -> next;
        }
        if(list -> tail == node){
            list-> tail = tmp;
        }
    }
    free(node);
}

void displayLinkedList(LinkedList * list, DISPLAY display){
    printf("\nLinked List\n");
    Node *current = list->head;
    while (current != NULL){
        display(current->data);
        current = current -> next;
    }
}

typedef LinkedList Queue;

void initializeQueue(Queue *queue){
    initializeList(queue);
}

void enqueue(Queue *queue, void *node){
    addHead(queue, node);
}

void *dequeue(Queue *queue){
    Node *tmp = queue->head;
    void* data;
    if(queue->head == NULL){
        data = NULL;
    }else if(queue -> head == queue->tail){
        queue->head = queue-> tail = NULL;
        data = tmp->data;
        free(tmp);
    }else{
        while(tmp->next != queue->tail){
            tmp = tmp->next;
        }
        queue-> tail = tmp;
        tmp = tmp->next;
        queue->tail->next = NULL;
        data = tmp->data;
        free(tmp);
    }
    return data;
}



// キュー
int main(void){

    Employee *samuel = (Employee*)malloc(sizeof(Employee));
    strcpy(samuel->name,"Samuel");
    samuel-> age = 32;

    Employee *gon = (Employee*)malloc(sizeof(Employee));
    strcpy(gon->name,"gon");
    gon -> age = 12;

    Employee *tari = (Employee*)malloc(sizeof(Employee));
    strcpy(tari->name,"tari");
    tari-> age = 32;


    Queue *queue = (Queue*)malloc(sizeof(Queue));
    initializeQueue(queue);

    enqueue(queue, samuel);
    enqueue(queue,gon);
    enqueue(queue,tari);

    displayLinkedList(queue,(DISPLAY)displayEmployee);

    void * data = dequeue(queue);

    printf("Dequeued %s\n",((Employee*)data)->name);


    return 0;
}