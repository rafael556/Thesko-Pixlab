/*------------------------
Nome: Rafael Cruz Costa
RA: 2266261
Turma: N11A
-------------------------*/

#include "funcoes_controle.h"

/*-------------------------------
Função: criacao_conta
Parâmetros: nenhum
Retorno: nenhum
Descrição: submenu principal que faz a admissão 
e validação de dados para a criação de contas
---------------------------------*/
void criacao_conta(){
    puts("Para prosseguir com o processo irei precisar de alguns dados");
                                                   
    puts("Digite seu nome:");                           //bloco de entrada do nome
    fgets(contas[n_contas].cliente.nome, 100, stdin);
    fflush(stdin);

    validar();                                          //valida cpf, email, senha, telefone e data de nascimento

                                                                              
    validacao_data_criacao();
    contas[n_contas].saldo = 0.00;                      //bloco de inicialização de valores pré-definidos 
    contas[n_contas].limite = 500.00;
    contas[n_contas].num_conta = numconta;
    
    print_contas();                                     //printa a conta recém-criada
    n_contas++;                                         //incrementa o numero de contas registradas
    numconta++;                                         //incrementa o numero padrão de conta
    system("PAUSE");
         
}

/*-------------------------------
Função: print_contas
Parâmetros: nenhum
Retorno: nenhum
Descrição: printa as informações principais da
conta após a criação da mesma
---------------------------------*/
void print_contas(){                               
    int i = 0;                              //armazena a posicao da conta no array contas
    if(existe_conta(numconta))                                 
        i = posicao_conta(numconta);        
    
    printf("Nome: %s", contas[i].cliente.nome);                 //nome
    printf("Numero da conta: %d\n", contas[i].num_conta);       //numero da conta
    printf("CPF: %s\n", contas[i].cliente.cpf);                 //cpf
    printf("Telefone: %lld\n", contas[i].cliente.telefone);     //telefone
    printf("Email: %s\n", contas[i].cliente.email);             //email
    printf("Saldo: R$%.2lf\n", contas[i].saldo);                //saldo
    
    printf("Data de criacao: %d/", contas[i].data_criacao.dia); //data de criacao
    printf("%d/", contas[i].data_criacao.mes);
    printf("%d\n", contas[i].data_criacao.ano);                                
}

/*-------------------------------
Função: deposito
Parâmetros: nenhum
Retorno: nenhum
Descrição: submenu principal que posicao conta
ou chave pix, deposita e depois mostra o saldo
---------------------------------*/
void deposito(){
    int nconta;                 //numero da conta
    int escolha = 0;            //variavel de decisão nos menus                                
    double deposito = 0;        //valor de depósito

    while(1){                                                           //verificacao da existencia da conta 
        puts("Digite o numero da conta a realizar o deposito");
        scanf("%d", &nconta);
        fflush(stdin);
        
        if(existe_conta(nconta))
            break;
        else{
            puts("conta inexistente");
            continue;
        }   
    }

    while(1){                                                           //entrada do valor de depósito
        puts("Digite o valor a ser depositado:");
        scanf("%lf", &deposito);
        
        if( (contas[posicao_conta(nconta)].saldo + deposito) > 500 ){       
            puts("o deposito excedeu o limite da conta");
            continue;
        }
        else{
            contas[posicao_conta(nconta)].saldo += deposito;
            puts("deposito realizado com sucesso");
            break;
        }           
    }

    while(1){                                                       //bloco de extrato do depósito
        puts("Deseja ver o saldo?");
        puts("1- Sim");
        puts("2- Nao");
        fflush(stdin);
        scanf("%d", &escolha);
        fflush(stdin);      

        switch(escolha){
            case 1:
                printf("Conta %d\n", nconta);
                printf("Saldo = R$%.2lf\n", extrato_conta(nconta));
                break;
            case 2:
                break;
        }
        break;                      
    }
    system("PAUSE");  
}

/*-------------------------------
Função: print_contas_ordenadas
Parâmetros: nenhum
Retorno: nenhum
Descrição: printa em ordem alfabetica
todas as contas registradas e mostra 
nome, cpf e numero da conta
---------------------------------*/
void print_contas_ordenadas(){                      //printa todas as contas em ordem alfabética
   conta ordem[n_contas];                           //cópia de contas que será ordenada
   conta aux;                                       //conta auxiliar para substituição
   
    for(int i = 0; i < n_contas; i++)  
        ordem[i] = contas[i];                       //ordem se torna cópia de contas

    for(int i = 0; i < n_contas; i++){
        for(int j = 0; j < n_contas; j++){
            if(strcmp(ordem[i].cliente.nome, ordem[j].cliente.nome) < 0){  //afere a ordem das strings
                
                strcpy(aux.cliente.nome, ordem[i].cliente.nome);             //passa os valores de i para auxiliar
                strcpy(aux.cliente.cpf, ordem[i].cliente.cpf);
                aux.num_conta = ordem[i].num_conta;
                aux.saldo = ordem[i].saldo;

                strcpy(ordem[i].cliente.nome, ordem[j].cliente.nome);        //substitui os valores de i por j
                strcpy(ordem[i].cliente.cpf, ordem[j].cliente.cpf);
                ordem[i].num_conta = ordem[j].num_conta;
                ordem[i].saldo = ordem[j].saldo;

                strcpy(ordem[j].cliente.nome, aux.cliente.nome);             //substitui o valor de j por auxiliar
                strcpy(ordem[j].cliente.cpf, aux.cliente.cpf);
                ordem[j].num_conta = aux.num_conta;
                ordem[j].saldo = aux.saldo;
            }       
        }
    }
    for(int i = 0; i < n_contas; i++){                          //printa as contas ordenadas
        printf("Nome: %s", ordem[i].cliente.nome);
        printf("CPF: %s\n", ordem[i].cliente.cpf);
        printf("Numero da conta: %d\n", ordem[i].num_conta);
        printf("Saldo: R$%.2lf\n\n", ordem[i].saldo);
    }
    system("PAUSE");
}

/*-------------------------------
Função: transacao_pix
Parâmetros: nenhum
Retorno: nenhum
Descrição: posicao conta para transferencia e
utiliza as chaves pix para encontrar o destino
e no final mostra as informações das duas contas
---------------------------------*/ 
void transacao_pix(){                                           
    int escolha;                //variável de controle dos menus
    int nconta;                 //armazena a conta a ser posicaoda
    char email[50];             //armazena o email a ser posicaodo
    char cpf[20];               //armazena o cpf a ser posicaodo
    char senha[11];             //armazena a senha para validação da transferencia
    long long int telefone;     //armazena o telefone a ser posicaodo
    double pagamento = 0.00;    //armazena o valor a ser transferido
                            
    while(1){                                               //login
        puts("Digite o numero da conta para acesso");
        scanf("%d", &nconta);
        fflush(stdin);
        
        if(existe_conta(nconta))
            break;
        else{
            puts("conta inexistente");
            continue;
        }   
    }
    while(1){                               //verificacao de senha 
        puts("Digite a senha de acesso");
        scanf("%s", senha);
        fflush(stdin);

        if(existe_senha(senha)){
            if(posicao_conta(nconta) == posicao_senha(senha))
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
    
    puts("Escolha a chave pix desejada para o pagamento");          //posicao pelas chaves pix
    puts("1- CPF");
    puts("2- email");
    puts("3- telefone");
    scanf("%d", &escolha);
    fflush(stdin);

    switch (escolha){
        case 1:                                                     //caso cpf
            while(1){
                puts("Digite o numero do cpf desejado");
                scanf("%s", cpf);
                fflush(stdin);
        
                if(existe_cpf(cpf))
                    break;
                else{
                    puts("cpf inexistente");
                    continue;
                }   
            }

            while(1){
                validar_pagamento(&pagamento, nconta);               //verifica o valor do pagamento e se é válido

                if(contas[posicao_cpf(cpf)].saldo + pagamento > 500){            //verifica se supera o limite de credito da conta
                    puts("Valor supera o limite de credito da conta");
                    continue;
                }
                contas[posicao_conta(nconta)].saldo -= pagamento;
                contas[posicao_cpf(cpf)].saldo += pagamento;
                break;
            }
            
            printf("\nNome: %s", contas[posicao_conta(nconta)].cliente.nome);             //nome
            printf("Numero da conta: %d\n", contas[posicao_conta(nconta)].num_conta);     //numero da conta
            printf("CPF: %s\n", contas[posicao_conta(nconta)].cliente.cpf);               //cpf
            printf("Telefone: %lld\n", contas[posicao_conta(nconta)].cliente.telefone);   //telefone
            printf("Email: %s\n", contas[posicao_conta(nconta)].cliente.email);           //email
            printf("Saldo: R$%.2lf\n\n", contas[posicao_conta(nconta)].saldo);            //saldo
                
            printf("Nome: %s", contas[posicao_cpf(cpf)].cliente.nome);                    //nome
            printf("Numero da conta: %d\n", contas[posicao_cpf(cpf)].num_conta);          //numero da conta
            printf("CPF: %s\n", contas[posicao_cpf(cpf)].cliente.cpf);                    //cpf
            printf("Telefone: %lld\n", contas[posicao_cpf(cpf)].cliente.telefone);        //telefone
            printf("Email: %s\n", contas[posicao_cpf(cpf)].cliente.email);                //email
            printf("Saldo: R$%.2lf\n", contas[posicao_cpf(cpf)].saldo);                   //saldo
            system("PAUSE");
            break;

        case 2:                                         //caso email
            while(1){
                puts("Digite o email desejado");
                scanf("%s", email);
                fflush(stdin);
        
                if(existe_email(email))
                    break;
                else{ 
                    puts("email inexistente");
                    continue;
                }   
            }

            while(1){
                validar_pagamento(&pagamento, nconta);          //verifica o valor do pagamento e se é válido

                if(contas[posicao_email(email)].saldo + pagamento > 500){   //verifica se supera o limite de credito da conta 
                    puts("Valor supera o limite de credito da conta");
                    continue;
                }
                contas[posicao_conta(nconta)].saldo -= pagamento;
                contas[posicao_email(email)].saldo += pagamento;
                break;    
            }
            
            printf("\nNome: %s", contas[posicao_conta(nconta)].cliente.nome);             //nome
            printf("Numero da conta: %d\n", contas[posicao_conta(nconta)].num_conta);     //numero da conta
            printf("CPF: %s\n", contas[posicao_conta(nconta)].cliente.cpf);               //cpf
            printf("Telefone: %lld\n", contas[posicao_conta(nconta)].cliente.telefone);   //telefone
            printf("Email: %s\n", contas[posicao_conta(nconta)].cliente.email);           //email
            printf("Saldo: R$%.2lf\n\n", contas[posicao_conta(nconta)].saldo);            //saldo
                
            printf("Nome: %s", contas[posicao_email(email)].cliente.nome);                //nome
            printf("Numero da conta: %d\n", contas[posicao_email(email)].num_conta);      //numero da conta
            printf("CPF: %s\n", contas[posicao_email(email)].cliente.cpf);                //cpf
            printf("Telefone: %lld\n", contas[posicao_email(email)].cliente.telefone);    //telefone
            printf("Email: %s\n", contas[posicao_email(email)].cliente.email);            //email
            printf("Saldo: R$%.2lf\n", contas[posicao_email(email)].saldo);               //saldo
                
            system("PAUSE");
            break;
        case 3:                                                 //caso telefone
            while(1){
                puts("Digite o numero do telefone registrado");
                scanf("%lld", &telefone);
                fflush(stdin);
        
                if(existe_telefone(telefone))
                    break;
                else{
                    puts("telefone inexistente");
                    continue;
                }   
            }
            while(1){
                validar_pagamento(&pagamento, nconta);              //verifica o valor do pagamento e se é válido

                if(contas[posicao_telefone(telefone)].saldo + pagamento > 500){ //verifica se supera o limite de credito
                    puts("Valor supera o limite de credito da conta");
                    continue;
                }
                contas[posicao_conta(nconta)].saldo -= pagamento;
                contas[posicao_telefone(telefone)].saldo += pagamento;
                break;
            }
            
            printf("\nNome: %s", contas[posicao_conta(nconta)].cliente.nome);                   //nome
            printf("Numero da conta: %d\n", contas[posicao_conta(nconta)].num_conta);           //numero da conta
            printf("CPF: %s\n", contas[posicao_conta(nconta)].cliente.cpf);                     //cpf
            printf("Telefone: %lld\n", contas[posicao_conta(nconta)].cliente.telefone);         //telefone
            printf("Email: %s\n", contas[posicao_conta(nconta)].cliente.email);                 //email
            printf("Saldo: R$%.2lf\n\n", contas[posicao_conta(nconta)].saldo);                  //saldo
                
            printf("Nome: %s", contas[posicao_telefone(telefone)].cliente.nome);                //nome
            printf("Numero da conta: %d\n", contas[posicao_telefone(telefone)].num_conta);      //numero da conta
            printf("CPF: %s\n", contas[posicao_telefone(telefone)].cliente.cpf);                //cpf
            printf("Telefone: %lld\n", contas[posicao_telefone(telefone)].cliente.telefone);    //telefone
            printf("Email: %s\n", contas[posicao_telefone(telefone)].cliente.email);            //email
            printf("Saldo: R$%.2lf\n", contas[posicao_telefone(telefone)].saldo);               //saldo

            system("PAUSE");
            break;
    }
}

/*-------------------------------
Função: excluir conta
Parâmetros: nenhum
Retorno: nenhum
Descrição: busca conta ou chave pix
e exclui a mesma do registro
---------------------------------*/
void excluir_contas(){              
    int escolha;                //variável de controle dos menus
    int nconta;                 //numero da conta
    long long int telefone;
    char email[50];
    char cpf[20];
    conta aux;                  //conta auxiliar para substituição


    puts("Procurar por numero da conta ou chaves pix?");
    puts("1- Numero da conta");
    puts("2- Chaves pix");
    scanf("%d", &escolha);
    fflush(stdin);

    switch(escolha){
        case 1:                                                     //excluir a partir do numero da conta           
            while(1){
                puts("Digite o numero da conta a ser excluida");
                scanf("%d", &nconta);
                fflush(stdin);
        
                if(existe_conta(nconta))
                    break;
                else
                {
                    puts("conta inexistente");
                    continue;
                }   
            }
            for(int i = posicao_conta(nconta); i < n_contas; i++){  //iteração a partir da conta a ser excluída
                if(posicao_conta(nconta) == n_contas - 1){          //se for excluir a ultima conta registrada
                    contas[i] = aux;
                    break;
                } 
                if(i == posicao_conta(nconta))                      //se for excluir a primeira conta registrada
                    continue;
                
                contas[i - 1] = contas[i];

                if(i == n_contas - 1)
                    contas[i] = aux;
                }
            --n_contas;
            puts("Conta excluida com sucesso");
            system("PAUSE");
            break;
        case 2:                                                     //chaves pix
            puts("1- CPF");
            puts("2- email");
            puts("3- telefone");
            scanf("%d", &escolha);
            fflush(stdin);

            switch (escolha){
                case 1:                         
                    while(1){                                       //excluir a partir do cpf
                        puts("Digite o numero do cpf registrado");
                        scanf("%s", cpf);
                        fflush(stdin);
            
                        if(existe_cpf(cpf))
                            break;
                        else{
                            puts("cpf inexistente");
                            continue;
                        }   
                    }
                    for(int i = posicao_cpf(cpf); i < n_contas; i++){
                        if(posicao_cpf(cpf) == n_contas - 1){       //se for excluir a ultima conta registrada
                            contas[i] = aux;
                            break;
                        } 
                        if(i == posicao_cpf(cpf))                   //se for excluir a primeira conta registrada
                            continue;
                        
                        contas[i - 1] = contas[i];
                        
                        if(i == n_contas - 1)
                            contas[i] = aux;
                    }
                    --n_contas;
                    puts("Conta excluida com sucesso");
                    system("PAUSE");
                    break;
                case 2:                         
                    while(1){                                       //excluir a partir do email
                        puts("Digite o email registrado");
                        scanf("%s", email);
                        fflush(stdin);
            
                        if(existe_email(email))
                            break;
                        else
                        {
                            puts("email inexistente");
                            continue;
                        }   
                    }
                    for(int i = posicao_email(email); i < n_contas; i++){
                        if(posicao_email(email) == n_contas - 1){   //se for excluir a ultima conta registrada
                            contas[i] = aux;
                            break;
                        } 
                        if(i == posicao_email(email))               //se for excluir a primeira conta registrada
                            continue;

                        contas[i - 1] = contas[i];

                        if(i == n_contas - 1)
                            contas[i] = aux;
                    }
                    --n_contas;
                    puts("Conta excluida com sucesso");
                    system("PAUSE");
                    break;
                case 3:                         
                    while(1){                                           //se for excluir pelo telefone
                        puts("Digite o numero do telefone registrado");
                        scanf("%lld", &telefone);
                        fflush(stdin);
            
                        if(existe_telefone(telefone))
                            break;
                        else
                        {
                            puts("telefone inexistente");
                            continue;
                        }   
                    }

                    for(int i = posicao_telefone(telefone); i < n_contas; i++){
                        if(posicao_telefone(telefone) == n_contas - 1){ //se for excluir a ultima conta registrada
                            contas[i] = aux;
                            break;
                        } 
                        if(i == posicao_telefone(telefone))             //se for excluir a primeira conta registrada 
                            continue;
                
                        contas[i - 1] = contas[i];
                
                        if(i == n_contas - 1)
                            contas[i] = aux;
                    }
                    --n_contas;
                    puts("Conta excluida com sucesso");
                    system("PAUSE");
                    break;
            }
            break;
    } 
}