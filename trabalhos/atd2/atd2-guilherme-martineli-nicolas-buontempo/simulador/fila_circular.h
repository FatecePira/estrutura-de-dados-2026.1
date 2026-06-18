#ifndef FILA_CIRC_H
#define FILA_CIRC_H

#include "tipos.h"

typedef struct {
    Elemento dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void fc_inicializar(FilaCircular *f);
int  fc_enfileirar(FilaCircular *f, Elemento e);
int  fc_desenfileirar(FilaCircular *f);
int  fc_consultar_inicio(FilaCircular *f);
int  fc_consultar_fim(FilaCircular *f);
void fc_exibir(FilaCircular *f);
int  fc_vazia(FilaCircular *f);
int  fc_cheia(FilaCircular *f);
void menu_fila_circular(FilaCircular *f);

#endif
