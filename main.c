#include<stdio.h>
#include<windows.h>
#include"estruturas.h"
#include"validacoes.c"
#include"funcoes_controle.c"


int main(){

    printf("Hello World\n");
   long long int telefone=43991717399;
   char t[15]="41991717399";
    // printf("%s\n",substr(t,0,2));
    // char ddd[3];
    // strcpy(ddd,substr(t,0,2));
    // printf("%s\n",ddd);
   
   if(validar_telefone(433991717399))
  // if(strcmp(ddd,"42")<0)
    printf("true\n");
   else
    printf("false\n");
    
    system("PAUSE");
    return 0;
}