#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int *pi = (int*)malloc(sizeof(int));
    // mallocはvoid*を返却するため、明示的にmallocの返り値をcastしなくても動作する
    // int *pi = malloc(sizeof(int));

    if(pi != NULL){
        printf("Memory allocate:Success! pi---- Address:%p value:%p\n",&pi,pi);
    }else {
        printf("Memory allocate:Fail!\n");
    }

    free(pi);

    const int NUMBER_OF_DOUBLES = 10;
    double *pi2 = (double*)malloc(sizeof(NUMBER_OF_DOUBLES * 8));

    if(pi2 != NULL){
        size_t allocatedMemorySize = NUMBER_OF_DOUBLES * sizeof(double);
        printf("Memory allocated size:%ld\n",allocatedMemorySize);
    }


    free(pi2);


    int *pi3 = calloc(5,sizeof(int));
    if(pi3 != NULL){
        printf("pi3 --- address:%p value:%p\n", &pi3, pi3);
    }

    char *string1;
    char *string2;
    string1 = (char*)malloc(16);
    strcpy(string1, "0123456789AB");

    // より小さいサイズにメモリ割り当て
    string2 = realloc(string1, 8);
    printf("string1 Address:%p Value:%p [%s]\n",&string1, string1, string1);
    printf("string2 Address:%p Value:%p [%s]\n",&string2, string2, string2);

    // 明示的にNUL終端文字を入れる
    if(string2 != NULL){
        string2[7] = '\0';
        printf("string1 Address:%p Value:%p [%s]\n",&string1, string1, string1);
        printf("string2 Address:%p Value:%p [%s]\n",&string2, string2, string2);
    }

    // free(string1);
    
    // より大きいサイズにメモリ割り当て
    char* string3;
    char* string4;
    string3 = (char*)malloc(16);
    strcpy(string3, "0123456789AB");
    string4 = realloc(string3,32);

    printf("string3 Address:%p Value:%p [%s]\n",&string3, string3, string3);
    printf("string4 Address:%p Value:%p [%s]\n",&string4, string4, string4);

    
    free(string4);  

    return 0;
}