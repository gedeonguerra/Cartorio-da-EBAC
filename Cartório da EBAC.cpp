#include <stdio.h>   // Biblioteca de comunicação com o usuário (entrada/saída)
#include <stdlib.h>  // Biblioteca para funções de alocação de memória, conversão, sistema, etc
#include <locale.h>  // Biblioteca para configuração de localidade (idioma)
#include <string.h>  // Biblioteca para manipulação de strings

int registro()
{
    char arquivo[40];     // Nome do arquivo (CPF)
    char cpf[40];         // Armazena o CPF digitado
    char nome[40];        // Armazena o nome
    char sobrenome[40];   // Armazena o sobrenome
    char cargo[40];       // Armazena o cargo

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo

    FILE *file = fopen(arquivo, "w"); // Cria (ou sobrescreve) o arquivo com nome igual ao CPF
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    fprintf(file, "%s,", cpf); // Escreve CPF seguido de vírgula
    fclose(file);

    printf("Digite o nome: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome); // Nome + vírgula
    fclose(file);

    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome); // Sobrenome + vírgula
    fclose(file);

    printf("Digite o cargo: ");
    scanf("%s", cargo);

    file = fopen(arquivo,"a");
    fprintf(file, "%s", cargo); // Cargo (último campo, sem vírgula)
    fclose(file);

    printf("Usuário cadastrado com sucesso!\n");
    system("pause");
    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "portuguese"); // Define a localidade para idioma português

    char cpf[40];            // Armazena o CPF a ser consultado
    char conteudo[200];      // Buffer para leitura do arquivo

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r"); // Abre o arquivo correspondente ao CPF
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo. Usuário não encontrado.\n");
        system("pause");
        return 1;
    }

    printf("\nInformações do usuário:\n");
    while(fgets(conteudo, sizeof(conteudo), file) != NULL)
    {
        printf("%s\n", conteudo); // Exibe conteúdo lido
    }
    fclose(file);

    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Erro: usuário não encontrado no sistema.\n");
    }

    system("pause");
    return 0;
}

int main()
{
    int opcao = 0;  // Armazena a opção do menu

    while (1) // Loop infinito até o usuário decidir sair
    {
        system("cls"); // Limpa a tela do terminal

        setlocale(LC_ALL, "portuguese"); // Configura o idioma

        // Menu principal
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada no menu:\n\n");
        printf("\t1 - Registrar usuário\n");
        printf("\t2 - Consultar usuário\n");
        printf("\t3 - Deletar usuário\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");

        scanf("%d", &opcao); // Lê a opção do usuário
        system("cls");

        switch(opcao)
        {
            case 1:
                registro();     // Chama a função de registro
                break;

            case 2:
                consulta();     // Chama a função de consulta
                break;

            case 3:
                deletar();      // Chama a função de exclusão
                break;

            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0;       // Encerra o programa

            default:
                printf("Opção inválida. Tente novamente.\n");
                system("pause");
                break;
        }
    }
}
