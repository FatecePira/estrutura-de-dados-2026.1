#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "elemento.h"
#include "lista_sequencial.h"

typedef struct No {
    Elemento dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int quantidade;
} ListaEncadeada;

void inicializar_lista_encadeada(ListaEncadeada *lista);
int lista_encadeada_vazia(const ListaEncadeada *lista);
int lista_encadeada_cheia(const ListaEncadeada *lista);
int inserir_inicio_lista_encadeada(ListaEncadeada *lista, Elemento elemento);
int inserir_fim_lista_encadeada(ListaEncadeada *lista, Elemento elemento);
int remover_lista_encadeada_por_id(ListaEncadeada *lista, int id, Elemento *removido);
int buscar_lista_encadeada_por_id(const ListaEncadeada *lista, int id, Elemento *encontrado);
void exibir_lista_encadeada(const ListaEncadeada *lista);
int quantidade_lista_encadeada(const ListaEncadeada *lista);
void liberar_lista_encadeada(ListaEncadeada *lista);

#endif
