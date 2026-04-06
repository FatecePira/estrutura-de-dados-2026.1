#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TITULO 120
#define TAM_AUTOR 100
#define TAM_BUFFER 256

typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int anoPublicacao;
    int exemplares;
} Livro;

typedef struct No {
    Livro livro;
    struct No *ant;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int quantidade;
} Lista;

void criarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
}

int listaVazia(const Lista *lista) {
    return lista->inicio == NULL;
}

void limparQuebraLinha(char *texto) {
    texto[strcspn(texto, "\n")] = '\0';
}

void lerTexto(const char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    limparQuebraLinha(destino);
}

int lerInteiro(const char *mensagem) {
    char buffer[TAM_BUFFER];
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            return 0;
        }
        if (sscanf(buffer, "%d", &valor) == 1) {
            return valor;
        }
        printf("Entrada inválida. Digite um número inteiro.\n");
    }
}

No *buscarLivro(Lista *lista, int codigo) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->livro.codigo == codigo) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

No *criarNo(Livro livro) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }
    novo->livro = livro;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

int inserirInicio(Lista *lista, Livro livro) {
    No *novo;

    if (buscarLivro(lista, livro.codigo) != NULL) {
        return 0;
    }

    novo = criarNo(livro);
    if (novo == NULL) {
        return -1;
    }

    if (listaVazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
    }

    lista->quantidade++;
    return 1;
}

int inserirFinal(Lista *lista, Livro livro) {
    No *novo;

    if (buscarLivro(lista, livro.codigo) != NULL) {
        return 0;
    }

    novo = criarNo(livro);
    if (novo == NULL) {
        return -1;
    }

    if (listaVazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->quantidade++;
    return 1;
}

int removerLivro(Lista *lista, int codigo) {
    No *remover = buscarLivro(lista, codigo);

    if (remover == NULL) {
        return 0;
    }

    if (remover->ant != NULL) {
        remover->ant->prox = remover->prox;
    } else {
        lista->inicio = remover->prox;
    }

    if (remover->prox != NULL) {
        remover->prox->ant = remover->ant;
    } else {
        lista->fim = remover->ant;
    }

    free(remover);
    lista->quantidade--;
    return 1;
}

void imprimirLivro(const Livro *livro) {
    printf("Código: %d\n", livro->codigo);
    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de publicação: %d\n", livro->anoPublicacao);
    printf("Exemplares disponíveis: %d\n", livro->exemplares);
}

void imprimirLista(Lista *lista) {
    No *atual;
    int contador = 1;

    if (listaVazia(lista)) {
        printf("\nA lista está vazia.\n");
        return;
    }

    printf("\n=== LIVROS CADASTRADOS (ORDEM DIRETA) ===\n");
    atual = lista->inicio;
    while (atual != NULL) {
        printf("\nLivro %d\n", contador++);
        imprimirLivro(&atual->livro);
        atual = atual->prox;
    }
}

void imprimirListaReversa(Lista *lista) {
    No *atual;
    int contador = lista->quantidade;

    if (listaVazia(lista)) {
        printf("\nA lista está vazia.\n");
        return;
    }

    printf("\n=== LIVROS CADASTRADOS (ORDEM REVERSA) ===\n");
    atual = lista->fim;
    while (atual != NULL) {
        printf("\nLivro %d\n", contador--);
        imprimirLivro(&atual->livro);
        atual = atual->ant;
    }
}

int contarElementos(const Lista *lista) {
    return lista->quantidade;
}

void liberarLista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    criarLista(lista);
}

Livro lerLivro(void) {
    Livro livro;
    livro.codigo = lerInteiro("Código do livro: ");
    lerTexto("Título do livro: ", livro.titulo, sizeof(livro.titulo));
    lerTexto("Nome do autor: ", livro.autor, sizeof(livro.autor));
    livro.anoPublicacao = lerInteiro("Ano de publicação: ");
    livro.exemplares = lerInteiro("Quantidade de exemplares disponíveis: ");
    return livro;
}

void exibirMenu(void) {
    printf("\n================ MENU ================\n");
    printf("1 - Inserir livro no início\n");
    printf("2 - Inserir livro no final\n");
    printf("3 - Remover livro\n");
    printf("4 - Buscar livro\n");
    printf("5 - Listar livros (ordem normal)\n");
    printf("6 - Listar livros (ordem reversa)\n");
    printf("7 - Quantidade de livros\n");
    printf("0 - Sair\n");
    printf("=====================================\n");
}

int main(void) {
    Lista lista;
    int opcao;

    criarLista(&lista);

    do {
        exibirMenu();
        opcao = lerInteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1: {
                Livro livro = lerLivro();
                int retorno = inserirInicio(&lista, livro);
                if (retorno == 1) {
                    printf("\nLivro inserido com sucesso no início da lista.\n");
                } else if (retorno == 0) {
                    printf("\nJá existe um livro cadastrado com esse código.\n");
                } else {
                    printf("\nErro de alocação de memória ao inserir o livro.\n");
                }
                break;
            }
            case 2: {
                Livro livro = lerLivro();
                int retorno = inserirFinal(&lista, livro);
                if (retorno == 1) {
                    printf("\nLivro inserido com sucesso no final da lista.\n");
                } else if (retorno == 0) {
                    printf("\nJá existe um livro cadastrado com esse código.\n");
                } else {
                    printf("\nErro de alocação de memória ao inserir o livro.\n");
                }
                break;
            }
            case 3: {
                int codigo = lerInteiro("Informe o código do livro a ser removido: ");
                if (removerLivro(&lista, codigo)) {
                    printf("\nLivro removido com sucesso.\n");
                } else {
                    printf("\nLivro não encontrado.\n");
                }
                break;
            }
            case 4: {
                int codigo = lerInteiro("Informe o código do livro a ser buscado: ");
                No *encontrado = buscarLivro(&lista, codigo);
                if (encontrado != NULL) {
                    printf("\n=== LIVRO ENCONTRADO ===\n");
                    imprimirLivro(&encontrado->livro);
                } else {
                    printf("\nLivro não encontrado.\n");
                }
                break;
            }
            case 5:
                imprimirLista(&lista);
                break;
            case 6:
                imprimirListaReversa(&lista);
                break;
            case 7:
                printf("\nQuantidade de livros cadastrados: %d\n", contarElementos(&lista));
                break;
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarLista(&lista);
    return 0;
}
