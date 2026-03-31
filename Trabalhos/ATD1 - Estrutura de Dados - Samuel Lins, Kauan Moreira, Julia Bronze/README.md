# Relatório Curto – Lista Duplamente Encadeada para Gerenciamento de Livros

## Integrantes
- Samuel Sampaio Lins
- Kauan Moreira
- Julia Bronze

## Descrição da estrutura utilizada
Neste trabalho foi utilizada a estrutura de dados **lista duplamente encadeada** para representar os livros de uma estante de biblioteca.  
Cada nó da lista armazena as informações de um livro, como código, título, autor, ano de publicação e quantidade de exemplares disponíveis.

Além desses dados, cada nó possui dois ponteiros:
- um ponteiro para o **próximo** nó;
- um ponteiro para o **nó anterior**.

Essa estrutura foi escolhida porque permite inserir, remover e percorrer elementos em ambas as direções da lista, tornando o gerenciamento dos livros mais flexível.

## Explicação das principais funções implementadas
Foram implementadas funções para manipular dinamicamente a lista de livros.

- **criarLista()**: inicializa a lista, definindo os ponteiros de início e fim como vazios.
- **criarNo()**: cria dinamicamente um novo nó com os dados de um livro.
- **inserirInicio()**: insere um novo livro no começo da lista.
- **inserirFinal()**: insere um novo livro no final da lista.
- **inserirOrdenadoPorCodigo()**: insere o livro na posição correta, mantendo a ordem crescente pelo código.
- **buscarLivro()**: procura um livro pelo código.
- **buscarPorTitulo()**: localiza um livro a partir do título.
- **removerLivro()**: remove um livro da lista com base no código informado.
- **editarLivro()**: altera as informações de um livro já cadastrado.
- **imprimirLista()**: exibe os livros na ordem normal.
- **imprimirListaReversa()**: exibe os livros na ordem inversa.
- **contarElementos()**: retorna a quantidade de livros cadastrados.
- **codigoExiste()**: verifica se já existe outro livro com o mesmo código.
- **tituloExiste()**: verifica se há livros com o mesmo título.
- **aumentarQuantidadeExemplares()**: soma exemplares disponíveis de um livro.
- **diminuirQuantidadeExemplares()**: reduz a quantidade de exemplares disponíveis.
- **liberarLista()**: libera toda a memória alocada dinamicamente, evitando vazamentos.

## Dificuldades encontradas
Além da dificuldade em usar os ponteiros que por si só já são complicados, uma das principais dificuldades encontradas foi manipular corretamente os ponteiros da lista duplamente encadeada, especialmente nas operações de inserção e remoção.  
Também foi necessário ter atenção com casos específicos, como:
- remoção do primeiro ou do último elemento;
- lista vazia;
- inserção em ordem correta;
- validação de códigos repetidos;
- atualização dos dados sem comprometer a estrutura da lista.

Outro ponto importante foi garantir o uso correto de **alocação dinâmica de memória**, utilizando `malloc` para criar os nós e `free` para liberar a memória ao final do programa.

## Conclusão
A implementação permitiu compreender melhor o funcionamento de listas duplamente encadeadas e o uso de ponteiros em C.  
O sistema desenvolvido atende ao objetivo proposto, permitindo cadastrar, buscar, editar, remover e listar livros de forma dinâmica e organizada.