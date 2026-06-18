#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "elemento.h"
#include "lista_sequencial.h"

typedef struct {
    Elemento dados[MAX_ELEMENTOS];
    int quantidade;
} FilaPrioridade;

void inicializar_fila_prioridade(FilaPrioridade *fila);
int fila_prioridade_vazia(const FilaPrioridade *fila);
int fila_prioridade_cheia(const FilaPrioridade *fila);
int inserir_fila_prioridade(FilaPrioridade *fila, Elemento elemento);
int remover_maior_prioridade(FilaPrioridade *fila, Elemento *removido);
int consultar_proximo_prioridade(const FilaPrioridade *fila, Elemento *proximo);
void exibir_fila_prioridade(const FilaPrioridade *fila);
int quantidade_fila_prioridade(const FilaPrioridade *fila);

#endif
