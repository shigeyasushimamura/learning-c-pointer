#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int square(int num){
    return num*num;
}

double increment(int num){
    return num + 1;
}


int add(int num1,int num2){
    return num1 + num2;
}
int sub(int num1, int num2){
    return num1 - num2;
}

typedef int (*fptrOperation)(int, int);
int compute(fptrOperation operation, int num1, int num2){
    return operation(num1, num2);
}

fptrOperation selectOperation(char opcode){
    switch(opcode){
        case '+': return add;
        case '-': return sub;
        default:
            return 0;
    }
}

int evaluation(char opcode, int num1, int num2){
    fptrOperation operation = selectOperation(opcode);
    return operation(num1, num2);
}


typedef int (*operation)(int, int);
operation operations[128] = {NULL};

void initializeOperationArray(){
    operations['+'] = add;
    operations['-'] = sub;
}



int main(void){
    typedef int (*fptr1_org)(int);
    fptr1_org fptr1;
    fptr1 = square;

    int n = 100;
    printf("%d squared is %d\n",n,(*fptr1)(n));

    typedef double (*fptr2_org)(int);
    fptr2_org fptr2;
    fptr2 = increment;
    
    double n2 = 100;
    printf("%f incremented is %f\n",n2,(*fptr2)(n2));

    printf("100 + 100 = %d\n", compute(add, 100,100));
    printf("100 - 100 = %d\n", compute(sub, 100,100));
    
    printf("100 + 100 = %d\n", evaluation('+', 100,100));
    printf("100 + 100 = %d\n", evaluation('-', 100,100));


    return 0;
}