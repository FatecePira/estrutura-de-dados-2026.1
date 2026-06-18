#include <stdio.h>
#include "biblioteca/pilha.h"
#include "biblioteca/listaSequencial.h"
#include "biblioteca/listaSimplesEncadeada.h"
#include "biblioteca/fila.h"
#include "biblioteca/filaCircular.h"
#include "biblioteca/filaDupla.h"
#include "biblioteca/filaDePrioridade.h"

/* =========================
   MENU PRINCIPAL
   ========================= */

int main() {

    int escolha;

    do {

        printf("\n=====================================\n");
        printf(" SIMULADOR DE ESTRUTURAS DE DADOS\n");
        printf("=====================================\n");

        printf("1 - Lista Sequencial\n");
        printf("2 - Lista Simplesmente Encadeada\n");
        printf("3 - Pilha\n");
        printf("4 - Fila\n");
        printf("5 - Fila Circular\n");
        printf("6 - Fila Dupla\n");
        printf("7 - Fila de Prioridade\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma estrutura: ");
        scanf("%d", &escolha);

        switch(escolha) {

            case 1:
                menuListaSequencial();
                break;

            case 2:
                menuListaSimplesmenteEncadeada();
                break;

            case 3:
                menuPilha();
                break;

            case 4:
                menuFila();
                break;

            case 5:
                menuFilaCircular();
                break;

            case 6:
                menuFilaDupla();
                break;

            case 7:
                menuFilaDePrioridade();
                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(escolha != 0);

    return 0;
}