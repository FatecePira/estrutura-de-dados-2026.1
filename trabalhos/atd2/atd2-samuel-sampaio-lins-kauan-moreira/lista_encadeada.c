#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

void inicializar_lista_encadeada(ListaEncadeada *lista) {
    lista->inicio = NULL;
    lista->quantidade = 0;
}

int lista_encadeada_vazia(const ListaEncadeada *lista) {
    return lista->inicio == NULL;
}

int lista_encadeada_cheia(const ListaEncadeada *lista) {
    return lista->quantidade == MAX_ELEMENTOS;
}

static No *criar_no(Elemento elemento) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }
    novo->dado = elemento;
    novo->proximo = NULL;
    return novo;
}

int inserir_inicio_lista_encadeada(ListaEncadeada *lista, Elemento elemento) {
    No *novo;

    if (lista_encadeada_cheia(lista)) {
        return 0;
    }

    novo = criar_no(elemento);
    if (novo == NULL) {
        return 0;
    }

    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->quantidade++;
    return 1;
}

int inserir_fim_lista_encadeada(ListaEncadeada *lista, Elemento elemento) {
    No *novo;
    No *atual;

    if (lista_encadeada_cheia(lista)) {
        return 0;
    }

    novo = criar_no(elemento);
    if (novo == NULL) {
        return 0;
    }

    if (lista_encadeada_vazia(lista)) {
        lista->inicio = novo;
    } else {
        atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }

    lista->quantidade++;
    return 1;
}

int remover_lista_encadeada_por_id(ListaEncadeada *lista, int id, Elemento *removido) {
    No *atual;
    No *anterior;

    if (lista_encadeada_vazia(lista)) {
        return 0;
    }

    atual = lista->inicio;
    anterior = NULL;

    while (atual != NULL && atual->dado.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return 0;
    }

    if (removido != NULL) {
        *removido = atual->dado;
    }

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->quantidade--;
    return 1;
}

int buscar_lista_encadeada_por_id(const ListaEncadeada *lista, int id, Elemento *encontrado) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->dado.id == id) {
            if (encontrado != NULL) {
                *encontrado = atual->dado;
            }
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

void exibir_lista_encadeada(const ListaEncadeada *lista) {
    No *atual = lista->inicio;
    int posicao = 1;

    if (lista_encadeada_vazia(lista)) {
        printf("Lista simplesmente encadeada vazia.\n");
        return;
    }

    printf("\n===== LISTA SIMPLESMENTE ENCADEADA =====\n");
    while (atual != NULL) {
        printf("No %d -> ID: %d | Nome: %s\n", posicao, atual->dado.id, atual->dado.nome);
        atual = atual->proximo;
        posicao++;
    }
}

int quantidade_lista_encadeada(const ListaEncadeada *lista) {
    return lista->quantidade;
}

void liberar_lista_encadeada(ListaEncadeada *lista) {
    No *atual = lista->inicio;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->quantidade = 0;
}
