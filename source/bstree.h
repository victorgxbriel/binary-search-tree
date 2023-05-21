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
            Node(T v=T{}, Node *n1 = nullptr, Node *n2 = nullptr, int ns1 = 0, int ns2 = 0) : value{v}, left_son{n1}, right_son{n2}, nodes_left{ns1}, nodes_right{ns2}
            {/*empty*/}
        };
        Node *m_root;
    public:
        // === Metodos regulares da classe arvore.
        /// Construtor padrão.
        Tree() : m_root{nullptr}
        {
            /*
            m_root = nullptr; // nó raiz
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
        void clear(){

        }
        /// Retorna o n-esimo elemento(contando a partir de 1) do percurso em ordem(ordem simetrica) da arvore, retorna -1 caso o n for maior que o número de nós da arvore.
        int enesimo_elemento(int n){
            // e
            return 0;
        }
        /// Retorna a posição do nó que contem o valor x em um percurso em ordem simetrica na arvore(contando a partir de 1), retorna -1 caso não esteja na arvore.
        int posicao(const T & value){
            return 0;
        }
        /// Retorna a posição do nó que contem a mediana da arvore. Se a arvore tiver um número par de nós, retorna o que tiver menor valor.
        int mediana(){
            return 0;
        }
        /// Rertorna a media aritmetica dos valores dos nós da arvore tem como nó raiz o valor value, e -1 caso não contenha o valor na arvore.
        double media(const T & value){
            return 0;
        }
        /// Retorna verdadeiro se a arvore for uma arvore de busca binaria cheia e falso, caso contrario.
        bool eh_cheia(){
            return 0;
        }
        /// Retorna verdadeiro se a arvore for uma arvore de busca binaria completa e falso, caso contrario.
        bool eh_completa(){
            return 0;
        }
        /// Retorna uma string que contém a sequencia de visitação(percorrimento) da arvore em pré-ordem.
        std::string pre_ordem(){
            return 0;
        }
        /// Caso m = 1, imprime a arvore de acordo com o metodo 1, se m = 2, imprime a arvore de acordo com o metodo 2.
        std::string imprime_arvore(int m){
            return 0;
        }
        /// Remove o nó da arvore cujo valor passado, caso não esteja na arvore retorna -1.
        int remove(const T & value){
            return 0;
        }
        /// Retorna o nó caso esteja na arvora, e -1, caso contrario.
        bool busca(const T & value){
            Node *var = new Node;
            // Verifica se a arvore é vazia
            if(m_root != nullptr){
                var = m_root;
                while(true){
                    // Verifica se o valor do nó é o procurado
                    if(var->value == value){
                        return true;
                    } else if(var->value > value and var->left_son != nullptr){
                        var = var->left_son;
                    } else if(var->value < value and var->right_son != nullptr){
                        var = var->right_son;
                    } else {
                        return false;
                    }
                }
            }
        }
        /// auxilar da recursão
        Node* aux(Node* a, const T & value){
            // Vai pra esquerda
            if(a->value > value){
                if(a->left_son == nullptr){
                    a->nodes_left++;
                    return a->left_son;
                } else 
                    a = aux(a->left_son, value);
                
            } else if(a->value < value){
                if(a->right_son == nullptr){
                    a->nodes_right++;
                    return a->right_son;
                } else 
                    a = aux(a->right_son, value);
            } else {
                return nullptr;
            }
        }
        /// Teste de inserção por recursão
        int insert(const T & value){
            Node *newnode = new Node;
            newnode->value = value;
            if(m_root == nullptr){
                m_root = newnode;
            } else {
                newnode = aux(m_root, value);
                if(newnode ==  nullptr)
                    return -1;
            }
            return newnode->value;
        }
        /// Insere um nó na arvore com o valor passado, caso já esteja na arvore retorna -1.
        int insere(const T & value){
            Node *newnode = new Node;
            newnode->value = value;
            if(m_root != nullptr){
                Node *var = new Node;
                var = m_root;
                while(true){
                    if(var->value == value){
                        return -1;
                    } else if(var->value > value){
                        var->nodes_left++;
                        if(var->left_son == nullptr){
                            var->left_son = newnode;
                            return var->left_son->value;
                            //return newnode->value;
                        } else {
                            var = var->left_son;
                        }
                    } else if(var->value < value){
                        var->nodes_right++;
                        if(var->right_son == nullptr){
                            var->right_son = newnode;
                            return var->right_son->value;
                        } else {
                            var = var->right_son;
                        }
                    } 
                }
            } else {
                m_root = newnode;
                return m_root->value;
            }
        }

};
}
#endif