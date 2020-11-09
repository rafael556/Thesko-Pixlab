#include"funcoes_controle.h"


void menu_inicial(){
    int decisao_1;

    puts("1- Criar nova conta");
    puts("2- Consultar extrato de conta");
    puts("3- Depositar em conta");
    puts("4- Listar todas as contas");
    puts("5- pagamento com chaves pix");
    puts("6- excluir conta");
    printf("\nDigite o numero da operacao requerida:");
    scanf("%d",&decisao_1);
    fflush(stdin);
    // printf("\n%d\n",decisao_1);

    switch (decisao_1)
    {
        case 1:
            criacao_conta();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
    default:
        break;
    }
}

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
            contas[n_contas].num_conta= numconta++;
        }
}

