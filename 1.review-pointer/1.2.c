#include <stdio.h>
#include <stdint.h>

int main(void){
  printf("Size of char %ld\n",sizeof(char));
  printf("Size of *char: %ld\n",sizeof(char*));

  int num = 123;
  intptr_t *pi = (intptr_t*)(void*)&num;
  printf("Sizeof num:%d pointer:%p\n",num,&num);
  printf("Sizeof pi:%ld pointer:%p Value:%p\n",sizeof(intptr_t*),&pi,pi);


  int num2 = 456;
  intptr_t *pi2 = (intptr_t*)(void*)&num;
  printf("Pointer:%p Value:%d\n", &num, num);
  printf("Sizeof pi2:%ld Pointer:%p Value:%p\n", sizeof(intptr_t*),&pi2,pi);


  return(0);
}