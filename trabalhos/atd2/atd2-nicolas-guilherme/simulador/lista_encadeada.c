#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

void le_inicializar(ListaEnc *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

int le_vazia(ListaEnc *l) {
    return l->inicio == NULL;
}

void le_inserir_inicio(ListaEnc *l, Elemento e) {
    if (l->tamanho >= MAX) {
        printf("  ERRO: Lista cheia!\n");
        return;
    }
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = e;
    novo->proximo = l->inicio;
    l->inicio = novo;
    l->tamanho++;
    printf("  Elemento inserido no inicio.\n");
}

void le_inserir_fim(ListaEnc *l, Elemento e) {
    if (l->tamanho >= MAX) {
        printf("  ERRO: Lista cheia!\n");
        return;
    }
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = e;
    novo->proximo = NULL;
    if (le_vazia(l)) {
        l->inicio = novo;
    } else {
        No *atual = l->inicio;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo;
    }
    l->tamanho++;
    printf("  Elemento inserido no fim.\n");
}

int le_remover_por_id(ListaEnc *l, int id) {
    if (le_vazia(l)) {
        printf("  ERRO: Lista vazia!\n");
        return 0;
    }
    No *atual = l->inicio, *anterior = NULL;
    while (atual != NULL && atual->dado.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("  ID %d nao encontrado.\n", id);
        return 0;
    }
    printf("  Removido: ");
    imprimir_elemento(atual->dado);
    if (anterior == NULL)
        l->inicio = atual->proximo;
    else
        anterior->proximo = atual->proximo;
    free(atual);
    l->tamanho--;
    return 1;
}

int le_buscar(ListaEnc *l, int id) {
    No *atual = l->inicio;
    int pos = 0;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            printf("  Encontrado na posicao %d: ", pos);
            imprimir_elemento(atual->dado);
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    printf("  ID %d nao encontrado.\n", id);
    return -1;
}

void le_listar(ListaEnc *l) {
    if (le_vazia(l)) {
        printf("  Lista vazia.\n");
        return;
    }
    No *atual = l->inicio;
    int i = 0;
    printf("  Lista encadeada (%d elemento(s)):\n", l->tamanho);
    while (atual != NULL) {
        printf("  [%d] -> ", i++);
        imprimir_elemento(atual->dado);
        atual = atual->proximo;
    }
}

void menu_lista_enc(ListaEnc *l) {
    int op, id;
    Elemento e;
    do {
        printf("\n===== MENU: LISTA ENCADEADA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover por ID\n");
        printf("4 - Buscar por ID\n");
        printf("5 - Exibir lista\n");
        printf("6 - Verificar se esta vazia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                e = ler_elemento();
                le_inserir_inicio(l, e);
                break;
            case 2:
                e = ler_elemento();
                le_inserir_fim(l, e);
                break;
            case 3:
                printf("  ID a remover: ");
                scanf("%d", &id);
                le_remover_por_id(l, id);
                break;
            case 4:
                printf("  ID a buscar: ");
                scanf("%d", &id);
                le_buscar(l, id);
                break;
            case 5:
                le_listar(l);
                break;
            case 6:
                printf("  Lista %s vazia.\n", le_vazia(l) ? "esta" : "nao esta");
                break;
            case 0:
                break;
            default:
                printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
