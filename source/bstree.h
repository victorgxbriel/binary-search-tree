#ifndef BSTREE_H
#define BSTREE_H
/*!
* Binary Search Tree project.
*
* @authors Victor, Daniel
* @date May 19th, 2022. 
*/

#include <string>

namespace edb{
/// Instancia de uma arvore de busca binaria.
template < typename T>
class Tree{
    private:
        struct Node{
            T value;
            Node *left_son;
            Node *right_son;
            int nodes_left;
            int nodes_right;
            Node(T v=T{}, Node *n1 = nullptr, node *n2 = nullptr, int ns1 = 0, int ns2 = 0) : value{v}, left_son{n1}, right_son{n2}, nodes_left{ns1}, nodes_right{ns2}
            {/*empty*/}
        };
        Node *m_root;
    public:
        // === Metodos regulares da classe da arvore.
        /// Construtor padrão.
        Tree() : m_root{new Node}
        {
            /*
            m_root = new Node; // nó raiz
            */
        }
        /// Construtor iniciando com nó raiz.
        Tree(const T& value){
            m_root = new Node;
            m_root->value = value;
        }
        /// Destrutor padrão.
        ~Tree(){
            clear();
            delete m_root;
        }
        /// Limpa a arvore, deixando apenas o nó raiz.
        void clear();
        /// Retorna o n-esimo elemento(contando a partir de 1) do percurso em ordem(ordem simetrica) da arvore, retorna -1 caso o n for maior que o número de nós da arvore.
        int enesimo_elemento(int n);
        /// Retorna a posição do nó que contem o valor x em um percurso em ordem simetrica na arvore(contando a partir de 1), retorna -1 caso não esteja na arvore.
        int posicao(const T & value);
        /// Retorna a posição do nó que contem a mediana da arvore. Se a arvore tiver um número par de nós, retorna o que tiver menor valor.
        int mediana();
        /// Rertorna a media aritmetica dos valores dos nós da arvore tem como nó raiz o valor value, e -1 caso não contenha o valor na arvore.
        double media(const T & value);
        /// Retorna verdadeiro se a arvore for uma arvore de busca binaria cheia e falso, caso contrario.
        bool eh_cheia();
        /// Retorna verdadeiro se a arvore for uma arvore de busca binaria completa e falso, caso contrario.
        bool eh_completa();
        /// Retorna uma string que contém a sequencia de visitação(percorrimento) da arvore em pré-ordem.
        std::string pre_ordem();
        /// Caso m = 1, imprime a arvore de acordo com o metodo 1, se m = 2, imprime a arvore de acordo com o metodo 2.
        std::string imprime_arvore(int m);
        /// Remove o nó da arvore cujo valor passado, caso não esteja na arvore retorna -1.
        int remove(const T & value);
        /// Retorna o nó caso esteja na arvora, e -1, caso contrario.
        bool busca(const T & value);
        /// Insere um nó na arvore com o valor passado, caso já esteja na arvore retorna -1.
        int insere(const T & value);

};
}
#endif