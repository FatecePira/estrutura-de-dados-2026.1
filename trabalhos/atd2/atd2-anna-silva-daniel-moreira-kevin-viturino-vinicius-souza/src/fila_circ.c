#include "../include/fila_circ.h"

/* ---------- operacoes ---------- */

void fc_inicializar(FilaCircular *fc) {
    fc->inicio  = 0;
    fc->fim     = 0;
    fc->tamanho = 0;
}

int fc_vazia(FilaCircular *fc) {
    return fc->tamanho == 0;
}

int fc_cheia(FilaCircular *fc) {
    return fc->tamanho == MAX;
}

// Insercao explora a circularidade reaproveitando espacos do inicio
int fc_enfileirar(FilaCircular *fc, Elemento e) {
    if (fc_cheia(fc)) {
        printf("  ERRO: fila circular cheia (max %d elementos).\n", MAX);
        return 0;
    }
    fc->dados[fc->fim] = e; // Usa o espaco livre apontado por 'fim'
    fc->fim = (fc->fim + 1) % MAX;   // avanca circularmente para o proximo espaco vazio
    fc->tamanho++;
    
    // Mostra o indice real em que o elemento foi gravado
    printf("  Elemento enfileirado. fim agora em indice %d.\n",
           (fc->fim == 0 ? MAX - 1 : fc->fim - 1));
    return 1;
}

int fc_desenfileirar(FilaCircular *fc, Elemento *e) {
    if (fc_vazia(fc)) {
        printf("  ERRO: fila circular vazia.\n");
        return 0;
    }
    *e = fc->dados[fc->inicio]; // Tira quem esta na frente
    fc->inicio = (fc->inicio + 1) % MAX; // O inicio caminha circularmente pra frente
    fc->tamanho--;
    return 1;
}

int fc_consultar_inicio(FilaCircular *fc, Elemento *e) {
    if (fc_vazia(fc)) {
        printf("  ERRO: fila circular vazia.\n");
        return 0;
    }
    *e = fc->dados[fc->inicio];
    return 1;
}

int fc_consultar_fim(FilaCircular *fc, Elemento *e) {
    if (fc_vazia(fc)) {
        printf("  ERRO: fila circular vazia.\n");
        return 0;
    }
    // O ponteiro 'fim' sempre aponta pro proximo vazio. 
    // Logo, o elemento recem-chegado esta na casa (fim - 1). 
    // Somar MAX evita que a subtracao gere numero negativo, quebrando o codigo C.
    int ultimo = (fc->fim - 1 + MAX) % MAX;
    *e = fc->dados[ultimo]; // Resgata o ultimo da fila circular
    return 1;
}

void fc_exibir(FilaCircular *fc) {
    if (fc_vazia(fc)) {
        printf("  Fila circular vazia.\n");
        return;
    }
    printf("  Fila Circular (%d elemento(s)) [inicio=%d, fim=%d]:\n",
           fc->tamanho, fc->inicio, (fc->fim - 1 + MAX) % MAX);
    printf("  INICIO -> ");
    // Laco roda do 0 ao limite do tamanho
    for (int i = 0; i < fc->tamanho; i++) {
        // Encontra onde cada dado esta fisicamente na memoria do vetor
        int idx = (fc->inicio + i) % MAX;
        printf("[ID:%d | %s]", fc->dados[idx].id, fc->dados[idx].dados);
        if (i < fc->tamanho - 1) printf(" -> ");
    }
    printf(" (-> INICIO)\n\n");
    // Repete o laco para formatar a tabela
    for (int i = 0; i < fc->tamanho; i++) {
        int idx = (fc->inicio + i) % MAX;
        printf("  Pos %d (idx %d): ", i + 1, idx);
        imprimir_elemento(fc->dados[idx]);
    }
}

/* ---------- menu ---------- */

void menu_fila_circular(FilaCircular *fc) {
    int opcao;
    do {
        printf("\n===== MENU - FILA CIRCULAR =====\n");
        printf("  1 - Enfileirar\n");
        printf("  2 - Desenfileirar\n");
        printf("  3 - Consultar inicio\n");
        printf("  4 - Consultar fim\n");
        printf("  5 - Exibir fila circular\n");
        printf("  6 - Verificar se esta vazia\n");
        printf("  7 - Verificar se esta cheia\n");
        printf("  8 - Quantidade de elementos\n");
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
                fc_enfileirar(fc, e);
                break;

            case 2:
                if (fc_desenfileirar(fc, &e)) {
                    printf("  Elemento removido do inicio:\n");
                    imprimir_elemento(e);
                }
                break;

            case 3:
                if (fc_consultar_inicio(fc, &e)) {
                    printf("  Elemento no inicio da fila:\n");
                    imprimir_elemento(e);
                }
                break;

            case 4:
                if (fc_consultar_fim(fc, &e)) {
                    printf("  Elemento no fim da fila:\n");
                    imprimir_elemento(e);
                }
                break;

            case 5:
                fc_exibir(fc);
                break;

            case 6:
                printf("  Fila esta %s.\n", fc_vazia(fc) ? "VAZIA" : "NAO VAZIA");
                break;

            case 7:
                printf("  Fila esta %s.\n", fc_cheia(fc) ? "CHEIA" : "NAO CHEIA");
                break;

            case 8:
                printf("  Quantidade de elementos: %d\n", fc->tamanho);
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