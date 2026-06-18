#include <stdio.h>
#include "fila.h"
#include "utils.h"

void f_inicializar(Fila *f) { f->inicio = 0; f->fim = -1; f->tamanho = 0; }

int f_enfileirar(Fila *f, int valor) {
    if (f->tamanho >= MAX) { printf("Fila cheia!\n"); return 0; }
    f->dados[++(f->fim)] = valor;
    f->tamanho++;
    printf("Valor %d enfileirado.\n", valor);
    return 1;
}

int f_desenfileirar(Fila *f) {
    if (f->tamanho == 0) { printf("Fila vazia!\n"); return 0; }
    printf("Desenfileirado: %d\n", f->dados[f->inicio++]);
    f->tamanho--;
    return 1;
}

void f_inicio(Fila *f) {
    if (f->tamanho == 0) printf("Fila vazia!\n");
    else printf("Inicio da fila: %d\n", f->dados[f->inicio]);
}

void f_exibir(Fila *f) {
    if (f->tamanho == 0) { printf("Fila vazia!\n"); return; }
    printf("Fila (inicio -> fim):\n");
    for (int i = f->inicio; i <= f->fim; i++) printf("  [%d]\n", f->dados[i]);
}

void menu_fila(Fila *f) {
    int op, val;
    do {
        printf("\n===== FILA (FIFO) =====\n");
        printf("1 - Enfileirar\n2 - Desenfileirar\n3 - Consultar inicio\n4 - Exibir fila\n5 - Verificar se esta vazia\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1: printf("Valor: "); val = ler_inteiro(); if(val==-99) break; f_enfileirar(f,val); break;
            case 2: f_desenfileirar(f); break;
            case 3: f_inicio(f); break;
            case 4: f_exibir(f); break;
            case 5: printf(f->tamanho == 0 ? "Fila vazia.\n" : "Fila nao esta vazia.\n"); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
