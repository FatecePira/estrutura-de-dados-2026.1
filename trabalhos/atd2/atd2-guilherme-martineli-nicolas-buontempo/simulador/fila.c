#include <stdio.h>
#include "fila.h"

void fila_inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == MAX;
}

int fila_enfileirar(Fila *f, Elemento e) {
    if (fila_cheia(f)) {
        printf("  ERRO: Fila cheia!\n");
        return 0;
    }
    f->fim++;
    f->dados[f->fim] = e;
    f->tamanho++;
    printf("  Elemento enfileirado.\n");
    return 1;
}

int fila_desenfileirar(Fila *f) {
    if (fila_vazia(f)) {
        printf("  ERRO: Fila vazia!\n");
        return 0;
    }
    printf("  Desenfileirado: ");
    imprimir_elemento(f->dados[f->inicio]);
    f->inicio++;
    f->tamanho--;
    return 1;
}

int fila_consultar_inicio(Fila *f) {
    if (fila_vazia(f)) {
        printf("  ERRO: Fila vazia!\n");
        return 0;
    }
    printf("  Inicio da fila: ");
    imprimir_elemento(f->dados[f->inicio]);
    return 1;
}

void fila_exibir(Fila *f) {
    if (fila_vazia(f)) {
        printf("  Fila vazia.\n");
        return;
    }
    printf("  Fila (inicio -> fim), %d elemento(s):\n", f->tamanho);
    for (int i = 0; i < f->tamanho; i++) {
        printf("  [%s] ", i == 0 ? "INICIO" : "      ");
        imprimir_elemento(f->dados[f->inicio + i]);
    }
}

void menu_fila(Fila *f) {
    int op;
    Elemento e;
    do {
        printf("\n===== MENU: FILA (FIFO) =====\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Exibir fila\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar se esta cheia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                e = ler_elemento();
                fila_enfileirar(f, e);
                break;
            case 2:
                fila_desenfileirar(f);
                break;
            case 3:
                fila_consultar_inicio(f);
                break;
            case 4:
                fila_exibir(f);
                break;
            case 5:
                printf("  Fila %s vazia.\n", fila_vazia(f) ? "esta" : "nao esta");
                break;
            case 6:
                printf("  Fila %s cheia.\n", fila_cheia(f) ? "esta" : "nao esta");
                break;
            case 0:
                break;
            default:
                printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
