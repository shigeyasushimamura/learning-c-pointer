#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display2DArray(int arr[][5], int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            printf("arr[%d][%d] Address:%p Value:%d",i,j,&arr[i][j],arr[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}

typedef void (*Operation2D)(int [][5],int);
void compute(Operation2D operation,int arr[][5], int rows){
    operation(arr,rows);
}



void display3DArray(int (*arr)[2][4], int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<2;j++){
             printf("{");
            for(int k=0;k<4;k++){
                printf("%d ",arr[i][j][k]);
            }
             printf("}");
        }
         printf("\n");
    }


}


typedef void (*dispalyOperation)(int (*)[2][4],int);


int main(void){
    int matrix[2][5]= {
        {1,2,3,4,5},{6,7,8,9,20}
    };

    display2DArray(matrix,2);


    int arr3d[3][2][4] = {
        {{1,2,3,4},{5,6,7,8}},
        {{9,10,11,12},{13,14,15,16}},
        {{17,18,19,20},{21,22,23,24}}
    };

    dispalyOperation operation = display3DArray;
    operation(arr3d,3);


    Operation2D op = display2DArray;
    compute(op, matrix, 2);


    return 0;   
}