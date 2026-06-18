#include <stdio.h>
#include "fila_prioridade.h"

void fp_inicializar(FilaPrioridade *f) {
    f->tamanho = 0;
}

int fp_vazia(FilaPrioridade *f) {
    return f->tamanho == 0;
}

int fp_cheia(FilaPrioridade *f) {
    return f->tamanho == MAX;
}

/* Insere mantendo vetor ordenado por prioridade (maior primeiro) */
int fp_inserir(FilaPrioridade *f, Elemento e) {
    if (fp_cheia(f)) {
        printf("  ERRO: Fila de prioridade cheia!\n");
        return 0;
    }
    int i = f->tamanho - 1;
    while (i >= 0 && f->dados[i].prioridade < e.prioridade) {
        f->dados[i + 1] = f->dados[i];
        i--;
    }
    f->dados[i + 1] = e;
    f->tamanho++;
    printf("  Elemento inserido com prioridade %d.\n", e.prioridade);
    return 1;
}

int fp_remover(FilaPrioridade *f) {
    if (fp_vazia(f)) {
        printf("  ERRO: Fila de prioridade vazia!\n");
        return 0;
    }
    printf("  Removido (maior prioridade): ");
    imprimir_elemento(f->dados[0]);
    for (int i = 0; i < f->tamanho - 1; i++)
        f->dados[i] = f->dados[i + 1];
    f->tamanho--;
    return 1;
}

int fp_consultar_proximo(FilaPrioridade *f) {
    if (fp_vazia(f)) {
        printf("  ERRO: Fila de prioridade vazia!\n");
        return 0;
    }
    printf("  Proximo a ser removido: ");
    imprimir_elemento(f->dados[0]);
    return 1;
}

void fp_exibir(FilaPrioridade *f) {
    if (fp_vazia(f)) {
        printf("  Fila de prioridade vazia.\n");
        return;
    }
    printf("  Fila de Prioridade (%d elemento(s)), ordem decrescente:\n", f->tamanho);
    for (int i = 0; i < f->tamanho; i++) {
        printf("  [%s] ", i == 0 ? "PROX" : "    ");
        imprimir_elemento(f->dados[i]);
    }
}

void menu_fila_prioridade(FilaPrioridade *f) {
    int op;
    Elemento e;
    do {
        printf("\n===== MENU: FILA DE PRIORIDADE =====\n");
        printf("1 - Inserir com prioridade\n");
        printf("2 - Remover elemento de maior prioridade\n");
        printf("3 - Consultar proximo\n");
        printf("4 - Exibir fila ordenada\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar se esta cheia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: e = ler_elemento_com_prioridade(); fp_inserir(f, e); break;
            case 2: fp_remover(f); break;
            case 3: fp_consultar_proximo(f); break;
            case 4: fp_exibir(f); break;
            case 5: printf("  Fila %s vazia.\n", fp_vazia(f) ? "esta" : "nao esta"); break;
            case 6: printf("  Fila %s cheia.\n", fp_cheia(f) ? "esta" : "nao esta"); break;
            case 0: break;
            default: printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
