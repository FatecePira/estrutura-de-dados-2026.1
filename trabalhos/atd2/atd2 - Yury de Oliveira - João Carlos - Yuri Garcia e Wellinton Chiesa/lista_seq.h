#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

#define MAX 100

typedef struct {
    int id;
    int valor;
} Elemento;

typedef struct {
    Elemento dados[MAX];
    int tamanho;
} ListaSeq;

void ls_inicializar(ListaSeq *l);
int  ls_inserir(ListaSeq *l, int posicao, int id, int valor);
int  ls_remover(ListaSeq *l, int posicao);
int  ls_buscar(ListaSeq *l, int id);
void ls_exibir(ListaSeq *l);
void menu_lista_seq(ListaSeq *l);

#endif
