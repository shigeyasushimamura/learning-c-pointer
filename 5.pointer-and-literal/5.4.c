#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 関数から文字列定数を返却する
char* returnALiteral(int code, int subCode){
    static char bpCenter[] = "Boston Processing Center";
    static char dpCenter[] = "Denver Processing Center";
    static char apCenter[] = "Atlanta Processing Center";
    static char sjpCenter[] = "San Jose Processing Center";

    switch(code){
        case 100:
            return bpCenter;
        case 135:
            if(subCode < 35){
                return dpCenter;
            }else {
                return bpCenter;
            }
        case 200:
            return dpCenter;
        case 300:
            return apCenter;
        case 400:
            return sjpCenter;
    }
}

char* blanks(int number){
    char* spaces = (char*)malloc(number+1);
    int i;
    for(int i=0;i<number;i++){
        spaces[i] = ' ';
    }
    spaces[number] = '\0';
    return spaces;
}


int main(void){

    printf("%s\n",returnALiteral(100,0));
    printf("%s\n",returnALiteral(200,0));


    char *tmp = blanks(100);

    return 0;
}