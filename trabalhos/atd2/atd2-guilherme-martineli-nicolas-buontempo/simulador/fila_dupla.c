#include <stdio.h>
#include "fila_dupla.h"

void fd_inicializar(FilaDupla *f) {
    f->inicio = MAX / 2;
    f->fim = MAX / 2 - 1;
    f->tamanho = 0;
}

int fd_vazia(FilaDupla *f) {
    return f->tamanho == 0;
}

int fd_cheia(FilaDupla *f) {
    return f->tamanho == MAX;
}

int fd_inserir_inicio(FilaDupla *f, Elemento e) {
    if (fd_cheia(f)) { printf("  ERRO: Fila dupla cheia!\n"); return 0; }
    if (!fd_vazia(f)) f->inicio--;
    if (f->inicio < 0) {
        /* Shift right to make room */
        for (int i = f->tamanho; i > 0; i--)
            f->dados[f->fim - f->tamanho + i + 1] = f->dados[f->fim - f->tamanho + i];
        f->inicio++;
        f->fim++;
    }
    f->dados[f->inicio] = e;
    if (fd_vazia(f)) f->fim = f->inicio;
    f->tamanho++;
    printf("  Inserido no inicio.\n");
    return 1;
}

int fd_inserir_fim(FilaDupla *f, Elemento e) {
    if (fd_cheia(f)) { printf("  ERRO: Fila dupla cheia!\n"); return 0; }
    if (!fd_vazia(f)) f->fim++;
    if (f->fim >= MAX) {
        /* Shift left to make room */
        int base = f->inicio;
        for (int i = 0; i < f->tamanho; i++)
            f->dados[base - 1 + i] = f->dados[f->inicio + i];
        f->inicio = base - 1;
        f->fim = f->inicio + f->tamanho - 1;
        f->fim++;
    }
    f->dados[f->fim] = e;
    if (fd_vazia(f)) f->inicio = f->fim;
    f->tamanho++;
    printf("  Inserido no fim.\n");
    return 1;
}

int fd_remover_inicio(FilaDupla *f) {
    if (fd_vazia(f)) { printf("  ERRO: Fila dupla vazia!\n"); return 0; }
    printf("  Removido do inicio: ");
    imprimir_elemento(f->dados[f->inicio]);
    f->inicio++;
    f->tamanho--;
    return 1;
}

int fd_remover_fim(FilaDupla *f) {
    if (fd_vazia(f)) { printf("  ERRO: Fila dupla vazia!\n"); return 0; }
    printf("  Removido do fim: ");
    imprimir_elemento(f->dados[f->fim]);
    f->fim--;
    f->tamanho--;
    return 1;
}

int fd_consultar_inicio(FilaDupla *f) {
    if (fd_vazia(f)) { printf("  ERRO: Fila dupla vazia!\n"); return 0; }
    printf("  Inicio: ");
    imprimir_elemento(f->dados[f->inicio]);
    return 1;
}

int fd_consultar_fim(FilaDupla *f) {
    if (fd_vazia(f)) { printf("  ERRO: Fila dupla vazia!\n"); return 0; }
    printf("  Fim: ");
    imprimir_elemento(f->dados[f->fim]);
    return 1;
}

void fd_exibir(FilaDupla *f) {
    if (fd_vazia(f)) { printf("  Fila dupla vazia.\n"); return; }
    printf("  Fila Dupla (%d elemento(s)):\n", f->tamanho);
    for (int i = 0; i < f->tamanho; i++) {
        int label_ini = (i == 0), label_fim = (i == f->tamanho - 1);
        if (label_ini && label_fim) printf("  [INI/FIM] ");
        else if (label_ini)         printf("  [INICIO ] ");
        else if (label_fim)         printf("  [FIM    ] ");
        else                        printf("  [       ] ");
        imprimir_elemento(f->dados[f->inicio + i]);
    }
}

void menu_fila_dupla(FilaDupla *f) {
    int op;
    Elemento e;
    do {
        printf("\n===== MENU: FILA DUPLA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Remover do fim\n");
        printf("5 - Consultar inicio\n");
        printf("6 - Consultar fim\n");
        printf("7 - Exibir fila\n");
        printf("8 - Verificar se esta vazia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: e = ler_elemento(); fd_inserir_inicio(f, e); break;
            case 2: e = ler_elemento(); fd_inserir_fim(f, e); break;
            case 3: fd_remover_inicio(f); break;
            case 4: fd_remover_fim(f); break;
            case 5: fd_consultar_inicio(f); break;
            case 6: fd_consultar_fim(f); break;
            case 7: fd_exibir(f); break;
            case 8: printf("  Fila %s vazia.\n", fd_vazia(f) ? "esta" : "nao esta"); break;
            case 0: break;
            default: printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
