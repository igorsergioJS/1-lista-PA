#include <stdio.h>

int main(){

  int pulo[5] = {1,2,3,4,5};
  int a,b,*c,*d;

  a = *(pulo + 2);
  b = *(pulo + 4);
  c = pulo + 4;
  d = pulo + 2;


  printf("%d %d %d %d",a, b, *c, *d);

  printf("\n %d", *(pulo + 2));

  printf("\n %d", *(pulo + 4));

  printf("\n %d", (pulo + 4)); //Builda e executa no codeblocks, mas pode dar erro em outros compiladores;

  printf("\n %d", (pulo + 4)); //Builda e executa no codeblocks, mas pode dar erro em outros compiladores;


}
