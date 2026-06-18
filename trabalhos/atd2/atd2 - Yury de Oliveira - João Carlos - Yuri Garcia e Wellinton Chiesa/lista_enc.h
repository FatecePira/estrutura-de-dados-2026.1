#ifndef LISTA_ENC_H
#define LISTA_ENC_H

typedef struct No {
    int id;
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} ListaEnc;

void le_inicializar(ListaEnc *l);
void le_inserir_inicio(ListaEnc *l, int id, int valor);
void le_inserir_fim(ListaEnc *l, int id, int valor);
int  le_remover(ListaEnc *l, int id);
void le_buscar(ListaEnc *l, int id);
void le_exibir(ListaEnc *l);
void menu_lista_enc(ListaEnc *l);

#endif
