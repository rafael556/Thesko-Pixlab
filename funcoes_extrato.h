/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#ifndef FUNCOES_EXTRATO_H
#define FUNCOES_EXTRATO_H
#include"funcoes_controle.h"

/*-------------------------------
Função: extrato
Parâmetros: nenhum
Retorno: nenhum
Descrição: faz a busca da conta ou pix
e mostra o saldo da conta em questão
---------------------------------*/ 
void extrato();

/*-------------------------------
Função: existe_conta
Parâmetros: nconta - numero da conta
Retorno: verdadeiro ou falso se a conta existe no registro de contas
Descrição: verifica se a conta existe no registro
---------------------------------*/               
bool existe_conta(int nconta);

/*-------------------------------
Função: existe_cpf
Parâmetros: cpf - string de cpf
Retorno: verdadeiro ou falso se cpf existe no registro de contas
Descrição: verifica se cpf pertence a alguma conta do registro
---------------------------------*/ 
bool existe_cpf(char cpf[]);

/*-------------------------------
Função: existe_email
Parâmetros: email - string de email
Retorno: verdadeiro ou falso se email existe no registro de contas
Descrição: verifica se email pertence a alguma conta do registro
---------------------------------*/ 
bool existe_email(char email[]);

/*-------------------------------
Função: existe_telefone
Parâmetros: telefone - numero de telefone
Retorno: verdadeiro ou falso se existe no registro de contas
Descrição: verifica se telefone pertence a alguma conta do registro
---------------------------------*/ 
bool existe_telefone(long long int telefone);

/*-------------------------------
Função: existe_senha
Parâmetros: senha - string de senha 
Retorno: verdadeiro ou falso se existe no 
registro de contas
Descrição: verifica se senha pertence a alguma 
conta do registro
---------------------------------*/ 
bool existe_senha(char senha[]);

/*-------------------------------
Função: posicao_conta
Parâmetros: conta - numero de conta
Retorno: numero da posição de conta no registro de contas
Descrição: verifica a posição da conta no registro 
---------------------------------*/ 
int posicao_conta(int nconta);  

/*-------------------------------
Função: posicao_cpf
Parâmetros: cpf - string de cpf
Retorno: posição do cpf no registro de contas
Descrição: verifica a posição da conta associada a esse cpf no registro 
---------------------------------*/ 
int posicao_cpf(char cpf[]);        

/*-------------------------------
Função: posicao_email
Parâmetros: email - string de email
Retorno: posição do email no registro de contas
Descrição: verifica a posição da conta associada a esse email no registro
---------------------------------*/ 
int posicao_email(char email[]);

/*-------------------------------
Função: posicao_telefone
Parâmetros: telefone - numero de telefone
Retorno: posição do telefone no registro de contas
Descrição: verifica a posição da conta associada a 
esse telefone no registro 
---------------------------------*/ 
int posicao_telefone(long long int telefone);

/*-------------------------------
Função: posicao_senha
Parâmetros: senha - string de senha que será analisado
Retorno: posição de senha no registro de contas
Descrição: verifica a posição da conta associada a 
essa senha no registro
---------------------------------*/ 
int posicao_senha(char senha[]);

/*-------------------------------
Função: extrato_conta
Parâmetros: nconta - numero da conta analisada
Retorno: saldo da conta analisada
Descrição: verifica a posição da conta no
registro e retorna seu saldo
---------------------------------*/ 
double extrato_conta(int nconta);

/*-------------------------------
Função: extrato_cpf
Parâmetros: cpf - string de cpf a ser analisado
Retorno: saldo da conta analisada
Descrição: busca a conta associada ao cpf
e retorna o saldo da mesma
---------------------------------*/ 
double extrato_cpf(char cpf[]);

/*-------------------------------
Função: extrato_email
Parâmetros: email - string de email a ser analisado
Retorno: saldo da conta analisada
Descrição: busca a conta associada ao email
e retorna o saldo da mesma
---------------------------------*/ 
double extrato_email(char email[]);

/*-------------------------------
Função: extrato_telefone
Parâmetros: telefone - numero de telefone a ser analisado
Retorno: saldo da conta analisada
Descrição: busca a conta associada ao telefone
e retorna o saldo da mesma
---------------------------------*/ 
double extrato_telefone(long long int telefone);

#endif
