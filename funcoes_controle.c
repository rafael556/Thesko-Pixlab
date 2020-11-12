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
            
            print_contas();           //printa a conta recém-criada
            n_contas++;
            numconta++;
            system("PAUSE");
        }         
}

void print_contas(){                               //printa informações relevantes da conta
    int i;      //armazena a posicao da conta
    //contas[n_contas].num_conta
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
        puts("Deseja ver o saldo?");
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

void print_contas_ordenadas(){                      //printa todas as contas em ordem alfabética
   conta ordem[n_contas];
   conta aux;
   
    for(int i=0;i<n_contas;i++)  
        ordem[i]=contas[i];

    for(int i=0;i<n_contas;i++){
        for(int j=0;j<n_contas;j++){
            if(strcmp(ordem[i].cliente.nome,ordem[j].cliente.nome)<0){  //afere a ordem das strings e as reorganizam
                
                strcpy(aux.cliente.nome,ordem[i].cliente.nome);
                strcpy(aux.cliente.cpf,ordem[i].cliente.cpf);
                aux.num_conta=ordem[i].num_conta;
                aux.saldo=ordem[i].saldo;

                strcpy(ordem[i].cliente.nome,ordem[j].cliente.nome);
                strcpy(ordem[i].cliente.cpf,ordem[j].cliente.cpf);
                ordem[i].num_conta=ordem[j].num_conta;
                ordem[i].saldo=ordem[j].saldo;

                strcpy(ordem[j].cliente.nome,aux.cliente.nome);
                strcpy(ordem[j].cliente.cpf,aux.cliente.cpf);
                ordem[j].num_conta=aux.num_conta;
                ordem[j].saldo=aux.saldo;
            }       
        }
    }
    for(int i=0;i<n_contas;i++){
        printf("Numero da conta: %d\n",ordem[i].num_conta);
        printf("CPF: %s\n",ordem[i].cliente.cpf);
        printf("Nome: %s",ordem[i].cliente.nome);
        printf("Saldo: R$%.2lf\n\n",ordem[i].saldo);
    }
    system("PAUSE");
}

void transacao_pix(){                                           
    int escolha;
    int nconta;
    int i=0;    //posicao da conta emissora
    int j=0;    //posicao da conta receptora
    char email[50];
    char cpf[20];
    char senha[11];
    long long int telefone;
    double pagamento;
                            
            while(1){                                               //login
                puts("Digite o numero da conta para acesso");
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
            while(1){                               //verificacao de senha 
                puts("Digite a senha de acesso");
                scanf("%s",senha);
                fflush(stdin);

                if(existe_senha(senha)){
                    if(busca_conta(nconta)==busca_senha(senha))
                        break;
                    else{
                    puts("Senha incorreta");
                    continue;
                    }
                }   
                else{
                    puts("Senha incorreta");
                    continue;
                }
            }
            puts("Escolha a chave pix desejada para o pagamento");          //extrato pelas chaves pix
            puts("1- CPF");
            puts("2- email");
            puts("3- telefone");
            scanf("%d",&escolha);
            fflush(stdin);

            switch (escolha)
            {
            case 1:                         //caso cpf
                while(1){
                    puts("Digite o numero do cpf desejado");
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
                while(1){                   //verificação de pagamento
                    puts("Digite o valor do pagamento");
                    scanf("%lf",&pagamento);
                    fflush(stdin);
                    if(pagamento<=extrato_conta(nconta)){
                        puts("pagamento aprovado");
                        break;
                    }
                    else{
                        puts("Valor invalido sem fundos disponiveis");
                        continue;
                    }        
                }
                i=busca_conta(nconta);
                j=busca_cpf(cpf);

                contas[i].saldo-=pagamento;
                contas[j].saldo+=pagamento;
    
                printf("\nNome: %s",contas[i].cliente.nome);            //nome
                printf("Numero da conta: %d\n",contas[i].num_conta);    //numero da conta
                printf("CPF: %s\n",contas[i].cliente.cpf);            //cpf
                printf("Telefone: %lld\n",contas[i].cliente.telefone);  //telefone
                printf("Email: %s\n",contas[i].cliente.email);          //email
                printf("Saldo: R$%.2lf\n\n",contas[i].saldo);             //saldo
                
                printf("Nome: %s",contas[j].cliente.nome);            //nome
                printf("Numero da conta: %d\n",contas[j].num_conta);    //numero da conta
                printf("CPF: %s\n",contas[j].cliente.cpf);            //cpf
                printf("Telefone: %lld\n",contas[j].cliente.telefone);  //telefone
                printf("Email: %s\n",contas[j].cliente.email);          //email
                printf("Saldo: R$%.2lf\n",contas[j].saldo);             //saldo
                system("PAUSE");
                break;
            case 2:                         //caso email
                while(1){
                    puts("Digite o email desejado");
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
                while(1){                   //verificação de pagamento
                    puts("Digite o valor do pagamento");
                    scanf("%lf",&pagamento);
                    fflush(stdin);
                    if(pagamento<=extrato_conta(nconta)){
                        puts("pagamento aprovado");
                        break;
                    }
                    else{
                        puts("Valor invalido sem fundos disponiveis");
                        continue;
                    }        
                }
                i=busca_conta(nconta);
                j=busca_email(email);

                contas[i].saldo-=pagamento;
                contas[j].saldo+=pagamento;
    
                printf("\nNome: %s",contas[i].cliente.nome);            //nome
                printf("Numero da conta: %d\n",contas[i].num_conta);    //numero da conta
                printf("CPF: %s\n",contas[i].cliente.cpf);            //cpf
                printf("Telefone: %lld\n",contas[i].cliente.telefone);  //telefone
                printf("Email: %s\n",contas[i].cliente.email);          //email
                printf("Saldo: R$%.2lf\n\n",contas[i].saldo);             //saldo
                
                printf("Nome: %s",contas[j].cliente.nome);            //nome
                printf("Numero da conta: %d\n",contas[j].num_conta);    //numero da conta
                printf("CPF: %s\n",contas[j].cliente.cpf);            //cpf
                printf("Telefone: %lld\n",contas[j].cliente.telefone);  //telefone
                printf("Email: %s\n",contas[j].cliente.email);          //email
                printf("Saldo: R$%.2lf\n",contas[j].saldo);             //saldo
                
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
                while(1){                   //verificação de pagamento
                    puts("Digite o valor do pagamento");
                    scanf("%lf",&pagamento);
                    fflush(stdin);
                    if(pagamento<=extrato_conta(nconta)){
                        puts("pagamento aprovado");
                        break;
                    }
                    else{
                        puts("Valor invalido sem fundos disponiveis");
                        continue;
                    }        
                }
                i=busca_conta(nconta);
                j=busca_telefone(telefone);

                contas[i].saldo-=pagamento;
                contas[j].saldo+=pagamento;
    
                printf("\nNome: %s",contas[i].cliente.nome);            //nome
                printf("Numero da conta: %d\n",contas[i].num_conta);    //numero da conta
                printf("CPF: %s\n",contas[i].cliente.cpf);            //cpf
                printf("Telefone: %lld\n",contas[i].cliente.telefone);  //telefone
                printf("Email: %s\n",contas[i].cliente.email);          //email
                printf("Saldo: R$%.2lf\n\n",contas[i].saldo);             //saldo
                
                printf("Nome: %s",contas[j].cliente.nome);            //nome
                printf("Numero da conta: %d\n",contas[j].num_conta);    //numero da conta
                printf("CPF: %s\n",contas[j].cliente.cpf);            //cpf
                printf("Telefone: %lld\n",contas[j].cliente.telefone);  //telefone
                printf("Email: %s\n",contas[j].cliente.email);          //email
                printf("Saldo: R$%.2lf\n",contas[j].saldo);             //saldo

                system("PAUSE");
                break;
            }
        
                               

}