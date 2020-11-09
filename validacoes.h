#ifndef VALIDACOES_H
#define VALIDACOES_H
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

bool validar_dia(int dia);
bool validar_mes(int mes);
bool validar_ano(int ano);
bool validar_cpf(char cpf[]);
bool validar_telefone(long long int telefone);
bool validar_email(char email[]);
bool validar_senha(char senha[]);
bool validar_pagamento(int num_conta,char senha[]); //pendente
char *substr(const char *origem,int inicio, int fim);
void validacao_data_criacao();
void validar(); 

#endif
