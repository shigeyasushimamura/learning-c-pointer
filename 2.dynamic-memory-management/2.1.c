#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void){
    int *pi = (int*)malloc(sizeof(int));
    printf("pi Address:%p Value:%p pValue:%d\n",&pi,pi,*pi);

    *pi = 5;
    printf("pi Address:%p Value:%p pValue:%d\n",&pi,pi,*pi);
    
    free(pi);


    return 0;
}