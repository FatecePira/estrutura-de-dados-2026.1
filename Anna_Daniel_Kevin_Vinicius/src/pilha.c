#include "../include/pilha.h"

/* ---------- operacoes ---------- */

// Inicializa a pilha definindo o topo como -1 (vazia)
void pi_inicializar(Pilha *p) {
    p->topo = -1; // Na linguagem C, indices comecam em 0. Entao -1 significa "nao ha elementos".
}

// Retorna 1 se o topo for -1 (verdadeiro, vazia) ou 0 caso contrario (falso)
int pi_vazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se atingiu o limite maximo definido no comum.h (MAX 100)
int pi_cheia(Pilha *p) {
    return p->topo == MAX - 1; // Se MAX eh 100, o ultimo indice do vetor eh 99.
}

// Adiciona um elemento no topo da pilha (Push)
int pi_empilhar(Pilha *p, Elemento e) {
    if (pi_cheia(p)) { // Nao pode empilhar se o vetor estiver cheio
        printf("  ERRO: pilha cheia (max %d elementos).\n", MAX);
        return 0; // Retorna falso
    }
    // ++p->topo (Pre-incremento): Sobe o nivel do topo em 1, e SOH DEPOIS grava o dado 'e' nessa posicao
    p->dados[++p->topo] = e;
    printf("  Elemento empilhado com sucesso. Topo: %d\n", p->topo + 1); // +1 para visualizacao humana
    return 1; // Retorna sucesso
}

// Remove o elemento do topo da pilha (Pop)
int pi_desempilhar(Pilha *p, Elemento *e) {
    if (pi_vazia(p)) { // Valida subfluxo (tentar tirar de onde nao tem)
        printf("  ERRO: pilha vazia.\n");
        return 0;
    }
    // p->topo-- (Pos-decremento): Pega o dado do topo atual, joga no ponteiro '*e', e DEPOIS desce o topo em 1
    *e = p->dados[p->topo--];
    return 1;
}

// Apenas espia qual elemento esta no topo, sem remove-lo (Peek)
int pi_topo(Pilha *p, Elemento *e) {
    if (pi_vazia(p)) {
        printf("  ERRO: pilha vazia.\n");
        return 0;
    }
    // Apenas copia o dado para o ponteiro '*e', deixando o indice 'topo' intacto
    *e = p->dados[p->topo];
    return 1;
}

// Desenha a pilha na tela de forma visual
void pi_exibir(Pilha *p) {
    if (pi_vazia(p)) {
        printf("  Pilha vazia.\n");
        return;
    }
    printf("  Pilha (%d elemento(s)) - topo para base:\n", p->topo + 1);
    printf("  +------------------------------------------------------+\n");
    printf("  | TOPO                                                 |\n");
    // Laco decrescente: imprime os itens de cima (topo) para baixo (0)
    for (int i = p->topo; i >= 0; i--) {
        printf("  | ");
        imprimir_elemento(p->dados[i]); // Imprime o dado usando a funcao padrao do comum.c
    }
    printf("  | BASE                                                 |\n");
    printf("  +------------------------------------------------------+\n");
}

/* ---------- menu ---------- */

void menu_pilha(Pilha *p) {
    int opcao;
    do {
        // Opcoes do submenu especifico da Pilha
        printf("\n===== MENU - PILHA (LIFO) =====\n");
        printf("  1 - Empilhar (push)\n");
        printf("  2 - Desempilhar (pop)\n");
        printf("  3 - Consultar topo (peek)\n");
        printf("  4 - Exibir pilha\n");
        printf("  5 - Verificar se esta vazia\n");
        printf("  6 - Verificar se esta cheia\n");
        printf("  7 - Quantidade de elementos\n");
        printf("  0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer(); // Limpa o '\n' do teclado

        Elemento e; // Variavel temporaria para carregar dados inseridos ou removidos

        switch (opcao) {
            case 1:
                printf("  ID do elemento: ");
                scanf("%d", &e.id);
                limpar_buffer();
                printf("  Dados (texto): ");
                fgets(e.dados, sizeof(e.dados), stdin);
                e.dados[strcspn(e.dados, "\n")] = '\0'; // Remove quebra de linha extra capturada pelo fgets
                e.prioridade = 0; // Pilha nao usa prioridade, entao zera
                pi_empilhar(p, e); // Chama operacao de insercao
                break;

            case 2:
                // Tenta desempilhar. Se retornar 1, sucesso, entao entra no IF e imprime o que foi tirado
                if (pi_desempilhar(p, &e)) {
                    printf("  Elemento desempilhado:\n");
                    imprimir_elemento(e);
                }
                break;

            case 3:
                // Tenta espiar o topo. Se sucesso, imprime o que viu.
                if (pi_topo(p, &e)) {
                    printf("  Elemento no topo:\n");
                    imprimir_elemento(e);
                }
                break;

            case 4:
                pi_exibir(p);
                break;

            case 5:
                printf("  Pilha esta %s.\n", pi_vazia(p) ? "VAZIA" : "NAO VAZIA");
                break;

            case 6:
                printf("  Pilha esta %s.\n", pi_cheia(p) ? "CHEIA" : "NAO CHEIA");
                break;

            case 7:
                printf("  Quantidade de elementos: %d\n", p->topo + 1); // +1 pq o topo comeca no indice 0
                break;

            case 0:
                printf("  Voltando ao menu principal...\n");
                break;

            default:
                printf("  Opcao invalida.\n");
        }
        if (opcao != 0) pausar();
    } while (opcao != 0);
}