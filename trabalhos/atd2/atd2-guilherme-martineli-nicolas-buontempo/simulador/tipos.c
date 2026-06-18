#include <stdio.h>
#include <string.h>
#include "tipos.h"

void imprimir_elemento(Elemento e) {
    printf("  [ID: %d | Nome: %s | Prioridade: %d]\n", e.id, e.nome, e.prioridade);
}

Elemento ler_elemento() {
    Elemento e;
    printf("  Digite o ID: ");
    scanf("%d", &e.id);
    getchar();
    printf("  Digite o nome: ");
    fgets(e.nome, sizeof(e.nome), stdin);
    e.nome[strcspn(e.nome, "\n")] = '\0';
    e.prioridade = 0;
    return e;
}

Elemento ler_elemento_com_prioridade() {
    Elemento e = ler_elemento();
    printf("  Digite a prioridade (maior = mais urgente): ");
    scanf("%d", &e.prioridade);
    return e;
}
