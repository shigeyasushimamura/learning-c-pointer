#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 引数を変更しないために定数constを付ける。
// constがない場合は*string = 'A';などで引数を変更してしまう
size_t stringLength(const char* string){
    size_t length = 0;
    while(*(string++)){
        length++;
    }
    return length;
}

char* format(char *buffer, size_t size, const char* name, size_t quantity, size_t weight){
    snprintf(buffer,size, "Item:%s Quantity:%lu Weight:%lu",name, quantity, weight);

    return buffer;
}

char* format2(char *buffer, size_t size, const char* name, size_t quantity, size_t weight){
    char *formatString = "Item: %s Quantity: %lu Weight:%lu";
    size_t formatStringLength = strlen(formatString)-6;
    size_t nameLength = strlen(name);
    size_t length = formatStringLength + nameLength + 10 + 10 + 1;

    if(buffer == NULL){
        buffer = (char*)malloc(length);
        size = length;
    }
    snprintf(buffer, size, formatString,name,quantity,weight);
    return buffer;
}


int main(void){
    char simpleArray[] = "simple";
    char *simplePtr = (char*)malloc(strlen("simple") + 1);
    strcpy(simplePtr,"simple");

    printf("%ld\n",stringLength(simplePtr));
    printf("%ld\n",stringLength(simpleArray));


    char buffer[128];
    printf("%s\n",format(buffer,sizeof(buffer),"Axle",25,45));

    char* buffer2;
    printf("%s\n",format2(buffer2,sizeof(buffer2),"HOHOJOJOJ",33,33));


    return 0;
}