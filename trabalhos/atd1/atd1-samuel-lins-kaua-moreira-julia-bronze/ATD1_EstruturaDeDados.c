#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TITULO 100
#define TAM_AUTOR 100

typedef struct Livro {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int quantidade;
    struct Livro *anterior;
    struct Livro *proximo;
} Livro;

typedef struct {
    Livro *inicio;
    Livro *fim;
} Lista;

/* Protótipos */
Lista* criarLista();
Livro* criarNo(int codigo, char titulo[], char autor[], int ano, int quantidade);

int codigoExiste(Lista *lista, int codigo);
int codigoExisteExceto(Lista *lista, int codigo, Livro *ignorar);
int tituloExiste(Lista *lista, char titulo[]);

void inserirInicio(Lista *lista, int codigo, char titulo[], char autor[], int ano, int quantidade);
void inserirFinal(Lista *lista, int codigo, char titulo[], char autor[], int ano, int quantidade);
void inserirOrdenadoPorCodigo(Lista *lista, int codigo, char titulo[], char autor[], int ano, int quantidade);

Livro* buscarLivro(Lista *lista, int codigo);
Livro* buscarPorTitulo(Lista *lista, char titulo[]);

int removerLivro(Lista *lista, int codigo);
int editarLivro(Lista *lista, int codigo);
int aumentarQuantidadeExemplares(Lista *lista, int codigo, int quantidade);
int diminuirQuantidadeExemplares(Lista *lista, int codigo, int quantidade);

void listarLivrosMesmoTitulo(Lista *lista, char titulo[]);
void imprimirLista(Lista *lista);
void imprimirListaReversa(Lista *lista);
int contarElementos(Lista *lista);
void exibirLivro(Livro *livro);
void liberarLista(Lista *lista);

void limparBuffer();
void lerString(char str[], int tamanho);

/* Cria a lista */
Lista* criarLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));

    if (lista == NULL) {
        printf("Erro ao alocar memoria para a lista.\n");
        exit(1);
    }

    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
}

/* Cria um novo nó */
Livro* criarNo(int codigo, char titulo[], char autor[], int ano, int quantidade) {
    Livro *novo = (Livro*) malloc(sizeof(Livro));

    if (novo == NULL) {
        printf("Erro ao alocar memoria para o livro.\n");
        exit(1);
    }

    novo->codigo = codigo;
    strncpy(novo->titulo, titulo, TAM_TITULO);
    novo->titulo[TAM_TITULO - 1] = '\0';

    strncpy(novo->autor, autor, TAM_AUTOR);
    novo->autor[TAM_AUTOR - 1] = '\0';

    novo->ano = ano;
    novo->quantidade = quantidade;
    novo->anterior = NULL;
    novo->proximo = NULL;

    return novo;
}

/* Verifica se o código já existe */
int codigoExiste(Lista *lista, int codigo) {
    Livro *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

/* Verifica se o código já existe, ignorando um nó específico */
int codigoExisteExceto(Lista *lista, int codigo, Livro *ignorar) {
    Livro *atual = lista->inicio;

    while (atual != NULL) {
        if (atual != ignorar && atual->codigo == codigo) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

/* Verifica se já existe algum livro com o mesmo título */
int tituloExiste(Lista *lista, char titulo[]) {
    Livro *atual = lista->inicio;

    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

/* Inserção no início */
void inserirInicio(Lista *lista, int codigo, char titulo[], char autor[], int ano, int quantidade) {
    Livro *novo;

    if (codigoExiste(lista, codigo)) {
        printf("Erro: ja existe um livro com esse codigo.\n");
        return;
    }

    if (tituloExiste(lista, titulo)) {
        printf("Aviso: ja existe livro(s) com esse mesmo titulo.\n");
    }

    novo = criarNo(codigo, titulo, autor, ano, quantidade);

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
    }

    printf("Livro inserido no inicio com sucesso.\n");
}

/* Inserção no final */
void inserirFinal(Lista *lista, int codigo, char titulo[], char autor[], int ano, int quantidade) {
    Livro *novo;

    if (codigoExiste(lista, codigo)) {
        printf("Erro: ja existe um livro com esse codigo.\n");
        return;
    }

    if (tituloExiste(lista, titulo)) {
        printf("Aviso: ja existe livro(s) com esse mesmo titulo.\n");
    }

    novo = criarNo(codigo, titulo, autor, ano, quantidade);

    if (lista->fim == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }

    printf("Livro inserido no final com sucesso.\n");
}

/* Inserção ordenada por código */
void inserirOrdenadoPorCodigo(Lista *lista, int codigo, char titulo[], char autor[], int ano, int quantidade) {
    Livro *novo, *atual;

    if (codigoExiste(lista, codigo)) {
        printf("Erro: ja existe um livro com esse codigo.\n");
        return;
    }

    if (tituloExiste(lista, titulo)) {
        printf("Aviso: ja existe livro(s) com esse mesmo titulo.\n");
    }

    novo = criarNo(codigo, titulo, autor, ano, quantidade);

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        printf("Livro inserido em lista vazia.\n");
        return;
    }

    if (codigo < lista->inicio->codigo) {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
        printf("Livro inserido em ordem por codigo.\n");
        return;
    }

    if (codigo > lista->fim->codigo) {
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
        printf("Livro inserido em ordem por codigo.\n");
        return;
    }

    atual = lista->inicio;
    while (atual != NULL && atual->codigo < codigo) {
        atual = atual->proximo;
    }

    novo->proximo = atual;
    novo->anterior = atual->anterior;
    atual->anterior->proximo = novo;
    atual->anterior = novo;

    printf("Livro inserido em ordem por codigo.\n");
}

/* Busca por código */
Livro* buscarLivro(Lista *lista, int codigo) {
    Livro *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

/* Busca o primeiro livro com o título informado */
Livro* buscarPorTitulo(Lista *lista, char titulo[]) {
    Livro *atual = lista->inicio;

    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

/* Remove livro pelo código */
int removerLivro(Lista *lista, int codigo) {
    Livro *remover = buscarLivro(lista, codigo);

    if (remover == NULL) {
        return 0;
    }

    if (remover->anterior != NULL) {
        remover->anterior->proximo = remover->proximo;
    } else {
        lista->inicio = remover->proximo;
    }

    if (remover->proximo != NULL) {
        remover->proximo->anterior = remover->anterior;
    } else {
        lista->fim = remover->anterior;
    }

    free(remover);
    return 1;
}

/* Edita todas as informações do livro */
int editarLivro(Lista *lista, int codigo) {
    Livro *livro;
    int novoCodigo, novoAno, novaQuantidade;
    char novoTitulo[TAM_TITULO];
    char novoAutor[TAM_AUTOR];

    livro = buscarLivro(lista, codigo);

    if (livro == NULL) {
        return 0;
    }

    printf("\n=== DADOS ATUAIS DO LIVRO ===\n");
    exibirLivro(livro);

    printf("\nNovo codigo: ");
    scanf("%d", &novoCodigo);
    limparBuffer();

    if (codigoExisteExceto(lista, novoCodigo, livro)) {
        printf("Erro: ja existe outro livro com esse codigo.\n");
        return -1;
    }

    printf("Novo titulo: ");
    lerString(novoTitulo, TAM_TITULO);

    if (strcmp(livro->titulo, novoTitulo) != 0 && tituloExiste(lista, novoTitulo)) {
        printf("Aviso: ja existe outro livro com esse titulo.\n");
    }

    printf("Novo autor: ");
    lerString(novoAutor, TAM_AUTOR);

    printf("Novo ano de publicacao: ");
    scanf("%d", &novoAno);

    printf("Nova quantidade de exemplares: ");
    scanf("%d", &novaQuantidade);
    limparBuffer();

    livro->codigo = novoCodigo;
    strcpy(livro->titulo, novoTitulo);
    strcpy(livro->autor, novoAutor);
    livro->ano = novoAno;
    livro->quantidade = novaQuantidade;

    return 1;
}

/* Aumenta a quantidade de exemplares */
int aumentarQuantidadeExemplares(Lista *lista, int codigo, int quantidade) {
    Livro *livro = buscarLivro(lista, codigo);

    if (livro == NULL || quantidade <= 0) {
        return 0;
    }

    livro->quantidade += quantidade;
    return 1;
}

/* Diminui a quantidade de exemplares */
int diminuirQuantidadeExemplares(Lista *lista, int codigo, int quantidade) {
    Livro *livro = buscarLivro(lista, codigo);

    if (livro == NULL || quantidade <= 0) {
        return 0;
    }

    if (quantidade > livro->quantidade) {
        return -1;
    }

    livro->quantidade -= quantidade;
    return 1;
}

/* Lista todos os livros com o mesmo título */
void listarLivrosMesmoTitulo(Lista *lista, char titulo[]) {
    Livro *atual = lista->inicio;
    int encontrou = 0;

    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            exibirLivro(atual);
            encontrou = 1;
        }
        atual = atual->proximo;
    }

    if (!encontrou) {
        printf("Nenhum livro com esse titulo foi encontrado.\n");
    }
}

/* Imprime do início para o fim */
void imprimirLista(Lista *lista) {
    Livro *atual = lista->inicio;

    if (atual == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\n===== LIVROS (ORDEM NORMAL) =====\n");
    while (atual != NULL) {
        exibirLivro(atual);
        atual = atual->proximo;
    }
}

/* Imprime do fim para o início */
void imprimirListaReversa(Lista *lista) {
    Livro *atual = lista->fim;

    if (atual == NULL) {
        printf("\nLista vazia.\n");
        return;
    }

    printf("\n===== LIVROS (ORDEM REVERSA) =====\n");
    while (atual != NULL) {
        exibirLivro(atual);
        atual = atual->anterior;
    }
}

/* Conta os elementos da lista */
int contarElementos(Lista *lista) {
    int contador = 0;
    Livro *atual = lista->inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}

/* Exibe um livro */
void exibirLivro(Livro *livro) {
    printf("Codigo: %d\n", livro->codigo);
    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano: %d\n", livro->ano);
    printf("Quantidade: %d\n", livro->quantidade);
    printf("-----------------------------\n");
}

/* Libera toda a memória da lista */
void liberarLista(Lista *lista) {
    Livro *atual = lista->inicio;
    Livro *temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(lista);
}

/* Limpa buffer */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Lê string com espaços */
void lerString(char str[], int tamanho) {
    if (fgets(str, tamanho, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

int main() {
    Lista *lista = criarLista();

    int opcao;
    int codigo, ano, quantidade;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    Livro *encontrado;
    int resultado;

    do {
        printf("\n========== MENU ==========\n");
        printf("1  - Inserir livro no inicio\n");
        printf("2  - Inserir livro no final\n");
        printf("3  - Remover livro\n");
        printf("4  - Buscar livro por codigo\n");
        printf("5  - Listar livros (ordem normal)\n");
        printf("6  - Listar livros (ordem reversa)\n");
        printf("7  - Quantidade de livros\n");
        printf("8  - Editar livro\n");
        printf("9  - Inserir livro em ordem por codigo\n");
        printf("10 - Buscar primeiro livro por titulo\n");
        printf("11 - Listar todos os livros com mesmo titulo\n");
        printf("12 - Aumentar quantidade de exemplares\n");
        printf("13 - Diminuir quantidade de exemplares\n");
        printf("0  - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                printf("\nCodigo do livro: ");
                scanf("%d", &codigo);
                limparBuffer();

                printf("Titulo do livro: ");
                lerString(titulo, TAM_TITULO);

                printf("Nome do autor: ");
                lerString(autor, TAM_AUTOR);

                printf("Ano de publicacao: ");
                scanf("%d", &ano);

                printf("Quantidade de exemplares: ");
                scanf("%d", &quantidade);
                limparBuffer();

                inserirInicio(lista, codigo, titulo, autor, ano, quantidade);
                break;

            case 2:
                printf("\nCodigo do livro: ");
                scanf("%d", &codigo);
                limparBuffer();

                printf("Titulo do livro: ");
                lerString(titulo, TAM_TITULO);

                printf("Nome do autor: ");
                lerString(autor, TAM_AUTOR);

                printf("Ano de publicacao: ");
                scanf("%d", &ano);

                printf("Quantidade de exemplares: ");
                scanf("%d", &quantidade);
                limparBuffer();

                inserirFinal(lista, codigo, titulo, autor, ano, quantidade);
                break;

            case 3:
                printf("\nInforme o codigo do livro a remover: ");
                scanf("%d", &codigo);
                limparBuffer();

                if (removerLivro(lista, codigo)) {
                    printf("Livro removido com sucesso.\n");
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;

            case 4:
                printf("\nInforme o codigo do livro a buscar: ");
                scanf("%d", &codigo);
                limparBuffer();

                encontrado = buscarLivro(lista, codigo);

                if (encontrado != NULL) {
                    printf("\nLivro encontrado:\n");
                    exibirLivro(encontrado);
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;

            case 5:
                imprimirLista(lista);
                break;

            case 6:
                imprimirListaReversa(lista);
                break;

            case 7:
                printf("\nQuantidade de livros na lista: %d\n", contarElementos(lista));
                break;

            case 8:
                printf("\nInforme o codigo do livro a editar: ");
                scanf("%d", &codigo);
                limparBuffer();

                resultado = editarLivro(lista, codigo);

                if (resultado == 1) {
                    printf("Livro editado com sucesso.\n");
                } else if (resultado == -1) {
                    printf("Edicao cancelada por codigo duplicado.\n");
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;

            case 9:
                printf("\nCodigo do livro: ");
                scanf("%d", &codigo);
                limparBuffer();

                printf("Titulo do livro: ");
                lerString(titulo, TAM_TITULO);

                printf("Nome do autor: ");
                lerString(autor, TAM_AUTOR);

                printf("Ano de publicacao: ");
                scanf("%d", &ano);

                printf("Quantidade de exemplares: ");
                scanf("%d", &quantidade);
                limparBuffer();

                inserirOrdenadoPorCodigo(lista, codigo, titulo, autor, ano, quantidade);
                break;

            case 10:
                printf("\nInforme o titulo a buscar: ");
                lerString(titulo, TAM_TITULO);

                encontrado = buscarPorTitulo(lista, titulo);

                if (encontrado != NULL) {
                    printf("\nPrimeiro livro encontrado com esse titulo:\n");
                    exibirLivro(encontrado);
                } else {
                    printf("Nenhum livro encontrado com esse titulo.\n");
                }
                break;

            case 11:
                printf("\nInforme o titulo para listar ocorrencias: ");
                lerString(titulo, TAM_TITULO);

                printf("\nLivros com o titulo \"%s\":\n", titulo);
                listarLivrosMesmoTitulo(lista, titulo);
                break;

            case 12:
                printf("\nInforme o codigo do livro: ");
                scanf("%d", &codigo);

                printf("Quantidade a adicionar: ");
                scanf("%d", &quantidade);
                limparBuffer();

                if (aumentarQuantidadeExemplares(lista, codigo, quantidade)) {
                    printf("Quantidade atualizada com sucesso.\n");
                } else {
                    printf("Operacao invalida ou livro nao encontrado.\n");
                }
                break;

            case 13:
                printf("\nInforme o codigo do livro: ");
                scanf("%d", &codigo);

                printf("Quantidade a remover: ");
                scanf("%d", &quantidade);
                limparBuffer();

                resultado = diminuirQuantidadeExemplares(lista, codigo, quantidade);

                if (resultado == 1) {
                    printf("Quantidade atualizada com sucesso.\n");
                } else if (resultado == -1) {
                    printf("Erro: quantidade a remover maior que a disponivel.\n");
                } else {
                    printf("Operacao invalida ou livro nao encontrado.\n");
                }
                break;

            case 0:
                liberarLista(lista);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}