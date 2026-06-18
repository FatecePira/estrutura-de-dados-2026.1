#include <stdio.h>
#include "lista_sequencial.h"

void inicializar_lista_sequencial(ListaSequencial *lista) {
    lista->quantidade = 0;
}

int lista_sequencial_vazia(const ListaSequencial *lista) {
    return lista->quantidade == 0;
}

int lista_sequencial_cheia(const ListaSequencial *lista) {
    return lista->quantidade == MAX_ELEMENTOS;
}

int inserir_lista_sequencial(ListaSequencial *lista, Elemento elemento, int posicao) {
    int i;

    if (lista_sequencial_cheia(lista)) {
        return 0;
    }

    if (posicao < 1 || posicao > lista->quantidade + 1) {
        return 0;
    }

    for (i = lista->quantidade; i >= posicao; i--) {
        lista->dados[i] = lista->dados[i - 1];
    }

    lista->dados[posicao - 1] = elemento;
    lista->quantidade++;
    return 1;
}

int remover_lista_sequencial(ListaSequencial *lista, int posicao, Elemento *removido) {
    int i;

    if (lista_sequencial_vazia(lista)) {
        return 0;
    }

    if (posicao < 1 || posicao > lista->quantidade) {
        return 0;
    }

    if (removido != NULL) {
        *removido = lista->dados[posicao - 1];
    }

    for (i = posicao - 1; i < lista->quantidade - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }

    lista->quantidade--;
    return 1;
}

int buscar_lista_sequencial_por_id(const ListaSequencial *lista, int id, Elemento *encontrado, int *posicao) {
    int i;

    for (i = 0; i < lista->quantidade; i++) {
        if (lista->dados[i].id == id) {
            if (encontrado != NULL) {
                *encontrado = lista->dados[i];
            }
            if (posicao != NULL) {
                *posicao = i + 1;
            }
            return 1;
        }
    }

    return 0;
}

void exibir_lista_sequencial(const ListaSequencial *lista) {
    int i;

    if (lista_sequencial_vazia(lista)) {
        printf("Lista sequencial vazia.\n");
        return;
    }

    printf("\n===== LISTA SEQUENCIAL =====\n");
    for (i = 0; i < lista->quantidade; i++) {
        printf("Posicao %d -> ID: %d | Nome: %s\n", i + 1, lista->dados[i].id, lista->dados[i].nome);
    }
}

int quantidade_lista_sequencial(const ListaSequencial *lista) {
    return lista->quantidade;
}
