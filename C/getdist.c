#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include<float.h>
#include "mylib.h"

//#define FILEOUT 
#define FILE_LENG 100
#define  DIVIDE_HISTO 10
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


void count_data(FILE *infp, FILE *outfp){   //data数を数える関数
  int i=1;
  double x;
  
  while((fscanf(infp, "%lf", &x))!=EOF){
    fprintf(outfp, "%d\t%lf\n", i, x);
    i++;
  }

}


void statistics(FILE *infp, FILE *outfp){
  int data_len=0;  //data_len=data数を格納
  double average=0.0; 
  double max=DBL_MIN, min=DBL_MAX;
  double infp_data;
  double variance=0.0; //variance=分散を格納

  while((fscanf(infp, "%lf", &infp_data)) != EOF){
    average+=infp_data;
    variance+=infp_data*infp_data;
    if(max < infp_data) max=infp_data;
    if(min > infp_data) min=infp_data;
    data_len++;
  } 
  
  fprintf(outfp, "average:%lf\n", ( average/(double)data_len ));
  fprintf(outfp, "standard deviation:%lf\n", sqrt(variance/(double)data_len));
  fprintf(outfp, "minimum:%lf\n", min);
  fprintf(outfp, "maximum:%lf\n", max);

}


void histogram(FILE *infp, FILE *outfp){
  int h[DIVIDE_HISTO]={0};
  int i, j;
  double histo_bins=1.0/DIVIDE_HISTO, infp_data;
  double n=DIVIDE_HISTO;
  
  while((fscanf(infp, "%lf", &infp_data)) != EOF)
    h[(int)(infp_data*n)]++;
  
  for(i=0; i<n; i++){
    fprintf(outfp, "%.2f-%.2f:", (i*histo_bins), ((i+1)*histo_bins));
    for(j=0; j<h[i]; j++) fprintf(outfp, "*");
    fprintf(outfp, "\n");
  }
}


/*------------------------------------------------------*/
  
int main(int argc, char *argv[]){
  int opt;
  int frag_n=0, frag_a=0, frag_g=0;
  char file_name[FILE_NAME_MAX];
  FILE* infp;
  FILE* outfp;
  
  
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
  
  infp=fRopen(file_name);

#ifdef FILEOUT
  if((outfp=fopen("result.dat", "w"))==NULL){
    return 0;
  }
#else
  outfp=stdout;
#endif
  
  
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
