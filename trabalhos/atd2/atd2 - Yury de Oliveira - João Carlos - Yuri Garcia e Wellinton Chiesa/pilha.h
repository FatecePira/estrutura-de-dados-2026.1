#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void p_inicializar(Pilha *p);
int  p_empilhar(Pilha *p, int valor);
int  p_desempilhar(Pilha *p);
void p_topo(Pilha *p);
void p_exibir(Pilha *p);
void menu_pilha(Pilha *p);

#endif
