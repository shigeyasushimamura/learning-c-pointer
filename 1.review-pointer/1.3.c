#include <stdio.h>
#include <stdint.h>

int main(void){
    int ary[] = {100,200,300};
    int *pi = ary;


    printf("value of ary:%p\n",ary);
    printf("Address of pi:%p target pointer:%p Value of target:%d\n",&pi,pi,*pi);

    pi += 1;
    printf("Address of pi:%p target pointer:%p Value of target:%d\n",&pi,pi,*pi);

    pi += 1;
    printf("Address of pi:%p target pointer:%p Value of target:%d\n",&pi,pi,*pi);

    // aryの要素のサイズだけ上記の操作でpiのポインタが動いた
    printf("Sizeof pi:%ld, Size of ary-index:%ld\n",sizeof(pi), sizeof(ary[0]));


    int *pi2 = &ary[2];
    printf("Address of pi:%p target pointer:%p Value of target:%d\n",&pi2,pi2,*pi2);

    // ポインタの比較
    printf("pi2-pi: %ld\n", pi2-pi);

    pi2 -= 1;
    printf("Address of pi:%p target pointer:%p Value of target:%d\n",&pi2,pi2,*pi2);

    // ポインタの比較
    printf("pi2-pi: %ld\n", pi2-pi);



    return 0;
}