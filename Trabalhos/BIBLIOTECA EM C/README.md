# Sistema de Gestão de Livros - Biblioteca Universitária

Trabalho prático da disciplina de Estrutura de Dados (FATECE).

## Integrantes
* Anna Luiza Maneo da Silva 
* Daniel Pereira Moreira
* Vinicius de Souza 

## Descrição da Estrutura
A estrutura principal desenvolvida foi uma Lista Duplamente Encadeada, implementada do zero em linguagem C, sem o uso de bibliotecas externas de listas prontas. Cada nó (`struct Livro`) armazena os dados primários de um livro (código, título, autor, ano, quantidade) e dois ponteiros de navegação (`*prox` e `*ant`), possibilitando o tráfego da memória em ambas as direções.

## Principais Funções
* **inserirFinal / inserirInicio**: Alocam dinamicamente (`malloc`) um novo bloco na memória para um livro, reatribuindo os ponteiros para manter a integridade da ligação dupla na inserção.
* **removerLivro**: Refaz o encadeamento isolando o nó escolhido e executa a função `free()` para evitar vazamento de memória. Lida com casos extremos (remoção no início, meio ou final).
* **imprimirListaReversa**: Demonstra a eficácia da ligação dupla, avançando pelo ponteiro `*prox` até o final da lista e retornando até o início utilizando o ponteiro `*ant`.
* **liberarLista**: Executada na opção `Sair` do menu para garantir que todos os nós alocados recebam `free()` antes de o processo ser finalizado no sistema operacional.

## Dificuldades Encontradas
Houve dificuldades iniciais com a configuração do compilador GCC no VS Code, mas a principal dificuldade envolveu o gerenciamento correto dos ponteiros durante a função de remoção, garantindo que o encadeamento não se perdesse e apontasse para locais indevidos na memória. Outro desafio superado foi a leitura correta de Strings via terminal (uso do `fgets`), exigindo a limpeza constante do buffer do teclado para não pular inserções de dados.