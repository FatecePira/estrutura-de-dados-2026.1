#ifndef PILHA_H // Include Guard para proteger a declaracao da Pilha
#define PILHA_H

#include "comum.h" // Importa o padrao (Elemento e MAX)

typedef struct { // Estrutura baseada na regra LIFO (Last In, First Out)
    Elemento dados[MAX]; // Vetor estatico de 100 posicoes
    int topo;            // Indice que indica qual e a posicao do elemento que esta no topo (-1 se vazia)
} Pilha;                 // Apelida a struct como Pilha

// Prototipos das operacoes de pilha
void pi_inicializar(Pilha *p);               // Define o topo inicialmente como -1
int  pi_empilhar(Pilha *p, Elemento e);       // Push: avanca o topo e grava o elemento
int  pi_desempilhar(Pilha *p, Elemento *e);   // Pop: captura o topo no ponteiro *e e desce o topo
int  pi_topo(Pilha *p, Elemento *e);          // Peek: apenas espia o topo, mas nao altera o indice
void pi_exibir(Pilha *p);                    // Imprime a pilha desenhando verticalmente
int  pi_vazia(Pilha *p);                     // Verifica se topo == -1
int  pi_cheia(Pilha *p);                     // Verifica se topo chegou ao limite de MAX - 1
void menu_pilha(Pilha *p);                   // Controlador interativo (submenu) da pilha

#endif // Fim do Include Guard