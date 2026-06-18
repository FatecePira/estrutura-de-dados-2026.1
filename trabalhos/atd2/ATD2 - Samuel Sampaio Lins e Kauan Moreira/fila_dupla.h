#ifndef FILA_DUPLA_H
#define FILA_DUPLA_H

#include "elemento.h"
#include "lista_sequencial.h"

typedef struct {
    Elemento dados[MAX_ELEMENTOS];
    int inicio;
    int fim;
    int quantidade;
} FilaDupla;

void inicializar_fila_dupla(FilaDupla *fila);
int fila_dupla_vazia(const FilaDupla *fila);
int fila_dupla_cheia(const FilaDupla *fila);
int inserir_inicio_fila_dupla(FilaDupla *fila, Elemento elemento);
int inserir_fim_fila_dupla(FilaDupla *fila, Elemento elemento);
int remover_inicio_fila_dupla(FilaDupla *fila, Elemento *removido);
int remover_fim_fila_dupla(FilaDupla *fila, Elemento *removido);
int consultar_inicio_fila_dupla(const FilaDupla *fila, Elemento *inicio);
int consultar_fim_fila_dupla(const FilaDupla *fila, Elemento *fim);
void exibir_fila_dupla(const FilaDupla *fila);
int quantidade_fila_dupla(const FilaDupla *fila);

#endif
