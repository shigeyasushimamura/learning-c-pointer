#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    int matrix[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};

    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
            printf("matrix[%d][%d] Address:%p Value:%d\n",i,j, &matrix[i][j],matrix[i][j]);
        }
    }

    printf("matrix Address:%p Value:%d\n",&matrix,**matrix);
    printf("matrix[1] Address:%p Value:%d\n",(matrix[0]+1),*(matrix[0]+1));

    return 0;
}