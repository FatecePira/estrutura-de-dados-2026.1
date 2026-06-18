#include "../include/fila_prio.h"

/* Implementacao com vetor nao-ordenado; remove-se sempre o de maior prioridade.
   Prioridade MAIOR = remove primeiro (max-heap simples via busca linear). */

void fp_inicializar(FilaPrioridade *fp) {
    fp->tamanho = 0;
}

int fp_vazia(FilaPrioridade *fp) {
    return fp->tamanho == 0;
}

int fp_cheia(FilaPrioridade *fp) {
    return fp->tamanho == MAX;
}

/* Retorna o indice do elemento de maior prioridade (Logica crucial deste arquivo) */
static int fp_indice_max(FilaPrioridade *fp) {
    int max_idx = 0; // Assume temporariamente que o primeiro item do vetor tem a maior urgencia
    
    // Varre todos os outros elementos do vetor a partir da posicao 1
    for (int i = 1; i < fp->tamanho; i++) {
        // Testa: "Se a prioridade do sujeito 'i' for MAIOR que a do campeao atual (max_idx)..."
        if (fp->dados[i].prioridade > fp->dados[max_idx].prioridade)
            max_idx = i; // "... o sujeito 'i' passa a ser o novo campeao"
    }
    return max_idx; // Devolve o indice exato de onde esta a pessoa mais urgente
}

int fp_inserir(FilaPrioridade *fp, Elemento e) {
    if (fp_cheia(fp)) {
        printf("  ERRO: fila de prioridade cheia (max %d elementos).\n", MAX);
        return 0;
    }
    // Como o vetor e baguncado (nao-ordenado fisicamente), joga a pessoa no final do vetor e soma +1 ao tamanho
    fp->dados[fp->tamanho++] = e;
    printf("  Elemento inserido com prioridade %d.\n", e.prioridade);
    return 1;
}

/* Remove o elemento de maior prioridade. */
int fp_remover(FilaPrioridade *fp, Elemento *e) {
    if (fp_vazia(fp)) {
        printf("  ERRO: fila de prioridade vazia.\n");
        return 0;
    }
    int idx = fp_indice_max(fp); // Pede para a funcao buscar quem e o mais urgente
    *e = fp->dados[idx];         // Salva os dados do sujeito que vai sair
    
    // TRUQUE DE OTIMIZACAO: move o ultimo elemento do vetor para tampar o buraco de quem acabou de sair
    fp->dados[idx] = fp->dados[fp->tamanho - 1]; 
    fp->tamanho--; // O tamanho e reduzido. O buraco sumiu sem precisar deslocar ninguem
    return 1;
}

int fp_consultar_proximo(FilaPrioridade *fp, Elemento *e) {
    if (fp_vazia(fp)) {
        printf("  ERRO: fila de prioridade vazia.\n");
        return 0;
    }
    // Acha o indice de quem tem a maior prioridade e so espia o valor (nao apaga)
    *e = fp->dados[fp_indice_max(fp)];
    return 1;
}

/* Exibe ordenado por prioridade (maior primeiro) sem alterar a estrutura fisicamente. */
void fp_exibir(FilaPrioridade *fp) {
    if (fp_vazia(fp)) {
        printf("  Fila de prioridade vazia.\n");
        return;
    }
    // Cria uma copia provisoria do vetor inteiro (para podermos organizar sem estragar o original)
    Elemento copia[MAX];
    memcpy(copia, fp->dados, fp->tamanho * sizeof(Elemento)); // Copia em bloco de memoria
    int n = fp->tamanho;

    // Algoritmo de ordenacao classico (Bubble Sort) em ordem decrescente (Maior pro Menor)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Se o atual for MENOR que o proximo da lista
            if (copia[j].prioridade < copia[j + 1].prioridade) {
                // Inverte os dois de lugar (troca) usando variavel temporaria
                Elemento tmp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = tmp;
            }
        }
    }

    printf("  Fila de Prioridade (%d elemento(s)) - maior prioridade primeiro:\n", n);
    printf("  %-6s  %-10s  %s\n", "Ordem", "Prioridade", "Elemento");
    printf("  %s\n", "-------------------------------------------------------------");
    // Agora imprime a copia que ja foi perfeitamente organizada pelo Bubble Sort
    for (int i = 0; i < n; i++) {
        printf("  %-6d  %-10d  ", i + 1, copia[i].prioridade);
        imprimir_elemento(copia[i]);
    }
}

/* ---------- menu ---------- */

void menu_fila_prioridade(FilaPrioridade *fp) {
    int opcao;
    do {
        printf("\n===== MENU - FILA DE PRIORIDADE =====\n");
        printf("  1 - Inserir elemento com prioridade\n");
        printf("  2 - Remover elemento de maior prioridade\n");
        printf("  3 - Consultar proximo a ser removido\n");
        printf("  4 - Exibir fila ordenada por prioridade\n");
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
                // DIFERENCIAL AQUI: Pede explicitamente a urgencia (prioridade) do item
                printf("  Prioridade (inteiro, maior = mais urgente): ");
                scanf("%d", &e.prioridade); 
                limpar_buffer();
                fp_inserir(fp, e);
                break;

            case 2:
                // A remocao e "cega" quanto ao ID. Ela tira quem tem maior numero em 'e.prioridade'
                if (fp_remover(fp, &e)) {
                    printf("  Elemento removido (maior prioridade):\n");
                    imprimir_elemento(e);
                }
                break;

            case 3:
                if (fp_consultar_proximo(fp, &e)) {
                    printf("  Proximo a ser removido:\n");
                    imprimir_elemento(e);
                }
                break;

            case 4:
                fp_exibir(fp);
                break;

            case 5:
                printf("  Fila esta %s.\n", fp_vazia(fp) ? "VAZIA" : "NAO VAZIA");
                break;

            case 6:
                printf("  Fila esta %s.\n", fp_cheia(fp) ? "CHEIA" : "NAO CHEIA");
                break;

            case 7:
                printf("  Quantidade de elementos: %d\n", fp->tamanho);
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