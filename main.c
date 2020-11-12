#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"estruturas.h"
#include"validacoes.c"
#include"funcoes_controle.c"
#include"funcoes_extrato.c"

/*
1
Rafael Cruz
016.553.436-29
43993469439
rafael7jf@hotmail.com.br
15/01/2000
20Rlmn
1
Leila Cruz
092.553.436-29
43993469439
rafael7jf@hotmail.com.br
15/01/2000
20Jklm
1
Joao Cruz
092.543.436-29
43993469439                     //testar pagamento email e telefone pendente
rafael7jf@hotmail.com.br
15/01/2000
20KLmn
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
      

      switch (decisao_1)
      {
          case 1:
            criacao_conta();
            break;
          case 2:
            extrato();
            break;
          case 3:
            deposito();
            break;
          case 4:
            print_contas_ordenadas();
            break;
          case 5:
            transacao_pix();
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