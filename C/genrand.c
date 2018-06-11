#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
int main(void){
  int i;
  double a;
  time_t tp;
  time(&tp);
  srand48(tp);

  for(i=0; i<MAX; i++){
    a = drand48();
    printf("%lf\n",a);
  }
  return 0;
}
