#include<stdio.h>

int main(int argc, char *argv[]){
  int i;

  printf("%d\n",argc);

  for(i=0; i<argc; i++) printf("%s ",argv[i]);
  printf("\n");

  return 0;
}
