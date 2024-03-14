#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CLIENTES 50

struct data {
    int dia;
    int mes;
    int ano;
};

struct Cliente {
    char nome[100];
    struct data data_nasciment;
    int idade;
    char sexo;
};

void lerCliente(struct Cliente *cliente) {
    printf("Por favor digite seu nome: ");
    scanf("%s", cliente->nome);
    printf("Coloque sua data de nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &cliente->data_nasciment.dia, &cliente->data_nasciment.mes, &cliente->data_nasciment.ano);
    printf("Coloque seu sexo (M/F): ");
    do {
        scanf(" %c", &cliente->sexo);
    } while (cliente->sexo != 'M' && cliente->sexo != 'm' && cliente->sexo != 'F' && cliente->sexo != 'f');

    struct tm *data_atual;
    time_t t = time(NULL);
    data_atual = localtime(&t);
    int ano_atual = data_atual->tm_year + 1900;
    int mes_atual = data_atual->tm_mon + 1;
    int dia_atual = data_atual->tm_mday;

    cliente->idade = ano_atual - cliente->data_nasciment.ano;
    if (mes_atual < cliente->data_nasciment.mes || (mes_atual == cliente->data_nasciment.mes && dia_atual < cliente->data_nasciment.dia)) {
        cliente->idade--;
    }
}

void imprimirCliente(const struct Cliente *cliente) {
    printf("Nome: %s\n", cliente->nome);
    printf("Data de Nascimento: %d/%d/%d\n", cliente->data_nasciment.dia, cliente->data_nasciment.mes, cliente->data_nasciment.ano);
    printf("Idade: %d\n", cliente->idade);
    printf("Sexo: %c\n", cliente->sexo);
}

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int numClientes = 0;
    int opcao;

    do {
        printf("1. Cadastrar\n");
        printf("2. Cadastros\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numClientes < MAX_CLIENTES) {
                    lerCliente(&clientes[numClientes]);
                    numClientes++;
                } else {
                    printf("Limite de clientes atingido.\n");
                }
                break;
            case 2:
                for (int i = 0; i < numClientes; i++) {
                    printf("Cliente %d:\n", i + 1);
                    imprimirCliente(&clientes[i]);
                    printf("\n");
                }
                break;
        };

    } while (opcao != 3);

    return 0;
}

