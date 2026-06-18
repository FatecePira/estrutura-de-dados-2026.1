#ifndef PILHA_H
#define PILHA_H

#include "elemento.h"
#include "lista_sequencial.h"

typedef struct {
    Elemento dados[MAX_ELEMENTOS];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *pilha);
int pilha_vazia(const Pilha *pilha);
int pilha_cheia(const Pilha *pilha);
int empilhar(Pilha *pilha, Elemento elemento);
int desempilhar(Pilha *pilha, Elemento *removido);
int consultar_topo(const Pilha *pilha, Elemento *topo);
void exibir_pilha(const Pilha *pilha);
int quantidade_pilha(const Pilha *pilha);

#endif
