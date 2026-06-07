#include "../include/comum.h" // Inclui os prototipos das funcoes definidas no comum.h

// Funcao para limpar restos de digitacao do teclado (buffer)
void limpar_buffer(void) {
    int c;
    // Le e descarta os caracteres um por um ate encontrar o 'Enter' (\n) ou o fim do arquivo (EOF)
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para congelar a tela
void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    limpar_buffer(); // Fica aguardando a entrada do usuario e ja limpa o buffer
}

// Funcao para imprimir um unico elemento de forma tabelada e bonita
void imprimir_elemento(Elemento e) {
    // %3d = formata inteiro com 3 espacos; %-30s = formata string alinhada a esquerda com 30 espacos
    printf("  [ID: %3d | Dados: %-30s | Prioridade: %d]\n",
           e.id, e.dados, e.prioridade);
}