#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include "elemento.h"
#include "lista_sequencial.h"

typedef struct {
    Elemento dados[MAX_ELEMENTOS];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

void inicializar_fila_circular(FilaCircular *fila);
int fila_circular_vazia(const FilaCircular *fila);
int fila_circular_cheia(const FilaCircular *fila);
int enfileirar_circular(FilaCircular *fila, Elemento elemento);
int desenfileirar_circular(FilaCircular *fila, Elemento *removido);
int consultar_inicio_fila_circular(const FilaCircular *fila, Elemento *inicio);
int consultar_fim_fila_circular(const FilaCircular *fila, Elemento *fim);
void exibir_fila_circular(const FilaCircular *fila);
int quantidade_fila_circular(const FilaCircular *fila);

#endif
