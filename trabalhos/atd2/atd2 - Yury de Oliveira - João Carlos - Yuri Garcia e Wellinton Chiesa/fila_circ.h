#ifndef FILA_CIRC_H
#define FILA_CIRC_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio, fim, tamanho;
} FilaCirc;

void fc_inicializar(FilaCirc *f);
int  fc_enfileirar(FilaCirc *f, int valor);
int  fc_desenfileirar(FilaCirc *f);
void fc_exibir(FilaCirc *f);
void menu_fila_circ(FilaCirc *f);

#endif
