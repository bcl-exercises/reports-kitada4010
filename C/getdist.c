#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define FILE_LENG 100
#define STRIDE 10
void Usage(void){
  printf("Usage: getdist [option]  <file>\n");
  printf("option:\n");
  printf("-h) Show this message\n");
  printf("-n) with line number\n");
  printf("-a) <average> <standard deviation> <minimum> <maximum>\n");
  printf("-g) histogram\n");
  exit(0);
}

int option_n(int option,FILE *input){
  int i=1, h=0;
  double x;
  if(option%2==0)
    h=1;
  while((fscanf(input,"%lf",&x))!=EOF){
    if(h)
      printf("%d\t%lf\n",i,x);
    i++;
  }
  
  return i-1;
}

/*void option_a(int leng, double x[]){
  int i;
  //  while
  printf("not complate");
  
  
  }*/

void option_g(int leng, double x[]){
  int h[STRIDE]={0};
  int n=STRIDE, i, j;
  double stride=1.0/STRIDE;
  
  for(i=0; i<leng; i++)
    h[(x[i]*n)]++;
  for(i=0; i<n; i++){
    printf("%.2f-%.2f:",i*stride,(i+1)*stride);
    for(j=0; j<x[i]; j++)
      printf("*");
    printf("\n");
  }

}



void option_n(FILE*){
}
  
int main(int argc, int *argv[]){
  int i, opt,option=1, leng;
  FILE *input;
  
  while((opt = getopt(argc, argv, "hnag:"))!= -1){
    switch (opt){
    case 'n':
      option*=2;
      break;
      
    case 'a':
      option*=3;
      break;
      
    case 'g':
      option*=5;
      break;
      
    default:
      Usage();
      
    }
  }

  if(option==1)
    Usage();

  else{
    *input=fRopen(argv[optind]);
    leng=option_n(option,*input);
  }
  
  
  printf("end\n");
  
  return 0;
}
