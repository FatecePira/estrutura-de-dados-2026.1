#ifndef FILA_DUPLA_H
#define FILA_DUPLA_H

#include "tipos.h"

typedef struct {
    Elemento dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaDupla;

void fd_inicializar(FilaDupla *f);
int  fd_inserir_inicio(FilaDupla *f, Elemento e);
int  fd_inserir_fim(FilaDupla *f, Elemento e);
int  fd_remover_inicio(FilaDupla *f);
int  fd_remover_fim(FilaDupla *f);
int  fd_consultar_inicio(FilaDupla *f);
int  fd_consultar_fim(FilaDupla *f);
void fd_exibir(FilaDupla *f);
int  fd_vazia(FilaDupla *f);
int  fd_cheia(FilaDupla *f);
void menu_fila_dupla(FilaDupla *f);

#endif
