#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int vector[5] = {1,2,3,4,5};
    int *pi = vector;
    


    printf("pi Address:%p Value:%p PValue:%d\n",&pi,pi,*pi);

    printf("&vector:%p\n",&vector);
    for(int i=0;i<5;i++){
        printf("vector[%d] Address:%p Value:%d\n",i,&vector[i],vector[i]);
    }

    return 0;
}