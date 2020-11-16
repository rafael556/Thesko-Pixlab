/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#include "funcoes_extrato.h"

/*-------------------------------
Função: extrato
Parâmetros: nenhum
Retorno: nenhum
Descrição: faz a busca da conta ou pix
e mostra o saldo da conta em questão
---------------------------------*/ 
void extrato(){                                           
    int escolha;        //variável de controle de menus
    int nconta;
    char email[50];
    char cpf[20];
    long long int telefone;

    puts("Deseja retirar o extrato com o numero da conta ou chaves pix?");  
    puts("1- Numero da conta");
    puts("2- Chaves pix");
    scanf("%d", &escolha);
    fflush(stdin);

    switch(escolha){
        case 1:                             //extrato pela conta
            while(1){
                puts("Digite o numero da conta a retirar o extrato");
                scanf("%d", &nconta);
                fflush(stdin);
        
                if( existe_conta(nconta) )    //verifica a existencia da conta no registro
                    break;
                else
                {
                    puts("conta inexistente");
                    continue;
                }   
            }
            printf("Saldo = R$%.2lf\n", extrato_conta(nconta));
            system("PAUSE");
            break;
        case 2:                                 //extrato pelas chaves pix
            puts("1- CPF");
            puts("2- email");
            puts("3- telefone");
            scanf("%d", &escolha);
            fflush(stdin);

            switch (escolha){
                case 1:                             //caso cpf
                    while(1){
                        puts("Digite o numero do cpf registrado");
                        scanf("%s", cpf);
                        fflush(stdin);
            
                        if(existe_cpf(cpf))         //verifica se o cpf consta no registro de contas
                            break;
                        else{
                            puts("cpf inexistente");
                            continue;
                        }   
                    }
                    printf("Saldo = R$%.2lf\n", extrato_cpf(cpf));
                    system("PAUSE");
                    break;
                case 2:                             //caso email
                    while(1){
                        puts("Digite o email registrado");
                        scanf("%s", email);
                        fflush(stdin);
            
                        if(existe_email(email))     //verifica se email existe no registro de contas
                            break;
                        else{
                            puts("email inexistente");
                            continue;
                        }   
                    }
                    printf("Saldo = R$%.2lf\n", extrato_email(email));
                    system("PAUSE");
                    break;
                case 3:                                 //caso telefone
                    while(1){
                        puts("Digite o numero do telefone registrado");
                        scanf("%lld", &telefone);
                        fflush(stdin);
            
                        if(existe_telefone(telefone))   //verifica se telefone existe no registro de contas
                            break;
                        else
                        {
                            puts("telefone inexistente");
                            continue;
                        }   
                    }
                printf("Saldo = R$%.2lf\n", extrato_telefone(telefone));
                system("PAUSE");
                break;
            }
            break;
    }                           
}

/*-------------------------------
Função: posicao_conta
Parâmetros: conta - numero de conta
Retorno: numero da posição de conta no registro de contas
Descrição: verifica a posição da conta no registro 
---------------------------------*/
int posicao_conta(int nconta){                          
    for(int i = 0; i < 100; i++){
        if(contas[i].num_conta == nconta)
            return i;
    }
}

/*-------------------------------
Função: existe_conta
Parâmetros: nconta - numero da conta
Retorno: verdadeiro ou falso se a conta existe no registro de contas
Descrição: verifica se a conta existe no registro
---------------------------------*/
bool existe_conta(int nconta){                        
    for(int i = 0; i < 100; i++){
        if(contas[i].num_conta == nconta)
            return true;
    }
    return false;               
}

/*-------------------------------
Função: extrato_conta
Parâmetros: nconta - numero da conta analisada
Retorno: saldo da conta analisada
Descrição: verifica a posição da conta no
registro e retorna seu saldo
---------------------------------*/ 
double extrato_conta(int nconta){                                   //extrato a partir do numero da conta 
        return contas[posicao_conta(nconta)].saldo;
 }

/*-------------------------------
Função: existe_cpf
Parâmetros: cpf - string de cpf
Retorno: verdadeiro ou falso se cpf existe no registro de contas
Descrição: verifica se cpf pertence a alguma conta do registro
---------------------------------*/
bool existe_cpf(char cpf[]){                                        
    for(int i = 0; i < 100; i++){
        if(strcmp(contas[i].cliente.cpf, cpf) == 0)
            return true;
    }
    return false;          
}

/*-------------------------------
Função: posicao_cpf
Parâmetros: cpf - string de cpf
Retorno: posição do cpf no registro de contas
Descrição: verifica a posição da conta associada a esse cpf no registro 
---------------------------------*/
int posicao_cpf(char cpf[]){                                          
    for(int i = 0; i < 100; i++){
        if(strcmp(contas[i].cliente.cpf, cpf) == 0)
            return i;
    }
}

/*-------------------------------
Função: extrato_cpf
Parâmetros: cpf - string de cpf a ser analisado
Retorno: saldo da conta analisada
Descrição: busca a conta associada ao cpf
e retorna o saldo da mesma
---------------------------------*/
double extrato_cpf(char cpf[]){                                     
    return contas[posicao_cpf(cpf)].saldo; 
}

/*-------------------------------
Função: existe_email
Parâmetros: email - string de email
Retorno: verdadeiro ou falso se email existe no registro de contas
Descrição: verifica se email pertence a alguma conta do registro
---------------------------------*/
bool existe_email(char email[]){                                    
    for(int i = 0; i < 100; i++){
        if(strcmp(contas[i].cliente.email, email) == 0)
            return true;
    }
    return false;
}

/*-------------------------------
Função: posicao_email
Parâmetros: email - string de email
Retorno: posição do email no registro de contas
Descrição: verifica a posição da conta associada a esse email no registro
---------------------------------*/
int posicao_email(char email[]){                                      
    for(int i = 0; i < 100; i++){
        if(strcmp(contas[i].cliente.email, email) == 0)
            return i;
    }
}

/*-------------------------------
Função: extrato_email
Parâmetros: email - string de email a ser analisado
Retorno: saldo da conta analisada
Descrição: busca a conta associada ao email
e retorna o saldo da mesma
---------------------------------*/
double extrato_email(char email[]){                                 
    return contas[posicao_email(email)].saldo;
}

/*-------------------------------
Função: existe_telefone
Parâmetros: telefone - numero de telefone
Retorno: verdadeiro ou falso se existe no registro de contas
Descrição: verifica se telefone pertence a alguma conta do registro
---------------------------------*/
bool existe_telefone(long long int telefone){                       
    for(int i = 0; i < 100; i++){
        if(contas[i].cliente.telefone == telefone)
            return true;
    }
    return false;
}

/*-------------------------------
Função: posicao_telefone
Parâmetros: telefone - numero de telefone
Retorno: posição do telefone no registro de contas
Descrição: verifica a posição da conta associada a 
esse telefone no registro 
---------------------------------*/
int posicao_telefone(long long int telefone){                         
    for(int i = 0; i < 100; i++){
        if(contas[i].cliente.telefone == telefone)
            return i;
    }
}

/*-------------------------------
Função: extrato_telefone
Parâmetros: telefone - numero de telefone a ser analisado
Retorno: saldo da conta analisada
Descrição: busca a conta associada ao telefone
e retorna o saldo da mesma
---------------------------------*/
double extrato_telefone(long long int telefone){                    
    return contas[posicao_telefone(telefone)].saldo;
}

/*-------------------------------
Função: existe_senha
Parâmetros: senha - string de senha 
Retorno: verdadeiro ou falso se existe no 
registro de contas
Descrição: verifica se senha pertence a alguma 
conta do registro
---------------------------------*/
bool existe_senha(char senha[]){
    for(int i = 0; i < 100; i++){
        if(strcmp(contas[i].senha, senha) == 0)
            return true;
    }
    return false;
}

/*-------------------------------
Função: posicao_senha
Parâmetros: senha - string de senha que será analisado
Retorno: posição de senha no registro de contas
Descrição: verifica a posição da conta associada a 
essa senha no registro
---------------------------------*/ 
int posicao_senha(char senha[]){
    for(int i = 0; i < 100; i++){
        if(strcmp(contas[i].senha, senha) == 0)
            return i;
    }
}
