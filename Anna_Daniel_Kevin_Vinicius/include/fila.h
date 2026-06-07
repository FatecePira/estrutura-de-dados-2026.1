#ifndef FILA_H // Include Guard: Impede dupla inclusao do cabecalho da Fila Simples
#define FILA_H

#include "comum.h" // Importa a base do sistema (struct Elemento, constante MAX)

typedef struct { // Estrutura de controle da Fila Simples (Regra FIFO - First In, First Out)
    Elemento dados[MAX]; // Vetor estatico para acomodar ate 100 Elementos na fila
    int inicio;          // Ponteiro (indice) que indica de onde o proximo dado sera lido/removido (Frente da fila)
    int fim;             // Ponteiro (indice) que indica onde o proximo dado sera inserido/escrito (Tras da fila)
    int tamanho;         // Contador da quantidade atual de elementos ativos na estrutura
} Fila;                  // Apelida a struct de controle como Fila

// Prototipos das operacoes da Fila Simples implementadas no fila.c
void fi_inicializar(Fila *f);                 // Inicializa inicio, fim e tamanho em zero
int  fi_enfileirar(Fila *f, Elemento e);      // Operacao Enqueue: insere o dado no 'fim' e avanca o indice
int  fi_desenfileirar(Fila *f, Elemento *e);  // Operacao Dequeue: retira o dado do 'inicio' e avanca o indice
int  fi_consultar_inicio(Fila *f, Elemento *e); // Peek: copia o dado do 'inicio' sem remove-lo da fila
void fi_exibir(Fila *f);                      // Imprime a fila completa visualmente
int  fi_vazia(Fila *f);                       // Retorna verdadeiro se tamanho for zero
int  fi_cheia(Fila *f);                       // Retorna verdadeiro se tamanho atingiu o limite MAX
void menu_fila(Fila *f);                      // Submenu de navegacao interativa para o usuario

#endif // Fim do Include Guard da FILA_H