#include <stdio.h>
#include "fila_circular.h"

void inicializar_fila_circular(FilaCircular *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade = 0;
}

int fila_circular_vazia(const FilaCircular *fila) {
    return fila->quantidade == 0;
}

int fila_circular_cheia(const FilaCircular *fila) {
    return fila->quantidade == MAX_ELEMENTOS;
}

int enfileirar_circular(FilaCircular *fila, Elemento elemento) {
    if (fila_circular_cheia(fila)) {
        return 0;
    }

    fila->fim = (fila->fim + 1) % MAX_ELEMENTOS;
    fila->dados[fila->fim] = elemento;
    fila->quantidade++;
    return 1;
}

int desenfileirar_circular(FilaCircular *fila, Elemento *removido) {
    if (fila_circular_vazia(fila)) {
        return 0;
    }

    if (removido != NULL) {
        *removido = fila->dados[fila->inicio];
    }

    fila->inicio = (fila->inicio + 1) % MAX_ELEMENTOS;
    fila->quantidade--;

    if (fila->quantidade == 0) {
        fila->inicio = 0;
        fila->fim = -1;
    }

    return 1;
}

int consultar_inicio_fila_circular(const FilaCircular *fila, Elemento *inicio) {
    if (fila_circular_vazia(fila)) {
        return 0;
    }

    if (inicio != NULL) {
        *inicio = fila->dados[fila->inicio];
    }

    return 1;
}

int consultar_fim_fila_circular(const FilaCircular *fila, Elemento *fim) {
    if (fila_circular_vazia(fila)) {
        return 0;
    }

    if (fim != NULL) {
        *fim = fila->dados[fila->fim];
    }

    return 1;
}

void exibir_fila_circular(const FilaCircular *fila) {
    int i;
    int indice;

    if (fila_circular_vazia(fila)) {
        printf("Fila circular vazia.\n");
        return;
    }

    printf("\n===== FILA CIRCULAR [INICIO -> FIM] =====\n");
    printf("Indice inicio: %d | Indice fim: %d\n", fila->inicio, fila->fim);

    for (i = 0; i < fila->quantidade; i++) {
        indice = (fila->inicio + i) % MAX_ELEMENTOS;
        printf("Indice %d -> ID: %d | Nome: %s\n", indice, fila->dados[indice].id, fila->dados[indice].nome);
    }
}

int quantidade_fila_circular(const FilaCircular *fila) {
    return fila->quantidade;
}
