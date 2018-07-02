#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include "mylib.h"
#define FILE_LENG 100
#define  STRIDE 10
void Usage(void){
  printf("Usage: getdist [option]  <file>\n");
  printf("option:\n");
  printf("-h) Show this message\n");
  printf("-n) with line number\n");
  printf("-a) <average> <standard deviation> <minimum> <maximum>\n");
  printf("-g) histogram\n");
  exit(0);
}

int option_n(int option,const char fname[]){
  int i=1, j=0;
  double x;
  FILE* input;
  input=fRopen(fname);
  if(option%2==0)
    j=1;
  while((fscanf(input,"%lf",&x))!=EOF){
    if(j)
      printf("%d\t%lf\n",i,x);
    i++;
  }
  fclose(input);
  return i-1;
}


void option_a(int leng,const char fname[]){
  double average=0.0, reciprocal=1.0/((double)leng);
  double max=0.0, min=1.0;
  double data;
  double stde=0.0;
  FILE *input;
  input=fRopen(fname);
  while((fscanf(input,"%lf",&data))!=EOF){
    average+=data;
    stde+=data*data;
    if(max<data)
      max=data;
    if(min>data)
      min=data;
  }
  printf("average:%lf\n",reciprocal*average);
  printf("standard deviation:%lf\n",sqrt(reciprocal*stde));
  printf("minimum:%lf\n",min);
  printf("maximum:%lf\n",max);
  fclose(input);
}

void option_g(const char fname[]){
  int h[STRIDE]={0};
  int i, j;
  double stride=1.0/STRIDE, data;
  FILE* input;
  double n=STRIDE;
  input=fRopen(fname);
  while((fscanf(input,"%lf",&data))!=EOF)
    h[(int)(data*n)]++;
  fclose(input);
  
  for(i=0; i<n; i++){
    printf("%.2f-%.2f:",i*stride,(i+1)*stride);
    for(j=0; j<h[i]; j++)
      printf("*");
    printf("\n");
  }
}


/*------------------------------------------------------*/
  
int main(int argc, char *argv[]){
  int opt,option=1, leng;
   
  while((opt = getopt(argc, argv, "gnah:"))!= -1){
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


  leng=option_n(option,argv[optind]);
  if(option%3==0)
    option_a(leng,argv[optind]);
  if(option%5==0)
    option_g(argv[optind]);
  
  return 0;
}
