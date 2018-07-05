#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

/*-------------------------*/

int main(void){
  int i;
  double rand_data;
  time_t tp;
  
  time(&tp);
  srand48(tp);

  for(i=0; i<MAX; i++){
    rand_data = drand48();
    printf("%lf\n",rand_data);
  }
  
  return 0;
}
