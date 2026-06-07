#include "../include/fila.h"

/* ---------- operacoes ---------- */

// Prepara a fila para uso pela primeira vez
void fi_inicializar(Fila *f) {
    f->inicio  = 0; // Ponteiro logico de onde lemos dados (frente)
    f->fim     = 0; // Ponteiro logico de onde escrevemos dados (tras)
    f->tamanho = 0; // Quantos elementos a fila contem
}

int fi_vazia(Fila *f) {
    return f->tamanho == 0; // Sem tamanho = fila zerada
}

int fi_cheia(Fila *f) {
    return f->tamanho == MAX; // Bateu os 100 elementos permitidos (MAX)
}

// Enfileirar (Adicionar no final da fila)
int fi_enfileirar(Fila *f, Elemento e) {
    if (fi_cheia(f)) {
        printf("  ERRO: fila cheia (max %d elementos).\n", MAX);
        return 0; // Nao insere
    }
    // Grava o elemento no final da fila
    f->dados[f->fim] = e;
    // Avanca o ponteiro do 'fim'. O modulo (% MAX) faz o indice voltar a zero se passar do limite.
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++; // Eleva contador de pessoas na fila
    printf("  Elemento enfileirado com sucesso.\n");
    return 1;
}

// Desenfileirar (Remover do inicio da fila)
int fi_desenfileirar(Fila *f, Elemento *e) {
    if (fi_vazia(f)) {
        printf("  ERRO: fila vazia.\n");
        return 0;
    }
    // Captura os dados do primeiro da fila e joga no ponteiro de saida '*e'
    *e = f->dados[f->inicio];
    // Avanca o ponteiro do 'inicio', efetivamente "esquecendo" o item que acabou de sair
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--; // Reduz a contagem de elementos na fila
    return 1;
}

// Espia quem e o proximo a ser atendido
int fi_consultar_inicio(Fila *f, Elemento *e) {
    if (fi_vazia(f)) {
        printf("  ERRO: fila vazia.\n");
        return 0;
    }
    *e = f->dados[f->inicio]; // Copia o dado, mas nao altera o indice inicio
    return 1;
}

// Exibe a fila visualmente da frente para tras
void fi_exibir(Fila *f) {
    if (fi_vazia(f)) {
        printf("  Fila vazia.\n");
        return;
    }
    printf("  Fila FIFO (%d elemento(s)) - frente para tras:\n", f->tamanho);
    printf("  FRENTE -> ");
    // Laco varre todos os elementos contidos atualmente na fila
    for (int i = 0; i < f->tamanho; i++) {
        // Calcula a posicao real no vetor usando a base circular (inicio + incremento % MAX)
        int idx = (f->inicio + i) % MAX;
        printf("[ID:%d | %s]", f->dados[idx].id, f->dados[idx].dados);
        if (i < f->tamanho - 1) printf(" -> "); // Desenha setas apenas entre os elementos
    }
    printf(" <- TRAS\n\n");
    // Laco secundario para imprimir a tabela detalhada vertical
    for (int i = 0; i < f->tamanho; i++) {
        int idx = (f->inicio + i) % MAX;
        printf("  Pos %d: ", i + 1);
        imprimir_elemento(f->dados[idx]);
    }
}

/* ---------- menu ---------- */

void menu_fila(Fila *f) {
    int opcao;
    do {
        printf("\n===== MENU - FILA (FIFO) =====\n");
        printf("  1 - Enfileirar\n");
        printf("  2 - Desenfileirar\n");
        printf("  3 - Consultar inicio da fila\n");
        printf("  4 - Exibir fila\n");
        printf("  5 - Verificar se esta vazia\n");
        printf("  6 - Verificar se esta cheia\n");
        printf("  7 - Quantidade de elementos\n");
        printf("  0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        Elemento e;

        switch (opcao) {
            case 1:
                printf("  ID do elemento: ");
                scanf("%d", &e.id);
                limpar_buffer();
                printf("  Dados (texto): ");
                fgets(e.dados, sizeof(e.dados), stdin);
                e.dados[strcspn(e.dados, "\n")] = '\0';
                e.prioridade = 0;
                fi_enfileirar(f, e); // Coloca na fila
                break;

            case 2:
                if (fi_desenfileirar(f, &e)) { // Retira e guarda em 'e'
                    printf("  Elemento desenfileirado:\n");
                    imprimir_elemento(e);
                }
                break;

            case 3:
                if (fi_consultar_inicio(f, &e)) { // Espia a frente
                    printf("  Elemento na frente da fila:\n");
                    imprimir_elemento(e);
                }
                break;

            case 4:
                fi_exibir(f);
                break;

            case 5:
                printf("  Fila esta %s.\n", fi_vazia(f) ? "VAZIA" : "NAO VAZIA");
                break;

            case 6:
                printf("  Fila esta %s.\n", fi_cheia(f) ? "CHEIA" : "NAO CHEIA");
                break;

            case 7:
                printf("  Quantidade de elementos: %d\n", f->tamanho);
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