# binary-search-tree
### Implementação de uma arvore de busca binaria em c++  
Está é uma implementação de uma árvore de busca binaria em c++, para fins acadêmicos.  
Para compilar, basta usar o g++, usando o seguinte comando: g++ source/main.cpp -o tree.  
Veja que em ambos os casos a seguir é passado dois arquivos de entrada. Isto é, o primeiro contendo os nós da árvore, em uma unica linha e separados por espaço, e o segundo com as funções a serem feitas na arvore, com uma função por linha.  
No projeto já se encontra dois arquivos de entrada como exemplo. Você pode encontrar os padrões das chamadas das funções no arquivo `sourc/main.cpp`.  
Afim de disponibilizar diferentes maneiras para testar, implementamos o projeto de maneira que aceite 2 métodos de entrada, sendo eles:
## 1 - Pelo console:  
  Caso queira testar as funções da árvore pelo console basta executar o seguinte comando:  
   `./tree`
## 2 - Por arquivos de entradas na execução:  
  Caso queira passar arquivos de entrada na hora da execução. Teremos duas opções de saída.  
    
### 2.1 - Com a saida sendo pelo console:  
  Caso queira que a saida das funções sejam no console, execute com o seguinte parâmetro:  
    `./tree docs/arquivo1.txt docs/arquivo2.txt -c` 
      
### 2.2 - Com saída em arquivo:  
#### 2.2.1 - Em um arquivo padrão
  Caso queira que a saída das funções sejam em um arquivo. Por padrão, o projeto vai salvar a saída no arquivo `docs/saida.txt`:  
    `./tree docs/arquivo1.txt docs/arquivo2.txt`  

#### 2.2.2 - Em um arquivo ja criado
  Porém caso queira em um arquivo da sua preferencia, coloque o nome do arquivo no parâmetro da execução:  
    `./tree docs/arquivo1.txt docs/arquivo2.txt nome_do_arquivo_de_saida`  

## Relatório  
Abaixo se encontra o link para o nosso relatorio sobre o projeto, para mais detalhes de funcionamento e complexidades.
https://docs.google.com/document/d/1JvLvmfpvo1BTV7ZnKgV-riiuFbFa5WiWhXdbIHtBNyE/edit?usp=sharing
