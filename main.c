#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"estruturas.h"
#include"validacoes.c"
#include"funcoes_controle.c"

/*
1
Rafael Cruz
016.553.436-29
43991717399
rafael7jf@hotmail.com.br
15/01/2020
2Rklmn
1
Rafael Cruz
016.553.436-29
43991717399
rafael7jf@hotmail.com.br
15/01/2020
2Rklmn


*/ 

int main(){
  int decisao_1;
   
    puts("Bem-Vindo ao sistema Pix\n");
    
    while(decisao_1!=7){
      puts("1- Criar nova conta");
      puts("2- Consultar extrato de conta");
      puts("3- Depositar em conta");
      puts("4- Listar todas as contas");
      puts("5- pagamento com chaves pix");
      puts("6- excluir conta");
      puts("7- sair");
      printf("\nDigite o numero da operacao requerida:");
      scanf("%d",&decisao_1);
      fflush(stdin);
      // printf("\n%d\n",decisao_1);

      switch (decisao_1)
      {
          case 1:
            criacao_conta();
            break;
          case 2:
           // extrato();
            break;
          case 3:
            deposito();
            break;
          case 4:

            break;
          case 5:

            break;
          case 6:

            break;
          case 7:
            exit(0);
            break;
          default:
            break;
      }
      system("cls");
    }
    system("PAUSE");
    return 0;
}
