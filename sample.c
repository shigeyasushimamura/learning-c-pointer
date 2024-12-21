# include <stdio.h>
volatile int i = 123;

int main(void){
    i = i + 456;
    printf("%d\n",i);
    return(0);
}