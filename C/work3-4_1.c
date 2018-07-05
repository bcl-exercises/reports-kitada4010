#include<stdio.h>
#include<stdlib.h>

void Usage(void){
  printf("Usage: array <natural number>\n");

  exit(0);
}

void write_array(int a[], int n){
  int i;

  for(i=0; i<n; i++) a[i]=i;
}

void display_array(int a[], int n){
  int i;
  
  for(i=0; i<n; i++) printf("a[%d]=%d\n", i, a[i]);
}

/*------------------------------------------------*/

int main(int argc, char *argv[]){
  int *a, n;

  if(argc != 2) Usage();
  if((n=atoi(argv[1])) == 0) Usage();
  if((a = (int *)calloc(n, sizeof(int))) == NULL){
    printf("メモリが確保できませんでした。\n");
    Usage();
  }

  write_array(a, n);
  display_array(a, n);

  free(a);
  
  return 0;
}
