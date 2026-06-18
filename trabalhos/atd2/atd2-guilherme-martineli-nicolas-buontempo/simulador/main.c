#include <stdio.h>
#include "tipos.h"
#include "lista_sequencial.h"
#include "lista_encadeada.h"
#include "pilha.h"
#include "fila.h"
#include "fila_circular.h"
#include "fila_dupla.h"
#include "fila_prioridade.h"

int main() {
    /* Cada estrutura tem seus proprios dados independentes */
    ListaSeq       lista_seq;
    ListaEnc       lista_enc;
    Pilha          pilha;
    Fila           fila;
    FilaCircular   fila_circ;
    FilaDupla      fila_dupla;
    FilaPrioridade fila_prior;

    ls_inicializar(&lista_seq);
    le_inicializar(&lista_enc);
    pilha_inicializar(&pilha);
    fila_inicializar(&fila);
    fc_inicializar(&fila_circ);
    fd_inicializar(&fila_dupla);
    fp_inicializar(&fila_prior);

    int op;
    do {
        printf("\n========================================\n");
        printf("   SIMULADOR DE ESTRUTURAS DE DADOS\n");
        printf("========================================\n");
        printf("1 - Lista Sequencial\n");
        printf("2 - Lista Simplesmente Encadeada\n");
        printf("3 - Pilha\n");
        printf("4 - Fila\n");
        printf("5 - Fila Circular\n");
        printf("6 - Fila Dupla\n");
        printf("7 - Fila de Prioridade\n");
        printf("0 - Sair\n");
        printf("Escolha uma estrutura: ");
        scanf("%d", &op);
        switch (op) {
            case 1: menu_lista_seq(&lista_seq);     break;
            case 2: menu_lista_enc(&lista_enc);     break;
            case 3: menu_pilha(&pilha);             break;
            case 4: menu_fila(&fila);               break;
            case 5: menu_fila_circular(&fila_circ); break;
            case 6: menu_fila_dupla(&fila_dupla);   break;
            case 7: menu_fila_prioridade(&fila_prior); break;
            case 0: printf("\nEncerrando o simulador. Ate mais!\n\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (op != 0);

    return 0;
}
