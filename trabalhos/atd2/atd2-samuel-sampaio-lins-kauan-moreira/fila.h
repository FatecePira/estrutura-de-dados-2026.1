#ifndef FILA_H
#define FILA_H

#include "elemento.h"
#include "lista_sequencial.h"

typedef struct {
    Elemento dados[MAX_ELEMENTOS];
    int quantidade;
} Fila;

void inicializar_fila(Fila *fila);
int fila_vazia(const Fila *fila);
int fila_cheia(const Fila *fila);
int enfileirar(Fila *fila, Elemento elemento);
int desenfileirar(Fila *fila, Elemento *removido);
int consultar_inicio_fila(const Fila *fila, Elemento *inicio);
void exibir_fila(const Fila *fila);
int quantidade_fila(const Fila *fila);

#endif
