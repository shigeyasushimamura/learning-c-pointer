#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char name[32];
    char* names[30];
    size_t count = 0;

    printf("名前を入寮くしてください：\n");
    scanf("%s",name);
    names[count] = (char*)malloc(sizeof(name)+1);
    strcpy(names[count],name);
    count++;

    printf("name:%s\n",name);

    return 0;
}