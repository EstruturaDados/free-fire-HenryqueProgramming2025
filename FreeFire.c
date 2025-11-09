# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// Struct Para Itens

struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Protótipos das Funções

void inserirItem(struct Item mochila[], int *totalItens);
void removerItem(struct Item mochila[], int *totalItens);
void listarItens(struct Item mochila[], int totalItens);
void buscarItem(struct Item mochila[], int totalItens);
void limparBuffer();

int main() {
    printf("=== SISTEMA DE INVENTÁRIO - SOBREVIVÊNCIA NA ILHA ===\n\n");

    // Vetor para armazenar itens

    struct Item mochila[10];
    int totalItens = 0;
    int opcao;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Adicionar item ao inventário\n");
        printf("2. Remover item do inventário\n");
        printf("3. Listar todos os itens\n");
        printf("4. Buscar item por nome\n");
        printf("5. Sair do sistema\n");
        printf("\nEscolha uma opção (1-5): ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpa Buffer

        switch(opcao){
            case 1:
                inserirItem(mochila, &totalItens);
                break;
            case 2:
                removerItem(mochila, &totalItens);
                break;
            case 3:
                listarItens(mochila, totalItens);
                break;
            case 4:
                buscarItem(mochila, totalItens);
                break;
            case 5:
                printf("\n=== SISTEMA ENCERRADO ===\n");
                printf("Obrigado por usar o sistema de inventário!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente!\n");
        }
    } while(opcao != 5);

    return 0;
}

void inserirItem(struct Item mochila[], int *totalItens) {
    if (*totalItens >= 10) {
        printf("\n❌ Mochila cheia! Máximo 10 itens.\n");
        return;
    }
    printf("\n=== ADICIONAR ITEM ===\n");
    printf("Nome: ");
    scanf("%29s", mochila[*totalItens].nome);
    limparBuffer();
    printf("Tipo: ");
    scanf("%19s", mochila[*totalItens].tipo);
    limparBuffer();
    printf("Quantidade: ");
    scanf("%d", &mochila[*totalItens].quantidade);
    limparBuffer();
    printf("✅ Item adicionado!\n");
    (*totalItens)++;
}

void removerItem(struct Item mochila[], int *totalItens) {
    if (*totalItens == 0) {
        printf("\n❌ Mochila vazia!\n");
        return;
    }
    printf("\n=== REMOVER ITEM ===\n");
    char nome[30];
    printf("Nome do item: ");
    scanf("%29s", nome);
    limparBuffer();
    for (int i = 0; i < *totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < *totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*totalItens)--;
            printf("✅ Item removido!\n");
            return;
        }
    }
    printf("❌ Item não encontrado!\n");
}

void listarItens(struct Item mochila[], int totalItens) {
    printf("\n=== INVENTÁRIO (%d/10) ===\n", totalItens);
    if (totalItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }
    for (int i = 0; i < totalItens; i++) {
        printf("%d. %s (%s) - %d unidades\n", 
               i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void buscarItem(struct Item mochila[], int totalItens) {
    if (totalItens == 0) {
        printf("\n❌ Mochila vazia!\n");
        return;
    }
    printf("\n=== BUSCAR ITEM ===\n");
    char nome[30];
    printf("Nome: ");
    scanf("%29s", nome);
    limparBuffer();
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("✅ Encontrado: %s (%s) - %d unidades\n", 
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }
    printf("❌ Item não encontrado!\n");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
