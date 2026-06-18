Trabalho Prático 01 — Lista Duplamente Encadeada em C

Integrantes: Yury de Oliveira / João Carlos Pilão Filisbino

Descrição do Projeto
Este projeto consiste na implementação de uma lista duplamente encadeada em linguagem C para o gerenciamento de livros de uma biblioteca universitária. A estrutura permite inserções, remoções e consultas dinâmicas, além da navegação nos dois sentidos da lista, atendendo aos requisitos propostos no trabalho prático da disciplina.

Estrutura de Dados
A lista é composta por nós que representam livros. Cada nó armazena:
* Código do livro
* Título
* Autor
* Ano de publicação
* Quantidade de exemplares

Cada nó possui dois ponteiros:

* Um para o próximo elemento da lista
* Um para o elemento anterior

A lista mantém referências para o primeiro e o último nó, facilitando operações nas extremidades.

Funcionalidades Implementadas

* Inserção de livro no início da lista
* Inserção de livro no final da lista
* Remoção de livro pelo código
* Busca de livro pelo código
* Listagem dos livros em ordem direta
* Listagem dos livros em ordem reversa
* Contagem do total de livros cadastrados

Gerenciamento de Memória
A alocação de memória é realizada dinamicamente utilizando `malloc`, e a liberação ocorre com `free`, tanto na remoção de elementos quanto no encerramento do programa, evitando vazamentos de memória.

Execução do Programa
Compilação:
```bash
gcc lista_dupla.c -o lista_dupla
```
Execução:
```bash
./lista_dupla
```
O programa apresenta um menu interativo no terminal para acesso às funcionalidades.

Observações
O projeto foi desenvolvido sem o uso de bibliotecas prontas para listas, utilizando exclusivamente estruturas, ponteiros e alocação dinâmica, conforme solicitado no enuncia
