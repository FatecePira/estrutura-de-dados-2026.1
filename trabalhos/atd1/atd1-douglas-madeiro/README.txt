PROJETO PARA ATD_1 - ESTRUTURA DE DADOS: SISTEMA DE GERENCIAMENTO DE BIBLIOTECA UNIVERSITÁRIA


INTEGRANTES:
- Douglas Madeiro Barbosa Fidencio

ESTRUTURA UTILIZADA:
- Lista duplamente encadeada
- TAD (Biblioteca e Livro)
- Ponteiros (anterior e proximo)
- Alocação dinâmica (malloc/free)

PRINCIPAIS FUNÇÕES:
- criarLista(): aloca e inicializa a lista
- inserirInicio(): insere livro (O(1) no início da lista)
- inserirFinal(): insere livro (O(1) no fim da lista)
- buscarLivro(): busca um livro pelo código (O(n))
- removerLivro(): remove um livro pelo código e ajusta os ponteiros (anterior e proximo)
- imprimirLista(): exibe a lista de livros
- imprimirListaReversa(): a lista de livros invertida
- contarElementos(): retorna total de livros
- liberarLista(): libera toda memória alocada

DIFICULDADES ENCONTRADAS:
- realizar a atualização dos ponteiros após cada operação dentro da lista
- realizar a lógica de switch case para o menu da aplicação
- conseguir compreender a manipulação dos ponteiros tando para inclusão no inicio/final, quanto para exclusão


FUNCIONALIDADES DO MENU:
1 - Inserir no início
2 - Inserir no final
3 - Remover livro
4 - Buscar livro
5 - Listar normal
6 - Listar reverso
7 - Ver quantidade
0 - Sair
