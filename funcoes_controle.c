#include"funcoes_controle.h"


void criacao_conta(){
    puts("Para prosseguir com o processo irei precisar de alguns dados");

        {                                                       //bloco de entrada do nome
            puts("Digite seu nome:");
            fgets(contas[n_contas].cliente.nome,100,stdin);
            fflush(stdin);
        }

        validar();

        {                                                       //bloco de inicialização de contas                                                  
            validacao_data_criacao();
            contas[n_contas].saldo=0.00;
            contas[n_contas].limite=500.00;
            contas[n_contas].num_conta= numconta;
            n_contas++;
            numconta++;
        }
        //printar todas as informações da conta
}
int busca_conta(int numconta){                                  //retorna a posicao da conta no vetor de armazenamento
    for(int i=0;i<100;i++){
        if(contas[i].num_conta==numconta)
            return i;
    }
}

bool existe_conta(int numconta){                                //procura se existe uma conta com determinado numero de conta
    for(int i=0;i<100;i++){
        if(contas[i].num_conta==numconta)
            return true;
    }
        return false;               
}    

void extrato(){

}

double extrato_t(int nconta){
    if(existe_conta(nconta))
        return contas[busca_conta(nconta)].saldo;
 }

void deposito(){
    int nconta,             //numero da conta
    escolha=0;              //variavel de decisão nos menus                                
    double deposito=0;      //valor de depósito

    while(1){
        puts("Digite o numero da conta a realizar o deposito");
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

    while(1){
        puts("Digite o valor a ser depositado:");
        scanf("%lf",&deposito);
        if( (contas[ busca_conta(nconta) ].saldo+deposito)>500 ){
            puts("o deposito excedeu o limite da conta");
            continue;
        }
        else{
            contas[ busca_conta(nconta) ].saldo = deposito;
            puts("deposito realizado com sucesso");
        //    printf("%.2lf\n",contas[ busca_conta(nconta) ].saldo);
            break;
        }           
    }

    while(1){                                       //bloco de extrato
        puts("Deseja retirar o extrato?");
        puts("1- Sim");
        puts("2- Nao");
        fflush(stdin);      //
        scanf("%d",&escolha);
        fflush(stdin);      //

        switch(escolha){
            case 1:
                printf("Conta %d\n",nconta);
                printf("Saldo = R$%.2lf\n",extrato_t(nconta));
                break;
            case 2:
                break;
        }
       puts("Deseja voltar para o menu?");
        puts("1- Sim");
        puts("2- Nao");
        fflush(stdin);      //
        scanf("%d",&escolha);
        fflush(stdin);      //
        if(escolha==1)
            break;
        else{
            exit(0);
        }                  
    }  
}

 