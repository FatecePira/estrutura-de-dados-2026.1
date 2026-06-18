#ifndef FILA_DUPLA_H
#define FILA_DUPLA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio, fim, tamanho;
} FilaDupla;

void fd_inicializar(FilaDupla *f);
int  fd_inserir_inicio(FilaDupla *f, int valor);
int  fd_inserir_fim(FilaDupla *f, int valor);
int  fd_remover_inicio(FilaDupla *f);
int  fd_remover_fim(FilaDupla *f);
void fd_exibir(FilaDupla *f);
void menu_fila_dupla(FilaDupla *f);

#endif
