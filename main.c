#include<stdio.h>
#include<windows.h>
#include"estruturas.h"
#include"validacoes.c"
#include"funcoes_controle.c"


int main(){

    printf("Hello World\n");
   
    char t[30]="rafael7jf@hotmail.com.br";
  //  char inicial[30];
  //  strcpy(inicial,substr(t,18,24));
   // printf("%s\n",inicial);
    
   
 if(validar_senha("Rafael556"))
    printf("true\n");
  else
    printf("false\n");
    
    system("PAUSE");
    return 0;
}