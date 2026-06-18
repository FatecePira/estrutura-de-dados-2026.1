#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#define TAM_FILA_CIRCULAR 100

typedef struct {
    int dados[TAM_FILA_CIRCULAR];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

// Funções principais
void inicializarFilaCircular(FilaCircular *f);
int filaEstaVaziaCircular(FilaCircular *f);
int filaEstaCheiaCircular(FilaCircular *f);

void enfileirarFilaCircular(FilaCircular *f);
void desenfileirarFilaCircular(FilaCircular *f);

void consultarInicioFilaCircular(FilaCircular *f);
void consultarFimFilaCircular(FilaCircular *f);

void exibirFilaCircular(FilaCircular *f);

void menuFilaCircular();

#endif