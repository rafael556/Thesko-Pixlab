/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#include<stdio.h>               
#include<stdlib.h>
#include<windows.h>             
#include"estruturas.h"          
#include"validacoes.c"          
#include"funcoes_controle.c"    
#include"funcoes_extrato.c"     

int main(){
  int decisao;                //variável de controle para o menu principal
   
    puts("Bem-Vindo ao sistema Pix\n");
    
    while(decisao!=7){
      puts("1- Criar nova conta");
      puts("2- Consultar extrato de conta");
      puts("3- Depositar em conta");
      puts("4- Listar todas as contas");
      puts("5- pagamento com chaves pix");
      puts("6- excluir conta");
      puts("7- sair");
      printf("\nDigite o numero da operacao requerida:");
      scanf("%d", &decisao);
      fflush(stdin);
      

      switch (decisao)
      {
          case 1:
            criacao_conta();          //comanda a entrada de dados para criação de contas
            break;
          case 2:
            extrato();                //busca conta ou chave pix e mostra seu saldo
            break;                
          case 3:
            deposito();               //busca conta e realiza o depósito na mesma
            break;
          case 4:
            print_contas_ordenadas(); //printa em ordem alfabetica todas as contas registradas
            break;
          case 5:
            transacao_pix();          //realiza transferencia entre contas através das chaves pix
            break;
          case 6:
            excluir_contas();         //exclui uma conta anteriormente registrada
            break;
          case 7:
            exit(0);                  //encerra o programa
            break;
          default:
            break;
      }
      system("cls");                  //limpa a tela
    }
    system("PAUSE");
    return 0;
}