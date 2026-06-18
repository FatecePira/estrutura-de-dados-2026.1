#ifndef FILA_H
#define FILA_H

#define TAM_FILA 100

typedef struct {
    int dados[TAM_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializarFila(Fila *f);
int filaEstaVazia(Fila *f);
int filaEstaCheia(Fila *f);
void enfileirarFila(Fila *f);
void desenfileirarFila(Fila *f);
void consultarInicioFila(Fila *f);
void exibirFila(Fila *f);
void menuFila();

#endif