#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#define TAM_FILA_PRIORIDADE 100

typedef struct {
    int valor;
    int prioridade;
} ElementoPrioridade;

typedef struct {
    ElementoPrioridade dados[TAM_FILA_PRIORIDADE];
    int quantidade;
} FilaPrioridade;


void inicializarFilaPrioridade(FilaPrioridade *f);
int filaPrioridadeEstaVazia(FilaPrioridade *f);
int filaPrioridadeEstaCheia(FilaPrioridade *f);
void inserirComPrioridade(FilaPrioridade *f);
void removerMaiorPrioridade(FilaPrioridade *f);
void consultarProximo(FilaPrioridade *f);
void exibirFilaPrioridade(FilaPrioridade *f);
void menuFilaDePrioridade();

#endif