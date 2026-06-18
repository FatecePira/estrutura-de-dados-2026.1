#include <stdio.h>
#include "utils.h"

int ler_inteiro() {
    int valor;
    if (scanf("%d", &valor) == 1) {
        return valor;  /* leitura ok */
    }
    /* entrada invalida: limpa tudo que ficou no buffer */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Caractere invalido! Tente novamente.\n");
    return -99;  /* codigo de erro */
}
