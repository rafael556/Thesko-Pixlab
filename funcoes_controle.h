#ifndef FUNCOES_CONTROLE_H
#define FUNCOES_CONTROLE_H
#include"validacoes.h"
#include"estruturas.h"

void criacao_conta();
void deposito();  
void print_contas();                            //pendente
void excluir_contas();//fudeu                   //pendente
void transacao_pix();                           //pendente
void informacao_transacao(conta x, conta y);    //pendente
double extrato_t(int num_conta);
void extrato();                                 //pendente
 bool existe_conta(int numconta);
 int busca_conta(int numconta);                 

 //buscar conta com pix

#endif
