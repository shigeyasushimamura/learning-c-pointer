#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void displayHeaer(){
    // 大域変数メモリにあり、リテラルプールの文字列へ参照
    static char* staticHeader = "Chapter";
    // displayHeaderのスタックフレームメモリにあり、リテラルプールの文字列へ参照
    char* localHeader = "Chapter";
    // 大域変数メモリにあり、staticArrayHeaderに文字列が格納
    static char staticArrayHeader[] = "Chapter";
    // displayHeaderスタックフレームメモリにあり、localArrayHeaderに文字列が格納
    char localArrayHeader[] = "Chapter";
    // ヒープ領域のメモリを指している
    char* heapHeader = (char*)malloc(strlen("Chapter")+1);
    strcpy(heapHeader,"Chapter");
}

// 大域変数メモリからリテラルプールの文字列へ参照
char* globalHeader = "Chapter";
// 大域変数メモリ、globalArrayHeaderに文字列が格納
char globalArrayHeader[] = "Chapter";


int main(void){
    displayHeaer();


    return 0;
}