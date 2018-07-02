#include<stdio.h>
#include<stdlib.h>
void Usage(void){
  printf("Usage: array <natural number>\n");
  exit(0);
}

void write(int a[], int n){
  int i,j;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++){
      if(i==j)
	a[(i*n)+j]=1;
      else
	a[(i*n)+j]=0;
    }
}	  

void display(int a[], int n){
  int i,j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++)
      printf("%3d ",a[(i*n)+j]);
    printf("\n");
  }
}

/*------------------------------------------------*/

int main(int argc, char *argv[]){
  int *a, n;
  if(argc != 2)
    Usage();
  if( (n=atoi(argv[1]))==0)
    Usage();
  if( (a = (int *)calloc(n*n,sizeof(int)))==NULL){
    printf("メモリが確保できませんでした。\n");
    Usage();
  }
   
  write(a,n);
  display(a,n);
  free(a);
   
  
  return 0;
}
