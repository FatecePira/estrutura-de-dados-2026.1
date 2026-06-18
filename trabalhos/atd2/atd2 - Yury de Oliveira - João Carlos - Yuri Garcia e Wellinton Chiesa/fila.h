#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio, fim, tamanho;
} Fila;

void f_inicializar(Fila *f);
int  f_enfileirar(Fila *f, int valor);
int  f_desenfileirar(Fila *f);
void f_inicio(Fila *f);
void f_exibir(Fila *f);
void menu_fila(Fila *f);

#endif
