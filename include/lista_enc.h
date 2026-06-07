#ifndef LISTA_ENC_H // Include Guard para a lista encadeada
#define LISTA_ENC_H

#include "comum.h" // Importa as dependencias basicas (Elemento, MAX, stdio...)

typedef struct No { // Define a menor parte da lista (o Nó) como uma estrutura autorreferenciada
    Elemento dado;       // Onde fica guardada a informacao util do usuario
    struct No *proximo;  // Ponteiro que guarda o endereco RAM do proximo Nó da correnteza
} No;                    // Apelida a struct como No

typedef struct { // Estrutura principal que gerencia a lista dinamica
    No *cabeca;          // Ponteiro que sempre aponta para o primeiro Nó da lista
    int tamanho;         // Guarda a quantidade de Nós criados na memoria
} ListaEncadeada;        // Apelida como ListaEncadeada

// Prototipos das operacoes dinamicas
void le_inicializar(ListaEncadeada *le);                 // Aponta a cabeca para NULL
int  le_inserir_inicio(ListaEncadeada *le, Elemento e);  // Aloca Nó e poe na frente da lista
int  le_inserir_fim(ListaEncadeada *le, Elemento e);     // Aloca Nó, viaja ate o final e anexa
int  le_remover_por_id(ListaEncadeada *le, int id);      // Procura, desvia o ponteiro e da free()
int  le_buscar_por_id(ListaEncadeada *le, int id);       // Procura o id e exibe caso encontre
void le_exibir(ListaEncadeada *le);                     // Desenha a lista ( [A] -> [B] -> FIM )
int  le_vazia(ListaEncadeada *le);                       // Verifica se cabeca == NULL
void le_liberar(ListaEncadeada *le);                    // Percorre tudo dando free() para evitar memory leak
void menu_lista_encadeada(ListaEncadeada *le);           // Submenu interativo

#endif // Fim do Include Guard