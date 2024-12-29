#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* stringToLower(const char* string){
    char* tmp = (char*)malloc(sizeof(string)+1);
    char* start = tmp;
    while(*string != '0'){
        *tmp++ = *string++;
    }
    *tmp = 0;
    return start;
}


int compare(const char* s1, const char* s2){
    return strcmp(s1,s2);
}

int compareIgnoreCase(const char* s1, const char* s2){
    char *t1 = stringToLower(s1);
    char *t2 = stringToLower(s2);

    int result = strcmp(t1,t2);
    free(t1);
    free(t2);
    return result;
}



typedef int (*fptrOperation)(const char*,const char*);

void sort(char* array[], int size, fptrOperation operation ){
    int swap = 1;
    while(swap){
        swap = 0;
        for(int i=0;i<size-1;i++){
            if(operation(array[i],array[i+1]) > 0){
                swap = 1;
                char *tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }
}

void displayNames(char* names[],int size){
    for(int i=0;i<size;i++){
        printf("%s ", names[i]);
    }
    printf("\n");
}


int main(void){
    char* names[] = {"Bob", "Ted", "Carol"};
    

    // 関数ポインタの型を宣言して代入しなくても、関数ポインタと同型の関数ならば直でsortに渡せる
    // fptrOperation op = compare;
    // sort(names,3, op);
    // 動的に比較方法を変えたい場合、strategyパターンとして、fptrOperation型を宣言して、切り替えるのが良い。
    sort(names,3,compare);

    displayNames(names,3);


    return 0;
}