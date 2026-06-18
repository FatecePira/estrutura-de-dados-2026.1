#ifndef PILHA_H
#define PILHA_H

#define TAM 100

typedef struct {
    int dados[TAM];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
int estaVaziaPilha(Pilha *p);
int estaCheiaPilha(Pilha *p);
int quantidadeElementosPilha(Pilha *p);

void inserirElementoPilha(Pilha *p);
void removerElementoPilha(Pilha *p);
void consultarElementoPilha(Pilha *p);
void exibirPilha(Pilha *p);

void menuPilha();

#endif