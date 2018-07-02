#include<stdio.h>
#include "mylib.h"
#define X0 1.0
#define H 0.0000001
#define END 1.0
#define MAX 256
int main(void){
  double x=X0, h=H;
  double re=END/H;
  int i;
  FILE *output;
  char fname[MAX]={'\0'};
  sprintf(fname,"%.7f-data.txt",h);
  output=fWopen(fname);
  fprintf(output,"%lf\t%lf\n",0.0,x);
  for(i=1; i<=re; i++){
  x+=h*x;
  fprintf(output,"%lf\t%lf\n",(double)i*h,x);
  }
  fclose(output);
  return 0;

}
