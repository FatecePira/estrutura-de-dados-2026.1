#include <stdio.h>
#include "fila_prioridade.h"

void inicializar_fila_prioridade(FilaPrioridade *fila) {
    fila->quantidade = 0;
}

int fila_prioridade_vazia(const FilaPrioridade *fila) {
    return fila->quantidade == 0;
}

int fila_prioridade_cheia(const FilaPrioridade *fila) {
    return fila->quantidade == MAX_ELEMENTOS;
}

int inserir_fila_prioridade(FilaPrioridade *fila, Elemento elemento) {
    int posicao;

    if (fila_prioridade_cheia(fila)) {
        return 0;
    }

    posicao = fila->quantidade;

    /* Ordem decrescente: maior prioridade fica no inicio.
       Em prioridades iguais, mantem a ordem de chegada. */
    while (posicao > 0 && elemento.prioridade > fila->dados[posicao - 1].prioridade) {
        fila->dados[posicao] = fila->dados[posicao - 1];
        posicao--;
    }

    fila->dados[posicao] = elemento;
    fila->quantidade++;

    return 1;
}

int remover_maior_prioridade(FilaPrioridade *fila, Elemento *removido) {
    int i;

    if (fila_prioridade_vazia(fila)) {
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

int consultar_proximo_prioridade(const FilaPrioridade *fila, Elemento *proximo) {
    if (fila_prioridade_vazia(fila)) {
        return 0;
    }

    if (proximo != NULL) {
        *proximo = fila->dados[0];
    }

    return 1;
}

void exibir_fila_prioridade(const FilaPrioridade *fila) {
    int i;

    if (fila_prioridade_vazia(fila)) {
        printf("Fila de prioridade vazia.\n");
        return;
    }

    printf("\n===== FILA DE PRIORIDADE [MAIOR -> MENOR] =====\n");
    for (i = 0; i < fila->quantidade; i++) {
        printf("ID: %d | Nome: %s | Prioridade: %d\n", fila->dados[i].id, fila->dados[i].nome, fila->dados[i].prioridade);
    }
}

int quantidade_fila_prioridade(const FilaPrioridade *fila) {
    return fila->quantidade;
}
