#ifndef FILA_H
#define FILA_H

#include "tipos.h"

typedef struct {
    Elemento dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void fila_inicializar(Fila *f);
int  fila_enfileirar(Fila *f, Elemento e);
int  fila_desenfileirar(Fila *f);
int  fila_consultar_inicio(Fila *f);
void fila_exibir(Fila *f);
int  fila_vazia(Fila *f);
int  fila_cheia(Fila *f);
void menu_fila(Fila *f);

#endif
