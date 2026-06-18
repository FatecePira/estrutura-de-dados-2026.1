#ifndef PILHA_H
#define PILHA_H

#include "tipos.h"

typedef struct {
    Elemento dados[MAX];
    int topo;
} Pilha;

void pilha_inicializar(Pilha *p);
int  pilha_empilhar(Pilha *p, Elemento e);
int  pilha_desempilhar(Pilha *p);
int  pilha_topo(Pilha *p);
void pilha_exibir(Pilha *p);
int  pilha_vazia(Pilha *p);
int  pilha_cheia(Pilha *p);
void menu_pilha(Pilha *p);

#endif
