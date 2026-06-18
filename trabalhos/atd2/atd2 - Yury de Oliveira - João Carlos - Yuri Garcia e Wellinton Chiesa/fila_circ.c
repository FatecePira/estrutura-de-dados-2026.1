#include <stdio.h>
#include "fila_circ.h"
#include "utils.h"

void fc_inicializar(FilaCirc *f) { f->inicio = 0; f->fim = -1; f->tamanho = 0; }

int fc_enfileirar(FilaCirc *f, int valor) {
    if (f->tamanho >= MAX) { printf("Fila circular cheia!\n"); return 0; }
    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = valor;
    f->tamanho++;
    printf("Valor %d enfileirado.\n", valor);
    return 1;
}

int fc_desenfileirar(FilaCirc *f) {
    if (f->tamanho == 0) { printf("Fila circular vazia!\n"); return 0; }
    printf("Desenfileirado: %d\n", f->dados[f->inicio]);
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

void fc_exibir(FilaCirc *f) {
    if (f->tamanho == 0) { printf("Fila circular vazia!\n"); return; }
    printf("Fila circular [%d elementos]:\n", f->tamanho);
    for (int i = 0; i < f->tamanho; i++)
        printf("  [%d]\n", f->dados[(f->inicio + i) % MAX]);
    printf("Inicio: %d | Fim: %d\n", f->dados[f->inicio], f->dados[f->fim]);
}

void menu_fila_circ(FilaCirc *f) {
    int op, val;
    do {
        printf("\n===== FILA CIRCULAR =====\n");
        printf("1 - Enfileirar\n2 - Desenfileirar\n3 - Consultar inicio\n4 - Consultar fim\n5 - Exibir fila\n6 - Verificar se esta cheia\n7 - Verificar se esta vazia\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1: printf("Valor: "); val = ler_inteiro(); if(val==-99) break; fc_enfileirar(f,val); break;
            case 2: fc_desenfileirar(f); break;
            case 3: if(f->tamanho==0) printf("Vazia!\n"); else printf("Inicio: %d\n",f->dados[f->inicio]); break;
            case 4: if(f->tamanho==0) printf("Vazia!\n"); else printf("Fim: %d\n",f->dados[f->fim]); break;
            case 5: fc_exibir(f); break;
            case 6: printf(f->tamanho == MAX ? "Fila cheia.\n" : "Fila nao esta cheia.\n"); break;
            case 7: printf(f->tamanho == 0 ? "Fila vazia.\n" : "Fila nao esta vazia.\n"); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
