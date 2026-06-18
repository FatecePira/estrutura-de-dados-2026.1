#include <stdio.h>
#include "lista_seq.h"
#include "utils.h"

void ls_inicializar(ListaSeq *l) {
    l->tamanho = 0;
}

int ls_inserir(ListaSeq *l, int posicao, int id, int valor) {
    if (l->tamanho >= MAX) { printf("Lista cheia!\n"); return 0; }
    if (posicao < 0 || posicao > l->tamanho) { printf("Posicao invalida!\n"); return 0; }
    for (int i = l->tamanho; i > posicao; i--)
        l->dados[i] = l->dados[i-1];
    l->dados[posicao].id = id;
    l->dados[posicao].valor = valor;
    l->tamanho++;
    printf("Elemento inserido na posicao %d.\n", posicao);
    return 1;
}

int ls_remover(ListaSeq *l, int posicao) {
    if (l->tamanho == 0) { printf("Lista vazia!\n"); return 0; }
    if (posicao < 0 || posicao >= l->tamanho) { printf("Posicao invalida!\n"); return 0; }
    for (int i = posicao; i < l->tamanho - 1; i++)
        l->dados[i] = l->dados[i+1];
    l->tamanho--;
    printf("Elemento removido da posicao %d.\n", posicao);
    return 1;
}

int ls_buscar(ListaSeq *l, int id) {
    for (int i = 0; i < l->tamanho; i++)
        if (l->dados[i].id == id) { printf("ID %d encontrado na posicao %d, valor: %d\n", id, i, l->dados[i].valor); return i; }
    printf("ID %d nao encontrado.\n", id);
    return -1;
}

void ls_exibir(ListaSeq *l) {
    if (l->tamanho == 0) { printf("Lista vazia!\n"); return; }
    printf("Lista [%d elementos]:\n", l->tamanho);
    for (int i = 0; i < l->tamanho; i++)
        printf("  [%d] ID=%d, Valor=%d\n", i, l->dados[i].id, l->dados[i].valor);
}

void menu_lista_seq(ListaSeq *l) {
    int op, pos, id, val;
    do {
        printf("\n===== LISTA SEQUENCIAL =====\n");
        printf("1 - Inserir elemento\n2 - Remover elemento\n3 - Buscar por ID\n4 - Exibir lista\n5 - Quantidade de elementos\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1:
                printf("Posicao: "); pos = ler_inteiro(); if (pos == -99) break;
                printf("ID: ");      id  = ler_inteiro(); if (id  == -99) break;
                printf("Valor: ");   val = ler_inteiro(); if (val == -99) break;
                ls_inserir(l, pos, id, val); break;
            case 2:
                printf("Posicao: "); pos = ler_inteiro(); if (pos == -99) break;
                ls_remover(l, pos); break;
            case 3:
                printf("ID: "); id = ler_inteiro(); if (id == -99) break;
                ls_buscar(l, id); break;
            case 4: ls_exibir(l); break;
            case 5: printf("Quantidade: %d\n", l->tamanho); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
