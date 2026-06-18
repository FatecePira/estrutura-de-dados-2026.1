#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "lista_sequencial.h"
#include "lista_encadeada.h"
#include "pilha.h"
#include "fila.h"
#include "fila_circular.h"
#include "fila_dupla.h"
#include "fila_prioridade.h"

static void menu_lista_sequencial(ListaSequencial *lista);
static void menu_lista_encadeada(ListaEncadeada *lista);
static void menu_pilha(Pilha *pilha);
static void menu_fila(Fila *fila);
static void menu_fila_circular(FilaCircular *fila);
static void menu_fila_dupla(FilaDupla *fila);
static void menu_fila_prioridade(FilaPrioridade *fila);

static void mostrar_resultado_remocao(int sucesso, Elemento removido, const char *mensagem_vazio_ou_erro) {
    if (sucesso) {
        printf("Elemento removido:\n");
        imprimir_elemento(removido);
    } else {
        printf("%s\n", mensagem_vazio_ou_erro);
    }
}

int main(void) {
    int opcao;

    ListaSequencial listaSequencial;
    ListaEncadeada listaEncadeada;
    Pilha pilha;
    Fila fila;
    FilaCircular filaCircular;
    FilaDupla filaDupla;
    FilaPrioridade filaPrioridade;

    inicializar_lista_sequencial(&listaSequencial);
    inicializar_lista_encadeada(&listaEncadeada);
    inicializar_pilha(&pilha);
    inicializar_fila(&fila);
    inicializar_fila_circular(&filaCircular);
    inicializar_fila_dupla(&filaDupla);
    inicializar_fila_prioridade(&filaPrioridade);

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

        opcao = ler_inteiro("Escolha uma estrutura: ");

        switch (opcao) {
            case 1:
                menu_lista_sequencial(&listaSequencial);
                break;
            case 2:
                menu_lista_encadeada(&listaEncadeada);
                break;
            case 3:
                menu_pilha(&pilha);
                break;
            case 4:
                menu_fila(&fila);
                break;
            case 5:
                menu_fila_circular(&filaCircular);
                break;
            case 6:
                menu_fila_dupla(&filaDupla);
                break;
            case 7:
                menu_fila_prioridade(&filaPrioridade);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberar_lista_encadeada(&listaEncadeada);

    return 0;
}

static void menu_lista_sequencial(ListaSequencial *lista) {
    int opcao;
    int posicao;
    int id;
    Elemento elemento;
    Elemento removido;
    Elemento encontrado;

    do {
        printf("\n===== MENU DA LISTA SEQUENCIAL =====\n");
        printf("1 - Inserir elemento em uma posicao\n");
        printf("2 - Remover elemento de uma posicao\n");
        printf("3 - Buscar elemento por ID\n");
        printf("4 - Exibir estrutura\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar quantidade de elementos\n");
        printf("7 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (lista_sequencial_cheia(lista)) {
                    printf("Lista cheia. Nao e possivel inserir mais elementos.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                posicao = ler_inteiro("Posicao para inserir (comecando em 1): ");
                if (inserir_lista_sequencial(lista, elemento, posicao)) {
                    printf("Elemento inserido com sucesso.\n");
                } else {
                    printf("Posicao invalida ou lista cheia.\n");
                }
                break;
            case 2:
                if (lista_sequencial_vazia(lista)) {
                    printf("Lista vazia. Nao ha elementos para remover.\n");
                    break;
                }
                posicao = ler_inteiro("Posicao para remover (comecando em 1): ");
                mostrar_resultado_remocao(remover_lista_sequencial(lista, posicao, &removido), removido, "Posicao invalida.");
                break;
            case 3:
                if (lista_sequencial_vazia(lista)) {
                    printf("Lista vazia. Nao ha elementos para buscar.\n");
                    break;
                }
                id = ler_inteiro("ID para buscar: ");
                if (buscar_lista_sequencial_por_id(lista, id, &encontrado, &posicao)) {
                    printf("Elemento encontrado na posicao %d:\n", posicao);
                    imprimir_elemento(encontrado);
                } else {
                    printf("Elemento nao encontrado.\n");
                }
                break;
            case 4:
                exibir_lista_sequencial(lista);
                break;
            case 5:
                printf(lista_sequencial_vazia(lista) ? "A lista esta vazia.\n" : "A lista nao esta vazia.\n");
                break;
            case 6:
                printf("Quantidade de elementos: %d\n", quantidade_lista_sequencial(lista));
                break;
            case 7:
                printf(lista_sequencial_cheia(lista) ? "A lista esta cheia.\n" : "A lista nao esta cheia.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

static void menu_lista_encadeada(ListaEncadeada *lista) {
    int opcao;
    int id;
    Elemento elemento;
    Elemento removido;
    Elemento encontrado;

    do {
        printf("\n===== MENU DA LISTA SIMPLESMENTE ENCADEADA =====\n");
        printf("1 - Inserir elemento no inicio\n");
        printf("2 - Inserir elemento no fim\n");
        printf("3 - Remover elemento por ID\n");
        printf("4 - Buscar elemento por ID\n");
        printf("5 - Exibir estrutura\n");
        printf("6 - Verificar se esta vazia\n");
        printf("7 - Verificar quantidade de elementos\n");
        printf("8 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (lista_encadeada_cheia(lista)) {
                    printf("Lista cheia. Limite de 100 elementos atingido.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (inserir_inicio_lista_encadeada(lista, elemento)) {
                    printf("Elemento inserido no inicio com sucesso.\n");
                } else {
                    printf("Falha ao inserir. Verifique memoria ou limite.\n");
                }
                break;
            case 2:
                if (lista_encadeada_cheia(lista)) {
                    printf("Lista cheia. Limite de 100 elementos atingido.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (inserir_fim_lista_encadeada(lista, elemento)) {
                    printf("Elemento inserido no fim com sucesso.\n");
                } else {
                    printf("Falha ao inserir. Verifique memoria ou limite.\n");
                }
                break;
            case 3:
                if (lista_encadeada_vazia(lista)) {
                    printf("Lista vazia. Nao ha elementos para remover.\n");
                    break;
                }
                id = ler_inteiro("ID para remover: ");
                mostrar_resultado_remocao(remover_lista_encadeada_por_id(lista, id, &removido), removido, "Elemento nao encontrado.");
                break;
            case 4:
                if (lista_encadeada_vazia(lista)) {
                    printf("Lista vazia. Nao ha elementos para buscar.\n");
                    break;
                }
                id = ler_inteiro("ID para buscar: ");
                if (buscar_lista_encadeada_por_id(lista, id, &encontrado)) {
                    printf("Elemento encontrado:\n");
                    imprimir_elemento(encontrado);
                } else {
                    printf("Elemento nao encontrado.\n");
                }
                break;
            case 5:
                exibir_lista_encadeada(lista);
                break;
            case 6:
                printf(lista_encadeada_vazia(lista) ? "A lista esta vazia.\n" : "A lista nao esta vazia.\n");
                break;
            case 7:
                printf("Quantidade de elementos: %d\n", quantidade_lista_encadeada(lista));
                break;
            case 8:
                printf(lista_encadeada_cheia(lista) ? "A lista esta cheia.\n" : "A lista nao esta cheia.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

static void menu_pilha(Pilha *pilha) {
    int opcao;
    Elemento elemento;
    Elemento removido;
    Elemento topo;

    do {
        printf("\n===== MENU DA PILHA =====\n");
        printf("1 - Empilhar elemento\n");
        printf("2 - Desempilhar elemento\n");
        printf("3 - Consultar topo\n");
        printf("4 - Exibir estrutura\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar quantidade de elementos\n");
        printf("7 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (pilha_cheia(pilha)) {
                    printf("Pilha cheia. Nao e possivel empilhar.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (empilhar(pilha, elemento)) {
                    printf("Elemento empilhado com sucesso.\n");
                } else {
                    printf("Falha ao empilhar.\n");
                }
                break;
            case 2:
                mostrar_resultado_remocao(desempilhar(pilha, &removido), removido, "Pilha vazia. Nao ha elementos para desempilhar.");
                break;
            case 3:
                if (consultar_topo(pilha, &topo)) {
                    printf("Topo da pilha:\n");
                    imprimir_elemento(topo);
                } else {
                    printf("Pilha vazia. Nao ha topo para consultar.\n");
                }
                break;
            case 4:
                exibir_pilha(pilha);
                break;
            case 5:
                printf(pilha_vazia(pilha) ? "A pilha esta vazia.\n" : "A pilha nao esta vazia.\n");
                break;
            case 6:
                printf("Quantidade de elementos: %d\n", quantidade_pilha(pilha));
                break;
            case 7:
                printf(pilha_cheia(pilha) ? "A pilha esta cheia.\n" : "A pilha nao esta cheia.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

static void menu_fila(Fila *fila) {
    int opcao;
    Elemento elemento;
    Elemento removido;
    Elemento inicio;

    do {
        printf("\n===== MENU DA FILA =====\n");
        printf("1 - Enfileirar elemento\n");
        printf("2 - Desenfileirar elemento\n");
        printf("3 - Consultar inicio da fila\n");
        printf("4 - Exibir estrutura\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar quantidade de elementos\n");
        printf("7 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (fila_cheia(fila)) {
                    printf("Fila cheia. Nao e possivel enfileirar.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (enfileirar(fila, elemento)) {
                    printf("Elemento enfileirado com sucesso.\n");
                } else {
                    printf("Falha ao enfileirar.\n");
                }
                break;
            case 2:
                mostrar_resultado_remocao(desenfileirar(fila, &removido), removido, "Fila vazia. Nao ha elementos para desenfileirar.");
                break;
            case 3:
                if (consultar_inicio_fila(fila, &inicio)) {
                    printf("Inicio da fila:\n");
                    imprimir_elemento(inicio);
                } else {
                    printf("Fila vazia. Nao ha inicio para consultar.\n");
                }
                break;
            case 4:
                exibir_fila(fila);
                break;
            case 5:
                printf(fila_vazia(fila) ? "A fila esta vazia.\n" : "A fila nao esta vazia.\n");
                break;
            case 6:
                printf("Quantidade de elementos: %d\n", quantidade_fila(fila));
                break;
            case 7:
                printf(fila_cheia(fila) ? "A fila esta cheia.\n" : "A fila nao esta cheia.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

static void menu_fila_circular(FilaCircular *fila) {
    int opcao;
    Elemento elemento;
    Elemento removido;
    Elemento inicio;
    Elemento fim;

    do {
        printf("\n===== MENU DA FILA CIRCULAR =====\n");
        printf("1 - Enfileirar elemento\n");
        printf("2 - Desenfileirar elemento\n");
        printf("3 - Consultar inicio\n");
        printf("4 - Consultar fim\n");
        printf("5 - Exibir estrutura\n");
        printf("6 - Verificar se esta cheia\n");
        printf("7 - Verificar se esta vazia\n");
        printf("8 - Verificar quantidade de elementos\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (fila_circular_cheia(fila)) {
                    printf("Fila circular cheia. Nao e possivel enfileirar.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (enfileirar_circular(fila, elemento)) {
                    printf("Elemento enfileirado com sucesso.\n");
                } else {
                    printf("Falha ao enfileirar.\n");
                }
                break;
            case 2:
                mostrar_resultado_remocao(desenfileirar_circular(fila, &removido), removido, "Fila circular vazia. Nao ha elementos para desenfileirar.");
                break;
            case 3:
                if (consultar_inicio_fila_circular(fila, &inicio)) {
                    printf("Inicio da fila circular:\n");
                    imprimir_elemento(inicio);
                } else {
                    printf("Fila circular vazia. Nao ha inicio para consultar.\n");
                }
                break;
            case 4:
                if (consultar_fim_fila_circular(fila, &fim)) {
                    printf("Fim da fila circular:\n");
                    imprimir_elemento(fim);
                } else {
                    printf("Fila circular vazia. Nao ha fim para consultar.\n");
                }
                break;
            case 5:
                exibir_fila_circular(fila);
                break;
            case 6:
                printf(fila_circular_cheia(fila) ? "A fila circular esta cheia.\n" : "A fila circular nao esta cheia.\n");
                break;
            case 7:
                printf(fila_circular_vazia(fila) ? "A fila circular esta vazia.\n" : "A fila circular nao esta vazia.\n");
                break;
            case 8:
                printf("Quantidade de elementos: %d\n", quantidade_fila_circular(fila));
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

static void menu_fila_dupla(FilaDupla *fila) {
    int opcao;
    Elemento elemento;
    Elemento removido;
    Elemento inicio;
    Elemento fim;

    do {
        printf("\n===== MENU DA FILA DUPLA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Remover do fim\n");
        printf("5 - Consultar inicio\n");
        printf("6 - Consultar fim\n");
        printf("7 - Exibir estrutura\n");
        printf("8 - Verificar se esta vazia\n");
        printf("9 - Verificar quantidade de elementos\n");
        printf("10 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (fila_dupla_cheia(fila)) {
                    printf("Fila dupla cheia. Nao e possivel inserir.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (inserir_inicio_fila_dupla(fila, elemento)) {
                    printf("Elemento inserido no inicio com sucesso.\n");
                } else {
                    printf("Falha ao inserir no inicio.\n");
                }
                break;
            case 2:
                if (fila_dupla_cheia(fila)) {
                    printf("Fila dupla cheia. Nao e possivel inserir.\n");
                    break;
                }
                elemento = ler_elemento_basico();
                if (inserir_fim_fila_dupla(fila, elemento)) {
                    printf("Elemento inserido no fim com sucesso.\n");
                } else {
                    printf("Falha ao inserir no fim.\n");
                }
                break;
            case 3:
                mostrar_resultado_remocao(remover_inicio_fila_dupla(fila, &removido), removido, "Fila dupla vazia. Nao ha elementos para remover do inicio.");
                break;
            case 4:
                mostrar_resultado_remocao(remover_fim_fila_dupla(fila, &removido), removido, "Fila dupla vazia. Nao ha elementos para remover do fim.");
                break;
            case 5:
                if (consultar_inicio_fila_dupla(fila, &inicio)) {
                    printf("Inicio da fila dupla:\n");
                    imprimir_elemento(inicio);
                } else {
                    printf("Fila dupla vazia. Nao ha inicio para consultar.\n");
                }
                break;
            case 6:
                if (consultar_fim_fila_dupla(fila, &fim)) {
                    printf("Fim da fila dupla:\n");
                    imprimir_elemento(fim);
                } else {
                    printf("Fila dupla vazia. Nao ha fim para consultar.\n");
                }
                break;
            case 7:
                exibir_fila_dupla(fila);
                break;
            case 8:
                printf(fila_dupla_vazia(fila) ? "A fila dupla esta vazia.\n" : "A fila dupla nao esta vazia.\n");
                break;
            case 9:
                printf("Quantidade de elementos: %d\n", quantidade_fila_dupla(fila));
                break;
            case 10:
                printf(fila_dupla_cheia(fila) ? "A fila dupla esta cheia.\n" : "A fila dupla nao esta cheia.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}

static void menu_fila_prioridade(FilaPrioridade *fila) {
    int opcao;
    Elemento elemento;
    Elemento removido;
    Elemento proximo;

    do {
        printf("\n===== MENU DA FILA DE PRIORIDADE =====\n");
        printf("1 - Inserir elemento com prioridade\n");
        printf("2 - Remover elemento de maior prioridade\n");
        printf("3 - Consultar proximo elemento a ser removido\n");
        printf("4 - Exibir fila ordenada por prioridade\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Verificar quantidade de elementos\n");
        printf("7 - Verificar se esta cheia\n");
        printf("0 - Voltar ao menu principal\n");

        opcao = ler_inteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                if (fila_prioridade_cheia(fila)) {
                    printf("Fila de prioridade cheia. Nao e possivel inserir.\n");
                    break;
                }
                elemento = ler_elemento_com_prioridade();
                if (inserir_fila_prioridade(fila, elemento)) {
                    printf("Elemento inserido com prioridade com sucesso.\n");
                } else {
                    printf("Falha ao inserir na fila de prioridade.\n");
                }
                break;
            case 2:
                mostrar_resultado_remocao(remover_maior_prioridade(fila, &removido), removido, "Fila de prioridade vazia. Nao ha elementos para remover.");
                break;
            case 3:
                if (consultar_proximo_prioridade(fila, &proximo)) {
                    printf("Proximo elemento a ser removido:\n");
                    imprimir_elemento(proximo);
                } else {
                    printf("Fila de prioridade vazia. Nao ha proximo elemento.\n");
                }
                break;
            case 4:
                exibir_fila_prioridade(fila);
                break;
            case 5:
                printf(fila_prioridade_vazia(fila) ? "A fila de prioridade esta vazia.\n" : "A fila de prioridade nao esta vazia.\n");
                break;
            case 6:
                printf("Quantidade de elementos: %d\n", quantidade_fila_prioridade(fila));
                break;
            case 7:
                printf(fila_prioridade_cheia(fila) ? "A fila de prioridade esta cheia.\n" : "A fila de prioridade nao esta cheia.\n");
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);
}
