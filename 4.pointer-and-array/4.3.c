#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void saferFree(void **p){
    if(p != NULL && *p != NULL){
        free(*p);
        *p = NULL;
        printf("free successfull!\n");
    }
}


int main(void){
    int *pv = (int*)malloc(5 * sizeof(int));
    for(int i=0;i<5;i++){
        // pv[i] = i+1 でも可
        *(pv+i) = i+1;
    }

    for(int i=0;i<5;i++){
        printf("pv[i] Value:%d Address:%p\n",*(pv+i),&pv[i]);
    }

    saferFree((void**)&(pv));

    return 0;
}