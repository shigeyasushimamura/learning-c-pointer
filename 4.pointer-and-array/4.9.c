#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    int rows = 2;
    int columns = 5;

    int **matrix = (int**)malloc(sizeof(int) * rows);

    for(int i=0;i<rows;i++){
        matrix[i] = (int*)malloc(sizeof(int)*columns);
    }

   


    return 0;
}