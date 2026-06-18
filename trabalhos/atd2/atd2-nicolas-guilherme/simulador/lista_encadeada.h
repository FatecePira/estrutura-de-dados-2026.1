#ifndef LISTA_ENC_H
#define LISTA_ENC_H

#include "tipos.h"

typedef struct No {
    Elemento dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} ListaEnc;

void le_inicializar(ListaEnc *l);
void le_inserir_inicio(ListaEnc *l, Elemento e);
void le_inserir_fim(ListaEnc *l, Elemento e);
int  le_remover_por_id(ListaEnc *l, int id);
int  le_buscar(ListaEnc *l, int id);
void le_listar(ListaEnc *l);
int  le_vazia(ListaEnc *l);
void menu_lista_enc(ListaEnc *l);

#endif
