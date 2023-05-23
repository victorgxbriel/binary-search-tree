#ifndef BSTREE_H
#define BSTREE_H
/*!
* Binary Search Tree project.
*
* @authors Victor, Daniel
* @date May 19th, 2022. 
*/

#include <string>
#include <cmath>

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
            int heigth_rigth;
            int heigth_left;
            int heigth;
            int nivel;
            Node(T v=T{}, Node *n1 = nullptr, Node *n2 = nullptr, int ns1 = 0, int ns2 = 0, int h = 1, int hr = 0, int hl = 0, int nivel = 0) : value{v}, left_son{n1}, right_son{n2}, nodes_left{ns1}, nodes_right{ns2}, heigth{h}, heigth_left{hl}, heigth_rigth{hr}, nivel{nivel}
            {/*empty*/}
        };
        Node *m_root;
        std::string seq_pre_ordem;
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
            int qtd = m_root->nodes_left + m_root->nodes_right + 1;
            // Verifica se a quantidade de nós da arvore é impar ou par
            if(qtd % 2 == 0){
                // Retornar o menor elemento entre os dois
            } else {

            }
        }
        /// Retorna a soma de todos os nós, a esquerda se direction = true, direita caso contrario, a partir da raiz.
        double soma(const Node * root, bool direction){
            if(root == nullptr){
                return 0;
            }
            if(direction){
                return root->value + soma(root->left_son, true);
            } else {
                return root->value + soma(root->right_son, false);
            }

        }
        /// Rertorna a media aritmetica dos valores dos nós da arvore tem como nó raiz o valor value, e -1 caso não contenha o valor na arvore.
        double media(const T & value){
            Node *var;
            if(m_root != nullptr){
                var = m_root;
                while(true){
                    if(var == nullptr)
                        return -1;
                    if(var->value == value){
                        return (soma(var, false) + soma(var, true) - value) / (var->nodes_left + var->nodes_right + 1);
                    } else if(var->value > value){
                        var = var->left_son;
                    } else if(var->value < value){
                        var = var->right_son;
                    }
                }   
            }
        }
        /// Retorna verdadeiro se a arvore for uma arvore de busca binaria cheia e falso, caso contrario.
        bool eh_cheia(){
            int qtd_nos = m_root->nodes_left + m_root->nodes_right + 1;
            int cheia_nos = std::pow(2, m_root->heigth) - 1;
            if(qtd_nos == cheia_nos)
                return true;
            return false;
        }
        /// Retorna verdadeiro se a arvore for uma arvore de busca binaria completa e falso, caso contrario.
        bool eh_completa(){
            int qtd_nos = m_root->nodes_left + m_root->nodes_right + 1;
            int min_nos = std::pow(2, m_root->heigth - 1);
            int max_nos = std::pow(2, m_root->heigth) - 1;
            if((min_nos <= qtd_nos) and (qtd_nos <= max_nos))
                return true;
            return false;
        }

        std::string aux_preordem(const Node * root){
            if(!root) return "";

            setSeq_pre_ordem(getSeq_pre_ordem() + std::to_string(root->value) + " ");
            aux_preordem(root->left_son);
            aux_preordem(root->right_son);

            return getSeq_pre_ordem();
        }

        std::string pre_ordem(){
            if(m_root != nullptr){
                std::string ret = aux_preordem(m_root);
                seq_pre_ordem.clear();
                return ret;
            }
            return "";
        }
        /// Retorna uma string que contém a sequencia de visitação(percorrimento) da arvore em pré-ordem.
        
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
        /// Função auxiliar a insert. Retorna true, caso a inserção for em sucessida, e false caso contrario(Valor já está na arvore).
        bool var_insert(Node * root, Node * newnode, int & h){
            if(newnode->value == root->value){
                return false;
            }
            // direita
            if(newnode->value > root->value){
                if(!root->right_son){
                    h = 1;
                    root->right_son = newnode;
                    root->nodes_right++;
                    root->heigth_rigth = newnode->heigth;
                    if(root->heigth_left < root->heigth_rigth)
                        root->heigth = root->heigth_rigth + h;
                    return true;
                } else {
                    if(var_insert(root->right_son, newnode, h)){
                        root->heigth_rigth += h;
                        if(root->heigth_left < root->heigth_rigth)
                            root->heigth = root->heigth_rigth+ h;
                        root->nodes_right++;
                    }
                }
                // esquerda
            } else if(newnode->value < root->value){
                if(!root->left_son){
                    h = 1;
                    root->left_son = newnode;
                    root->nodes_left++;
                    root->heigth_left = newnode->heigth;
                    if(root->heigth_left > root->heigth_rigth)
                        root->heigth = root->heigth_left + h;
                    return true;
                } else {
                    if(var_insert(root->left_son, newnode, h)){
                        root->heigth_left += h;
                        if(root->heigth_left > root->heigth_rigth)
                            root->heigth = root->heigth_left + h;
                    }
                        root->nodes_left++;
                }
            }
        }
        /// Insere um nó na arvore com o valor passado, caso já esteja na arvore retorna -1.
        int insert(const T & value){
            bool flag;
            Node *newnode = new Node;
            newnode->value = value;
            if(m_root == nullptr){
                m_root = newnode;
                flag = true;
            } else {
                int v = 0;
                int& h = v;
                flag = var_insert(m_root, newnode, h);
                /*
                newnode = aux_insert(m_root, value);
                if(newnode != m_root)
                    return -1;
                */
            }
            if(flag)
                return value;
            else
                return -1;
        }
        
        Node getRoot() {
            return m_root;
        }

        void setSeq_pre_ordem(std::string preOrdemString) {
            seq_pre_ordem = preOrdemString;
        }

        std::string getSeq_pre_ordem() {
            return seq_pre_ordem;
        }

};
}
#endif