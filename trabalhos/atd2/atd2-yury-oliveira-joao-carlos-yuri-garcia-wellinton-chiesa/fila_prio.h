#ifndef FILA_PRIO_H
#define FILA_PRIO_H

#define MAX 100

typedef struct {
    int valor;
    int prioridade;
} ItemPrio;

typedef struct {
    ItemPrio dados[MAX];
    int tamanho;
} FilaPrio;

void fp_inicializar(FilaPrio *f);
int  fp_inserir(FilaPrio *f, int valor, int prioridade);
int  fp_remover(FilaPrio *f);
void fp_consultar(FilaPrio *f);
void fp_exibir(FilaPrio *f);
void menu_fila_prio(FilaPrio *f);

#endif
