#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList *lista = createEmptyList();
    int idLivro = 0;
    int opcao, codigo;

    do
    {
        printf("\n1 - Inserir inicio\n");
        printf("2 - Inserir final\n");
        printf("3 - Remover livro\n");
        printf("4 - Buscar livro\n");
        printf("5 - Listar\n");
        printf("6 - Listar reverso\n");
        printf("7 - Quantidade\n");
        printf("0 - Sair\n");

        scanf("%d", &opcao);
        getchar(); // limpa \n do menu

        switch (opcao)
        {

        case 1:
        case 2:
        {
            char titulo[100];
            char autor[100];
            int anoPublic;
            int numeroCopias;
            char confirmacao;

            idLivro++;

            printf("Nome do livro: ");
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = '\0';

            printf("Nome do autor: ");
            fgets(autor, sizeof(autor), stdin);
            autor[strcspn(autor, "\n")] = '\0';

            printf("Ano de publicação: ");
            scanf("%d", &anoPublic);

            printf("Número de cópias: ");
            scanf("%d", &numeroCopias);
            getchar();

            printf("\nConfira os dados do livro:\n");
            printf("Título: %s\n", titulo);
            printf("Autor: %s\n", autor);
            printf("Ano: %d\n", anoPublic);
            printf("Cópias: %d\n", numeroCopias);

            printf("\nDeseja inserir este livro? (s/n): ");
            scanf(" %c", &confirmacao);
            getchar();

            if (confirmacao == 's' || confirmacao == 'S')
            {
                if (opcao == 1)
                    pushFront(lista, idLivro, titulo, autor, anoPublic, numeroCopias);
                else
                    pushBack(lista, idLivro, titulo, autor, anoPublic, numeroCopias);

                printf("\nLivro inserido com sucesso.\n");
            }
            else
            {
                idLivro--;
                printf("\nInserção cancelada.\n");
            }

            break;
        }

        case 3:
            printf("Codigo do livro: ");
            scanf("%d", &codigo);
            getchar();
            removeById(lista, codigo);
            break;

        case 4:
        {
            printf("Codigo do livro: ");
            scanf("%d", &codigo);
            getchar();

            Book *b = searchById(lista, codigo);
            if (b != NULL)
            {
                printf("\nID: %d | Título: %s | Autor: %s | Ano: %d | Cópias: %d\n",
                       b->bookId, b->title, b->authorName,
                       b->publishYear, b->numberOfCopies);
            }
            else
            {
                printf("Livro não encontrado.\n");
            }
            break;
        }

        case 5:
            printList(lista);
            break;

        case 6:
            printListBackwards(lista);
            break;

        case 7:
            printf("Quantidade de livros: %d\n", getListSize(lista));
            break;
        }

    } while (opcao != 0);

    freeList(lista);
    return 0;
}