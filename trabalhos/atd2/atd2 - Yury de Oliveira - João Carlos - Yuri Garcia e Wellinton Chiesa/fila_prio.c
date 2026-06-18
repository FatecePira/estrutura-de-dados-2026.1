#include <stdio.h>
#include "fila_prio.h"
#include "utils.h"

void fp_inicializar(FilaPrio *f) { f->tamanho = 0; }

int fp_inserir(FilaPrio *f, int valor, int prioridade) {
    if (f->tamanho >= MAX) { printf("Fila de prioridade cheia!\n"); return 0; }
    int i = f->tamanho - 1;
    while (i >= 0 && f->dados[i].prioridade < prioridade) {
        f->dados[i+1] = f->dados[i];
        i--;
    }
    f->dados[i+1].valor = valor;
    f->dados[i+1].prioridade = prioridade;
    f->tamanho++;
    printf("Inserido valor=%d, prioridade=%d.\n", valor, prioridade);
    return 1;
}

int fp_remover(FilaPrio *f) {
    if (f->tamanho == 0) { printf("Fila vazia!\n"); return 0; }
    printf("Removido: valor=%d, prioridade=%d\n", f->dados[0].valor, f->dados[0].prioridade);
    for (int i = 0; i < f->tamanho-1; i++) f->dados[i] = f->dados[i+1];
    f->tamanho--;
    return 1;
}

void fp_consultar(FilaPrio *f) {
    if (f->tamanho == 0) printf("Fila vazia!\n");
    else printf("Proximo: valor=%d, prioridade=%d\n", f->dados[0].valor, f->dados[0].prioridade);
}

void fp_exibir(FilaPrio *f) {
    if (f->tamanho == 0) { printf("Fila vazia!\n"); return; }
    printf("Fila de prioridade (maior -> menor):\n");
    for (int i = 0; i < f->tamanho; i++)
        printf("  Valor=%d | Prioridade=%d\n", f->dados[i].valor, f->dados[i].prioridade);
}

void menu_fila_prio(FilaPrio *f) {
    int op, val, prio;
    do {
        printf("\n===== FILA DE PRIORIDADE =====\n");
        printf("1 - Inserir elemento\n2 - Remover maior prioridade\n3 - Consultar proximo\n4 - Exibir fila\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1:
                printf("Valor: ");      val  = ler_inteiro(); if(val ==-99) break;
                printf("Prioridade: "); prio = ler_inteiro(); if(prio==-99) break;
                fp_inserir(f,val,prio); break;
            case 2: fp_remover(f); break;
            case 3: fp_consultar(f); break;
            case 4: fp_exibir(f); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
