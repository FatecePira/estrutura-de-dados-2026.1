#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TEXTO 100

typedef struct Livro {
    int codigo;
    char titulo[TAM_TEXTO];
    char autor[TAM_TEXTO];
    int ano;
    int quantidade;
    struct Livro *prox;
    struct Livro *ant;
} Livro;

typedef struct {
    Livro *inicio;
    Livro *fim;
} Lista;

Lista* criarLista() {
    Lista *lista = malloc(sizeof(Lista));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

Livro* criarLivro() {
    Livro *novo = malloc(sizeof(Livro));
    if (!novo) return NULL;

    printf("Codigo do livro: ");
    scanf("%d", &novo->codigo);
    getchar();

    printf("Titulo do livro: ");
    fgets(novo->titulo, TAM_TEXTO, stdin);
    novo->titulo[strcspn(novo->titulo, "\n")] = '\0';

    printf("Autor do livro: ");
    fgets(novo->autor, TAM_TEXTO, stdin);
    novo->autor[strcspn(novo->autor, "\n")] = '\0';

    printf("Ano de publicacao: ");
    scanf("%d", &novo->ano);

    printf("Quantidade de exemplares: ");
    scanf("%d", &novo->quantidade);

    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void inserirInicio(Lista *lista) {
    Livro *novo = criarLivro();
    if (!novo) return;

    if (!lista->inicio) {
        lista->inicio = lista->fim = novo;
        return;
    }

    novo->prox = lista->inicio;
    lista->inicio->ant = novo;
    lista->inicio = novo;
}

void inserirFinal(Lista *lista) {
    Livro *novo = criarLivro();
    if (!novo) return;

    if (!lista->fim) {
        lista->inicio = lista->fim = novo;
        return;
    }

    novo->ant = lista->fim;
    lista->fim->prox = novo;
    lista->fim = novo;
}

Livro* buscarLivro(Lista *lista, int codigo) {
    for (Livro *aux = lista->inicio; aux; aux = aux->prox)
        if (aux->codigo == codigo)
            return aux;
    return NULL;
}

void removerLivro(Lista *lista) {
    int codigo;
    printf("Informe o codigo do livro a remover: ");
    scanf("%d", &codigo);

    Livro *remover = buscarLivro(lista, codigo);
    if (!remover) {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (remover->ant)
        remover->ant->prox = remover->prox;
    else
        lista->inicio = remover->prox;

    if (remover->prox)
        remover->prox->ant = remover->ant;
    else
        lista->fim = remover->ant;

    free(remover);
}

void imprimirLivro(Livro *l) {
    printf("\nCodigo: %d", l->codigo);
    printf("\nTitulo: %s", l->titulo);
    printf("\nAutor: %s", l->autor);
    printf("\nAno: %d", l->ano);
    printf("\nQuantidade: %d", l->quantidade);
    printf("\n------------------------");
}

void imprimirLista(Lista *lista) {
    if (!lista->inicio) {
        printf("Lista vazia.\n");
        return;
    }

    for (Livro *aux = lista->inicio; aux; aux = aux->prox)
        imprimirLivro(aux);
}

void imprimirListaReversa(Lista *lista) {
    if (!lista->fim) {
        printf("Lista vazia.\n");
        return;
    }

    for (Livro *aux = lista->fim; aux; aux = aux->ant)
        imprimirLivro(aux);
}

int contarElementos(Lista *lista) {
    int count = 0;
    for (Livro *aux = lista->inicio; aux; aux = aux->prox)
        count++;
    return count;
}

void liberarLista(Lista *lista) {
    Livro *aux = lista->inicio;
    while (aux) {
        Livro *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(lista);
}

int main() {
    Lista *lista = criarLista();
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir livro no inicio\n");
        printf("2 - Inserir livro no final\n");
        printf("3 - Remover livro\n");
        printf("4 - Buscar livro\n");
        printf("5 - Listar livros (ordem normal)\n");
        printf("6 - Listar livros (ordem reversa)\n");
        printf("7 - Quantidade de livros\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirInicio(lista);
                break;
            case 2:
                inserirFinal(lista);
                break;
            case 3:
                removerLivro(lista);
                break;
            case 4: {
                int codigo;
                printf("Informe o codigo do livro: ");
                scanf("%d", &codigo);
                Livro *l = buscarLivro(lista, codigo);
                if (l)
                    imprimirLivro(l);
                else
                    printf("Livro nao encontrado.\n");
                break;
            }
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
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
