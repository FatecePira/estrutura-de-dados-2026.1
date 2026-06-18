#include "../include/lista_enc.h"

/* ---------- operacoes ---------- */

void le_inicializar(ListaEncadeada *le) {
    le->cabeca = NULL; // NULL significa que o ponteiro nao aponta para canto nenhum (lista vazia)
    le->tamanho = 0;
}

int le_vazia(ListaEncadeada *le) {
    return le->cabeca == NULL; // Se a cabeca for NULL, a lista esta vazia
}

int le_inserir_inicio(ListaEncadeada *le, Elemento e) {
    if (le->tamanho >= MAX) { // Valida limite estipulado pelo professor
        printf("  ERRO: lista cheia (max %d elementos).\n", MAX);
        return 0;
    }
    // malloc: Aloca dinamicamente um bloco de memoria RAM do tamanho exato da struct 'No'
    No *novo = (No *)malloc(sizeof(No));
    // Se o sistema operacional negar memoria, o 'novo' sera NULL
    if (!novo) { printf("  ERRO: falha de alocacao de memoria.\n"); return 0; }
    
    novo->dado = e;             // Grava o conteudo na area de dados do No
    novo->proximo = le->cabeca; // O novo No aponta para onde a cabeca apontava antes
    le->cabeca = novo;          // A cabeca muda e passa a apontar para esse novo No
    le->tamanho++;
    printf("  Elemento inserido no inicio com sucesso.\n");
    return 1;
}

int le_inserir_fim(ListaEncadeada *le, Elemento e) {
    if (le->tamanho >= MAX) {
        printf("  ERRO: lista cheia (max %d elementos).\n", MAX);
        return 0;
    }
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) { printf("  ERRO: falha de alocacao de memoria.\n"); return 0; }
    novo->dado = e;
    novo->proximo = NULL; // Como ele sera o ultimo da lista, o seu proximo eh NULL

    if (le_vazia(le)) {
        le->cabeca = novo; // Caso especial: se a lista tava vazia, ele eh o inicio e o fim ao mesmo tempo
    } else {
        No *atual = le->cabeca; // Cria um ponteiro auxiliar para viajar pela lista a partir da cabeca
        while (atual->proximo != NULL) // Vai pulando de No em No ate achar o ultimo (aquele cujo proximo e NULL)
            atual = atual->proximo;
        atual->proximo = novo; // Chegou no ultimo! Agora faz o antigo ultimo apontar para o novo No
    }
    le->tamanho++;
    printf("  Elemento inserido no fim com sucesso.\n");
    return 1;
}

/* Remove no com o id fornecido; retorna 1 se removeu, 0 caso contrario. */
int le_remover_por_id(ListaEncadeada *le, int id) {
    if (le_vazia(le)) {
        printf("  ERRO: lista vazia.\n");
        return 0;
    }
    No *atual = le->cabeca;  // Ponteiro que vai navegar para procurar o ID
    No *anterior = NULL;     // Ponteiro que vai ficar um passo atras do 'atual'

    // Enquanto nao chegar no final da lista e nao achar o ID, continua andando
    while (atual != NULL && atual->dado.id != id) {
        anterior = atual;       // O 'anterior' guarda a posicao de onde estamos agora
        atual = atual->proximo; // O 'atual' da um passo pra frente
    }
    if (atual == NULL) { // Chegou no fim da lista e nao achou
        printf("  Elemento com ID %d nao encontrado.\n", id);
        return 0;
    }
    printf("  Elemento removido: ");
    imprimir_elemento(atual->dado);

    if (anterior == NULL)          // Caso especial: o elemento que queremos apagar era o primeiro da lista
        le->cabeca = atual->proximo; // A cabeca da lista pula o atual e aponta para o segundo No
    else // O elemento esta no meio ou no fim
        anterior->proximo = atual->proximo; // O No 'anterior' desvia sua seta e aponta direto para o proximo do 'atual'

    free(atual); // Libera o bloco de memoria RAM na qual o 'atual' estava
    le->tamanho--;
    return 1;
}

/* Busca por id; retorna posicao (1-based) ou -1 se nao encontrado. */
int le_buscar_por_id(ListaEncadeada *le, int id) {
    No *atual = le->cabeca;
    int pos = 1; // Contador humano (comeca do 1)
    while (atual != NULL) { // Navega ate o fim da lista
        if (atual->dado.id == id) {
            printf("  Encontrado na posicao %d:\n", pos);
            imprimir_elemento(atual->dado);
            return pos;
        }
        atual = atual->proximo; // Avanca para o proximo No
        pos++;                  // Aumenta o contador de posicao
    }
    return -1;
}

void le_exibir(ListaEncadeada *le) {
    if (le_vazia(le)) {
        printf("  Lista vazia.\n");
        return;
    }
    printf("  Lista Encadeada (%d elemento(s)):\n", le->tamanho);
    printf("  INICIO -> ");
    No *atual = le->cabeca;
    // Laco para desenhar os bloquinhos da lista na tela: [ID] -> [ID] -> FIM
    while (atual != NULL) {
        printf("[ID:%d | %s]", atual->dado.id, atual->dado.dados);
        if (atual->proximo != NULL) printf(" -> ");
        atual = atual->proximo;
    }
    printf(" -> FIM\n\n");

    // detalhes: repete a navegacao para imprimir a tabela vertical
    atual = le->cabeca;
    int pos = 1;
    while (atual != NULL) {
        printf("  Pos %d: ", pos++);
        imprimir_elemento(atual->dado);
        atual = atual->proximo;
    }
}

// Funcao critica: chamada no final do main para limpar os lixos de memoria (mallocs sem free)
void le_liberar(ListaEncadeada *le) {
    No *atual = le->cabeca;
    while (atual != NULL) {
        No *prox = atual->proximo; // Salva o endereco do proximo ANTES de matar o atual
        free(atual);               // Apaga o No atual da RAM
        atual = prox;              // Pula para o proximo No salvo
    }
    le->cabeca = NULL; // Apos apagar tudo, reseta a cabeca
    le->tamanho = 0;
}

/* ---------- menu ---------- */

void menu_lista_encadeada(ListaEncadeada *le) {
    int opcao;
    do {
        printf("\n===== MENU - LISTA SIMPLESMENTE ENCADEADA =====\n");
        printf("  1 - Inserir no inicio\n");
        printf("  2 - Inserir no fim\n");
        printf("  3 - Remover por ID\n");
        printf("  4 - Buscar por ID\n");
        printf("  5 - Exibir lista\n");
        printf("  6 - Verificar se esta vazia\n");
        printf("  7 - Quantidade de elementos\n");
        printf("  0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        Elemento e;
        int id;

        // O switch chama as respectivas funcoes passando a estrutura de controle (le)
        switch (opcao) {
            case 1:
                printf("  ID do elemento: ");
                scanf("%d", &e.id);
                limpar_buffer();
                printf("  Dados (texto): ");
                fgets(e.dados, sizeof(e.dados), stdin);
                e.dados[strcspn(e.dados, "\n")] = '\0';
                e.prioridade = 0;
                le_inserir_inicio(le, e); // Chama insercao no inicio
                break;

            case 2:
                printf("  ID do elemento: ");
                scanf("%d", &e.id);
                limpar_buffer();
                printf("  Dados (texto): ");
                fgets(e.dados, sizeof(e.dados), stdin);
                e.dados[strcspn(e.dados, "\n")] = '\0';
                e.prioridade = 0;
                le_inserir_fim(le, e); // Chama insercao no fim
                break;

            case 3:
                printf("  ID para remover: ");
                scanf("%d", &id);
                limpar_buffer();
                le_remover_por_id(le, id); // Chama a remocao passando o ID pesquisado
                break;

            case 4:
                printf("  ID para buscar: ");
                scanf("%d", &id);
                limpar_buffer();
                if (le_buscar_por_id(le, id) == -1) // Se retornar -1, exibe erro
                    printf("  Elemento com ID %d nao encontrado.\n", id);
                break;

            case 5:
                le_exibir(le);
                break;

            case 6:
                printf("  Lista esta %s.\n", le_vazia(le) ? "VAZIA" : "NAO VAZIA");
                break;

            case 7:
                printf("  Quantidade de elementos: %d\n", le->tamanho);
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