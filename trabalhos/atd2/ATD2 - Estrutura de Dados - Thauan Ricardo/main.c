#include <stdio.h>

#define MAX 100

/* LISTA */
int lista[MAX];
int qtdLista = 0;

/* PILHA */
int pilha[MAX];
int topo = -1;

/* FILA */
int fila[MAX];
int inicioFila = 0;
int fimFila = -1;
int qtdFila = 0;

/* ================= LISTA ================= */

void menuLista() {
    int op, valor;

    do {
        printf("\n===== LISTA SEQUENCIAL =====\n");
        printf("1 - Inserir\n");
        printf("2 - Remover ultimo\n");
        printf("3 - Exibir\n");
        printf("4 - Quantidade\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                if(qtdLista < MAX) {
                    printf("Valor: ");
                    scanf("%d", &valor);
                    lista[qtdLista++] = valor;
                } else {
                    printf("Lista cheia!\n");
                }
                break;

            case 2:
                if(qtdLista > 0) {
                    qtdLista--;
                    printf("Elemento removido.\n");
                } else {
                    printf("Lista vazia!\n");
                }
                break;

            case 3:
                if(qtdLista == 0) {
                    printf("Lista vazia!\n");
                } else {
                    printf("Elementos: ");
                    for(int i = 0; i < qtdLista; i++)
                        printf("%d ", lista[i]);
                    printf("\n");
                }
                break;

            case 4:
                printf("Quantidade: %d\n", qtdLista);
                break;
        }

    } while(op != 0);
}

/* ================= PILHA ================= */

void menuPilha() {
    int op, valor;

    do {
        printf("\n===== PILHA =====\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Consultar topo\n");
        printf("4 - Exibir pilha\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                if(topo < MAX - 1) {
                    printf("Valor: ");
                    scanf("%d", &valor);
                    pilha[++topo] = valor;
                } else {
                    printf("Pilha cheia!\n");
                }
                break;

            case 2:
                if(topo >= 0) {
                    printf("Removido: %d\n", pilha[topo]);
                    topo--;
                } else {
                    printf("Pilha vazia!\n");
                }
                break;

            case 3:
                if(topo >= 0)
                    printf("Topo: %d\n", pilha[topo]);
                else
                    printf("Pilha vazia!\n");
                break;

            case 4:
                if(topo == -1) {
                    printf("Pilha vazia!\n");
                } else {
                    printf("Pilha: ");
                    for(int i = topo; i >= 0; i--)
                        printf("%d ", pilha[i]);
                    printf("\n");
                }
                break;
        }

    } while(op != 0);
}

/* ================= FILA ================= */

void menuFila() {
    int op, valor;

    do {
        printf("\n===== FILA =====\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Exibir fila\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                if(qtdFila < MAX) {
                    printf("Valor: ");
                    scanf("%d", &valor);

                    fila[++fimFila] = valor;
                    qtdFila++;
                } else {
                    printf("Fila cheia!\n");
                }
                break;

            case 2:
                if(qtdFila > 0) {
                    printf("Removido: %d\n", fila[inicioFila]);
                    inicioFila++;
                    qtdFila--;
                } else {
                    printf("Fila vazia!\n");
                }
                break;

            case 3:
                if(qtdFila > 0)
                    printf("Inicio: %d\n", fila[inicioFila]);
                else
                    printf("Fila vazia!\n");
                break;

            case 4:
                if(qtdFila == 0) {
                    printf("Fila vazia!\n");
                } else {
                    printf("Fila: ");
                    for(int i = inicioFila; i <= fimFila; i++)
                        printf("%d ", fila[i]);
                    printf("\n");
                }
                break;
        }

    } while(op != 0);
}

/* ================= MAIN ================= */

int main() {

    int op;

    do {

        printf("\n===== SIMULADOR DE ESTRUTURAS DE DADOS =====\n");
        printf("1 - Lista Sequencial\n");
        printf("2 - Pilha\n");
        printf("3 - Fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                menuLista();
                break;

            case 2:
                menuPilha();
                break;

            case 3:
                menuFila();
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(op != 0);

    return 0;
}