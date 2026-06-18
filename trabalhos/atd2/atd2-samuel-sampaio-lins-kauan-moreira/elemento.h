#ifndef ELEMENTO_H
#define ELEMENTO_H

#define TAM_NOME 50

typedef struct {
    int id;
    char nome[TAM_NOME];
    int prioridade;
} Elemento;

#endif
