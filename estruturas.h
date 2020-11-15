/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/
#ifndef ESTRUTURAS_H            
#define ESTRUTURAS_H
#include<time.h>                //biblioteca com funções de tempo

typedef struct{                 //estrutura para datas
    int dia;
    int mes;
    int ano;
}data;

typedef struct{                 //estrutura para informações do cliente
    char nome[100];
    char cpf[15];
    long long int telefone;
    char email[50];
    data data_nascimento;
}pessoa;

typedef struct{                 //estrutura das contas
    int num_conta;
    pessoa cliente;
    double saldo;
    double limite;
    char senha[11];
    data data_criacao;
}conta;

//VARIÁVEIS GLOBAIS
conta contas[100];          //estrutura declarada como variavel global
int n_contas=0;             //controle da quantidade de contas para criação e exclusão das mesmas
int numconta=100;           //numero padrão para definição dos numeros das contas
struct tm *data_c;          //estrutura de tempo para data de criação

#endif
