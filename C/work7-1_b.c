#include<stdio.h>
#include "mylib.h"

#define X0 1.0
#define DIVIDE_NUM 100
#define END 1.0
#define MAX 256

int main(void){
  double x=X0, h=1.0/DIVIDE_NUM;
  int re=DIVIDE_NUM;
  int i;
  FILE *outfp;
  char fname[MAX]={'\0'};

  sprintf(fname, "%.7f-data.txt", h);
  outfp=fWopen(fname);
  
  fprintf(outfp, "%lf\t%lf\n", 0.0, x);
  
  for(i=1; i<=re; i++){
    x+=h*x;
    fprintf(outfp, "%lf\t%lf\n", (double)i*h, x);
  }
  
  fclose(outfp);
  
  return 0;

}
