#include <stdio.h>
#include "pilha.h"

void inicializar_pilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilha_vazia(const Pilha *pilha) {
    return pilha->topo == -1;
}

int pilha_cheia(const Pilha *pilha) {
    return pilha->topo == MAX_ELEMENTOS - 1;
}

int empilhar(Pilha *pilha, Elemento elemento) {
    if (pilha_cheia(pilha)) {
        return 0;
    }

    pilha->topo++;
    pilha->dados[pilha->topo] = elemento;
    return 1;
}

int desempilhar(Pilha *pilha, Elemento *removido) {
    if (pilha_vazia(pilha)) {
        return 0;
    }

    if (removido != NULL) {
        *removido = pilha->dados[pilha->topo];
    }

    pilha->topo--;
    return 1;
}

int consultar_topo(const Pilha *pilha, Elemento *topo) {
    if (pilha_vazia(pilha)) {
        return 0;
    }

    if (topo != NULL) {
        *topo = pilha->dados[pilha->topo];
    }

    return 1;
}

void exibir_pilha(const Pilha *pilha) {
    int i;

    if (pilha_vazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("\n===== PILHA [TOPO -> BASE] =====\n");
    for (i = pilha->topo; i >= 0; i--) {
        printf("ID: %d | Nome: %s\n", pilha->dados[i].id, pilha->dados[i].nome);
    }
}

int quantidade_pilha(const Pilha *pilha) {
    return pilha->topo + 1;
}
