#ifndef FILA_DUPLA_H // Include Guard da Fila Dupla (Deque - Double Ended Queue)
#define FILA_DUPLA_H

#include "comum.h" // Importa as constantes e o tipo Elemento

typedef struct { // Estrutura que permite inserir e remover pelas duas extremidades
    Elemento dados[MAX]; // Vetor base de 100 elementos
    int inicio;          // Indice da extremidade inicial
    int fim;             // Indice da extremidade final
    int tamanho;         // Quantidade de dados no deque
} FilaDupla;             // Apelida como FilaDupla

// Prototipos das operacoes (O diferencial do Deque e ter 4 funcoes de movimentacao)
void fd_inicializar(FilaDupla *fd);                 // Reseta tudo para zero
int  fd_inserir_inicio(FilaDupla *fd, Elemento e);  // Recua o inicio circularmente e insere o dado
int  fd_inserir_fim(FilaDupla *fd, Elemento e);     // Insere o dado e avanca o fim circularmente
int  fd_remover_inicio(FilaDupla *fd, Elemento *e); // Pega o dado do inicio e avanca (encolhendo a fila)
int  fd_remover_fim(FilaDupla *fd, Elemento *e);    // Recua o fim e pega o dado (encolhendo a fila por tras)
int  fd_consultar_inicio(FilaDupla *fd, Elemento *e); // Apenas le a cabeca da fila
int  fd_consultar_fim(FilaDupla *fd, Elemento *e);    // Apenas le a cauda da fila
void fd_exibir(FilaDupla *fd);                      // Exibe o deque desenhando as setas de dupla direcao <->
int  fd_vazia(FilaDupla *fd);                       // Verifica se o tamanho esta zerado
int  fd_cheia(FilaDupla *fd);                       // Verifica se atingiu o teto MAX
void menu_fila_dupla(FilaDupla *fd);                // Submenu exclusivo da Fila Dupla

#endif // Fim do Include Guard da FILA_DUPLA_H