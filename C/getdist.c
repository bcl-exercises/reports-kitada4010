#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include "mylib.h"

#define FILE_LENG 100
#define  STRIDE 10
#define FILE_NAME_MAX 256

void Usage(void){
  printf("Usage: getdist [option]  <file>\n");
  printf("option:\n");
  printf("-h) Show this message\n");
  printf("-n) with line number\n");
  printf("-a) <average> <standard deviation> <minimum> <maximum>\n");
  printf("-g) histogram\n");
  
  exit(0);
}


int count_line(int frag_n, const char fname[]){
  int i=1;
  double x;
  FILE* input;

  input=fRopen(fname);
  
  while((fscanf(input, "%lf", &x))!=EOF){
    if(frag_n) printf("%d\t%lf\n", i, x);
    i++;
  }
  
  fclose(input);

  return i-1;
}


void statistics(int len, const char fname[]){
  double average=0.0, reciprocal=1.0/((double)len);
  double max=0.0, min=1.0;
  double rand_data;
  double stde=0.0;
  FILE *input;

  input=fRopen(fname);

  while((fscanf(input, "%lf", &rand_data)) != EOF){
    average+=rand_data;
    stde+=rand_data*rand_data;
    if(max < rand_data) max=rand_data;
    if(min > rand_data) min=rand_data;
  }
  
  printf("average:%lf\n", (reciprocal*average));
  printf("standard deviation:%lf\n", sqrt(reciprocal*stde));
  printf("minimum:%lf\n", min);
  printf("maximum:%lf\n", max);
  
  fclose(input);
}


void histogram(const char fname[]){
  int h[STRIDE]={0};
  int i, j;
  double stride=1.0/STRIDE, rand_data;
  FILE* input;
  double n=STRIDE;

  input=fRopen(fname);
  
  while((fscanf(input, "%lf", &rand_data)) != EOF)
    h[(int)(rand_data*n)]++;
  
  fclose(input);
  
  for(i=0; i<n; i++){
    printf("%.2f-%.2f:", (i*stride), ((i+1)*stride));
    for(j=0; j<h[i]; j++) printf("*");
    printf("\n");
  }
}

/*------------------------------------------------------*/
  
int main(int argc, char *argv[]){
  int opt, len;
  int frag_n=0, frag_a=0, frag_g=0;
  char file_name[FILE_NAME_MAX];
  
  while( (opt = getopt(argc, argv, "gnah:")) != -1){
    switch(opt){
    case 'n':
      frag_n=1;
      break;  
    case 'a':
      frag_a=1;
      break;
    case 'g':
      frag_g=1;
      break;
    default:
      Usage();
    }
  }

  if((frag_n + frag_a + frag_g) == 0)
    Usage();
  
  strcpy(file_name, argv[optind]);
  
  len=count_line(frag_n, file_name);
  if(frag_a) statistics(len, file_name);
  if(frag_g) histogram(file_name);
  
  return 0;
}
