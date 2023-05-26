# binary-search-tree
Implementação de uma arvore de busca binaria em c++
Está é uma implementação de uma árvore de busca binaria em c++, para fins academicos.
Para compilar, basta usar o g++, usando o seguinte comando: g++ source/main.cpp -o tree
Afim de uma melhor maneira para testar, implementamos o projeto de maneira que aceite 2 maneiras de entrada
1. Pelo console:
  Caso queira testar as funções da árvore pelo console. Para executar basta apenas o seguinte comando:
   ./tree
2. Por arquivos de entradas na execução:
  Caso queira passar arquivos de entrada na hora da execução. Tem duas maneiras de saida.
  2.1 Com a saida sendo pelo console:
    Caso queira que a saida das funções sejam no console, execute com o seguinte parametro:
    ./tree docs/arquivo1.txt docs/arquivo2.txt -c
  2.2 Passando um arquivo de saida ou não:
    Caso queira que a saida das funções sejam em um arquivo. Por padrão, o projeto vai salvar a saida no arquivo docs/saida.txt:
    ./tree docs/arquivo1.txt docs/arquivo2.txt
    Porem caso queira em um arquivo da sua preferencia, coloque o nome do arquivo no paramentro da execução;
    ./tree docs/arquivo1.txt docs/arquivo2.txt nome_do_arquivo_de_saida
 Veja bem que em ambos os casos é passado dois arquivos de entrada. Isto é, o primeiro contendo os nós da arvore em uma unica linha, separados por espaço
 e o segundo com as funções a serem feitas na arvore, com uma função por linha.

No projeto já se encontra dois arquivos de entrada como exemplo. Você pode encontrar os padrões das chamadas das funções no arquvio sourc/main.cpp
Abaixo se encontra o link para o nosso relatorio sobre o projeto, para mais detalhes de funcionamento e complexidade.
https://docs.google.com/document/d/1JvLvmfpvo1BTV7ZnKgV-riiuFbFa5WiWhXdbIHtBNyE/edit?usp=sharing
