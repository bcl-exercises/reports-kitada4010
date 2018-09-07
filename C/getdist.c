#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include<float.h>
#include "mylib.h"

#define FILEOUT 
#define FILE_LENG 100
#define  DIVIDE 10
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


int count_data(int frag_n, FILE *randfp, FILE *output_datafp){   //data数を数える関数
  int i=1;
  double x;
  
  while((fscanf(randfp, "%lf", &x))!=EOF){
    if(frag_n) fprintf(output_datafp, "%d\t%lf\n", i, x);
    i++;
  }

  return i-1;
}


void statistics(int len, FILE *randfp, FILE *output_datafp){
  double average=0.0, reciprocal=1.0/((double)len); //reciprocal=data数の逆数を格納
  double max=DBL_MIN, min=DBL_MAX;
  double rand_data;
  double stde=0.0; //stde=standard deviationを計算するための変数

  while((fscanf(randfp, "%lf", &rand_data)) != EOF){
    average+=rand_data;
    stde+=rand_data*rand_data;
    if(max < rand_data) max=rand_data;
    if(min > rand_data) min=rand_data;
  }
  
  fprintf(output_datafp, "average:%lf\n", (reciprocal*average));
  fprintf(output_datafp, "standard deviation:%lf\n", sqrt(reciprocal*stde));
  fprintf(output_datafp, "minimum:%lf\n", min);
  fprintf(output_datafp, "maximum:%lf\n", max);

}


void histogram(FILE *randfp, FILE *output_datafp){
  int h[DIVIDE]={0};
  int i, j;
  double stride=1.0/DIVIDE, rand_data;
  double n=DIVIDE;
  
  while((fscanf(randfp, "%lf", &rand_data)) != EOF)
    h[(int)(rand_data*n)]++;
  
  for(i=0; i<n; i++){
    fprintf(output_datafp, "%.2f-%.2f:", (i*stride), ((i+1)*stride));
    for(j=0; j<h[i]; j++) fprintf(output_datafp, "*");
    fprintf(output_datafp, "\n");
  }
}

/*------------------------------------------------------*/
  
int main(int argc, char *argv[]){
  int opt, data_len; //data_len=dataの長さを格納する変数
  int frag_n=0, frag_a=0, frag_g=0;
  char file_name[FILE_NAME_MAX];
  FILE* randfp;
  FILE* output_datafp;
  
#ifdef FILEOUT
  if((output_datafp=fopen("result.dat", "w"))==NULL){
    return 0;
  }
  // output_datafp=stdout;
#else
  output_datafp=stdout;
#endif
  
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

  if((frag_n + frag_a + frag_g) == 0) Usage();
  
  strcpy(file_name, argv[optind]);
  
  randfp=fRopen(file_name);
  data_len=count_data(frag_n, randfp, output_datafp);
  fclose(randfp);
  if(frag_a){
    randfp=fRopen(file_name);
    statistics(data_len, randfp, output_datafp);
    fclose(randfp);
  }
  if(frag_g){
    randfp=fRopen(file_name);
    histogram(randfp, output_datafp);
    fclose(randfp);
  }
  fclose(output_datafp);
  
  return 0;
}
