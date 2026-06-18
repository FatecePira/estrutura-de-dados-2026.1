#include <stdio.h>
#include "fila_circular.h"

void fc_inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int fc_vazia(FilaCircular *f) {
    return f->tamanho == 0;
}

int fc_cheia(FilaCircular *f) {
    return f->tamanho == MAX;
}

int fc_enfileirar(FilaCircular *f, Elemento e) {
    if (fc_cheia(f)) {
        printf("  ERRO: Fila circular cheia!\n");
        return 0;
    }
    f->dados[f->fim] = e;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    printf("  Elemento enfileirado.\n");
    return 1;
}

int fc_desenfileirar(FilaCircular *f) {
    if (fc_vazia(f)) {
        printf("  ERRO: Fila circular vazia!\n");
        return 0;
    }
    printf("  Desenfileirado: ");
    imprimir_elemento(f->dados[f->inicio]);
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}

int fc_consultar_inicio(FilaCircular *f) {
    if (fc_vazia(f)) {
        printf("  ERRO: Fila circular vazia!\n");
        return 0;
    }
    printf("  Inicio: ");
    imprimir_elemento(f->dados[f->inicio]);
    return 1;
}

int fc_consultar_fim(FilaCircular *f) {
    if (fc_vazia(f)) {
        printf("  ERRO: Fila circular vazia!\n");
        return 0;
    }
    int idx = (f->fim - 1 + MAX) % MAX;
    printf("  Fim: ");
    imprimir_elemento(f->dados[idx]);
    return 1;
}

void fc_exibir(FilaCircular *f) {
    if (fc_vazia(f)) {
        printf("  Fila circular vazia.\n");
        return;
    }
    printf("  Fila Circular (%d/%d elemento(s)):\n", f->tamanho, MAX);
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("  [%s] ", i == 0 ? "INI" : (i == f->tamanho - 1 ? "FIM" : "   "));
        imprimir_elemento(f->dados[idx]);
    }
}

void menu_fila_circular(FilaCircular *f) {
    int op;
    Elemento e;
    do {
        printf("\n===== MENU: FILA CIRCULAR =====\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Consultar fim\n");
        printf("5 - Exibir fila\n");
        printf("6 - Verificar se esta vazia\n");
        printf("7 - Verificar se esta cheia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: e = ler_elemento(); fc_enfileirar(f, e); break;
            case 2: fc_desenfileirar(f); break;
            case 3: fc_consultar_inicio(f); break;
            case 4: fc_consultar_fim(f); break;
            case 5: fc_exibir(f); break;
            case 6: printf("  Fila %s vazia.\n", fc_vazia(f) ? "esta" : "nao esta"); break;
            case 7: printf("  Fila %s cheia.\n", fc_cheia(f) ? "esta" : "nao esta"); break;
            case 0: break;
            default: printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
