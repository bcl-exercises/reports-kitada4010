#include<stdio.h>
#include <stdlib.h>


int main(void){
  int **matrix;
  int i, j, n, m;
  n = 100, m = 100;

  matrix = malloc(sizeof(int *) * n);
  for (i=0;i<n;i++) {
    matrix[i] = malloc(sizeof(int) * m);
  }

  for (i=0;i<n;i++) {
    for (j=0;j<m;j++) {
      matrix[i][j] = i * m + j;
      printf("%d\n", matrix[i][j]);
    }
  }

  for (i=0;i<n;i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}
