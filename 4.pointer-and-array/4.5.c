#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void displayArray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d\n",*(arr+i));
    }
}

void displayArray2(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
}


int main(void){
    int vector[] = {1,2,4,7,9};

    displayArray2(vector,5);
    displayArray(vector,5);


    return 0;
}