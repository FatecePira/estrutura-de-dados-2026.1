#include <stdio.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int estaVaziaPilha(Pilha *p) {
    return p->topo == -1;
}

int estaCheiaPilha(Pilha *p) {
    return p->topo == TAM - 1;
}

int quantidadeElementosPilha(Pilha *p) {
    return p->topo + 1;
}

void inserirElementoPilha(Pilha *p) {
    int valor;

    if (estaCheiaPilha(p)) {
        printf("Pilha cheia!\n");
        return;
    }

    printf("Digite o valor: ");
    scanf("%d", &valor);

    p->dados[++p->topo] = valor;
}

void removerElementoPilha(Pilha *p) {
    if (estaVaziaPilha(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Elemento removido: %d\n", p->dados[p->topo--]);
}

void consultarElementoPilha(Pilha *p) {
    if (estaVaziaPilha(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("Topo: %d\n", p->dados[p->topo]);
}

void exibirPilha(Pilha *p) {
    if (estaVaziaPilha(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    for (int i = p->topo; i >= 0; i--) {
        printf("%d\n", p->dados[i]);
    }
}

void menuPilha() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int op;

    do {
        printf("\n===== MENU DA ESTRUTURA =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Consultar elemento\n");
        printf("4 - Exibir estrutura\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar quantidade de elementos\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1: inserirElementoPilha(&pilha); break;
            case 2: removerElementoPilha(&pilha); break;
            case 3: consultarElementoPilha(&pilha); break;
            case 4: exibirPilha(&pilha); break;
            case 5:
                printf("%s\n",
                       estaVaziaPilha(&pilha)
                       ? "Pilha vazia"
                       : "Pilha nao vazia");
                break;
            case 6:
                printf("Quantidade: %d\n",
                       quantidadeElementosPilha(&pilha));
                break;
        }

    } while(op != 0);
}