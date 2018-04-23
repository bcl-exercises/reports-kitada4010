#include<stdio.h>
#include<stdlib.h>
FILE* fRopen(const char fname[]){
  FILE *fp;
  if( (fp=fopen(fname,"r"))==NULL){
    printf("Failed to open %s\n",fname);
    exit(0);
  }
  return fp;
}

FILE* fWopen(const char fname[]){
  FILE *fp;
  if( (fp=fopen(fname,"w"))==NULL){
    printf("Failed to open %s\n",fname);
    exit(0);
  }
  return fp;
}
