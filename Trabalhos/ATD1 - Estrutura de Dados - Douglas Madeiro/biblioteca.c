#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"


Biblioteca* criarLista(void) {
    Biblioteca* nova = (Biblioteca*) malloc(sizeof(Biblioteca));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    nova->primeiro = NULL;
    nova->ultimo = NULL;
    return nova;
}

Livro* criarLivro(int codigo, char* titulo, char* autor, int ano, int quantidade) {
    Livro* novo = (Livro*) malloc(sizeof(Livro));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    novo->codigo = codigo;
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->ano = ano;
    novo->quantidade = quantidade;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void inserirInicio(Biblioteca* lista, int codigo, char* titulo, char* autor, int ano, int quantidade) {
    if (lista == NULL) return;
    
    Livro* novo = criarLivro(codigo, titulo, autor, ano, quantidade);
    if (novo == NULL) return;

    if (lista->primeiro == NULL) {

        lista->primeiro = lista->ultimo = novo;
    } else {

        novo->proximo = lista->primeiro;
        lista->primeiro->anterior = novo;
        lista->primeiro = novo;
    }
    printf("Livro inserido no início com sucesso!\n");
}

void inserirFinal(Biblioteca* lista, int codigo, char* titulo, char* autor, int ano, int quantidade) {
    if (lista == NULL) return;
    
    Livro* novo = criarLivro(codigo, titulo, autor, ano, quantidade);
    if (novo == NULL) return;

    if (lista->ultimo == NULL) {

        lista->primeiro = lista->ultimo = novo;
    } else {

        novo->anterior = lista->ultimo;
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }
    printf("Livro inserido no final com sucesso!\n");
}

Livro* buscarLivro(Biblioteca* lista, int codigo) {
    if (lista == NULL || lista->primeiro == NULL) {
        return NULL;
    }
    
    Livro* atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->codigo == codigo)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void removerLivro(Biblioteca* lista, int codigo) {
    if (lista == NULL || lista->primeiro == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    Livro* atual = buscarLivro(lista, codigo);

    if (atual == NULL) {
        printf("Livro com código %d não encontrado!\n", codigo);
        return;
    }


    if (atual->anterior != NULL)
        atual->anterior->proximo = atual->proximo;
    else
        lista->primeiro = atual->proximo;

    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;
    else
        lista->ultimo = atual->anterior;

    free(atual);
    printf("Livro removido com sucesso!\n");
}

void imprimirLista(Biblioteca* lista) {
    if (lista == NULL || lista->primeiro == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    Livro* atual = lista->primeiro;
    int contador = 1;

    printf("\n========== LISTA DE LIVROS (ORDEM NORMAL) ==========\n");
    while (atual != NULL) {
        printf("\n--- Livro %d ---\n", contador);
        printf("Código: %d\n", atual->codigo);
        printf("Título: %s\n", atual->titulo);
        printf("Autor: %s\n", atual->autor);
        printf("Ano: %d\n", atual->ano);
        printf("Quantidade: %d\n", atual->quantidade);
        
        atual = atual->proximo;
        contador++;
    }
    printf("\n===================================================\n");
}

void imprimirListaReversa(Biblioteca* lista) {
    if (lista == NULL || lista->ultimo == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    Livro* atual = lista->ultimo;
    int contador = 1;

    printf("\n========== LISTA DE LIVROS (ORDEM REVERSA) ==========\n");
    while (atual != NULL) {
        printf("\n--- Livro %d ---\n", contador);
        printf("Código: %d\n", atual->codigo);
        printf("Título: %s\n", atual->titulo);
        printf("Autor: %s\n", atual->autor);
        printf("Ano: %d\n", atual->ano);
        printf("Quantidade: %d\n", atual->quantidade);
        
        atual = atual->anterior;
        contador++;
    }
    printf("\n===================================================\n");
}

int contarElementos(Biblioteca* lista) {
    if (lista == NULL) return 0;
    
    int count = 0;
    Livro* atual = lista->primeiro;

    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    return count;
}

void liberarLista(Biblioteca* lista) {
    if (lista == NULL) return;
    
    Livro* atual = lista->primeiro;

    while (atual != NULL) {
        Livro* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(lista);
}