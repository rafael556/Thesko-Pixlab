#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    char nome[100];
    char cpf[15];
    long long int telefone;
    char email[50];
    data data_nascimento;
}pessoa;

typedef struct{
    int num_conta;
    pessoa cliente;
    double saldo;
    double limite;
    char senha[11];
    data data_criacao;
}conta;

#endif