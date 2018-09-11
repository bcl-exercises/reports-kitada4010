#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<string.h>
#include<float.h>
#include "mylib.h"

<<<<<<< HEAD
//#define FILEOUT
#define FILE_LENG 100
#define  DIVIDE 10
=======
#define FILEPUT
#define FILE_LENG 100
#define DIVIDE 10
>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
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

<<<<<<< HEAD
int count_data(int frag_n, FILE *infp, FILE *outfp){
=======

int count_data(int frag_n, FILE *infp, FILE *outfp){  //data数を数える関数
>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
  int i=1;
  double x;

  while((fscanf(infp, "%lf", &x)) != EOF){
<<<<<<< HEAD
    if(frag_n)
      fprintf(outfp, "%d\t%lf\n", i, x);
    i++;
  }
  
=======
    if(frag_n) fprintf(outfp, "%d\t%lf\n", i, x);
    i++;
  }

>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
  return i-1;
}


<<<<<<< HEAD
void statistics(int data_len, FILE *infp, FILE *outfp){
  double average=0.0, reciprocal=1.0/((double)data_len);
  double max=0.0, min=1.0;
  double rand_data;
  double stde=0.0;
  
=======
void statistics(int len, FILE *infp, FILE *outfp){
  double average=0.0, reciprocal=1.0/((double)len); //reciprocal=data数の逆数を格納
  double max=DBL_MIN, min=DBL_MAX;
  double rand_data;
  double stde=0.0; //stde=standard deviationを計算するための変数

>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
  while((fscanf(infp, "%lf", &rand_data)) != EOF){
    average+=rand_data;
    stde+=rand_data*rand_data;
    if(max < rand_data) max=rand_data;
    if(min > rand_data) min=rand_data;
  }
  
  fprintf(outfp, "average:%lf\n", (reciprocal*average));
  fprintf(outfp, "standard deviation:%lf\n", sqrt(reciprocal*stde));
  fprintf(outfp, "minimum:%lf\n", min);
  fprintf(outfp, "maximum:%lf\n", max);

}

<<<<<<< HEAD
=======

>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
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
<<<<<<< HEAD
  int data_len;
=======
  int opt, data_len,fs=0; //data_len=dataの長さを格納する変数 fs=ファイルの有無
>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
  int frag_n=0, frag_a=0, frag_g=0;
  char file_name[FILE_NAME_MAX]={'\0'};
  FILE* infp;
  FILE* outfp;
<<<<<<< HEAD

#ifdef FILEOUT
  outfp=fopen("result.dat", "w");
=======
  
#ifdef FILEOUT
  if((outfp=fopen("result.dat", "w"))==NULL){
    return 0;
  }
>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
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
  
<<<<<<< HEAD
  else{
    strcpy(file_name, argv[optind]);
    infp=fRopen(file_name);
  }

  data_len=count_data(frag_n, infp, outfp);
=======
  if(fs) infp=fRopen(file_name);
  else infp=fRPopen();
  
  data_len=count_data(frag_n, infp, outfp);
  fclose(infp);
  if(frag_a){
    infp=fRopen(file_name);
    statistics(data_len, infp, outfp);
    fclose(infp);
  }
  if(frag_g){
    infp=fRopen(file_name);
    histogram(infp, outfp);
    fclose(infp);
  }
  fclose(outfp);
>>>>>>> eb99e1fc762cbff6513751a8921636e88f78f459
  
  if(frag_a){
    rewind(infp);
    statistics(data_len, infp, outfp);
  }
  if(frag_g){
    rewind(infp);
    histogram(infp, outfp);
  }

  fclose(infp);
  fclose(outfp);

  return 0;
}
