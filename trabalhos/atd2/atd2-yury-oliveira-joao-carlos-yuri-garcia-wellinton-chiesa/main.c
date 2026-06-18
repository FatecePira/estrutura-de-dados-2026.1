#include <stdio.h>
#include "utils.h"
#include "lista_seq.h"
#include "lista_enc.h"
#include "pilha.h"
#include "fila.h"
#include "fila_circ.h"
#include "fila_dupla.h"
#include "fila_prio.h"

int main() {
    ListaSeq  lista_seq;
    ListaEnc  lista_enc;
    Pilha     pilha;
    Fila      fila;
    FilaCirc  fila_circ;
    FilaDupla fila_dupla;
    FilaPrio  fila_prio;

    ls_inicializar(&lista_seq);
    le_inicializar(&lista_enc);
    p_inicializar(&pilha);
    f_inicializar(&fila);
    fc_inicializar(&fila_circ);
    fd_inicializar(&fila_dupla);
    fp_inicializar(&fila_prio);

    int op;
    do {
        printf("\n===== SIMULADOR DE ESTRUTURAS DE DADOS =====\n");
        printf("1 - Lista Sequencial\n");
        printf("2 - Lista Simplesmente Encadeada\n");
        printf("3 - Pilha\n");
        printf("4 - Fila\n");
        printf("5 - Fila Circular\n");
        printf("6 - Fila Dupla\n");
        printf("7 - Fila de Prioridade\n");
        printf("0 - Sair\n");
        printf("Escolha uma estrutura: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1: menu_lista_seq(&lista_seq); break;
            case 2: menu_lista_enc(&lista_enc); break;
            case 3: menu_pilha(&pilha);         break;
            case 4: menu_fila(&fila);           break;
            case 5: menu_fila_circ(&fila_circ); break;
            case 6: menu_fila_dupla(&fila_dupla); break;
            case 7: menu_fila_prio(&fila_prio); break;
            case 0: printf("Encerrando...\n");  break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);

    return 0;
}
