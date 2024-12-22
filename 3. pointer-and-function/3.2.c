#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swapWithPointer(int* p1, int* p2){
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void invalidSwap(int num1, int num2){
    int tmp;
    num1 = tmp;
    num2 = num1;
    num1 = tmp;
}

int* allocateArray(int size, int value){
    int* ary = (int*)malloc(size * sizeof(int));
    for(int i=0;i<size;i++){
        ary[i] = value;
    }
    return ary;
}

double* allocateArrayDouble(int size, int value){
    double* ary = (double*)malloc(size * sizeof(double));
    for(int i=0;i<size;i++){
        ary[i] = value;
    }
    return ary;
}

void safeFree(void **pp){
    if(pp != NULL && *pp != NULL){
        printf("can free\n");
        free(*pp);
        *pp = NULL;
    }
}


int main(void){
    int n1 = 5;
    int n2 = 10;
    printf("n1 --- Address:%p Value:%d\n",&n1,n1);
    printf("n2 --- Address:%p Value:%d\n",&n2,n2);
    swapWithPointer(&n1,&n2);
    printf("n1 --- Address:%p Value:%d\n",&n1,n1);
    printf("n2 --- Address:%p Value:%d\n",&n2,n2);


    // 関数の引数に値のコピーを渡してるだけなのでswapが効かない
    int n3 = 5;
    int n4 = 10;
    invalidSwap(n3,n4);
    printf("n3 --- Address:%p Value:%d\n",&n3,n3);
    printf("n4 --- Address:%p Value:%d\n",&n4,n4);


    int* vector = allocateArray(5,777);
    printf("---- vector -----\n");
    for(int i=0;i<5;i++){
        printf("vector[i] Value:%d Address:%p\n",vector[i],&vector[i]);
    }

    double* vector2 = allocateArrayDouble(5,777);
    printf("---- vector2 -----\n");
    for(int i=0;i<5;i++){
        printf("vector2[i] Value:%f Address:%p\n",vector2[i],&vector2[i]);
    }

    int *pi;
    pi = (int*)malloc(sizeof(int));
    *pi = 5;
    printf("Before: %p\n",pi);
    safeFree((void**)&(pi));
    printf("After: %p\n",pi);
    // safeFree((void**)&(pi));

    return 0;
}