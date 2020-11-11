#include"funcoes_controle.h"


void criacao_conta(){
    puts("Para prosseguir com o processo irei precisar de alguns dados");

        {                                                       //bloco de entrada do nome
            puts("Digite seu nome:");
            fgets(contas[n_contas].cliente.nome,100,stdin);
            fflush(stdin);
        }

        validar();

        {   
                                                               //bloco de inicialização de contas
            validacao_data_criacao();
            contas[n_contas].saldo=0.00;
            contas[n_contas].limite=500.00;
            contas[n_contas].num_conta= numconta;
            
            print_contas(contas[n_contas].num_conta);           //printa a conta recém-criada
            n_contas++;
            numconta++;
            system("PAUSE");
        }         
}

void print_contas(int numconta){                               //printa informações relevantes da conta
    int i;      //armazena a posicao da conta
    
    if(existe_conta(numconta))                                 ////////////// //cuidado para caso de erro
        i=busca_conta(numconta);
    
    printf("Nome: %s",contas[i].cliente.nome);            //nome
    printf("Numero da conta: %d\n",contas[i].num_conta);    //numero da conta
    printf("CPF: %s\n",contas[i].cliente.cpf);            //cpf
    printf("Telefone: %lld\n",contas[i].cliente.telefone);  //telefone
    printf("Email: %s\n",contas[i].cliente.email);          //email
    printf("Saldo: R$%.2lf\n",contas[i].saldo);             //saldo
    printf("Data de criacao: %d/%d/%d\n"
    ,contas[i].data_criacao.dia                             //data de criacao
    ,contas[i].data_criacao.mes
    ,contas[i].data_criacao.ano);                                
}





void deposito(){
    int nconta,             //numero da conta
    escolha=0;              //variavel de decisão nos menus                                
    double deposito=0;      //valor de depósito

    while(1){                                                           //verificacao da existencia da conta 
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

    while(1){                                                           //entrada do valor de depósito
        puts("Digite o valor a ser depositado:");
        scanf("%lf",&deposito);
        
        if( (contas[ busca_conta(nconta) ].saldo+deposito)>500 ){
            puts("o deposito excedeu o limite da conta");
            continue;
        }
        else{
            contas[ busca_conta(nconta) ].saldo = deposito;
            puts("deposito realizado com sucesso");
            break;
        }           
    }

    while(1){                                                       //bloco de extrato do depósito
        puts("Deseja retirar o extrato?");
        puts("1- Sim");
        puts("2- Nao");
        fflush(stdin);      //
        scanf("%d",&escolha);
        fflush(stdin);      //

        switch(escolha){
            case 1:
                printf("Conta %d\n",nconta);
                printf("Saldo = R$%.2lf\n",extrato_conta(nconta));
                break;
            case 2:
                break;
        }
        break;                      
    }
    system("PAUSE");  
}

