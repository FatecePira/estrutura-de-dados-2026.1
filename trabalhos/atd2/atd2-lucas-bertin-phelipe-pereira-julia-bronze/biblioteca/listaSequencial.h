#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Limite máximo de elementos exigido pelo enunciado
// Definição da estrutura do elemento
typedef struct
{

    int valor;
} Elemento;
// Definição da Lista Sequencial
typedef struct
{
    Elemento dados[MAX];
    int quantidade;
} ListaSequencial;

void inicializarListaSequencial(ListaSequencial *l);
int estaVaziaSequencial(ListaSequencial *l);
int estaCheiaSequencial(ListaSequencial *l);
int inserirSequencial(ListaSequencial *l, int posicao, Elemento e);
int removerSequencial(ListaSequencial *l, int posicao);
int buscarSequencial(ListaSequencial *l, int valor);
void exibirSequencial(ListaSequencial *l);
void menuListaSequencial();
