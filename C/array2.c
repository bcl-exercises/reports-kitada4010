#include<stdio.h>
#include<stdlib.h>

void Usage(void){
  printf("Usage: array <natural number>\n");
  exit(0);
}

/*
void 2d_array_cordon_off(int **a, int n){
  int i;
  if((a = (int *)calloc(n, sizeof(int))) == NULL){
    printf("メモリが確保できませんでした。\n");
    Usage();
  }
  for(i=0; i<n; i++){
    if((a[i] = (int*)calloc(n, sizeof(int)))==NULL){
      printf("メモリが確保できませんでした。\n");
      Usage();
    }
  }

}*/

void write_identity_matrix(int **a, int n){
  int i,j;
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(i==j) a[i][j]=1;
      else a[i][j]=0;
    }
  }
}	  

void display_2d_array(int **a, int n){
  int i,j;
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++) printf("%3d ", a[i][j]);
    printf("\n");
  }
}

/*------------------------------------------------*/

int main(int argc, char *argv[]){
  int **a;
  int n;
  int i;
  
  if(argc != 2) Usage();
  
  if((n=atoi(argv[1])) == 0) Usage();
  
  //if((*a = (int *)calloc(n, sizeof(int))) == NULL){
  if((a = malloc(sizeof(int *) * n)) == NULL){
    printf("メモリが確保できませんでした。\n");
    Usage();
  }
  for(i=0; i<n; i++){
    //if((a[i] = (int *)calloc(n, sizeof(int)))==NULL){
    if((a[i] = malloc(sizeof(int *) * n)) == NULL){
      printf("メモリが確保できませんでした。\n");
      Usage();
    }
  }

  write_identity_matrix(a, n);
  display_2d_array(a, n);
  for(i=0; i<n; i++) free(a[i]);
  free(a);

 
  return 0;
}
