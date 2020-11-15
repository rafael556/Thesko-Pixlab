/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#ifndef FUNCOES_CONTROLE_H
#define FUNCOES_CONTROLE_H
#include"validacoes.h"
#include"estruturas.h"
#include"funcoes_extrato.h"

/*-------------------------------
Função: criacao_conta
Parâmetros: nenhum
Retorno: nenhum
Descrição: submenu principal que faz a admissão 
e validação de dados para a criação de contas
---------------------------------*/
void criacao_conta();  

/*-------------------------------
Função: deposito
Parâmetros: nenhum
Retorno: nenhum
Descrição: submenu principal que busca conta
ou chave pix, deposita e depois mostra o saldo
---------------------------------*/
void deposito();       

 /*-------------------------------
Função: print_contas
Parâmetros: nenhum
Retorno: nenhum
Descrição: printa as informações principais da
conta após a criação da mesma
---------------------------------*/                        
void print_contas();

/*-------------------------------
Função: print_contas_ordenadas
Parâmetros: nenhum
Retorno: nenhum
Descrição: printa em ordem alfabetica
todas as contas registradas e mostra 
nome, cpf e numero da conta
---------------------------------*/                
void print_contas_ordenadas();   

 /*-------------------------------
Função: excluir conta
Parâmetros: nenhum
Retorno: nenhum
Descrição: busca conta ou chave pix
e exclui a mesma do registro
---------------------------------*/              
void excluir_contas();

/*-------------------------------
Função: transacao_pix
Parâmetros: nenhum
Retorno: nenhum
Descrição: busca conta para transferencia e
utiliza as chaves pix para encontrar o destino
e no final mostra as informações das duas contas
---------------------------------*/                   
void transacao_pix();
                           
#endif
