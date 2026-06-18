#include <stdio.h>
#include "pilha.h"

void pilha_inicializar(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int pilha_empilhar(Pilha *p, Elemento e) {
    if (pilha_cheia(p)) {
        printf("  ERRO: Pilha cheia!\n");
        return 0;
    }
    p->dados[++(p->topo)] = e;
    printf("  Elemento empilhado.\n");
    return 1;
}

int pilha_desempilhar(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("  ERRO: Pilha vazia!\n");
        return 0;
    }
    printf("  Desempilhado: ");
    imprimir_elemento(p->dados[p->topo]);
    p->topo--;
    return 1;
}

int pilha_topo(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("  ERRO: Pilha vazia!\n");
        return 0;
    }
    printf("  Topo: ");
    imprimir_elemento(p->dados[p->topo]);
    return 1;
}

void pilha_exibir(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("  Pilha vazia.\n");
        return;
    }
    printf("  Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("  [%s] ", i == p->topo ? "TOPO" : "    ");
        imprimir_elemento(p->dados[i]);
    }
}

void menu_pilha(Pilha *p) {
    int op;
    Elemento e;
    do {
        printf("\n===== MENU: PILHA (LIFO) =====\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Consultar topo\n");
        printf("4 - Exibir pilha\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar se esta cheia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                e = ler_elemento();
                pilha_empilhar(p, e);
                break;
            case 2:
                pilha_desempilhar(p);
                break;
            case 3:
                pilha_topo(p);
                break;
            case 4:
                pilha_exibir(p);
                break;
            case 5:
                printf("  Pilha %s vazia.\n", pilha_vazia(p) ? "esta" : "nao esta");
                break;
            case 6:
                printf("  Pilha %s cheia.\n", pilha_cheia(p) ? "esta" : "nao esta");
                break;
            case 0:
                break;
            default:
                printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
