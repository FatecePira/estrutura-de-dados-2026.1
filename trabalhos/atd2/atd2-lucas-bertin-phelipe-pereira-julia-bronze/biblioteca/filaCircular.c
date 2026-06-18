#include <stdio.h>
#include "filaCircular.h"

void inicializarFilaCircular(FilaCircular *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

int filaEstaVaziaCircular(FilaCircular *f) {
    return f->quantidade == 0;
}

int filaEstaCheiaCircular(FilaCircular *f) {
    return f->quantidade == TAM_FILA_CIRCULAR;
}

// Enfileirar
void enfileirarFilaCircular(FilaCircular *f) {
    if (filaEstaCheiaCircular(f)) {
        printf("Fila cheia!\n");
        return;
    }

    int valor;
    printf("Digite o valor: ");
    scanf("%d", &valor);

    f->fim = (f->fim + 1) % TAM_FILA_CIRCULAR;
    f->dados[f->fim] = valor;
    f->quantidade++;

    printf("Valor %d inserido na fila.\n", valor);
}

// Desenfileirar
void desenfileirarFilaCircular(FilaCircular *f) {
    if (filaEstaVaziaCircular(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Elemento removido: %d\n", f->dados[f->inicio]);

    f->inicio = (f->inicio + 1) % TAM_FILA_CIRCULAR;
    f->quantidade--;

    // Reset quando esvaziar
    if (filaEstaVaziaCircular(f)) {
        f->inicio = 0;
        f->fim = -1;
    }
}

// Consultar início
void consultarInicioFilaCircular(FilaCircular *f) {
    if (filaEstaVaziaCircular(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Inicio da fila: %d\n", f->dados[f->inicio]);
}

// Consultar fim
void consultarFimFilaCircular(FilaCircular *f) {
    if (filaEstaVaziaCircular(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fim da fila: %d\n", f->dados[f->fim]);
}

// Exibir fila
void exibirFilaCircular(FilaCircular *f) {
    if (filaEstaVaziaCircular(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("---- Conteudo da fila ----\n");

    int idx = f->inicio;

    for (int i = 0; i < f->quantidade; i++) {
        printf("%d\n", f->dados[idx]);
        idx = (idx + 1) % TAM_FILA_CIRCULAR;
    }
}

// Menu
void menuFilaCircular() {
    FilaCircular fila;
    inicializarFilaCircular(&fila);

    int opcao;

    do {
        printf("\n===== MENU FILA CIRCULAR =====\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Consultar fim\n");
        printf("5 - Exibir fila\n");
        printf("6 - Verificar se esta cheia\n");
        printf("7 - Verificar se esta vazia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                enfileirarFilaCircular(&fila);
                break;

            case 2:
                desenfileirarFilaCircular(&fila);
                break;

            case 3:
                consultarInicioFilaCircular(&fila);
                break;

            case 4:
                consultarFimFilaCircular(&fila);
                break;

            case 5:
                exibirFilaCircular(&fila);
                break;

            case 6:
                printf("%s\n",
                    filaEstaCheiaCircular(&fila) ?
                    "Fila cheia" : "Fila nao cheia");
                break;

            case 7:
                printf("%s\n",
                    filaEstaVaziaCircular(&fila) ?
                    "Fila vazia" : "Fila nao vazia");
                break;

            case 0:
                printf("Voltando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}