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

    // if(vtelefone[0]!='4')
    //     return false;
    
    // if(vtelefone[1]<='0' || vtelefone[1]>='5')
    //     return false;

    return true;
}

bool validar_email(char email[]){

    

}

bool validar_senha(char senha[]){

}

char *substr(const char *origem,int inicio, int fim){
    
    int tamanho = fim - inicio;

    char *destino = malloc(sizeof(char) * (tamanho+1));//ponteiro de destino

    for(int i=inicio; i<fim && (*(origem+i) != '\0');i++){
        *destino= *(origem+i);
        destino++;
    }
    *destino = '\0';

    return destino-tamanho;  
}