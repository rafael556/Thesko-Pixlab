#include<stdio.h>
#include<windows.h>
#include"estruturas.h"
#include"validacoes.c"
#include"funcoes_controle.c"


int main(){

    printf("Hello World\n");
   char cpf[16]="016.553.436-29";
   
  
   
   if(validar_cpf("226.554.260.10"))
    printf("true\n");
   else
    printf("false\n");
    
    system("PAUSE");
    return 0;
}