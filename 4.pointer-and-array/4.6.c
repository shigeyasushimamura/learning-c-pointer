#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int* arr[5];

    for(int i=0;i<5;i++){
        // 書き方パターン1
        // arr[i] = (int*)malloc(sizeof(int));
        // *arr[i] = i;
        // 書き方パターン２
        *(arr+i) = (int*)malloc(sizeof(int));
        **(arr+i) = i;
    }

    for(int i=0;i<5;i++){
        printf("arr[%d] Address:%p Value:%d\n",i,&arr[i],*arr[i]);
    }

    return 0;
}