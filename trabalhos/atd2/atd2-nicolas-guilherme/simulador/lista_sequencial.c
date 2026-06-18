#include <stdio.h>
#include "lista_sequencial.h"

void ls_inicializar(ListaSeq *l) {
    l->tamanho = 0;
}

int ls_vazia(ListaSeq *l) {
    return l->tamanho == 0;
}

int ls_inserir(ListaSeq *l, Elemento e, int posicao) {
    if (l->tamanho >= MAX) {
        printf("  ERRO: Lista cheia!\n");
        return 0;
    }
    if (posicao < 0 || posicao > l->tamanho) {
        printf("  ERRO: Posicao invalida! (0 a %d)\n", l->tamanho);
        return 0;
    }
    for (int i = l->tamanho; i > posicao; i--)
        l->dados[i] = l->dados[i - 1];
    l->dados[posicao] = e;
    l->tamanho++;
    printf("  Elemento inserido na posicao %d com sucesso.\n", posicao);
    return 1;
}

int ls_remover(ListaSeq *l, int posicao) {
    if (ls_vazia(l)) {
        printf("  ERRO: Lista vazia!\n");
        return 0;
    }
    if (posicao < 0 || posicao >= l->tamanho) {
        printf("  ERRO: Posicao invalida! (0 a %d)\n", l->tamanho - 1);
        return 0;
    }
    printf("  Elemento removido: ");
    imprimir_elemento(l->dados[posicao]);
    for (int i = posicao; i < l->tamanho - 1; i++)
        l->dados[i] = l->dados[i + 1];
    l->tamanho--;
    return 1;
}

int ls_buscar(ListaSeq *l, int id) {
    for (int i = 0; i < l->tamanho; i++) {
        if (l->dados[i].id == id) {
            printf("  Elemento encontrado na posicao %d: ", i);
            imprimir_elemento(l->dados[i]);
            return i;
        }
    }
    printf("  Elemento com ID %d nao encontrado.\n", id);
    return -1;
}

void ls_listar(ListaSeq *l) {
    if (ls_vazia(l)) {
        printf("  Lista vazia.\n");
        return;
    }
    printf("  Lista (%d elemento(s)):\n", l->tamanho);
    for (int i = 0; i < l->tamanho; i++) {
        printf("  [%d] ", i);
        imprimir_elemento(l->dados[i]);
    }
}

int ls_tamanho(ListaSeq *l) {
    return l->tamanho;
}

void menu_lista_seq(ListaSeq *l) {
    int op, pos, id;
    Elemento e;
    do {
        printf("\n===== MENU: LISTA SEQUENCIAL =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Buscar por ID\n");
        printf("4 - Exibir lista\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Quantidade de elementos\n");
        printf("0 - Voltar\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                e = ler_elemento();
                printf("  Posicao para inserir (0 a %d): ", l->tamanho);
                scanf("%d", &pos);
                ls_inserir(l, e, pos);
                break;
            case 2:
                printf("  Posicao para remover (0 a %d): ", l->tamanho - 1);
                scanf("%d", &pos);
                ls_remover(l, pos);
                break;
            case 3:
                printf("  ID a buscar: ");
                scanf("%d", &id);
                ls_buscar(l, id);
                break;
            case 4:
                ls_listar(l);
                break;
            case 5:
                printf("  Lista %s vazia.\n", ls_vazia(l) ? "esta" : "nao esta");
                break;
            case 6:
                printf("  Quantidade de elementos: %d\n", ls_tamanho(l));
                break;
            case 0:
                break;
            default:
                printf("  Opcao invalida!\n");
        }
    } while (op != 0);
}
