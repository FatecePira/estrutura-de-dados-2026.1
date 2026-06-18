#ifndef FILA_DUPLA_H
#define FILA_DUPLA_H

#define TAM_FILA_DUPLA 100

typedef struct {
    int dados[TAM_FILA_DUPLA];
    int inicio;
    int fim;
    int quantidade;
} FilaDupla;


void inicializarFilaDupla(FilaDupla *f);
int filaEstaVaziaDupla(FilaDupla *f);
int filaEstaCheiaDupla(FilaDupla *f);
void inserirInicio(FilaDupla *f);
void inserirFim(FilaDupla *f);
void removerInicio(FilaDupla *f);
void removerFim(FilaDupla *f);
void consultarInicio(FilaDupla *f);
void consultarFim(FilaDupla *f);
void exibirFilaDupla(FilaDupla *f);
void menuFilaDupla();

#endif