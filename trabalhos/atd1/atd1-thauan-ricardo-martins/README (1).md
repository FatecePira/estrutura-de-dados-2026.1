# Sistema de Gerenciamento de Livros

## Integrante:
- Thauan Ricardo Martins

## Descrição da Estrutura Utilizada:

O sistema foi desenvolvido utilizando uma lista duplamente encadeada. 
Cada nó representa um livro e contém informações como código, título, autor, ano e quantidade, além de ponteiros para o próximo e o anterior.

Essa estrutura permite navegação nos dois sentidos e facilita inserções e remoções.

## Explicação das Principais Funções:

- criarLista(): inicializa a lista
- inserirInicio(): insere livro no início
- inserirFinal(): insere no final
- removerLivro(): remove pelo código
- buscarLivro(): busca e exibe o livro
- imprimirLista(): mostra do início ao fim
- imprimirListaReversa(): mostra do fim ao início
- contarElementos(): conta os livros

## Dificuldades Encontradas:

As principais dificuldades foram trabalhar com ponteiros, principalmente na remoção de nós e na ligação entre anterior e próximo. Também houve cuidado para evitar erros de memória.
