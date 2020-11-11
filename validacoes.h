#ifndef VALIDACOES_H
#define VALIDACOES_H
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

bool validar_dia(int dia);                                  //concluido
bool validar_mes(int mes);                                  //concluido
bool validar_ano(int ano);                                  //concluido
bool validar_cpf(char cpf[]);                               //concluido
bool validar_telefone(long long int telefone);              //concluido
bool validar_email(char email[]);                           //concluido
bool validar_senha(char senha[]);                           //concluido
bool validar_acesso(int num_conta,char senha[]);     //pendente
char *substr(const char *origem,int inicio, int fim);       //concluido
void validacao_data_criacao();                              //concluido
void validar();                                             //concluido

#endif
