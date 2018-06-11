#include<stdio.h>

FILE* fRopen(char* fname){
  FILE *fp;
  if( (fp=fopen(fname,"r"))==NULL){
    printf("Failed to open %s\n",fname);
    exit(0);
  }
  return fp;
}



