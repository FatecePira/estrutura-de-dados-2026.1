#include <stdio.h>
#include <stdlib.h>
#include "lista_enc.h"
#include "utils.h"

void le_inicializar(ListaEnc *l) { l->inicio = NULL; l->tamanho = 0; }

void le_inserir_inicio(ListaEnc *l, int id, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) { printf("Memoria insuficiente!\n"); return; }
    novo->id = id; novo->valor = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;
    l->tamanho++;
    printf("Inserido no inicio.\n");
}

void le_inserir_fim(ListaEnc *l, int id, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) { printf("Memoria insuficiente!\n"); return; }
    novo->id = id; novo->valor = valor; novo->proximo = NULL;
    if (!l->inicio) { l->inicio = novo; }
    else {
        No *atual = l->inicio;
        while (atual->proximo) atual = atual->proximo;
        atual->proximo = novo;
    }
    l->tamanho++;
    printf("Inserido no fim.\n");
}

int le_remover(ListaEnc *l, int id) {
    if (!l->inicio) { printf("Lista vazia!\n"); return 0; }
    No *atual = l->inicio, *anterior = NULL;
    while (atual && atual->id != id) { anterior = atual; atual = atual->proximo; }
    if (!atual) { printf("ID %d nao encontrado.\n", id); return 0; }
    if (!anterior) l->inicio = atual->proximo;
    else anterior->proximo = atual->proximo;
    free(atual);
    l->tamanho--;
    printf("ID %d removido.\n", id);
    return 1;
}

void le_buscar(ListaEnc *l, int id) {
    No *atual = l->inicio;
    while (atual) {
        if (atual->id == id) { printf("Encontrado: ID=%d, Valor=%d\n", atual->id, atual->valor); return; }
        atual = atual->proximo;
    }
    printf("ID %d nao encontrado.\n", id);
}

void le_exibir(ListaEnc *l) {
    if (!l->inicio) { printf("Lista vazia!\n"); return; }
    printf("Lista encadeada:\n");
    No *atual = l->inicio;
    while (atual) { printf("  ID=%d, Valor=%d\n", atual->id, atual->valor); atual = atual->proximo; }
}

void menu_lista_enc(ListaEnc *l) {
    int op, id, val;
    do {
        printf("\n===== LISTA ENCADEADA =====\n");
        printf("1 - Inserir no inicio\n2 - Inserir no fim\n3 - Remover por ID\n4 - Buscar por ID\n5 - Exibir lista\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1: printf("ID: "); id = ler_inteiro(); if(id==-99) break; printf("Valor: "); val = ler_inteiro(); if(val==-99) break; le_inserir_inicio(l,id,val); break;
            case 2: printf("ID: "); id = ler_inteiro(); if(id==-99) break; printf("Valor: "); val = ler_inteiro(); if(val==-99) break; le_inserir_fim(l,id,val); break;
            case 3: printf("ID: "); id = ler_inteiro(); if(id==-99) break; le_remover(l,id); break;
            case 4: printf("ID: "); id = ler_inteiro(); if(id==-99) break; le_buscar(l,id); break;
            case 5: le_exibir(l); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
