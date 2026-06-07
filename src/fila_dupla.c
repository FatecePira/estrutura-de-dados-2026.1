#include "../include/fila_dupla.h"

/* Implementacao com vetor de tamanho fixo (deque baseado em array circular). */

void fd_inicializar(FilaDupla *fd) {
    fd->inicio  = 0;
    fd->fim     = 0;
    fd->tamanho = 0;
}

int fd_vazia(FilaDupla *fd) {
    return fd->tamanho == 0;
}

int fd_cheia(FilaDupla *fd) {
    return fd->tamanho == MAX;
}

/* Insere no inicio: recua o ponteiro inicio circularmente. */
int fd_inserir_inicio(FilaDupla *fd, Elemento e) {
    if (fd_cheia(fd)) {
        printf("  ERRO: fila dupla cheia (max %d elementos).\n", MAX);
        return 0;
    }
    // Para recuar, faz -1. Soma MAX antes do % MAX para evitar dar "Resto Negativo".
    fd->inicio = (fd->inicio - 1 + MAX) % MAX;
    fd->dados[fd->inicio] = e; // Insere o dado na posicao recuada conquistada
    fd->tamanho++;
    printf("  Elemento inserido no inicio com sucesso.\n");
    return 1;
}

/* Insere no fim: usa o ponteiro fim e avanca normalmente. */
int fd_inserir_fim(FilaDupla *fd, Elemento e) {
    if (fd_cheia(fd)) {
        printf("  ERRO: fila dupla cheia (max %d elementos).\n", MAX);
        return 0;
    }
    fd->dados[fd->fim] = e; // Grava no local indicado pelo Fim
    fd->fim = (fd->fim + 1) % MAX; // O fim avanca para o proximo indice
    fd->tamanho++;
    printf("  Elemento inserido no fim com sucesso.\n");
    return 1;
}

// Remove de quem esta na cabeca (inicio) da fila dupla
int fd_remover_inicio(FilaDupla *fd, Elemento *e) {
    if (fd_vazia(fd)) {
        printf("  ERRO: fila dupla vazia.\n");
        return 0;
    }
    *e = fd->dados[fd->inicio];          // Pega o dado do inicio
    fd->inicio = (fd->inicio + 1) % MAX; // Incolhe a fila movendo o inicio pra frente
    fd->tamanho--;
    return 1;
}

// Remove quem esta na calda (fim) da fila dupla
int fd_remover_fim(FilaDupla *fd, Elemento *e) {
    if (fd_vazia(fd)) {
        printf("  ERRO: fila dupla vazia.\n");
        return 0;
    }
    // O fim real e uma casa atras do ponteiro 'fim' (pois 'fim' aponta pro proximo espaco vazio). 
    // Entao recuamos o fim.
    fd->fim = (fd->fim - 1 + MAX) % MAX;
    *e = fd->dados[fd->fim]; // Resgata e "apaga" esse elemento da fila
    fd->tamanho--;
    return 1;
}

int fd_consultar_inicio(FilaDupla *fd, Elemento *e) {
    if (fd_vazia(fd)) {
        printf("  ERRO: fila dupla vazia.\n");
        return 0;
    }
    *e = fd->dados[fd->inicio];
    return 1;
}

int fd_consultar_fim(FilaDupla *fd, Elemento *e) {
    if (fd_vazia(fd)) {
        printf("  ERRO: fila dupla vazia.\n");
        return 0;
    }
    int ultimo = (fd->fim - 1 + MAX) % MAX; // Calcula posicao da cauda
    *e = fd->dados[ultimo];
    return 1;
}

void fd_exibir(FilaDupla *fd) {
    if (fd_vazia(fd)) {
        printf("  Fila dupla vazia.\n");
        return;
    }
    printf("  Fila Dupla / Deque (%d elemento(s)):\n", fd->tamanho);
    printf("  INICIO <-> ");
    for (int i = 0; i < fd->tamanho; i++) {
        int idx = (fd->inicio + i) % MAX;
        printf("[ID:%d | %s]", fd->dados[idx].id, fd->dados[idx].dados);
        if (i < fd->tamanho - 1) printf(" <-> ");
    }
    printf(" <-> FIM\n\n");
    for (int i = 0; i < fd->tamanho; i++) {
        int idx = (fd->inicio + i) % MAX;
        printf("  Pos %d: ", i + 1);
        imprimir_elemento(fd->dados[idx]);
    }
}

/* ---------- menu ---------- */

void menu_fila_dupla(FilaDupla *fd) {
    int opcao;
    do {
        printf("\n===== MENU - FILA DUPLA (DEQUE) =====\n");
        printf("  1 - Inserir no inicio\n");
        printf("  2 - Inserir no fim\n");
        printf("  3 - Remover do inicio\n");
        printf("  4 - Remover do fim\n");
        printf("  5 - Consultar inicio\n");
        printf("  6 - Consultar fim\n");
        printf("  7 - Exibir fila\n");
        printf("  8 - Verificar se esta vazia\n");
        printf("  9 - Verificar se esta cheia\n");
        printf("  10 - Quantidade de elementos\n");
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
                fd_inserir_inicio(fd, e);
                break;

            case 2:
                printf("  ID do elemento: ");
                scanf("%d", &e.id);
                limpar_buffer();
                printf("  Dados (texto): ");
                fgets(e.dados, sizeof(e.dados), stdin);
                e.dados[strcspn(e.dados, "\n")] = '\0';
                e.prioridade = 0;
                fd_inserir_fim(fd, e);
                break;

            case 3:
                if (fd_remover_inicio(fd, &e)) {
                    printf("  Elemento removido do inicio:\n");
                    imprimir_elemento(e);
                }
                break;

            case 4:
                if (fd_remover_fim(fd, &e)) {
                    printf("  Elemento removido do fim:\n");
                    imprimir_elemento(e);
                }
                break;

            case 5:
                if (fd_consultar_inicio(fd, &e)) {
                    printf("  Elemento no inicio:\n");
                    imprimir_elemento(e);
                }
                break;

            case 6:
                if (fd_consultar_fim(fd, &e)) {
                    printf("  Elemento no fim:\n");
                    imprimir_elemento(e);
                }
                break;

            case 7:
                fd_exibir(fd);
                break;

            case 8:
                printf("  Fila esta %s.\n", fd_vazia(fd) ? "VAZIA" : "NAO VAZIA");
                break;

            case 9:
                printf("  Fila esta %s.\n", fd_cheia(fd) ? "CHEIA" : "NAO CHEIA");
                break;

            case 10:
                printf("  Quantidade de elementos: %d\n", fd->tamanho);
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