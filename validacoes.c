/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#include"validacoes.h"

/*-------------------------------
Função: validar_dia
Parâmetros: dia - numero de dia que será validado
Retorno: verdadeiro ou falso
Descrição: verifica se dia atende aos requisitos
para ser válido
---------------------------------*/
bool validar_dia(int dia){                                      
    if(dia > 0 && dia < 31)
        return true;
    else
        return false;   
}

/*-------------------------------
Função: validar_mes
Parâmetros: mes - numero de mes que será validado
Retorno: verdadeiro ou falso
Descrição: verifica se mes atende aos requisitos
para ser válido
---------------------------------*/
bool validar_mes(int mes){                                      
    if(mes > 0 && mes < 13)
        return true;
    else
        return false;
}

/*-------------------------------
Função: validar_ano
Parâmetros: ano - numero de ano que será validado
Retorno: verdadeiro ou falso
Descrição: verifica se ano atende aos requisitos
para ser válido
---------------------------------*/
bool validar_ano(int ano){                                      
    if(ano > 1999 && ano < 2021)
        return true;
    else
        return false;
}

/*-------------------------------
Função: validar_cpf
Parâmetros: cpf - string de cpf que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se cpf é válido
---------------------------------*/
bool validar_cpf(char cpf[]){                                   
    
    if( duplicata_cpf(cpf, posicao_cpf(cpf) ) )                     //evita duplicata
        return false;

    if(strlen(cpf) != 14)                     //verifica se o cpf tem o tamanho certo
        return false;  
    
    for(int i = 0; i < 14; i++){            
        if(i != 3 && i != 7 && i != 11){    //verifica se é composto exclusivamente por numeros
            if( !( isdigit(cpf[i]) ) )
                return false;
        }   
        if( i == 3 || i == 7 ){             //verifica se os pontos estão corretos
            if(cpf[i] != 46) 
                return false;
        }
        if(i == 11){                          //verifica se o traço está correto
            if(cpf[i] != 45)
                return false;
        }   
    }
    return true;    
}

/*-------------------------------
Função: validar_telefone
Parâmetros: telefone - numero de telefone que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se telefone é válido
---------------------------------*/ 
bool validar_telefone(long long int telefone){               

    char vtelefone[11];                                                 //string de telefone
    char ddd[3];                                                        //substring de vtelefone composto pelo DDD
    
    if( duplicata_telefone(telefone, posicao_telefone(telefone) ) )     //evita duplicata
        return false;

    sprintf(vtelefone, "%lld", telefone);                               //transforma o numero em string

    strcpy(ddd, substr(vtelefone, 0, 2));                               //gera substring de DDD
    
    if(strlen(vtelefone) != 11)                                         //verifica se o tamanho está correto
        return false;

    if(strcmp(ddd, "41") < 0 || strcmp(ddd, "44") > 0)                  //verifica se o DDD está correto  
        return false;

    return true;
}

/*-------------------------------
Função: validar_email
Parâmetros: email - string de email que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se email é válido
---------------------------------*/
bool validar_email(char email[]){                       
                           
    char inicial[30];                       //substring da parte anterior ao arroba
    char final[30];                         //substring da parte após o arroba e antes da finalizacao
    char finalizacao[10] = "com.br";        //string de comparação para a finalização
    char finalizacao_teste[10];
    int tamanho_total = strlen(email);      //tamanho total de email
    int tamanho_inicial;                    //tamanho da parte inicial
    int tamanho_final;                      //tamanho da parte final
    int posicao_arroba;                     //posição de arroba
    int posicao_ponto;                      //posição do primeiro ponto
    int num_arroba = 0;                     //variável de controle de quantidade de arrobas
    int num_pontos = 0;                     //variável de controle de quantidade de pontos

    if( duplicata_email(email, posicao_email(email) ) )             //evita duplicata
        return false;
    
    for(int i = 0; i < tamanho_total; i++){
        if(email[i] == '@'){                //verifica a existencia,quantidade e posição de arroba
            posicao_arroba = i;
            num_arroba++;
        }
        if(email[i] == '.'){              //verifica a existencia, quantidade e posição dos pontos
            posicao_ponto = i - 4; 
            num_pontos++;
        }         
    }
    strcpy(inicial, substr(email, 0, posicao_arroba));                         
    strcpy(final, substr(email, (posicao_arroba + 1), posicao_ponto));           
    strcpy(finalizacao_teste, substr(email, posicao_ponto + 1, tamanho_total));  
    tamanho_inicial = strlen(inicial);                                        
    tamanho_final = strlen(final);                                            

    if(num_arroba != 1)                               
        return false;
    if(num_pontos < 2)
        return false;
    if(tamanho_inicial <= 4)
        return false;
    if(tamanho_final <= 3)
        return false;
    if(strcmp(finalizacao_teste, finalizacao) != 0)     //verifica se a finalização é a adequada
        return false;

    for(int i = 0; i < tamanho_inicial; i++){
        if( isdigit(inicial[i]) )       //verifica a existencia de numeros
            continue;
        if( ispunct (inicial[i]) )      //verifica a existencia de simbolos   
            continue;    
        if(islower(inicial[i]) == 0)    //verifica se as letras são minusculas
            return false; 
                   
    }
    for(int i = 0; i < tamanho_final; i++){
        if( isdigit(final[i]) )           //verifica a existencia de numeros
            continue;
        if( ispunct (final[i]) )      //verifica a existencia de simbolos   
            continue;
        if(islower(final[i]) == 0)      //verifica se as letras são minusculas
            return false;
             
    }
    return true;
}

/*-------------------------------
Função: validar_senha
Parâmetros: senha - string de senha que será analisado
Retorno: verdadeiro ou falso
Descrição: verifica se senha é válido
---------------------------------*/
bool validar_senha(char senha[]){                       

    int maiuscula = 0;            //conta a quantidade de letras maiusculas   
    int minuscula = 0;            //conta a quantidade de letras minusculas
    int numero = 0;               //conta a quantidade de numeros
    int tamanho = strlen(senha);  //conta o tamanho da string senha

    if(tamanho < 6 || tamanho > 10) //verifica se o tamanho está correto
        return false;
    for(int i = 0; i < tamanho; i++){
        if( isupper(senha[i]) )   //verifica a existencia de letras maiusculas
            maiuscula++;
        if( islower(senha[i]) )   //verifica a existencia de letras minusculas
            minuscula++;
        if( isdigit(senha[i]) )   //verifica a existencia de numeros
            numero++;
    }
    if(maiuscula > 0 && minuscula > 0 && numero > 0)
        return true;
    else   
        return false;
}

/*-------------------------------
Função: substr
Parâmetros: origem - ponteiro de string de origem para gerar uma substring
Parâmetros: inicio - numero do index de inicio da substring em origem
Parâmetros: fim - numero do index do fim da substring em origem
Retorno: substring de origem delimitada por inicio e fim
Descrição: retorna substring de uma string origem
delimitada por inicio e fim
---------------------------------*/ 
char *substr(char *origem, int inicio, int fim){       
    
    int tamanho = fim - inicio;
    char *destino = malloc(sizeof(char) * (tamanho+1));     //aloca dinamicamente a string destino

    for(int i = inicio; i < fim && (*(origem + i) != '\0'); i++){
        *destino = *(origem + i);                           
        destino++;
    }
    *destino = '\0';

    return destino - tamanho;  
}

/*-------------------------------
Função: validacao_data_criacao
Parâmetros: nenhum
Retorno: nenhum
Descrição: utiliza a estrutura de tempo
para determinar a data de criacao de conta
em tempo real
---------------------------------*/ 
void validacao_data_criacao(){                              
    time_t segundos;                //variavel  para armazenar tempo
    time(&segundos);                //função para armazenar o tempo do sistema em segundos
    data_c = localtime(&segundos);  //converte o tempo do sistema para o tempo local

    contas[n_contas].data_criacao.dia = data_c->tm_mday;
    contas[n_contas].data_criacao.mes = data_c->tm_mon + 1;
    contas[n_contas].data_criacao.ano = data_c->tm_year + 1900;
}

/*-------------------------------
Função: validar
Parâmetros: nenhum
Retorno: nenhum
Descrição: faz a entrada de cpf, email, senha, telefone
e data e verifica se todos são válidos
---------------------------------*/ 
void validar(){
    while(1){                                               //bloco de verificação do cpf     
        puts("Digite seu cpf no formato nnn.nnn.nnn-nn");
        scanf("%s", contas[n_contas].cliente.cpf);
        fflush(stdin);
            
        if(validar_cpf(contas[n_contas].cliente.cpf))
            break;
        else{
            puts("cpf invalido");
            continue;
        }         
    }

    while(1){                                               //bloco de verificação do telefone
        puts("Digite seu telefone");
        scanf("%lld", &contas[n_contas].cliente.telefone);
        fflush(stdin);
            
        if(validar_telefone(contas[n_contas].cliente.telefone))
            break;
        else{
            puts("telefone invalido");
            continue;
        }
    }

    while(1){                                               //bloco de verificação de email
        puts("Digite seu email com final 'com.br'");
        scanf("%s", contas[n_contas].cliente.email);
        fflush(stdin);

        if(validar_email(contas[n_contas].cliente.email))
            break;
        else{
            puts("Email invalido");
            continue;
        }
    }

    while(1){                                               //bloco de verificação de data de nascimento
        puts("Digite sua data de nascimento com formato: dd/mm/aaaa");
        scanf("%d/%d/%d", &contas[n_contas].cliente.data_nascimento.dia,
        &contas[n_contas].cliente.data_nascimento.mes,
        &contas[n_contas].cliente.data_nascimento.ano);
        fflush(stdin);
            
        if( !validar_dia(contas[n_contas].cliente.data_nascimento.dia) ){
            puts("Dia invalido");
            continue;
        }
        if( !validar_mes(contas[n_contas].cliente.data_nascimento.mes) ){
            puts("Mes invalido");
            continue;
        }
        if( !validar_ano(contas[n_contas].cliente.data_nascimento.ano) ){
            puts("Ano invalido");
            continue;
        }
        break;   
    }

    while(1){                                               //bloco de verificacao de senha
        puts("Crie uma senha de 6 a 10 digitos com letras maiusculas, minusculas e numeros");
        scanf("%s", contas[n_contas].senha);

        if( validar_senha(contas[n_contas].senha) )
            break;
        else{
            puts("Senha invalida");
            continue;
        }
    }
}

/*-------------------------------
Função: validar_pagamento
Parâmetros: pagamento - ponteiro do flutuante pagamento que será analisado
Parâmetros: nconta - numero da conta relacionada ao pagamento
Retorno: nenhum
Descrição: faz a entrada do valor do pagamento e 
verifica se a conta possui saldo para realizar o pagamento
---------------------------------*/ 
void validar_pagamento(double *pagamento, int nconta){
    while(1){
        double pag;     //flutuante para receber o valor do pagamento
                    
        puts("Digite o valor do pagamento");
        scanf("%lf", &pag);
        fflush(stdin);
                    
        if( pag <= extrato_conta(nconta) ){
            *pagamento = pag;
            break;
        }
        else{
            puts("Valor invalido sem fundos disponiveis");
            *pagamento = 0;
            break;
        }        
    }
}

/*-------------------------------
Função: duplicata_cpf
Parâmetros: cpf - string de cpf que será analisado
Parâmetros: posicao - inteiro da posição do cpf em contas
Retorno: verdadeiro ou falso
Descrição: verifica se existe duplicata de cpf em contas
---------------------------------*/
bool duplicata_cpf(char cpf[], int posicao){                                        
    for(int i = 0; i < 100; i++){
        if(n_contas == 0)                           //ignora a primeira conta a ser criada
            return false;
        else
            if(posicao == 0)
            return true;

        if(n_contas == posicao)                     //ignora as informações da criação corrente
            return false;

        if(strcmp(contas[i].cliente.cpf, cpf) == 0) //procura o cpf em contas
            return true;
    }
    return false;          
}

/*-------------------------------
Função: duplicata_telefone
Parâmetros: telefone - inteiro de telefone que será analisado
Parâmetros: posicao - inteiro da posição do telefone em contas
Retorno: verdadeiro ou falso
Descrição: verifica se existe duplicata de telefone em contas
---------------------------------*/
bool duplicata_telefone(long long int telefone, int posicao){                                        
    for(int i = 0; i < 100; i++){
        if(n_contas == 0){                          //ignora a primeira conta a ser criada
            return false;
        }
        else{
            if(posicao == 0)
            return true;
        }
        if(n_contas == posicao)                     //ignora as informações da criação corrente
            return false;
        
        if(contas[i].cliente.telefone == telefone)  //procura o telefone em contas
            return true;
    }
    return false;          
}

/*-------------------------------
Função: duplicata_email
Parâmetros: email - string de email que será analisado
Parâmetros: posicao - inteiro da posição do email em contas
Retorno: verdadeiro ou falso
Descrição: verifica se existe duplicata de email em contas
---------------------------------*/
bool duplicata_email(char email[], int posicao){                                        
    for(int i = 0; i < 100; i++){
        if(n_contas == 0){                              //ignora a primeira conta a ser criada
            return false;
        }
        else{
            if(posicao == 0)
            return true;
        }
        if(n_contas == posicao)                         //ignora as informações da criação corrente
            return false;
        
        if(strcmp(contas[i].cliente.email, email) == 0) //procura o email em contas
            return true;
    }
    return false;          
}