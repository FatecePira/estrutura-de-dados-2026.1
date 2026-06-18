#include <stdio.h>
#include "filaDePrioridade.h"

// Inicializar
void inicializarFilaPrioridade(FilaPrioridade *f) {
    f->quantidade = 0;
}

// Verifica vazia
int filaPrioridadeEstaVazia(FilaPrioridade *f) {
    return f->quantidade == 0;
}

// Verifica cheia
int filaPrioridadeEstaCheia(FilaPrioridade *f) {
    return f->quantidade == TAM_FILA_PRIORIDADE;
}

// Inserir elemento mantendo ordenação por prioridade
void inserirComPrioridade(FilaPrioridade *f) {

    if (filaPrioridadeEstaCheia(f)) {
        printf("Fila cheia!\n");
        return;
    }

    int valor, prioridade;

    printf("Digite o valor: ");
    scanf("%d", &valor);

    printf("Digite a prioridade: ");
    scanf("%d", &prioridade);

    int i = f->quantidade - 1;

    // desloca elementos menores
    while (i >= 0 && f->dados[i].prioridade < prioridade) {
        f->dados[i + 1] = f->dados[i];
        i--;
    }

    f->dados[i + 1].valor = valor;
    f->dados[i + 1].prioridade = prioridade;

    f->quantidade++;

    printf("Elemento inserido.\n");
}

// Remove o maior prioridade (posição 0)
void removerMaiorPrioridade(FilaPrioridade *f) {

    if (filaPrioridadeEstaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Removido: %d (Prioridade %d)\n",
           f->dados[0].valor,
           f->dados[0].prioridade);

    // desloca tudo para esquerda
    for (int i = 0; i < f->quantidade - 1; i++) {
        f->dados[i] = f->dados[i + 1];
    }

    f->quantidade--;
}

// Consulta próximo a sair
void consultarProximo(FilaPrioridade *f) {

    if (filaPrioridadeEstaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Proximo elemento: %d | Prioridade: %d\n",
           f->dados[0].valor,
           f->dados[0].prioridade);
}

// Exibe fila
void exibirFilaPrioridade(FilaPrioridade *f) {

    if (filaPrioridadeEstaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("---- FILA ORDENADA ----\n");

    for (int i = 0; i < f->quantidade; i++) {

        printf("Valor: %d | Prioridade: %d\n",
               f->dados[i].valor,
               f->dados[i].prioridade);
    }
}

// Menu
void menuFilaDePrioridade() {

    FilaPrioridade fila;
    inicializarFilaPrioridade(&fila);

    int opcao;

    do {
        printf("\n===== MENU FILA PRIORIDADE =====\n");
        printf("1 - Inserir elemento com prioridade\n");
        printf("2 - Remover maior prioridade\n");
        printf("3 - Consultar proximo elemento\n");
        printf("4 - Exibir fila ordenada\n");
        printf("5 - Verificar se esta cheia\n");
        printf("6 - Verificar se esta vazia\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                inserirComPrioridade(&fila);
                break;

            case 2:
                removerMaiorPrioridade(&fila);
                break;

            case 3:
                consultarProximo(&fila);
                break;

            case 4:
                exibirFilaPrioridade(&fila);
                break;

            case 5:
                printf("%s\n",
                       filaPrioridadeEstaCheia(&fila)
                       ? "Fila cheia"
                       : "Fila nao cheia");
                break;

            case 6:
                printf("%s\n",
                       filaPrioridadeEstaVazia(&fila)
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