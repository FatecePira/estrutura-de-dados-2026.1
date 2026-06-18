#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

#include "tipos.h"

typedef struct {
    Elemento dados[MAX];
    int tamanho;
} ListaSeq;

void ls_inicializar(ListaSeq *l);
int  ls_inserir(ListaSeq *l, Elemento e, int posicao);
int  ls_remover(ListaSeq *l, int posicao);
int  ls_buscar(ListaSeq *l, int id);
void ls_listar(ListaSeq *l);
int  ls_tamanho(ListaSeq *l);
int  ls_vazia(ListaSeq *l);
void menu_lista_seq(ListaSeq *l);

#endif
