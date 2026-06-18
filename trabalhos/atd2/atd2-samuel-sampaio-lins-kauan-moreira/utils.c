#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void limpar_buffer_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta caracteres restantes */
    }
}

static void remover_quebra_linha(char *texto) {
    size_t tamanho = strlen(texto);
    if (tamanho > 0 && texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }
}

int ler_inteiro(const char *mensagem) {
    char linha[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Entrada invalida. Tente novamente.\n");
            clearerr(stdin);
            continue;
        }

        valor = strtol(linha, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (fim != linha && *fim == '\0') {
            return (int)valor;
        }

        printf("Valor invalido. Digite um numero inteiro.\n");
    }
}

void ler_texto(const char *mensagem, char *destino, int tamanho) {
    while (1) {
        printf("%s", mensagem);
        if (fgets(destino, tamanho, stdin) == NULL) {
            printf("Entrada invalida. Tente novamente.\n");
            clearerr(stdin);
            continue;
        }

        remover_quebra_linha(destino);

        if (strlen(destino) > 0) {
            return;
        }

        printf("O texto nao pode ficar vazio.\n");
    }
}

Elemento ler_elemento_basico(void) {
    Elemento elemento;
    elemento.id = ler_inteiro("ID: ");
    ler_texto("Nome: ", elemento.nome, TAM_NOME);
    elemento.prioridade = 0;
    return elemento;
}

Elemento ler_elemento_com_prioridade(void) {
    Elemento elemento;
    elemento.id = ler_inteiro("ID: ");
    ler_texto("Nome: ", elemento.nome, TAM_NOME);
    elemento.prioridade = ler_inteiro("Prioridade: ");
    return elemento;
}

void imprimir_elemento(Elemento elemento) {
    printf("ID: %d | Nome: %s | Prioridade: %d\n", elemento.id, elemento.nome, elemento.prioridade);
}

void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    fflush(stdout);
    getchar();
}
