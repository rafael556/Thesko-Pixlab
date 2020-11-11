#include"funcoes_extrato.h"

void extrato(){                                            //extrato geral
    int escolha
        ,nconta;
    char email[50]
        ,cpf[20];
    long long int telefone;

    puts("Deseja retirar o extrato com o numero da conta ou chaves pix?");  //submenu
    puts("1- Numero da conta");
    puts("2- Chaves pix");
    scanf("%d",&escolha);
    fflush(stdin);

    switch(escolha){
        case 1:                             //extrato pela conta
            while(1){
                puts("Digite o numero da conta a retirar o extrato");
                scanf("%d",&nconta);
                fflush(stdin);
        
                if(existe_conta(nconta))
                    break;
                else
                {
                    puts("conta inexistente");
                    continue;
                }   
            }
            printf("Saldo = R$%.2lf\n",extrato_conta(nconta));
            system("PAUSE");
            break;
        case 2:                             //extrato pelas chaves pix
            puts("1- CPF");
            puts("2- email");
            puts("3- telefone");
            scanf("%d",&escolha);
            fflush(stdin);

            switch (escolha)
            {
            case 1:                         //caso cpf
                while(1){
                puts("Digite o numero do cpf registrado");
                scanf("%s",cpf);
                fflush(stdin);
        
                if(existe_cpf(cpf))
                    break;
                else
                {
                    puts("cpf inexistente");
                    continue;
                }   
            }
            printf("Saldo = R$%.2lf\n",extrato_cpf(cpf));
            system("PAUSE");
                break;
            case 2:                         //caso email
                while(1){
                puts("Digite o email registrado");
                scanf("%s",email);
                fflush(stdin);
        
                if(existe_email(email))
                    break;
                else
                {
                    puts("email inexistente");
                    continue;
                }   
            }
            printf("Saldo = R$%.2lf\n",extrato_email(email));
            system("PAUSE");
                break;
            case 3:                         //caso telefone
                while(1){
                puts("Digite o numero do telefone registrado");
                scanf("%lld",&telefone);
                fflush(stdin);
        
                if(existe_telefone(telefone))
                    break;
                else
                {
                    puts("telefone inexistente");
                    continue;
                }   
            }
            printf("Saldo = R$%.2lf\n",extrato_telefone(telefone));
            system("PAUSE");
                break;
            }
            break;
    }                           
}

int busca_conta(int numconta){                          //retorna a posicao da conta no vetor de armazenamento
    for(int i=0;i<100;i++){
        if(contas[i].num_conta==numconta)
            return i;
    }
}

bool existe_conta(int numconta){                        //procura se existe uma conta com determinado numero de conta
    for(int i=0;i<100;i++){
        if(contas[i].num_conta==numconta)
            return true;
    }
    return false;               
}

double extrato_conta(int nconta){                                   //extrato a partir do numero da conta 
        return contas[busca_conta(nconta)].saldo;
 }

bool existe_cpf(char cpf[]){                                        //procura se existe conta com o cpf registrado
    for(int i=0;i<100;i++){
        if(strcmp(contas[i].cliente.cpf,cpf)==0)
            return true;
    }
    return false;          
}

int busca_cpf(char cpf[]){                                          //busca qual conta possui o cpf registrado
    for(int i=0;i<100;i++){
        if(strcmp(contas[i].cliente.cpf,cpf)==0)
            return i;
    }
}

double extrato_cpf(char cpf[]){                                     //retorna o extrato baseado no cpf registrado
    return contas[busca_cpf(cpf)].saldo; 
}

bool existe_email(char email[]){                                    //diz se existe uma conta com o email registrado
    for(int i=0;i<100;i++){
        if(strcmp(contas[i].cliente.email,email)==0)
            return true;
    }
    return false;
}

int busca_email(char email[]){                                      //retorna a posicao da conta com o email registrado
    for(int i=0;i<100;i++){
        if(strcmp(contas[i].cliente.email,email)==0)
            return i;
    }
}

double extrato_email(char email[]){                                 //retorna o extrato baseado no email
    return contas[busca_email(email)].saldo;
}

bool existe_telefone(long long int telefone){                       //verifica se existe conta associada a este telefone
    for(int i=0;i<100;i++){
        if(contas[i].cliente.telefone==telefone)
            return true;
    }
    return false;
}

int busca_telefone(long long int telefone){                         //verifica qual conta está relacionada a este telefone
    for(int i=0;i<100;i++){
        if(contas[i].cliente.telefone==telefone)
            return i;
    }
}

double extrato_telefone(long long int telefone){                    //retorna o extrato da conta associada a este telefone
    return contas[busca_telefone(telefone)].saldo;
}
