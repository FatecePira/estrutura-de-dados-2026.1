#ifndef FILA_PRIOR_H
#define FILA_PRIOR_H

#include "tipos.h"

typedef struct {
    Elemento dados[MAX];
    int tamanho;
} FilaPrioridade;

void fp_inicializar(FilaPrioridade *f);
int  fp_inserir(FilaPrioridade *f, Elemento e);
int  fp_remover(FilaPrioridade *f);
int  fp_consultar_proximo(FilaPrioridade *f);
void fp_exibir(FilaPrioridade *f);
int  fp_vazia(FilaPrioridade *f);
int  fp_cheia(FilaPrioridade *f);
void menu_fila_prioridade(FilaPrioridade *f);

#endif
