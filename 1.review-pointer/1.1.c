# include <stdio.h>
volatile int i = 123;

int main(void){
    int num = 123;
    int *pi = &num;
    printf("num:%d\n",num);
    printf("&num:%p\n",&num);
    printf("*&pi:%p\n",&pi);
    // *は間接演算子：ポインタ変数が指している先の値を取得する
    printf("*pi:%d\n",*pi);
    // int型へのポインタpiが指している値を変更する
    *pi = 321;
    printf("Address of num:%p Value: %d\n",&num,num);

    return(0);
}