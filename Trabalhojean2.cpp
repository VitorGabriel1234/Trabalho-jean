#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FUNCIONARIOS 50

struct Funcionario {
    char nome[100];
    char cargo;
    float salario_base;
    float beneficios;
    float descontos;
    float salario_liquido;
};

void lerFuncionario(struct Funcionario *funcionario) {
    printf("Por favor, digite seu nome: \n");
    scanf("%s", funcionario->nome);
    printf("Coloque seu cargo na loja: \n");
    scanf(" %c", &funcionario->cargo); // Corrigido para ler um único caractere
    printf("Coloque seu salario base: \n");
    scanf("%f", &funcionario->salario_base);
    printf("Coloque seus beneficios: \n");
    scanf("%f", &funcionario->beneficios);
    printf("Coloque seus descontos: \n");
    scanf("%f", &funcionario->descontos);

    // Calcular o salário líquido
    float salario_bruto = funcionario->salario_base + funcionario->beneficios;
    float salario_liquido = salario_bruto - funcionario->descontos;
    funcionario->salario_liquido = salario_liquido;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios = 0;
    int opcao;

    do {
        printf("\n1. Cadastrar\n");
        printf("2. Cadastros\n");
        printf("3. Salario médio\n");
        printf("4. Maior salario\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numFuncionarios < MAX_FUNCIONARIOS) {
                    lerFuncionario(&funcionarios[numFuncionarios]);
                    numFuncionarios++;
                } else {
                    printf("Limite de funcionarios atingido.\n");
                }
                break;
            case 2:
                if (numFuncionarios > 0) {
                    printf("Funcionarios cadastrados:\n");
                    for (int i = 0; i < numFuncionarios; i++) {
                        printf("Funcionario %d:\n", i + 1);
                        printf("Nome: %s\n", funcionarios[i].nome);
                        printf("Cargo: %c\n", funcionarios[i].cargo);
                        printf("Salario base: %.2f\n", funcionarios[i].salario_base);
                        printf("Beneficios: %.2f\n", funcionarios[i].beneficios);
                        printf("Descontos: %.2f\n", funcionarios[i].descontos);
                        printf("Salario liquido: %.2f\n", funcionarios[i].salario_liquido);
                        printf("\n");
                    }
                } else {
                    printf("Nenhum funcionario cadastrado.\n");
                }
                break;
            case 3:
                if (numFuncionarios > 0) {
                    float somaSalarios = 0;
                    for (int i = 0; i < numFuncionarios; i++) {
                        somaSalarios += funcionarios[i].salario_liquido;
                    }
                    float salarioMedio = somaSalarios / numFuncionarios;
                    printf("Salario medio: %.2f\n", salarioMedio);
                } else {
                    printf("Nenhum funcionario cadastrado.\n");
                }
                break;
            case 4:
                if (numFuncionarios > 0) {
                    float maiorSalario = funcionarios[0].salario_liquido;
                    for (int i = 1; i < numFuncionarios; i++) {
                        if (funcionarios[i].salario_liquido > maiorSalario) {
                            maiorSalario = funcionarios[i].salario_liquido;
                        }
                    }
                    printf("Maior salario: %.2f\n", maiorSalario);
                } else {
                    printf("Nenhum funcionario cadastrado.\n");
                }
                break;
            default:
                printf("Opção inválida.\n");
                break;
        };

    } while (opcao != 5);

    return 0;
}
