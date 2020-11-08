#include"validacoes.h"

bool validar_dia(int dia){
    if(dia>0 && dia<31)
        return true;
    else
        return false;   
}

bool validar_mes(int mes){
    if(mes>0 && mes<13)
        return true;
    else
        return false;
}

bool validar_ano(int ano){
    if(ano>1999 && ano<2021)
        return true;
    else
        return false;
}
bool validar_cpf(char cpf[]){   
  
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

bool validar_telefone(long long int telefone){

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

bool validar_email(char email[]){

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

bool validar_senha(char senha[]){

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

char *substr(const char *origem,int inicio, int fim){
    
    int tamanho = fim - inicio;

    char *destino = malloc(sizeof(char) * (tamanho+1));

    for(int i=inicio; i<fim && (*(origem+i) != '\0');i++){
        *destino= *(origem+i);
        destino++;
    }
    *destino = '\0';

    return destino-tamanho;  
}