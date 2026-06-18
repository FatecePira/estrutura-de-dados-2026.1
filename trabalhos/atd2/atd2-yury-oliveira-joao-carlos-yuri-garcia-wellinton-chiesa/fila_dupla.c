#include <stdio.h>
#include "fila_dupla.h"
#include "utils.h"

void fd_inicializar(FilaDupla *f) { f->inicio = MAX/2; f->fim = MAX/2 - 1; f->tamanho = 0; }

int fd_inserir_inicio(FilaDupla *f, int valor) {
    if (f->tamanho >= MAX) { printf("Fila dupla cheia!\n"); return 0; }
    if (f->inicio == 0) { printf("Sem espaco no inicio!\n"); return 0; }
    f->dados[--(f->inicio)] = valor;
    f->tamanho++;
    printf("Inserido no inicio: %d\n", valor);
    return 1;
}

int fd_inserir_fim(FilaDupla *f, int valor) {
    if (f->tamanho >= MAX) { printf("Fila dupla cheia!\n"); return 0; }
    if (f->fim >= MAX-1) { printf("Sem espaco no fim!\n"); return 0; }
    f->dados[++(f->fim)] = valor;
    f->tamanho++;
    printf("Inserido no fim: %d\n", valor);
    return 1;
}

int fd_remover_inicio(FilaDupla *f) {
    if (f->tamanho == 0) { printf("Fila dupla vazia!\n"); return 0; }
    printf("Removido do inicio: %d\n", f->dados[f->inicio++]);
    f->tamanho--;
    return 1;
}

int fd_remover_fim(FilaDupla *f) {
    if (f->tamanho == 0) { printf("Fila dupla vazia!\n"); return 0; }
    printf("Removido do fim: %d\n", f->dados[f->fim--]);
    f->tamanho--;
    return 1;
}

void fd_exibir(FilaDupla *f) {
    if (f->tamanho == 0) { printf("Fila dupla vazia!\n"); return; }
    printf("Fila dupla [inicio -> fim]:\n");
    for (int i = f->inicio; i <= f->fim; i++) printf("  [%d]\n", f->dados[i]);
}

void menu_fila_dupla(FilaDupla *f) {
    int op, val;
    do {
        printf("\n===== FILA DUPLA =====\n");
        printf("1 - Inserir no inicio\n2 - Inserir no fim\n3 - Remover do inicio\n4 - Remover do fim\n5 - Consultar inicio\n6 - Consultar fim\n7 - Exibir fila\n0 - Voltar\nOpcao: ");
        op = ler_inteiro();
        if (op == -99) continue;
        switch(op) {
            case 1: printf("Valor: "); val = ler_inteiro(); if(val==-99) break; fd_inserir_inicio(f,val); break;
            case 2: printf("Valor: "); val = ler_inteiro(); if(val==-99) break; fd_inserir_fim(f,val); break;
            case 3: fd_remover_inicio(f); break;
            case 4: fd_remover_fim(f); break;
            case 5: if(f->tamanho==0) printf("Vazia!\n"); else printf("Inicio: %d\n",f->dados[f->inicio]); break;
            case 6: if(f->tamanho==0) printf("Vazia!\n"); else printf("Fim: %d\n",f->dados[f->fim]); break;
            case 7: fd_exibir(f); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while(op != 0);
}
