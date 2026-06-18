#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include "elemento.h"

#define MAX_ELEMENTOS 100

typedef struct {
    Elemento dados[MAX_ELEMENTOS];
    int quantidade;
} ListaSequencial;

void inicializar_lista_sequencial(ListaSequencial *lista);
int lista_sequencial_vazia(const ListaSequencial *lista);
int lista_sequencial_cheia(const ListaSequencial *lista);
int inserir_lista_sequencial(ListaSequencial *lista, Elemento elemento, int posicao);
int remover_lista_sequencial(ListaSequencial *lista, int posicao, Elemento *removido);
int buscar_lista_sequencial_por_id(const ListaSequencial *lista, int id, Elemento *encontrado, int *posicao);
void exibir_lista_sequencial(const ListaSequencial *lista);
int quantidade_lista_sequencial(const ListaSequencial *lista);

#endif
