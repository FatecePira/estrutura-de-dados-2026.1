#include <stdio.h>
#include "fila.h"

void inicializar_fila(Fila *fila) {
    fila->quantidade = 0;
}

int fila_vazia(const Fila *fila) {
    return fila->quantidade == 0;
}

int fila_cheia(const Fila *fila) {
    return fila->quantidade == MAX_ELEMENTOS;
}

int enfileirar(Fila *fila, Elemento elemento) {
    if (fila_cheia(fila)) {
        return 0;
    }

    fila->dados[fila->quantidade] = elemento;
    fila->quantidade++;
    return 1;
}

int desenfileirar(Fila *fila, Elemento *removido) {
    int i;

    if (fila_vazia(fila)) {
        return 0;
    }

    if (removido != NULL) {
        *removido = fila->dados[0];
    }

    for (i = 0; i < fila->quantidade - 1; i++) {
        fila->dados[i] = fila->dados[i + 1];
    }

    fila->quantidade--;
    return 1;
}

int consultar_inicio_fila(const Fila *fila, Elemento *inicio) {
    if (fila_vazia(fila)) {
        return 0;
    }

    if (inicio != NULL) {
        *inicio = fila->dados[0];
    }

    return 1;
}

void exibir_fila(const Fila *fila) {
    int i;

    if (fila_vazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\n===== FILA [INICIO -> FIM] =====\n");
    for (i = 0; i < fila->quantidade; i++) {
        printf("ID: %d | Nome: %s\n", fila->dados[i].id, fila->dados[i].nome);
    }
}

int quantidade_fila(const Fila *fila) {
    return fila->quantidade;
}
