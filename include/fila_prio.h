#ifndef FILA_PRIO_H // Include Guard para a Fila de Prioridade
#define FILA_PRIO_H

#include "comum.h" // Traz as definicoes basicas (aqui o campo e.prioridade sera muito usado)

typedef struct { // Estrutura baseada em prioridade (Quebra a regra basica de ordem de chegada/FIFO)
    Elemento dados[MAX]; // Vetor para guardar ate 100 itens. No nosso caso, fica desordenado.
    int tamanho;         // Unica variavel de controle necessaria, pois inserimos no final e removemos por busca.
} FilaPrioridade;        // Apelida a struct como FilaPrioridade

// Prototipos das operacoes implementadas no fila_prio.c
void fp_inicializar(FilaPrioridade *fp);               // Zera o tamanho
int  fp_inserir(FilaPrioridade *fp, Elemento e);       // Joga o dado no primeiro espaco livre ao final do vetor
int  fp_remover(FilaPrioridade *fp, Elemento *e);      // Busca linearmente o de MAIOR prioridade, remove e tampa buraco
int  fp_consultar_proximo(FilaPrioridade *fp, Elemento *e); // Descobre quem e o maior, mas apenas espia
void fp_exibir(FilaPrioridade *fp);                    // Exibe a fila ordenada (Maior pro Menor) usando Bubble Sort numa copia
int  fp_vazia(FilaPrioridade *fp);                     // Testa se o vetor esta sem itens
int  fp_cheia(FilaPrioridade *fp);                     // Testa se o vetor atingiu o limite global
void menu_fila_prioridade(FilaPrioridade *fp);         // Submenu interativo para gerenciar prioridades

#endif // Fim do Include Guard da FILA_PRIO_H