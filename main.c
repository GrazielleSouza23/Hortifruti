#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void MenuLogin();
void MenuCliente();
void MenuCaixa();
void MenuEstacao();

void MenuCaixaCadastrar();
void MenuCaixaAlterar();
void MenuCaixaExcluir();
void MenuCaixaConsultar();

void MenuEstacaoAdicionar();
void MenuEstacaoExcluir();
void MenuEstacaoConsultar();
void MenuEstacaoComprar();

void MetodoPagamento();
void ZerarSacola();
void Condicao();

int main(){

int opcao;

        inicio:
        printf("\n\nMENU\n");
        printf("1 - Login de Funcionarios\n");
        printf("2 - Area do Cliente\n");
        printf("0 - Sair\n\n");
        printf("Por favor, selecione uma opcao: ");

        scanf("%d", &opcao);

    switch(opcao){
        case 1:
            system("cls");
            MenuLogin();
        case 2:
            system("cls");
            MenuCliente();
        case 0:
            printf("\nSaindo...\n\n");
            exit(EXIT_SUCCESS);
        default:
            system("cls");
            printf("Opcao invalida. Tente novamente.\n");
            goto inicio;
            break;
        }
}

void MenuLogin(){
 char usuario[20];
 char senha[20];
 char saudacao[50] = "\nBem-vindo, ";

 printf("\n\nAREA DE LOGIN\n");

 getchar();

 volta:
  // Leitura do nome
 printf("Usuario: ");
 fgets(usuario, sizeof(usuario), stdin);
 usuario[strcspn(usuario, "\n")] = 0;

  // Leitura da senha
 printf("Senha: ");
 fgets(senha, sizeof(senha), stdin);
 senha[strcspn(senha, "\n")] = 0;

 // Comparação do usuário e senha
    if (strcmp(usuario, "Joice") == 0 && strcmp(senha, "12345") == 0){
    strcat(saudacao, usuario);
    system("cls");
    printf("%s\n", saudacao);
    MenuCaixa();
    }
    else {
    printf("Senha ou usuario incorretos!\n\n");
    goto volta;
    }
}

void MenuCliente(){
char usuario[20];
char senha[20];

 printf("\n\nAREA DO CLIENTE\n");

 getchar();

 volta:
  // Leitura do nome
 printf("Usuario: ");
 fgets(usuario, sizeof(usuario), stdin);
 usuario[strcspn(usuario, "\n")] = 0;

  // Leitura da senha
 printf("Senha: ");
 fgets(senha, sizeof(senha), stdin);
 senha[strcspn(senha, "\n")] = 0;

 // Comparação do usuário e senha
    if (strcmp(usuario, "Cliente") == 0 && strcmp(senha, "05112024") == 0){
    system("cls");
    MenuEstacao();
    }
    else {
    printf("Senha ou usuario incorretos!\n\n");
    goto volta;
    }
}

void MenuCaixa(){
int opcao;

    do {
        printf("\nMenu:\n\n");
        printf("0. Sair\n");
        printf("1. Cadastrar produto\n");
        printf("2. Alterar produto\n");
        printf("3. Excluir produto\n");
        printf("4. Consultar produtos\n");
        printf("5. Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: printf("Saindo...\n"); exit(EXIT_SUCCESS); break;
            case 1: system("cls"); MenuCaixaCadastrar(); break;
            case 2: system("cls"); MenuCaixaAlterar(); break;
            case 3: system("cls"); MenuCaixaExcluir(); break;
            case 4: system("cls"); MenuCaixaConsultar(); break;
            case 5: system("cls"); main(); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
    system("cls");
 }

void MenuEstacao(){
int opcao;

    do {
        printf("\nMenu:\n\n");
        printf("0. Sair\n");
        printf("1. Adicionar produto(s) na sacola\n");
        printf("2. Excluir produto(s) da sacola\n");
        printf("3. Consultar produtos na sacola\n");
        printf("4. Comprar produtos na sacola\n");
        printf("5. Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: printf("Saindo...\n"); exit(EXIT_SUCCESS); break;
            case 1: system("cls"); MenuEstacaoAdicionar(); break;
            case 2: system("cls"); MenuEstacaoExcluir(); break;
            case 3: system("cls"); MenuEstacaoConsultar(); break;
            case 4: system("cls"); MenuEstacaoComprar(); break;
            case 5: system("cls"); main(); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);
    system("cls");
}

//Funções Cadastrar, Alterar, Excluir e Consultar do Caixa
#define MAX_NOME 100
#define MAX_PRODUTOS 100

typedef struct {
    char nome[MAX_NOME];
    float preco;
    float quantidade;
    float soma;
} Produto;

void MenuCaixaCadastrar() {
    Produto p;
    FILE *arquivo = fopen("Produtos.txt", "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("\nDigite o nome do produto: ");
    scanf("%s", p.nome);
    preco:
    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);
        if(p.preco<=0){
            printf("Adicione um preco valido!\n");
            goto preco;
        }
        else{
        fprintf(arquivo, "%s,%.2f\n", p.nome, p.preco);
        fclose(arquivo);
        }
}

void MenuCaixaAlterar(){
    Produto p;
    char nome_antigo[MAX_NOME];
    int encontrado = 0;
    FILE *arquivo = fopen("Produtos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("\nDigite o nome do produto a ser alterado: ");
    scanf("%s", nome_antigo);


    while (fscanf(arquivo, "%99[^,],%f\n", p.nome, &p.preco) != EOF) {
        if (strcmp(p.nome, nome_antigo) == 0) {
                printf("Digite o novo nome do produto: ");
                scanf("%s", p.nome);
                printf("Digite o novo preco do produto: ");
                scanf("%f", &p.preco);
                encontrado = 1;
                fprintf(temp, "%s,%.2f\n", p.nome, p.preco);
        } else {
            fprintf(temp, "%s,%.2f\n", p.nome, p.preco);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("Produtos.txt");
    rename("temp.txt", "Produtos.txt");

    if (encontrado) {
        printf("Produto alterado com sucesso.\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void MenuCaixaConsultar() {
    Produto p;
    FILE *arquivo = fopen("Produtos.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
        printf("%-22s %-10s\n", "\nNome", "Preco");
    while (fscanf(arquivo, "%99[^,],%f\n", p.nome, &p.preco) != EOF)
        {
        printf("%-22s %-15.2f\n", p.nome, p.preco);
        }
    fclose(arquivo);
}

void MenuCaixaExcluir() {
    Produto p;
    char nome[MAX_NOME];
    int encontrado = 0;
    FILE *arquivo = fopen("Produtos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("\nDigite o nome do produto a ser excluido: ");
    scanf("%s", nome);

    while (fscanf(arquivo, "%99[^,],%f\n", p.nome, &p.preco) != EOF) {
        if (strcmp(p.nome, nome) != 0) {
            fprintf(temp, "%s,%.2f\n", p.nome, p.preco);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("Produtos.txt");
    rename("temp.txt", "Produtos.txt");

    if (encontrado) {
        printf("Produto excluido com sucesso.\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}



//Funções Adicionar, Excluir, Consultar e Comprar itens na Sacola.

void MenuEstacaoAdicionar(){
Produto p;
    char nome_consulta[MAX_NOME];
    int encontrado = 0;
    FILE *arquivo = fopen("Sacola.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("Digite o nome do produto a ser adicionado: ");
    scanf("%s", nome_consulta);

    while (fscanf(arquivo, "%99[^,],%f,%f\n", p.nome, &p.preco, &p.quantidade) != EOF) {
    float valor_atual;
        if (strcmp(p.nome, nome_consulta) == 0) {
                retorno:
                printf("Digite a quantidade (kg) do produto: ");
                scanf("%f", &valor_atual);
                if(valor_atual<=0){
                    printf("Adicione uma quantidade valida!\n");
                    goto retorno;
                }
                else{
                encontrado = 1;
                fprintf(temp, "%s,%.2f,%.3f\n", p.nome, p.preco, (p.quantidade+valor_atual));
                }
        }
        else {
            fprintf(temp, "%s,%.2f,%.3f\n", p.nome, p.preco, p.quantidade);
        }

    }

    fclose(arquivo);
    fclose(temp);

    remove("Sacola.txt");
    rename("temp.txt", "Sacola.txt");

    if (encontrado) {
        printf("Produto adicionado com sucesso.\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void MenuEstacaoExcluir(){
    Produto p;
    char nome_consulta[MAX_NOME];
    int encontrado = 0;
    FILE *arquivo = fopen("Sacola.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("Digite o nome do produto a ser excluido: ");
    scanf("%s", nome_consulta);

    while (fscanf(arquivo, "%99[^,],%f,%f\n", p.nome, &p.preco, &p.quantidade) != EOF) {
        if (strcmp(p.nome, nome_consulta) == 0) {
                p.quantidade = 0;
                encontrado = 1;
                fprintf(temp, "%s,%.2f,%.3f\n", p.nome, p.preco, p.quantidade);
        } else {
            fprintf(temp, "%s,%.2f,%.3f\n", p.nome, p.preco, p.quantidade);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("Sacola.txt");
    rename("temp.txt", "Sacola.txt");

    if (encontrado) {
        printf("Produto excluido com sucesso.\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void MenuEstacaoConsultar(){
    Produto p;
    FILE *arquivo = fopen("Sacola.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
        printf("%-22s %-10s %-10s\n", "\nNome", "Preco", "Quantidade(kg)");
    while (fscanf(arquivo, "%99[^,],%f,%f\n", p.nome, &p.preco, &p.quantidade) != EOF)
        {
        printf("%-22s %-15.2f %-15.3f\n", p.nome, p.preco, p.quantidade);
        }
    fclose(arquivo);

}

void MenuEstacaoComprar(){
    Produto p;
    FILE *arquivo = fopen("Sacola.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    FILE *arquivoCompra = fopen("ValorCompra.txt", "w");

    printf("%-22s %-15s %-20s %-20s\n", "\nNome", "Preco", "Quantidade(kg)", "Valor");
    while (fscanf(arquivo, "%99[^,],%f,%f\n", p.nome, &p.preco, &p.quantidade) != EOF){
        printf("%-22s %-15.2f %-20.3f %-20.2f\n", p.nome, p.preco, p.quantidade, (p.preco*p.quantidade));
        p.soma += p.preco*p.quantidade;
    }

    printf("-----------------------------------------------------------------------\n");
    printf("%-59s %-15.2f\n", "TOTAL", p.soma);

    fprintf(arquivoCompra, "%.2f\n", p.soma);

    fclose(arquivoCompra);
    fclose(arquivo);

    int opcao;

    do {
        printf("\n\n0. Sair\n");
        printf("1. Realizar compra\n");
        printf("2. Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: printf("Saindo...\n"); exit(EXIT_SUCCESS); break;
            case 1: system("cls"); MetodoPagamento(); break;
            case 2: system("cls"); MenuEstacao(); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);
    system("cls");
}

void Condicao(){
    FILE *arquivoCompra = fopen("ValorCompra.txt", "r");
    float ValorCompra;

    while(fscanf(arquivoCompra,"%f", &ValorCompra) != EOF) {
        printf("Valor da compra: R$ %.2f\n", ValorCompra);
    }

        if (ValorCompra > 0) {
        printf("Pagamento permitido.\n\n");
        ZerarSacola();
        }
        else {
        printf("Pagamento nao permitido. O valor da compra deve ser maior que zero.\n\n");
        MenuEstacao();
        }
}

void MetodoPagamento(){
    int opcao;

    do {
        printf("\nForma de Pagamento:\n\n");
        printf("0. Sair\n\n");
        printf("1. Dinheiro\n");
        printf("2. Cartao de Credito\n");
        printf("3. Cartao de Debito\n");
        printf("4. PIX\n");
        printf("5. Vale Alimentacao\n\n");
        printf("6. Voltar\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: printf("Saindo...\n"); exit(EXIT_SUCCESS); break;
            case 1: system("cls");
            printf("Pagamento pelo DINHEIRO\n");
            Condicao();
            break;
            case 2: system("cls");
            Condicao();
            break;
            case 3: system("cls");
            Condicao();
            break;
            case 4: system("cls");
            Condicao();
            break;
            case 5: system("cls");
            Condicao();
            break;
            case 6: system("cls"); MenuEstacao(); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);
    system("cls");
}

void ZerarSacola(){
    Produto p;
    FILE *arquivo = fopen("Sacola.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    while (fscanf(arquivo, "%99[^,],%f,%f\n", p.nome, &p.preco, &p.quantidade) != EOF) {
                p.quantidade = 0;
                fprintf(temp, "%s,%.2f,%.3f\n", p.nome, p.preco, p.quantidade);
    }

    fclose(arquivo);
    fclose(temp);
    remove("Sacola.txt");
    rename("temp.txt", "Sacola.txt");

    MenuEstacao();
}
