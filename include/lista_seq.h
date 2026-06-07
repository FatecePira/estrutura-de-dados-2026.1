#ifndef LISTA_SEQ_H // Include Guard: Impede multiplas inclusoes deste cabecalho
#define LISTA_SEQ_H

#include "comum.h" // Importa a struct Elemento e a constante MAX (100)

typedef struct { // Estrutura de controle da Lista Sequencial
    Elemento dados[MAX]; // Vetor estatico contendo espaco continuo para 100 Elementos
    int tamanho;         // Inteiro que controla quantos itens validos estao salvos no momento
} ListaSequencial;       // Apelida a struct como ListaSequencial

// Prototipos das funcoes (As assinaturas de tudo que a lista sequencial sabe fazer)
void ls_inicializar(ListaSequencial *ls);                    // Inicializa o tamanho com zero
int  ls_inserir(ListaSequencial *ls, int posicao, Elemento e); // Insere o Elemento 'e' deslocando itens
int  ls_remover(ListaSequencial *ls, int posicao);           // Remove deslocando itens para tapar buraco
int  ls_buscar(ListaSequencial *ls, int id);                 // Busca um id e retorna a posicao
void ls_exibir(ListaSequencial *ls);                        // Lista todos os itens na tela
int  ls_tamanho(ListaSequencial *ls);                        // Retorna o numero de elementos atuais
int  ls_vazia(ListaSequencial *ls);                          // Retorna 1 se estiver vazia
void menu_lista_sequencial(ListaSequencial *ls);            // Exibe e controla o submenu desta estrutura

#endif // Fim do Include Guard