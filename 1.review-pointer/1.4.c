#include <stdio.h>
#include <stdint.h>

// 多重間接参照
int main(void){
    // 2D形式で宣言できるが、2D形式だと文字数を開発者が指定しないといけないので面倒
    // char titles[2][10]  // 文字数10までの要素2の文字列要素群
    char *titles[] = {"aiueo","oeuia"};

    char **targetTitle[2];

    targetTitle[0] = &titles[0];
    targetTitle[1] = &titles[1];

    printf("titles address:%p titles[1] address:%p\n",&titles,&titles[1]);
    printf("typeof char*:%ld\n",sizeof(char*));
    printf("targetTitle[0] address:%p value:%p targetPointerValue:%s\n",&targetTitle[0], targetTitle[0],*targetTitle[0]);


    // (手椅子へのポインタ)のポインタ
    const int limit = 100;
    const int *const cpi = &limit;
    const int *const * pcpi = &cpi;

    printf("limit address:%p value:%d\n",&limit,limit);
    printf("cpi address:%p value:%p pValue:%d\n",&cpi,cpi,*cpi);
    printf("pcpi address:%p value:%p pValue:%p\n",&pcpi,pcpi,*pcpi);

    return 0;
}