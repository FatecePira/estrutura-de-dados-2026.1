/*
 * FATECE - Ciência da Computacao
 * Disciplina: Estrutura de Dados
 * Prof. Stefane Menezes
 * * ATD1: Implementacao de Lista Duplamente Encadeada em C
 * Alunos: Anna Luiza Maneo da Silva, Daniel Pereira Moreira, Vinicius de Souza
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicão da estrutura do nó (Livro)
typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;
    struct Livro* prox; // Ponteiro para o proximo nó
    struct Livro* ant;  // Ponteiro para o nó anterior
} Livro;

// Funcao auxiliar para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Inicializa a lista como vazia
Livro* criarLista() {
    return NULL; 
}

// Funcao para alocar memoria e coletar dados de um novo livro
Livro* criarNo() {
    Livro* novo = (Livro*)malloc(sizeof(Livro));
    if (novo == NULL) {
        printf("Erro: Memoria insuficiente!\n");
        exit(1);
    }
    
    printf("Codigo do livro (inteiro): ");
    scanf("%d", &novo->codigo);
    limparBuffer();
    
    printf("Titulo do livro: ");
    fgets(novo->titulo, 100, stdin);
    novo->titulo[strcspn(novo->titulo, "\n")] = 0; // Remove o \n
    
    printf("Nome do autor: ");
    fgets(novo->autor, 100, stdin);
    novo->autor[strcspn(novo->autor, "\n")] = 0;
    
    printf("Ano de publicacao: ");
    scanf("%d", &novo->ano);
    
    printf("Quantidade de exemplares: ");
    scanf("%d", &novo->quantidade);
    
    novo->prox = NULL;
    novo->ant = NULL;
    
    return novo;
}

// Inserir no inicio da lista
void inserirInicio(Livro** inicio) {
    Livro* novo = criarNo();
    
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        novo->prox = *inicio;
        (*inicio)->ant = novo;
        *inicio = novo;
    }
    printf("-> Livro inserido no inicio com sucesso!\n");
}

// Inserir no final da lista
void inserirFinal(Livro** inicio) {
    Livro* novo = criarNo();
    
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        Livro* atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
        novo->ant = atual;
    }
    printf("-> Livro inserido no final com sucesso!\n");
}

// Remover livro da lista por codigo
void removerLivro(Livro** inicio, int codigo) {
    if (*inicio == NULL) {
        printf("-> A lista esta vazia!\n");
        return;
    }

    Livro* atual = *inicio;
    while (atual != NULL && atual->codigo != codigo) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("-> Livro com codigo %d nao encontrado!\n", codigo);
        return;
    }

    // Ajuste dos ponteiros para remocao
    if (atual->ant == NULL) { // Se for o primeiro
        *inicio = atual->prox;
        if (*inicio != NULL) {
            (*inicio)->ant = NULL;
        }
    } else { // Se estiver no meio ou fim
        atual->ant->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        }
    }

    free(atual); // Libera a memoria
    printf("-> Livro removido com sucesso!\n");
}

// Buscar livro pelo codigo e exibir informacoes
void buscarLivro(Livro* inicio, int codigo) {
    Livro* atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            printf("\n--- Informacoes do Livro ---\n");
            printf("Codigo: %d\n", atual->codigo);
            printf("Titulo: %s\n", atual->titulo);
            printf("Autor: %s\n", atual->autor);
            printf("Ano: %d\n", atual->ano);
            printf("Quantidade: %d\n", atual->quantidade);
            return;
        }
        atual = atual->prox;
    }
    printf("-> Livro nao encontrado!\n");
}

// Listar todos os livros (ordem direta)
void imprimirLista(Livro* inicio) {
    if (inicio == NULL) {
        printf("-> A lista esta vazia!\n");
        return;
    }
    
    Livro* atual = inicio;
    printf("\n--- Lista de Livros (Ordem Direta) ---\n");
    while (atual != NULL) {
        printf("[%d] %s | Autor: %s | Qtd: %d\n", atual->codigo, atual->titulo, atual->autor, atual->quantidade);
        atual = atual->prox;
    }
}

// Listar todos os livros (ordem reversa)
void imprimirListaReversa(Livro* inicio) {
    if (inicio == NULL) {
        printf("-> A lista esta vazia!\n");
        return;
    }
    
    Livro* atual = inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    printf("\n--- Lista de Livros (Ordem Reversa) ---\n");
    while (atual != NULL) {
        printf("[%d] %s | Autor: %s | Qtd: %d\n", atual->codigo, atual->titulo, atual->autor, atual->quantidade);
        atual = atual->ant;
    }
}

// Mostrar quantidade de livros cadastrados
void contarElementos(Livro* inicio) {
    int contador = 0;
    Livro* atual = inicio;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    printf("-> Total de livros na estante: %d\n", contador);
}

// Liberar toda a memoria alocada antes de fechar o programa
void liberarLista(Livro** inicio) {
    Livro* atual = *inicio;
    Livro* proximo;
    
    while (atual != NULL) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

int main() {
    Livro* minhaLista = criarLista();
    int opcao, codigoBusca;

    do {
        printf("\n===================================\n");
        printf("    SISTEMA DE GESTAO DE LIVROS      \n");
        printf("===================================\n");
        printf("1 - Inserir livro no final\n");
        printf("2 - Inserir livro no inicio\n");
        printf("3 - Remover livro\n");
        printf("4 - Buscar livro\n");
        printf("5 - Listar livros (Ordem Direta)\n");
        printf("6 - Listar livros (Ordem Reversa)\n");
        printf("7 - Quantidade de livros\n");
        printf("0 - Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirFinal(&minhaLista);
                break;
            case 2:
                inserirInicio(&minhaLista);
                break;
            case 3:
                printf("Digite o codigo do livro para remover: ");
                scanf("%d", &codigoBusca);
                removerLivro(&minhaLista, codigoBusca);
                break;
            case 4:
                printf("Digite o codigo do livro para buscar: ");
                scanf("%d", &codigoBusca);
                buscarLivro(minhaLista, codigoBusca);
                break;
            case 5:
                imprimirLista(minhaLista);
                break;
            case 6:
                imprimirListaReversa(minhaLista);
                break;
            case 7:
                contarElementos(minhaLista);
                break;
            case 0:
                printf("Limpando memoria e encerrando...\n");
                liberarLista(&minhaLista);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}