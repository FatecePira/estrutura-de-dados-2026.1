#include <stdio.h>
#include "filaDupla.h"

// Inicializa a fila
void inicializarFilaDupla(FilaDupla *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

// Verifica se está vazia
int filaEstaVaziaDupla(FilaDupla *f) {
    return f->quantidade == 0;
}

// Verifica se está cheia
int filaEstaCheiaDupla(FilaDupla *f) {
    return f->quantidade == TAM_FILA_DUPLA;
}

// Inserir no fim
void inserirFim(FilaDupla *f) {
    if (filaEstaCheiaDupla(f)) {
        printf("Fila cheia!\n");
        return;
    }

    int valor;
    printf("Digite o valor: ");
    scanf("%d", &valor);

    f->fim = (f->fim + 1) % TAM_FILA_DUPLA;
    f->dados[f->fim] = valor;
    f->quantidade++;

    printf("Valor inserido no fim.\n");
}

// Inserir no início
void inserirInicio(FilaDupla *f) {
    if (filaEstaCheiaDupla(f)) {
        printf("Fila cheia!\n");
        return;
    }

    int valor;
    printf("Digite o valor: ");
    scanf("%d", &valor);

    if (filaEstaVaziaDupla(f)) {
        f->inicio = 0;
        f->fim = 0;
    } else {
        f->inicio = (f->inicio - 1 + TAM_FILA_DUPLA) % TAM_FILA_DUPLA;
    }

    f->dados[f->inicio] = valor;
    f->quantidade++;

    printf("Valor inserido no inicio.\n");
}

// Remover do início
void removerInicio(FilaDupla *f) {
    if (filaEstaVaziaDupla(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Elemento removido do inicio: %d\n", f->dados[f->inicio]);

    f->inicio = (f->inicio + 1) % TAM_FILA_DUPLA;
    f->quantidade--;

    if (filaEstaVaziaDupla(f)) {
        f->inicio = 0;
        f->fim = -1;
    }
}

// Remover do fim
void removerFim(FilaDupla *f) {
    if (filaEstaVaziaDupla(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Elemento removido do fim: %d\n", f->dados[f->fim]);

    f->fim = (f->fim - 1 + TAM_FILA_DUPLA) % TAM_FILA_DUPLA;
    f->quantidade--;

    if (filaEstaVaziaDupla(f)) {
        f->inicio = 0;
        f->fim = -1;
    }
}

// Consultar início
void consultarInicio(FilaDupla *f) {
    if (filaEstaVaziaDupla(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Inicio da fila: %d\n", f->dados[f->inicio]);
}

// Consultar fim
void consultarFim(FilaDupla *f) {
    if (filaEstaVaziaDupla(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fim da fila: %d\n", f->dados[f->fim]);
}

// Exibir fila
void exibirFilaDupla(FilaDupla *f) {
    if (filaEstaVaziaDupla(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("---- Conteudo da fila ----\n");

    int idx = f->inicio;

    for (int i = 0; i < f->quantidade; i++) {
        printf("%d\n", f->dados[idx]);
        idx = (idx + 1) % TAM_FILA_DUPLA;
    }
}

// Menu
void menuFilaDupla() {
    FilaDupla fila;
    inicializarFilaDupla(&fila);

    int opcao;

    do {
        printf("\n===== MENU FILA DUPLA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Remover do fim\n");
        printf("5 - Consultar inicio\n");
        printf("6 - Consultar fim\n");
        printf("7 - Exibir fila\n");
        printf("8 - Verificar se esta cheia\n");
        printf("9 - Verificar se esta vazia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                inserirInicio(&fila);
                break;

            case 2:
                inserirFim(&fila);
                break;

            case 3:
                removerInicio(&fila);
                break;

            case 4:
                removerFim(&fila);
                break;

            case 5:
                consultarInicio(&fila);
                break;

            case 6:
                consultarFim(&fila);
                break;

            case 7:
                exibirFilaDupla(&fila);
                break;

            case 8:
                printf("%s\n",
                       filaEstaCheiaDupla(&fila)
                       ? "Fila cheia"
                       : "Fila nao cheia");
                break;

            case 9:
                printf("%s\n",
                       filaEstaVaziaDupla(&fila)
                       ? "Fila vazia"
                       : "Fila nao vazia");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while(opcao != 0);
}