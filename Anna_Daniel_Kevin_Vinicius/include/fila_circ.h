#ifndef FILA_CIRC_H // Include Guard para a Fila Circular
#define FILA_CIRC_H

#include "comum.h" // Importa dados base do projeto

typedef struct { // Estrutura da Fila Circular (Resolve o problema de desperdicio de espaco da fila simples)
    Elemento dados[MAX]; // Vetor base de 100 posicoes
    int inicio;          // Indice de leitura (avanca de forma circular usando % MAX)
    int fim;             // Indice de escrita (avanca de forma circular usando % MAX)
    int tamanho;         // Controle rigoroso de lotacao (crucial pois os ponteiros dao voltas no vetor)
} FilaCircular;          // Apelida a struct como FilaCircular

// Prototipos das operacoes da Fila Circular implementadas no fila_circ.c
void fc_inicializar(FilaCircular *fc);                 // Zera os indices e o tamanho
int  fc_enfileirar(FilaCircular *fc, Elemento e);      // Insere no 'fim' e aplica % MAX para rotacionar
int  fc_desenfileirar(FilaCircular *fc, Elemento *e);  // Retira do 'inicio' e aplica % MAX para rotacionar
int  fc_consultar_inicio(FilaCircular *fc, Elemento *e); // Apenas le o valor no indice 'inicio'
int  fc_consultar_fim(FilaCircular *fc, Elemento *e);    // Calcula a posicao anterior ao 'fim' atual e espia
void fc_exibir(FilaCircular *fc);                      // Percorre imprimindo a partir do inicio de forma circular
int  fc_vazia(FilaCircular *fc);                       // Testa se tamanho == 0
int  fc_cheia(FilaCircular *fc);                       // Testa se tamanho == MAX
void menu_fila_circular(FilaCircular *fc);             // Submenu de controle para a Fila Circular

#endif // Fim do Include Guard da FILA_CIRC_H