#include<stdio.h>

#define MAX 10000000000

int main(void){
  int i;
  double x=0.1;

  for(i=0; i<MAX; i++){
    x*=0.1;
    x*=10;
  }

  return 0;
}
