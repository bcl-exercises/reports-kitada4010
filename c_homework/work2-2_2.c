#include<stdio.h>

void func(int n1, int *np2){
  n1=*np2;
  *np2=8;
  np2=&n1;
}

int main(void){
  int n1=0, n2=5;
  int *np1, *np2, *tmp;

  np1=&n2; //np1にn2のポインタを代入
  n2++; //n2をプラス１
  tmp=&n1; //tmpにn1のポインタを代入
  (*tmp)++; //tmpのポインタを指定してプラス1
  np2=tmp; //np2にtmpのポインタを代入
  (*tmp)++; //tmpのポインタを指定してプラス１

  printf("N1=%d, N2=%d, *NP1=%d, *NP2=%d\n" ,n1,n2,*np1, *np2);
  //n1はtmpとおなじポインタであるため2
  //n2は++したので6
  //*np1はn2のポインタと同様であるため6
  //*np2はtmpとおなじポインタであるため2

  func(*np1,np2); //np1の数字とnp2のポインタを関数に渡す。よって、この関数によってnp1の値は変化しない。
  //n1にnp2のポインタを代入
  //np2に8を代入
  //np2にn1のポインタを代入
  printf("*NP1=%d, *NP2=%d\n",*np1,*np2); //*np1の値は変化しないため6、*np2の値は8
}
