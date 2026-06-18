#include <stdio.h>
#include "pilha.h"
#include "utils.h"

void p_inicializar(Pilha *p) { p->topo = -1; }

int p_empilhar(Pilha *p, int valor) {
    if (p->topo >= MAX-1) { printf("Pilha cheia!\n"); return 0; }
    p->dados[++(p->topo)] = valor;
    printf("Valor %d empilhado.\n", valor);
    return 1;
}

int p_desempilhar(Pilha *p) {
    if (p->topo == -1) { printf("Pilha vazia!\n"); return 0; }
    printf("Desempilhado: %d\n", p->dados[(p->topo)--]);
    return 1;
}

void p_topo(Pilha *p) {
    if (p->topo == -1) printf("Pilha vazia!\n");
    else printf("Topo: %d\n", p->dados[p->topo]);
}

void p_exibir(Pilha *p) {
    if (p->topo == -1) { printf("Pilha vazia!\n"); return; }
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) printf("  [%d]\n", p->dados[i]);
}

void menu_pilha(Pilha *p) {
    int op, val;
    do {
        printf("\n===== PILHA (LIFO) =====\n");
        printf("1 - Empilhar\n2 - Desempilhar\n3 - Consultar topo\n4 - Exibir pilha\n5 - Verificar se esta vazia\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1: printf("Valor: "); val = ler_inteiro(); if(val==-99) break; p_empilhar(p,val); break;
            case 2: p_desempilhar(p); break;
            case 3: p_topo(p); break;
            case 4: p_exibir(p); break;
            case 5: printf(p->topo == -1 ? "Pilha vazia.\n" : "Pilha nao esta vazia.\n"); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
