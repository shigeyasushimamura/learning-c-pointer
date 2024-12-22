#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swapWithPointer(int* p1, int* p2){
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}



int main(void){
    int n1 = 5;
    int n2 = 10;
    printf("n1 --- Address:%p Value:%d",&n1,n1);
    printf("n2 --- Address:%p Value:%d",&n2,n2);
    swapWithPointer(&n1,&n2);
    printf("n1 --- Address:%p Value:%d",&n1,n1);
    printf("n2 --- Address:%p Value:%d",&n2,n2);


    return 0;
}