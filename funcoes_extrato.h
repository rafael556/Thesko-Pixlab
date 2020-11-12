#ifndef FUNCOES_EXTRATO_H
#define FUNCOES_EXTRATO_H
#include"funcoes_controle.h"

void extrato();
              
bool existe_conta(int nconta);                          
bool existe_cpf(char cpf[]);
bool existe_email(char email[]);
bool existe_telefone(long long int telefone);
bool existe_senha(char senha[]);

int busca_conta(int nconta);  
int busca_cpf(char cpf[]);                           
int busca_email(char email[]);
int busca_telefone(long long int telefone);
int busca_senha(char senha[]);

double extrato_conta(int nconta);
double extrato_cpf(char cpf[]);
double extrato_email(char email[]);
double extrato_telefone(long long int telefone);

#endif
