#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "mylib.h"
#define T0 0.0
#define X0 0.0
#define Y0 1.5
#define H 0.0001
#define G 9.8
#define MAX 256
void Usage(void){
  printf("Usage: work7-2_b <mass[kg]> <angle[°]> <initial velocity[m/s]>\n");
  exit(0);
}



int main(int argc, char *argv[]){
  double t=T0, x=X0, y=Y0, h=H, g=G;
  double m,theta,v0;
  double v0sin, v0cos;
  double time=0;
  char fname[MAX]={'\0'};
  FILE* output;
  if(argc!=4)
    Usage();
  if((m=atof(argv[1]))==0 || (v0=atof(argv[3]))==0)
    Usage();
  theta=atof(argv[2]);
  sprintf(fname,"m:%.3f_θ:%.2f_v0:%.3f-data",m,theta,v0); 
  output=fWopen(fname);
  theta=(theta*M_PI)/180.0;
  v0sin=v0*sin(theta);
  v0cos=v0*cos(theta);
  fprintf(output,"%lf\t%lf\t%lf\n",t,x,y);
  while(y>0){
    x+=h*v0cos;
    time+=h;
    y+=h*((-g*time)+v0sin);
    fprintf(output,"%lf\t%lf\t%lf\n",t+time,x,y);
  }
  fclose(output);
  return 0;
}
