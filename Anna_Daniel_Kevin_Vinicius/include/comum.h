#ifndef COMUM_H // Include Guard: Verifica se COMUM_H ainda nao foi definido nesta compilacao
#define COMUM_H // Define COMUM_H para impedir que este arquivo seja processado mais de uma vez

#include <stdio.h>   // Inclui a biblioteca padrao de entrada/saida (printf, scanf)
#include <stdlib.h>  // Inclui a biblioteca para alocacao dinamica de memoria e controle (malloc, free)
#include <string.h>  // Inclui a biblioteca para manipulacao de strings (strcspn)

#define MAX 100 // Define a constante global que limita todas as estruturas a 100 elementos

// Elemento generico armazenado nas estruturas
typedef struct { // Define o registro (struct) padrao que vai trafegar no sistema
    int id;             // Identificador unico do elemento
    char dados[50];     // Vetor de caracteres para guardar a descricao ou nome (string)
    int prioridade;     // Usado exclusivamente na fila de prioridade para ditar a urgencia
} Elemento;             // Apelida a struct como 'Elemento'

// Utilitarios
void limpar_buffer(void);           // Prototipo: promete uma funcao que limpa o lixo de memoria do teclado
void pausar(void);                  // Prototipo: promete uma funcao que pausa a tela ate apertar ENTER
void imprimir_elemento(Elemento e); // Prototipo: promete uma funcao que exibe o Elemento formatado

#endif // Encerra a protecao do Include Guard