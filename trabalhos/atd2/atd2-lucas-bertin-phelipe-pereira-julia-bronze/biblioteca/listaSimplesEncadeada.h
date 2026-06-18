#ifndef LISTA_SIMPLES_ENCADEADA_H
#define LISTA_SIMPLES_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

// Definição do Nó da lista
typedef struct No
{
    int valor;
    struct No *proximo;
} No;

// Definição da Lista Encadeada para controle
typedef struct
{
    No *inicio;
    int quantidade; // Controla o limite de 100 elementos
} ListaEncadeada;

void inicializarListaEncadeada(ListaEncadeada *l);
int estaVaziaEncadeada(ListaEncadeada *l);
int inserirNoInicio(ListaEncadeada *l, int valor);
int inserirNoFim(ListaEncadeada *l, int valor);
int removerPorValor(ListaEncadeada *l, int valor);
int buscarEncadeada(ListaEncadeada *l, int valor);
void exibirEncadeada(ListaEncadeada *l);
void menuListaSimplesmenteEncadeada();

#endif // LISTA_SIMPLES_ENCADEADA_H