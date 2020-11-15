/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#ifndef VALIDACOES_H
#define VALIDACOES_H
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include"funcoes_controle.h"

/*-------------------------------
Função: validar_dia
Parâmetros: dia - numero de dia que será validado
Retorno: verdadeiro ou falso
Descrição: verifica se dia atende aos requisitos
para ser válido
---------------------------------*/
bool validar_dia(int dia);

/*-------------------------------
Função: validar_mes
Parâmetros: mes - numero de mes que será validado
Retorno: verdadeiro ou falso
Descrição: verifica se mes atende aos requisitos
para ser válido
---------------------------------*/
bool validar_mes(int mes);

/*-------------------------------
Função: validar_ano
Parâmetros: ano - numero de ano que será validado
Retorno: verdadeiro ou falso
Descrição: verifica se ano atende aos requisitos
para ser válido
---------------------------------*/
bool validar_ano(int ano);  

/*-------------------------------
Função: validar_cpf
Parâmetros: cpf - string de cpf que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se cpf é válido
---------------------------------*/                                
bool validar_cpf(char cpf[]);

/*-------------------------------
Função: validar_telefone
Parâmetros: telefone - numero de telefone que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se telefone é válido
---------------------------------*/ 
bool validar_telefone(long long int telefone);

/*-------------------------------
Função: validar_email
Parâmetros: email - string de email que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se email é válido
---------------------------------*/ 
bool validar_email(char email[]);

/*-------------------------------
Função: validar_senha
Parâmetros: senha - string de senha que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se senha é válido
---------------------------------*/ 
bool validar_senha(char senha[]);

/*-------------------------------
Função: validar_pagamento
Parâmetros: pagamento - ponteiro do flutuante pagamento que será analisado
Parâmetros: nconta - numero da conta relacionada ao pagamento
Retorno: nenhum
Descrição: faz a entrada do valor do pagamento e 
verifica se a conta possui saldo para realizar o pagamento
---------------------------------*/ 
void validar_pagamento(double *pagamento, int nconta);

/*-------------------------------
Função: validacao_data_criacao
Parâmetros: nenhum
Retorno: nenhum
Descrição: utiliza a estrutura de tempo
para determinar a data de criacao de conta
em tempo real
---------------------------------*/ 
void validacao_data_criacao();                              

/*-------------------------------
Função: validar
Parâmetros: nenhum
Retorno: nenhum
Descrição: faz a entrada de cpf, email, senha, telefone
e data e verifica se todos são válidos
---------------------------------*/ 
void validar();                                             

/*-------------------------------
Função: substr
Parâmetros: origem - ponteiro de string de origem para gerar uma substring
Parâmetros: inicio - numero do index de inicio da substring em origem
Parâmetros: fim - numero do index do fim da substring em origem
Retorno: substring de origem delimitada por inicio e fim
Descrição: retorna substring de uma string origem
delimitada por inicio e fim
---------------------------------*/ 
char *substr(const char *origem, int inicio, int fim);       

#endif
