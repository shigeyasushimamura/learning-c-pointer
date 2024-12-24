#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* getLine(void){
    const size_t sizeIncrement = 10;
    char* buffer = malloc(sizeIncrement);
    char* currentPosition = buffer;
    size_t maximumLength = sizeIncrement;
    size_t length = 0;
    int character;

    if(currentPosition == NULL){return NULL;};

    while(1){
        character = fgetc(stdin);
        if(character == '\n'){break;}
        if(++length > maximumLength){
            char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
            if(newBuffer == NULL){
                free(buffer);
                return NULL;
            }
            currentPosition = newBuffer + (currentPosition - buffer);
        }
        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}

char* trim(char* phrase){
    char* old = phrase;
    char* new = phrase;
    printf("org phrase:%s\n",phrase);

    while(*old == ' '){
        old++;
    }
    while(*old){
        *(new++) = *(old++);
    }
    *new = '\0';
    return (char*)realloc(phrase,strlen(phrase)+1);

}


int main(void){

    char* word = getLine();

    printf("%s\n",word);


    printf("------\n");
    char* word2 = (char*)malloc(strlen("  cat")+1);
    strcpy(word2,"  cat");
    printf("%s\n",trim(word2));

    return 0;
}