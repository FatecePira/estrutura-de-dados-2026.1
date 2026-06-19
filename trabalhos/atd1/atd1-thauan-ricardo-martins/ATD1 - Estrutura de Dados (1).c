#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó
typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;

    struct Livro *anterior;
    struct Livro *proximo;
} Livro;

// Criar lista (inicializa vazia)
Livro* criarLista() {
    return NULL;
}

// Criar novo livro
Livro* criarLivro() {
    Livro* novo = (Livro*) malloc(sizeof(Livro));

    printf("Codigo: ");
    scanf("%d", &novo->codigo);

    printf("Titulo: ");
    scanf(" %[^\n]", novo->titulo);

    printf("Autor: ");
    scanf(" %[^\n]", novo->autor);

    printf("Ano: ");
    scanf("%d", &novo->ano);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    novo->anterior = NULL;
    novo->proximo = NULL;

    return novo;
}

// Inserir no inicio
void inserirInicio(Livro **lista) {
    Livro *novo = criarLivro();

    if (*lista == NULL) {
        *lista = novo;
    } else {
        novo->proximo = *lista;
        (*lista)->anterior = novo;
        *lista = novo;
    }
}

// Inserir no final
void inserirFinal(Livro **lista) {
    Livro *novo = criarLivro();

    if (*lista == NULL) {
        *lista = novo;
        return;
    }

    Livro *aux = *lista;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }

    aux->proximo = novo;
    novo->anterior = aux;
}

// Remover livro
void removerLivro(Livro **lista, int codigo) {
    Livro *aux = *lista;

    while (aux != NULL && aux->codigo != codigo) {
        aux = aux->proximo;
    }

    if (aux == NULL) {
        printf("Livro nao encontrado!\n");
        return;
    }

    if (aux->anterior != NULL)
        aux->anterior->proximo = aux->proximo;
    else
        *lista = aux->proximo;

    if (aux->proximo != NULL)
        aux->proximo->anterior = aux->anterior;

    free(aux);
    printf("Livro removido com sucesso!\n");
}

// Buscar livro
void buscarLivro(Livro *lista, int codigo) {
    Livro *aux = lista;

    while (aux != NULL) {
        if (aux->codigo == codigo) {
            printf("\nLivro encontrado:\n");
            printf("Codigo: %d\n", aux->codigo);
            printf("Titulo: %s\n", aux->titulo);
            printf("Autor: %s\n", aux->autor);
            printf("Ano: %d\n", aux->ano);
            printf("Quantidade: %d\n\n", aux->quantidade);
            return;
        }
        aux = aux->proximo;
    }

    printf("Livro nao encontrado!\n");
}

// Imprimir lista normal
void imprimirLista(Livro *lista) {
    Livro *aux = lista;

    if (aux == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (aux != NULL) {
        printf("\nCodigo: %d\n", aux->codigo);
        printf("Titulo: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Ano: %d\n", aux->ano);
        printf("Quantidade: %d\n", aux->quantidade);

        aux = aux->proximo;
    }
}

// Imprimir lista reversa
void imprimirListaReversa(Livro *lista) {
    Livro *aux = lista;

    if (aux == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }

    while (aux != NULL) {
        printf("\nCodigo: %d\n", aux->codigo);
        printf("Titulo: %s\n", aux->titulo);
        printf("Autor: %s\n", aux->autor);
        printf("Ano: %d\n", aux->ano);
        printf("Quantidade: %d\n", aux->quantidade);

        aux = aux->anterior;
    }
}

// Contar elementos
int contarElementos(Livro *lista) {
    int count = 0;
    Livro *aux = lista;

    while (aux != NULL) {
        count++;
        aux = aux->proximo;
    }

    return count;
}

// Liberar memória
void liberarLista(Livro *lista) {
    Livro *aux;

    while (lista != NULL) {
        aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}

// Programa principal
int main() {
    Livro *lista = criarLista();
    int opcao, codigo;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Remover livro\n");
        printf("4 - Buscar livro\n");
        printf("5 - Listar (normal)\n");
        printf("6 - Listar (reversa)\n");
        printf("7 - Quantidade de livros\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirInicio(&lista);
                break;

            case 2:
                inserirFinal(&lista);
                break;

            case 3:
                printf("Codigo do livro: ");
                scanf("%d", &codigo);
                removerLivro(&lista, codigo);
                break;

            case 4:
                printf("Codigo do livro: ");
                scanf("%d", &codigo);
                buscarLivro(lista, codigo);
                break;

            case 5:
                imprimirLista(lista);
                break;

            case 6:
                imprimirListaReversa(lista);
                break;

            case 7:
                printf("Total de livros: %d\n", contarElementos(lista));
                break;

            case 0:
                liberarLista(lista);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}