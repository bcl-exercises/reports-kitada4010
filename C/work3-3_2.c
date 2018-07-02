#include<stdio.h>
#include<stdlib.h>
void Usage(void){
  printf("Usage: sum <num1> <num2>\n");
  exit(0);
}

int main(int argc, char *argv[]){
  double a, b;
  if(argc != 3)
    Usage();

  a=atof(argv[1]);
  b=atof(argv[2]);
  printf("%lf\n",a+b);
  
  return 0;
}
