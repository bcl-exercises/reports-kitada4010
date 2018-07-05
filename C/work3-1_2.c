#include<stdio.h>

#define MAX 3

int main(void){
  int a[MAX];
  int i;

  for(i=0; i<MAX; i++) a[i]=0;

  for(i=0; i<MAX; i++) printf("a[%d]=%d\n", i, a[i]);
  
  return(0);
}
