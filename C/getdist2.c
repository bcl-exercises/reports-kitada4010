#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include<float.h>
#include "mylib.h"

#define FILEPUT
#define FILE_LENG 100
#define DIVIDE 10
#define FILE_NAME_MAX 256

void Usage(void){
  printf("Usage: getdist2 [option]  <file>\n");
  printf("option:\n");
  printf("-h) Show this message\n");
  printf("-n) with line number\n");
  printf("-a) <average> <standard deviation> <minimum> <maximum>\n");
  printf("-g) histogram\n");

  exit(0);
}


void count_data(FILE *infp, FILE *outfp){  //data数を数える関数
  int i=1;
  double x;

  while((fscanf(infp, "%lf", &x)) != EOF){
    fprintf(outfp, "%d\t%lf\n", i, x);
    i++;
  }
  
}


void statistics(FILE *infp, FILE *outfp){
  int data_len=0; //data_len=data数を格納
  double average=0.0;
  double max=DBL_MIN, min=DBL_MAX;
  double infp_data;
  double stde=0.0; //stde=standard deviationを計算するための変数

  while((fscanf(infp, "%lf", &rand_data)) != EOF){
    average+=rand_data;
    stde+=rand_data*rand_data;
    if(max < rand_data) max=rand_data;
    if(min > rand_data) min=rand_data;
  }
  
  fprintf(outfp, "average:%lf\n", ( average/(double)data_len ));
  fprintf(outfp, "standard deviation:%lf\n", sqrt(stde/(double)data_len));
  fprintf(outfp, "minimum:%lf\n", min);
  fprintf(outfp, "maximum:%lf\n", max);

}


void histogram(FILE *infp, FILE *outfp){
  int h[DIVIDE]={0};
  int i, j;
  double stride=1.0/DIVIDE, rand_data;
  double n=DIVIDE;

  while((fscanf(infp, "%lf", &rand_data)) != EOF)
    h[(int)(rand_data*n)]++;
  
  for(i=0; i<n; i++){
    fprintf(outfp, "%.2f-%.2f:", (i*stride), ((i+1)*stride));
    for(j=0; j<h[i]; j++) fprintf(outfp, "*");
    fprintf(outfp, "\n");
  }
}


/*-------------------------------------------------------*/
  
int main(int argc, char *argv[]){
  int opt; 
  int frag_n=0, frag_a=0, frag_g=0;
  char file_name[FILE_NAME_MAX]={'\0'};
  FILE* infp;
  FILE* outfp;

  
#ifdef FILEOUT
  if((outfp=fopen("result.dat", "w"))==NULL){
    return 0;
  }
#else
  outfp=stdout;
#endif

  
  while((opt = getopt(argc, argv, "nagh:")) != -1){
    switch (opt){
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

  if(argv[optind]=='\0'){
    infp=fRPopen();
  }
  

  else{
    strcpy(file_name, argv[optind]);
    infp=fRopen(file_name);
  }
  
  if(frag_n){
    count_data(infp, outfp);
  }
  if(frag_a){
    rewind(infp);
    statistics(infp, outfp);
  }
  if(frag_g){
    rewind(infp);
    histogram(infp, outfp);
  }

  fclose(infp);
  fclose(outfp);

  return 0;
}
