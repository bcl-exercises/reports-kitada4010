#include<stdio.h>
#define X0 1
#define H 0.1

int main(void){
  double x=X0, h=H;
  
  x+=h*x;
  

  return 0;

}
