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
    }
}
