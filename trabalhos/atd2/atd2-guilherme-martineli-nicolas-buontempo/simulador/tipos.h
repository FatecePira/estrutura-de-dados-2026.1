#ifndef TIPOS_H
#define TIPOS_H

#define MAX 100

typedef struct {
    int id;
    char nome[50];
    int prioridade;
} Elemento;

void imprimir_elemento(Elemento e);
Elemento ler_elemento();
Elemento ler_elemento_com_prioridade();

#endif
