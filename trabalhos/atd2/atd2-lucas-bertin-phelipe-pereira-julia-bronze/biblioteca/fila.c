#include <stdio.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

int filaEstaVazia(Fila *f) {
    return f->quantidade == 0;
}

int filaEstaCheia(Fila *f) {
    return f->fim == TAM_FILA - 1;
}

/* Enfileirar */
void enfileirarFila(Fila *f) {
    if (filaEstaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }

    int valor;
    printf("Digite o valor: ");
    scanf("%d", &valor);

    f->fim++;                // sem %
    f->dados[f->fim] = valor;
    f->quantidade++;

    printf("Valor %d inserido na fila.\n", valor);
}

/* Desenfileirar */
void desenfileirarFila(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Elemento removido: %d\n", f->dados[f->inicio]);

    f->inicio++;            // sem %
    f->quantidade--;

    /* reset quando esvaziar */
    if (filaEstaVazia(f)) {
        f->inicio = 0;
        f->fim = -1;
    }
}

/* Consultar início */
void consultarInicioFila(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Inicio da fila: %d\n", f->dados[f->inicio]);
}

/* Exibir fila */
void exibirFila(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("--- Conteudo da fila ---\n");

    for (int i = f->inicio; i <= f->fim; i++) {
        printf("%d\n", f->dados[i]);
    }
}

/* Menu */
void menuFila() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;

    do {
        printf("\n===== MENU DA FILA =====\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Exibir fila\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                enfileirarFila(&fila);
                break;

            case 2:
                desenfileirarFila(&fila);
                break;

            case 3:
                consultarInicioFila(&fila);
                break;

            case 4:
                exibirFila(&fila);
                break;

            case 5:
                printf("%s\n",
                       filaEstaVazia(&fila)
                       ? "Fila vazia"
                       : "Fila nao vazia");
                break;

            case 6:
                printf("%s\n",
                       filaEstaCheia(&fila)
                       ? "Fila cheia"
                       : "Fila nao cheia");
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 0);
}