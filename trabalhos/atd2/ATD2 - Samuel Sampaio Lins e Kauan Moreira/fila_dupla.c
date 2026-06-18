#include <stdio.h>
#include "fila_dupla.h"

void inicializar_fila_dupla(FilaDupla *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade = 0;
}

int fila_dupla_vazia(const FilaDupla *fila) {
    return fila->quantidade == 0;
}

int fila_dupla_cheia(const FilaDupla *fila) {
    return fila->quantidade == MAX_ELEMENTOS;
}

int inserir_inicio_fila_dupla(FilaDupla *fila, Elemento elemento) {
    if (fila_dupla_cheia(fila)) {
        return 0;
    }

    if (fila_dupla_vazia(fila)) {
        fila->inicio = 0;
        fila->fim = 0;
    } else {
        fila->inicio = (fila->inicio - 1 + MAX_ELEMENTOS) % MAX_ELEMENTOS;
    }

    fila->dados[fila->inicio] = elemento;
    fila->quantidade++;
    return 1;
}

int inserir_fim_fila_dupla(FilaDupla *fila, Elemento elemento) {
    if (fila_dupla_cheia(fila)) {
        return 0;
    }

    if (fila_dupla_vazia(fila)) {
        fila->inicio = 0;
        fila->fim = 0;
    } else {
        fila->fim = (fila->fim + 1) % MAX_ELEMENTOS;
    }

    fila->dados[fila->fim] = elemento;
    fila->quantidade++;
    return 1;
}

int remover_inicio_fila_dupla(FilaDupla *fila, Elemento *removido) {
    if (fila_dupla_vazia(fila)) {
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

int remover_fim_fila_dupla(FilaDupla *fila, Elemento *removido) {
    if (fila_dupla_vazia(fila)) {
        return 0;
    }

    if (removido != NULL) {
        *removido = fila->dados[fila->fim];
    }

    fila->fim = (fila->fim - 1 + MAX_ELEMENTOS) % MAX_ELEMENTOS;
    fila->quantidade--;

    if (fila->quantidade == 0) {
        fila->inicio = 0;
        fila->fim = -1;
    }

    return 1;
}

int consultar_inicio_fila_dupla(const FilaDupla *fila, Elemento *inicio) {
    if (fila_dupla_vazia(fila)) {
        return 0;
    }

    if (inicio != NULL) {
        *inicio = fila->dados[fila->inicio];
    }

    return 1;
}

int consultar_fim_fila_dupla(const FilaDupla *fila, Elemento *fim) {
    if (fila_dupla_vazia(fila)) {
        return 0;
    }

    if (fim != NULL) {
        *fim = fila->dados[fila->fim];
    }

    return 1;
}

void exibir_fila_dupla(const FilaDupla *fila) {
    int i;
    int indice;

    if (fila_dupla_vazia(fila)) {
        printf("Fila dupla vazia.\n");
        return;
    }

    printf("\n===== FILA DUPLA [INICIO -> FIM] =====\n");
    for (i = 0; i < fila->quantidade; i++) {
        indice = (fila->inicio + i) % MAX_ELEMENTOS;
        printf("ID: %d | Nome: %s\n", fila->dados[indice].id, fila->dados[indice].nome);
    }
}

int quantidade_fila_dupla(const FilaDupla *fila) {
    return fila->quantidade;
}
