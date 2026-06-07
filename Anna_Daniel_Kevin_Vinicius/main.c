#include "include/comum.h"        // Inclui as definicoes basicas (constante MAX, struct Elemento)
#include "include/lista_seq.h"    // Inclui as funcoes da Lista Sequencial
#include "include/lista_enc.h"    // Inclui as funcoes da Lista Encadeada
#include "include/pilha.h"        // Inclui as funcoes da Pilha
#include "include/fila.h"         // Inclui as funcoes da Fila Simples
#include "include/fila_circ.h"    // Inclui as funcoes da Fila Circular
#include "include/fila_dupla.h"   // Inclui as funcoes da Fila Dupla
#include "include/fila_prio.h"    // Inclui as funcoes da Fila de Prioridade

/* Cada estrutura possui seus proprios dados,
   independentes das demais. */

int main(void) {
    // Declaracao (instanciacao) das variaveis de cada estrutura na memoria
    ListaSequencial ls;
    ListaEncadeada  le;
    Pilha           pilha;
    Fila            fila;
    FilaCircular    fcirc;
    FilaDupla       fdupla;
    FilaPrioridade  fprio;

    // Inicializacao: Prepara os ponteiros e tamanhos de todas as estruturas para iniciarem do zero
    ls_inicializar(&ls);     // Passa o endereco (&) da variavel 'ls' para a funcao alterar o original
    le_inicializar(&le);
    pi_inicializar(&pilha);
    fi_inicializar(&fila);
    fc_inicializar(&fcirc);
    fd_inicializar(&fdupla);
    fp_inicializar(&fprio);

    int opcao; // Variavel para guardar a escolha do usuario no menu
    do {
        // Exibicao do menu principal usando printf
        printf("\n");
        printf("  ============================================\n");
        printf("     SIMULADOR DE ESTRUTURAS DE DADOS         \n");
        printf("  ============================================\n");
        printf("   1 - Lista Sequencial\n");
        printf("   2 - Lista Simplesmente Encadeada\n");
        printf("   3 - Pilha\n");
        printf("   4 - Fila\n");
        printf("   5 - Fila Circular\n");
        printf("   6 - Fila Dupla\n");
        printf("   7 - Fila de Prioridade\n");
        printf("   0 - Sair\n");
        printf("  ============================================\n");
        printf("  Escolha uma estrutura: ");
        
        scanf("%d", &opcao); // Le o numero que o usuario digitou e guarda em 'opcao'
        limpar_buffer();     // Chama a funcao que limpa o 'Enter' (\n) deixado no teclado pelo scanf

        // Verifica qual foi a opcao escolhida e chama o submenu correspondente
        switch (opcao) {
            case 1: menu_lista_sequencial(&ls);    break; // Chama o menu da Lista Sequencial
            case 2: menu_lista_encadeada(&le);     break; // Chama o menu da Lista Encadeada
            case 3: menu_pilha(&pilha);            break; // Chama o menu da Pilha
            case 4: menu_fila(&fila);              break; // Chama o menu da Fila Simples
            case 5: menu_fila_circular(&fcirc);    break; // Chama o menu da Fila Circular
            case 6: menu_fila_dupla(&fdupla);      break; // Chama o menu da Fila Dupla
            case 7: menu_fila_prioridade(&fprio);  break; // Chama o menu da Fila de Prioridade
            case 0:
                printf("\n  Encerrando o simulador. Ate mais!\n\n");
                break;
            default: // Caso o usuario digite um numero que nao existe no menu
                printf("  Opcao invalida. Tente novamente.\n");
                pausar(); // Congela a tela ate o usuario apertar Enter
        }
    } while (opcao != 0); // O laco se repete infinitamente ate a opcao ser 0 (Sair)

    // libera memoria da lista encadeada
    le_liberar(&le); // Funcao super importante: varre a lista dinamica dando 'free' para evitar vazamento de memoria

    return 0; // Encerra o programa com sucesso (codigo 0)
}