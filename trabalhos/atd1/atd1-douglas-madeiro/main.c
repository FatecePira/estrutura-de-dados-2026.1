#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    Biblioteca* lista = criarLista();
    if (lista == NULL) {
        printf("Erro ao criar a lista!\n");
        return 1;
    }
    
    int opcao;

    do {
        printf("\n========== SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ==========\n");
        printf("1 - Inserir livro no início\n");
        printf("2 - Inserir livro no final\n");
        printf("3 - Remover livro\n");
        printf("4 - Buscar livro\n");
        printf("5 - Listar livros (ordem normal)\n");
        printf("6 - Listar livros (ordem reversa)\n");
        printf("7 - Quantidade de livros\n");
        printf("0 - Sair\n");
        printf("================================================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        while (getchar() != '\n');

        int codigo, ano, quantidade;
        char titulo[100], autor[100];

        switch(opcao) {
            case 1:
                printf("\n--- Inserir Livro no Início ---\n");
                printf("Código: ");
                scanf("%d", &codigo);
                while (getchar() != '\n');
                
                printf("Título: ");
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove o \n
                
                printf("Autor: ");
                fgets(autor, 100, stdin);
                autor[strcspn(autor, "\n")] = 0;
                
                printf("Ano: ");
                scanf("%d", &ano);
                
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                
                inserirInicio(lista, codigo, titulo, autor, ano, quantidade);
                break;

            case 2:
                printf("\n--- Inserir Livro no Final ---\n");
                printf("Código: ");
                scanf("%d", &codigo);
                while (getchar() != '\n');
                
                printf("Título: ");
                fgets(titulo, 100, stdin);
                titulo[strcspn(titulo, "\n")] = 0;
                
                printf("Autor: ");
                fgets(autor, 100, stdin);
                autor[strcspn(autor, "\n")] = 0;
                
                printf("Ano: ");
                scanf("%d", &ano);
                
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                
                inserirFinal(lista, codigo, titulo, autor, ano, quantidade);
                break;

            case 3:
                printf("\n--- Remover Livro ---\n");
                printf("Digite o código do livro a ser removido: ");
                scanf("%d", &codigo);
                removerLivro(lista, codigo);
                break;

            case 4: {
                printf("\n--- Buscar Livro ---\n");
                printf("Digite o código do livro: ");
                scanf("%d", &codigo);

                Livro* l = buscarLivro(lista, codigo);

                if (l != NULL) {
                    printf("\n========== LIVRO ENCONTRADO ==========\n");
                    printf("Código: %d\n", l->codigo);
                    printf("Título: %s\n", l->titulo);
                    printf("Autor: %s\n", l->autor);
                    printf("Ano: %d\n", l->ano);
                    printf("Quantidade: %d\n", l->quantidade);
                    printf("======================================\n");
                } else {
                    printf("Livro com código %d não encontrado!\n", codigo);
                }
                break;
            }

            case 5:
                imprimirLista(lista);
                break;

            case 6:
                imprimirListaReversa(lista);
                break;

            case 7:
                printf("\nTotal de livros cadastrados: %d\n", contarElementos(lista));
                break;

            case 0: 
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    liberarLista(lista);
    printf("Memória liberada com sucesso!\n");
    
    return 0;
}