#include"validacoes.h"

bool validar_dia(int dia){                                      //retorna se o dia é válido ou não
    if(dia>0 && dia<31)
        return true;
    else
        return false;   
}

bool validar_mes(int mes){                                      //retorna se o mês é válido ou não
    if(mes>0 && mes<13)
        return true;
    else
        return false;
}

bool validar_ano(int ano){                                      //retorna se o ano é válido ou não
    if(ano>1999 && ano<2021)
        return true;
    else
        return false;
}
bool validar_cpf(char cpf[]){                                   //retorna se o cpf é válido ou não
  
    if(strlen(cpf)!=14)
        return false;  
    
    for(int i = 0; i < 14; i++){
        if(i != 3 && i != 7 && i != 11){
            if( !(isdigit( cpf[i] )) )
                return false;
        }   
        if( i == 3 || i == 7 ){
            if( cpf[i] != 46 ) 
                return false;
        }
        if(i==11){
            if(cpf[i]!=45)
                return false;
        }   
    }
        return true;    
}

bool validar_telefone(long long int telefone){               //retorna se o telefone é válido ou não


    char vtelefone[11];
    
    sprintf(vtelefone,"%lld",telefone);

    char ddd[3];
    strcpy(ddd,substr(vtelefone,0,2));
    
    if(strlen(vtelefone)!=11)
        return false;

    if(strcmp(ddd,"41")<0 || strcmp(ddd,"44")>0)
        return false;

    return true;
}

bool validar_email(char email[]){                       //retorna se o email é válido ou não
                           

    char inicial[30],
    final[30],
    finalizacao[10]="com.br",
    finalizacao_teste[10];
    int tamanho_total=strlen(email),
    tamanho_inicial,
    tamanho_final,
    posicao_arroba,
    posicao_ponto,
    num_arroba=0,
    num_pontos=0;;
    
    for(int i=0;i<tamanho_total;i++){
        if(email[i]=='@'){
            posicao_arroba=i;
            num_arroba++;
        }
        if(email[i]=='.'){
            posicao_ponto=i-4; 
            num_pontos++;
        }         
    }
    strcpy(inicial,substr(email,0,posicao_arroba));
    strcpy(final,substr(email,(posicao_arroba+1),posicao_ponto));
    strcpy(finalizacao_teste,substr(email,posicao_ponto+1,tamanho_total));
    tamanho_inicial=strlen(inicial);
    tamanho_final=strlen(final);

    if(num_arroba!=1)
        return false;
    if(num_pontos!=2)
        return false;
    if(tamanho_inicial<=4)
        return false;
    if(tamanho_final<=3)
        return false;
    if(strcmp(finalizacao_teste,finalizacao)!=0)
        return false;

    for(int i=0;i<tamanho_inicial;i++){
        if(isdigit(inicial[i]))
            continue;
        if(islower(inicial[i])==0)
            return false;            
    }
    for(int i=0;i<tamanho_final;i++){
        if(isdigit(final[i]))
            continue;
        if(islower(final[i])==0)
            return false;     
    }
    return true;
}

bool validar_senha(char senha[]){                       //retorna se a senha é válida ou não

    int maiuscula=0,            
    minuscula=0,
    numero=0;
    int tamanho=strlen(senha);

    if(tamanho<6 || tamanho>10)
        return false;
    for(int i=0;i<tamanho;i++){
        if(isupper(senha[i]))
            maiuscula++;
        if(islower(senha[i]))
            minuscula++;
        if(isdigit(senha[i]))
            numero++;
    }
    if(maiuscula>0 && minuscula>0 && numero>0)
        return true;
    else   
        return false;
}

char *substr(const char *origem,int inicio, int fim){       //retorna substring limitando seu inicio e fim
    
    int tamanho = fim - inicio;

    char *destino = malloc(sizeof(char) * (tamanho+1));

    for(int i=inicio; i<fim && (*(origem+i) != '\0');i++){
        *destino= *(origem+i);
        destino++;
    }
    *destino = '\0';

    return destino-tamanho;  
}

void validacao_data_criacao(){                              //valida a data de criação de conta em tempo real
    time_t segundos;
    time(&segundos);
    data_c=localtime(&segundos);

    contas[n_contas].data_criacao.dia=data_c->tm_mday;
    contas[n_contas].data_criacao.mes=data_c->tm_mon+1;
    contas[n_contas].data_criacao.ano=data_c->tm_year+1900;
}

void validar(){
    while(1){                                               //bloco de verificação do cpf     
        puts("Digite seu cpf no formato nnn.nnn.nnn-nn");
        scanf("%s",contas[n_contas].cliente.cpf);
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
        scanf("%lld",&contas[n_contas].cliente.telefone);
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
        scanf("%s",contas[n_contas].cliente.email);
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
        scanf("%d/%d/%d",&contas[n_contas].cliente.data_nascimento.dia,
            &contas[n_contas].cliente.data_nascimento.mes,
            &contas[n_contas].cliente.data_nascimento.ano);
        fflush(stdin);
            
        if( !validar_dia(contas[n_contas].cliente.data_nascimento.dia) ){
            puts("Dia invalido");
            continue;
        }
        if(!validar_mes(contas[n_contas].cliente.data_nascimento.mes)){
            puts("Mes invalido");
            continue;
        }
        if(!validar_ano(contas[n_contas].cliente.data_nascimento.ano)){
            puts("Ano invalido");
            continue;
        }
        break;   
    }

    while(1){                                               //bloco de verificacao de senha
        puts("Crie uma senha de 6 a 10 digitos com letras maiusculas, minusculas e numeros");
        scanf("%s",contas[n_contas].senha);

        if(validar_senha(contas[n_contas].senha))
            break;
        else{
            puts("Senha invalida");
            continue;
        }
    }
}

void validar_pagamento(double *pagamento,int nconta){
    while(1){
        double pag;
                    
        puts("Digite o valor do pagamento");
        scanf("%lf",&pag);
        fflush(stdin);
                    
        if(*pagamento<=extrato_conta(nconta)){
            puts("pagamento aprovado");
            *pagamento=pag;
            break;
        }
        else{
            puts("Valor invalido sem fundos disponiveis");
            continue;
        }        
    }
}
