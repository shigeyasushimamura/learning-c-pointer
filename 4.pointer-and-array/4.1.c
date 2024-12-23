#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int vector[5] = {1,2,3,4,5};

    printf("vector-size:%ld element-num:%ld\n", sizeof(vector),sizeof(vector)/sizeof(int));

    for(int i=0;i<5;i++){
        printf("index:%d value:%d \n",i,*(vector+i));
    }

    int matrix[2][3] = {{1,2,3},{4,5,6}};

    for(int i=0;i<2;i++){
        printf("&matrix[%d]: %p sizeof(matrix[%d]): %ld\n", i, &matrix[i], i,sizeof(matrix[i]));
        for(int j=0;j<3;j++){
            printf("&matrix[%d][%d]:%p value:%d\n",i,j,&matrix[i][j],matrix[i][j]);
        }
    }


    return 0;
}