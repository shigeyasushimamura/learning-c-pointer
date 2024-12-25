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


    // 連続メモリ割り当て パターン1
    int **matrix2 = (int **)malloc(sizeof(int) * rows);
    matrix2[0] = (int*)malloc(rows * columns * sizeof(int));
    for(int i=0;i<rows;i++){
        matrix2[i] = matrix[0] + i * columns;
    }
   
   // 連続メモリ割り当て パターン2
   int *matrix3 = (int*)malloc(sizeof(int) * rows * columns);

   for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
        printf("i:%d j:%d\n",i,j);
        *(matrix3 + i * rows + j) = i * j;
        printf("%d\n",*(matrix3 + i * rows + j));
    }
   }


    return 0;
}