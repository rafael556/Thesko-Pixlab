#ifndef VALIDACOES_H
#define VALIDACOES_H
#include<stdbool.h>
#include<ctype.h>

bool validar_dia(int dia);
bool validar_mes(int mes);
bool validar_ano(int ano);
bool validar_cpf(char cpf[]);
bool validar_telefone(long long int telefone);
bool validar_email(char email[]);
bool validar_senha(char senha[]);


#endif