#include "../include/lista_seq.h"

/* ---------- operacoes ---------- */

// Inicializa a lista definindo a quantidade de elementos ativos como zero
void ls_inicializar(ListaSequencial *ls) {
    ls->tamanho = 0;
}

// Retorna 1 (verdadeiro) se o tamanho for 0, indicando que esta vazia
int ls_vazia(ListaSequencial *ls) {
    return ls->tamanho == 0;
}

// Retorna a quantidade atual de itens na lista
int ls_tamanho(ListaSequencial *ls) {
    return ls->tamanho;
}

/* Insere elemento na posicao indicada (1-based).
   Desloca os seguintes para a direita. */
int ls_inserir(ListaSequencial *ls, int posicao, Elemento e) {
    // Verifica se ja chegou em 100 elementos (MAX)
    if (ls->tamanho >= MAX) {
        printf("  ERRO: lista cheia (max %d elementos).\n", MAX);
        return 0; // Retorna 0 (falso) pois falhou ao inserir
    }
    // A posicao digitada nao pode ser menor que 1 nem maior que o proximo espaco vazio
    if (posicao < 1 || posicao > ls->tamanho + 1) {
        printf("  ERRO: posicao invalida. Use entre 1 e %d.\n", ls->tamanho + 1);
        return 0;
    }
    int idx = posicao - 1; // Converte a posicao 1 (humana) para o indice 0 (linguagem C)
    
    // Laco FOR decrescente: comeca no fim da lista e empurra os elementos uma casa para a direita
    for (int i = ls->tamanho; i > idx; i--)
        ls->dados[i] = ls->dados[i - 1];
        
    ls->dados[idx] = e; // Insere o dado no 'buraco' que foi aberto pelo deslocamento
    ls->tamanho++;      // Atualiza o contador de tamanho da lista
    printf("  Elemento inserido na posicao %d com sucesso.\n", posicao);
    return 1; // Sucesso
}

/* Remove elemento na posicao indicada (1-based).
   Desloca os seguintes para a esquerda. */
int ls_remover(ListaSequencial *ls, int posicao) {
    if (ls_vazia(ls)) { // Nao pode remover de lista vazia
        printf("  ERRO: lista vazia.\n");
        return 0;
    }
    if (posicao < 1 || posicao > ls->tamanho) { // A posicao alvo tem que existir
        printf("  ERRO: posicao invalida. Use entre 1 e %d.\n", ls->tamanho);
        return 0;
    }
    int idx = posicao - 1; // Ajuste para o indice C
    printf("  Elemento removido: ");
    imprimir_elemento(ls->dados[idx]); // Exibe o elemento antes de sobrescreve-lo
    
    // Puxa todos os elementos da direita para a esquerda, sobrescrevendo o apagado
    for (int i = idx; i < ls->tamanho - 1; i++)
        ls->dados[i] = ls->dados[i + 1];
        
    ls->tamanho--; // Reduz o tamanho total
    return 1;
}

/* Busca por id, retorna posicao (1-based) ou -1. */
int ls_buscar(ListaSequencial *ls, int id) {
    // Varre o vetor do comeco ao fim (ate ls->tamanho)
    for (int i = 0; i < ls->tamanho; i++) {
        if (ls->dados[i].id == id) // Se achar o ID...
            return i + 1;          // Retorna a posicao humana (indice + 1)
    }
    return -1; // Retorna -1 se rodar o laco todo e nao achar
}

void ls_exibir(ListaSequencial *ls) {
    if (ls_vazia(ls)) {
        printf("  Lista vazia.\n");
        return;
    }
    // Cabecalho de exibicao
    printf("  Lista Sequencial (%d elemento(s)):\n", ls->tamanho);
    printf("  %-5s  %s\n", "Pos.", "Elemento");
    printf("  %s\n", "-------------------------------------------------------");
    // Laco para imprimir item por item
    for (int i = 0; i < ls->tamanho; i++) {
        printf("  %-5d", i + 1); // Imprime a posicao (formatada com 5 espacos)
        imprimir_elemento(ls->dados[i]); // Imprime os dados usando a funcao comum
    }
}

/* ---------- menu ---------- */

void menu_lista_sequencial(ListaSequencial *ls) {
    int opcao;
    do {
        // Exibicao do submenu exato exigido pelo PDF
        printf("\n===== MENU - LISTA SEQUENCIAL =====\n");
        printf("  1 - Inserir elemento\n");
        printf("  2 - Remover elemento\n");
        printf("  3 - Buscar elemento por ID\n");
        printf("  4 - Exibir lista\n");
        printf("  5 - Verificar se esta vazia\n");
        printf("  6 - Quantidade de elementos\n");
        printf("  0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        Elemento e; // Variavel temporaria para recolher os dados do usuario
        int pos, id, result;

        switch (opcao) {
            case 1:
                printf("  ID do elemento: ");
                scanf("%d", &e.id);
                limpar_buffer();
                printf("  Dados (texto): ");
                fgets(e.dados, sizeof(e.dados), stdin); // fgets permite ler strings com espaco
                e.dados[strcspn(e.dados, "\n")] = '\0'; // Remove o 'Enter' que o fgets captura no final da string
                e.prioridade = 0;
                printf("  Posicao para inserir (1 a %d): ", ls->tamanho + 1);
                scanf("%d", &pos);
                limpar_buffer();
                ls_inserir(ls, pos, e); // Manda o dado coletado para a funcao inserir
                break;

            case 2:
                if (ls_vazia(ls)) { printf("  Lista vazia.\n"); break; }
                ls_exibir(ls); // Exibe antes para o usuario saber o que pode remover
                printf("  Posicao para remover: ");
                scanf("%d", &pos);
                limpar_buffer();
                ls_remover(ls, pos);
                break;

            case 3:
                printf("  ID para buscar: ");
                scanf("%d", &id);
                limpar_buffer();
                result = ls_buscar(ls, id); // Recebe o retorno da busca (-1 se nao achar)
                if (result == -1)
                    printf("  Elemento com ID %d nao encontrado.\n", id);
                else {
                    printf("  Encontrado na posicao %d:\n", result);
                    imprimir_elemento(ls->dados[result - 1]); // Imprime o elemento encontrado
                }
                break;

            case 4:
                ls_exibir(ls);
                break;

            case 5:
                // Uso do operador ternario (condicao ? verdadeiro : falso)
                printf("  Lista esta %s.\n", ls_vazia(ls) ? "VAZIA" : "NAO VAZIA");
                break;

            case 6:
                printf("  Quantidade de elementos: %d\n", ls_tamanho(ls));
                break;

            case 0:
                printf("  Voltando ao menu principal...\n");
                break;

            default:
                printf("  Opcao invalida.\n");
        }
        if (opcao != 0) pausar(); // Se nao for pra sair, pausa a tela
    } while (opcao != 0);
}