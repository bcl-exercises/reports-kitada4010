#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "mylib.h"

#define T0 0.0 //初期時間
#define X0 0.0 //初期位置(横軸)
#define Y0 1.5 //初期位置(縦軸)
#define DIVIDE_NUM 1000 
#define G 9.8 //重力加速度
#define FNAMEMAX 256 //ファイル名の最大文字数

void Usage(void){
  printf("Usage: work7-2_b <mass[kg]> <angle[°]> <initial velocity[m/s]>\n");
  exit(0);
}


/*----------------------------------------------------------------------------*/


int main(int argc, char *argv[]){
  double t=T0, x=X0, y=Y0, h=1.0/DIVIDE_NUM, g=G; //t:初期時間 x:位置(横軸) y:位置(縦軸) h:刻み値 g:重力加速度
  double m,theta,v; //m:質量 theta:進行方向の角度 v:速度
  double v_y, v_x; //v_y:縦方向の速度 v_x:横方向の速度
  double time=0; //経過時間
  char fname[FNAMEMAX]={'\0'}; //ファイル名
  FILE* outfp;

  if(argc!=4)
    Usage();
  
  if((m=atof(argv[1]))==0 || (v=atof(argv[3]))==0)
    Usage();
  
  theta=atof(argv[2]);
  
  sprintf(fname, "m:%.3f_θ:%.2f_v:%.3f-data", m, theta, v); 
  outfp=fWopen(fname);
  
  theta=(theta*M_PI)/180.0;
  
  v_y=v*sin(theta);
  v_x=v*cos(theta);
  
  fprintf(outfp, "%lf\t%lf\t%lf\n", t, x, y);

  while(y>0){
    x+=h*v_x;
    time+=h;
    y+=h*((-g*time)+v_y);
    fprintf(outfp, "%lf\t%lf\t%lf\n", t+time, x, y);
  }
  
  fclose(outfp);
  return 0;
}
