#include "listaSimplesEncadeada.h"

// Inicializa a lista
void inicializarListaEncadeada(ListaEncadeada *l)
{
    l->inicio = NULL;
    l->quantidade = 0;
}
int estaVaziaEncadeada(ListaEncadeada *l)
{
    return l->inicio == NULL && l->quantidade == 0;
}
// Inserir no Início
int inserirNoInicio(ListaEncadeada *l, int valor)
{
    if (l->quantidade >= 100)
    {
        printf("Erro: Limite de 100 elementos atingido!\n");
        return 0;
    }
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0; // Falha de memória
    novo->valor = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;
    l->quantidade++;
    return 1;
}
// Inserir no Fim
int inserirNoFim(ListaEncadeada *l, int valor)
{
    if (l->quantidade >= 100)
    {
        printf("Erro: Limite de 100 elementos atingido!\n");
        return 0;
    }
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->valor = valor;
    novo->proximo = NULL;
    if (estaVaziaEncadeada(l))
    {
        l->inicio = novo;
    }
    else
    {
        No *atual = l->inicio;
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    l->quantidade++;
    return 1;
}
// Remover por ID
int removerPorValor(ListaEncadeada *l, int valor)
{
    if (estaVaziaEncadeada(l))
    {
        printf("Erro: Lista vazia!\n");
        return 0;
    }
    No *atual = l->inicio;
    No *anterior = NULL;
    while (atual != NULL && atual->valor != valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL)
    {
        printf("Erro: Elemento com valor %d nao encontrado.\n", valor);
        return 0; // Não achou
    }
    if (anterior == NULL)
    {
        // O elemento a ser removido é o primeiro
        l->inicio = atual->proximo;
    }
    else
    {
        // O elemento está no meio ou fim
        anterior->proximo = atual->proximo;
    }
    free(atual); // Libera a memória alocada dinamicamente
    l->quantidade--;
    return 1;
}
// Buscar por ID
int buscarEncadeada(ListaEncadeada *l, int valor)
{
    No *atual = l->inicio;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            return 1; // Encontrado
        }
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}
// Listar elementos
void exibirEncadeada(ListaEncadeada *l)
{
    if (estaVaziaEncadeada(l))
    {
        printf("Lista vazia.\n");
        return;
    }
    No *atual = l->inicio;
    printf("--- Elementos da Lista Encadeada ---\n");
    while (atual != NULL)
    {
        printf("[Valor: %d] -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void menuListaSimplesmenteEncadeada()
{
    ListaEncadeada listaEnc;
    inicializarListaEncadeada(&listaEnc);
    int opcao, valor;

    do
    {
        printf("\n===== MENU DA LISTA ENCADEADA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover por valor\n");
        printf("4 - Buscar por valor\n");
        printf("5 - Exibir lista\n");
        printf("6 - Verificar se esta vazia\n");
        printf("7 - Quantidade de elementos\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);

            if (inserirNoInicio(&listaEnc, valor))
                printf("Inserido!\n");
            break;

        case 2:
            printf("Digite o valor: ");
            scanf("%d", &valor);

            if (inserirNoFim(&listaEnc, valor))
                printf("Inserido!\n");
            break;

        case 3:
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);

            if (removerPorValor(&listaEnc, valor))
                printf("Removido!\n");
            break;

        case 4:
            printf("Digite o valor para buscar: ");
            scanf("%d", &valor);

            if (buscarEncadeada(&listaEnc, valor))
                printf("Elemento encontrado!\n");
            else
                printf("Elemento nao encontrado.\n");

            break;

        case 5:
            exibirEncadeada(&listaEnc);
            break;

        case 6:
            if (estaVaziaEncadeada(&listaEnc))
                printf("Lista vazia.\n");
            else
                printf("Lista nao esta vazia.\n");
            break;

        case 7:
            printf("Quantidade: %d\n", listaEnc.quantidade);
            break;
        }

    } while (opcao != 0);
}