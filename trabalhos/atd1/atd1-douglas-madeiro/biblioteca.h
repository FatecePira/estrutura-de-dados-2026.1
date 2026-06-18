#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;

    struct Livro* anterior;
    struct Livro* proximo;
} Livro;

typedef struct {
    Livro* primeiro;
    Livro* ultimo;
} Biblioteca;

Biblioteca* criarLista(void);
void inserirInicio(Biblioteca* lista, int codigo, char* titulo, char* autor, int ano, int quantidade);
void inserirFinal(Biblioteca* lista, int codigo, char* titulo, char* autor, int ano, int quantidade);
void removerLivro(Biblioteca* lista, int codigo);
Livro* buscarLivro(Biblioteca* lista, int codigo);
void imprimirLista(Biblioteca* lista);
void imprimirListaReversa(Biblioteca* lista);
int contarElementos(Biblioteca* lista);
void liberarLista(Biblioteca* lista);

#endif