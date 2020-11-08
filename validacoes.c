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
    bool validade=false;
  
    
    if(strlen(cpf)!=14)
        return false;  
    
    for(int i=0;i<14;i++){
        if(i!=3 && i!=7 && i!=11){
            if(isdigit(cpf[i])){
                validade=true;
            }
            else
                return false;
        }   
        if(i==3 || i==7){
            if(cpf[i]==46)
                validade=true;
            else 
                return false;
        }
        if(i==11){
            if(cpf[i]==45)
                validade=true;
            else
                return false;
        }   
    }
    if(validade)
        return true;    
}