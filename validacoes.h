#ifndef VALIDACOES_H
#define VALIDACOES_H
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include"funcoes_controle.h"

bool validar_dia(int dia);                                  //concluido
bool validar_mes(int mes);                                  //concluido
bool validar_ano(int ano);
bool validar_data(int dia, int mes, int ano);///////  
                                //concluido
bool validar_cpf(char cpf[]);                               //concluido
bool validar_telefone(long long int telefone);              //concluido
bool validar_email(char email[]);                           //concluido
bool validar_senha(char senha[]);

void validar_pagamento(double *pagamento,int nconta);/////////

void validacao_data_criacao();                              //concluido

void validar();                                             //concluido

char *substr(const char *origem,int inicio, int fim);       //concluido

#endif
