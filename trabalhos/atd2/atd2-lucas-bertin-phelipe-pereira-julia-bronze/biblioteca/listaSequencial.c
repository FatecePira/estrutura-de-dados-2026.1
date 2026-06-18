#include "listaSequencial.h"

// Função para inicializar a lista
void inicializarListaSequencial(ListaSequencial *l)
{
    l->quantidade = 0;
}
// Validações obrigatórias
int estaVaziaSequencial(ListaSequencial *l)
{
    return l->quantidade == 0;
}
int estaCheiaSequencial(ListaSequencial *l)
{
    return l->quantidade == MAX;
}
// Inserir elemento em uma posição escolhida (0 até quantidade)
int inserirSequencial(ListaSequencial *l, int posicao, Elemento e)
{
    if (estaCheiaSequencial(l))
    {
        printf("Erro: Lista cheia!\n");
        return 0;
    }
    if (posicao < 0 || posicao > l->quantidade)
    {
        printf("Erro: Posicao invalida!\n");
        return 0;
    }
    // Desloca os elementos para a direita para abrir espaço
    for (int i = l->quantidade; i > posicao; i--)
    {
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[posicao] = e;
    l->quantidade++;
    return 1;
}
// Remover elemento de uma posição escolhida
int removerSequencial(ListaSequencial *l, int posicao)
{
    if (estaVaziaSequencial(l))
    {
        printf("Erro: Lista vazia!\n");
        return 0;
    }
    if (posicao < 0 || posicao >= l->quantidade)
    {
        printf("Erro: Posicao invalida!\n");
        return 0;
    }
    // Desloca os elementos para a esquerda para cobrir o buraco
    for (int i = posicao; i < l->quantidade - 1; i++)
    {
        l->dados[i] = l->dados[i + 1];
    }
    l->quantidade--;
    return 1;
}
// Buscar elemento por ID
int buscarSequencial(ListaSequencial *l, int valor)
{
    for (int i = 0; i < l->quantidade; i++)
    {
        if (l->dados[i].valor == valor)
        {
            return i; // Retorna o índice onde foi encontrado
        }
    }
    return -1; // Não encontrado
}
// Listar todos os elementos
void exibirSequencial(ListaSequencial *l)
{
    if (estaVaziaSequencial(l))
    {
        printf("Lista vazia.\n");
        return;
    }
    printf("--- Elementos da Lista Sequencial ---\n");
    for (int i = 0; i < l->quantidade; i++)
    {
        printf("[Pos %d] Valor: %d\n", i, l->dados[i].valor);
    }
}

void menuListaSequencial()
{
    ListaSequencial listaSeq;
    inicializarListaSequencial(&listaSeq);
    int opcao, posicao, valor, posEncontrada;
    Elemento e;

    do
    {
        printf("\n===== MENU DA LISTA SEQUENCIAL =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Buscar elemento por valor\n");
        printf("4 - Exibir lista\n");
        printf("5 - Verificar se esta vazia\n");
        printf("6 - Quantidade de elementos\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            printf("Digite o valor: ");
            scanf("%d", &e.valor);

            printf("Digite a posicao (0 a %d): ", listaSeq.quantidade);
            scanf("%d", &posicao);

            if (inserirSequencial(&listaSeq, posicao, e))
                printf("Inserido com sucesso!\n");
            break;

        case 2:
            printf("Digite a posicao para remover: ");
            scanf("%d", &posicao);

            if (removerSequencial(&listaSeq, posicao))
                printf("Removido com sucesso!\n");
            break;

        case 3:
            printf("Digite o ID para buscar: ");
            scanf("%d", &valor);

            posEncontrada = buscarSequencial(&listaSeq, valor);

            if (posEncontrada != -1)
                printf("Encontrado na posicao %d\n", posEncontrada);
            else
                printf("Elemento nao encontrado.\n");

            break;

        case 4:
            exibirSequencial(&listaSeq);
            break;

        case 5:
            if (estaVaziaSequencial(&listaSeq))
                printf("Lista vazia.\n");
            else
                printf("Lista nao esta vazia.\n");
            break;

        case 6:
            printf("Quantidade: %d\n", listaSeq.quantidade);
            break;

        case 0:
            printf("Voltando...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}