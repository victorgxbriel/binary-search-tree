#include <string>

#include "bstree.h"

namespace edb{

    template<typename T>
    void Tree<T>::clear(){
        // waiting
    }

    template<typename T>
    int Tree<T>::enesimo_elemento(int n){
        //waiting
        return 0;
    }

    template<typename T>
    int Tree<T>::posicao(const T& value){
        //waiting
        return 0;        
    }

    template<typename T>
    int Tree<T>::mediana(){
        //waiting
        return 0;
    }

    template<typename T>
    double Tree<T>::media(const T& value){
        //waiting
        return 0;
    }

    template<typename T>
    bool Tree<T>::eh_cheia(){
        //waiting
        return 0;
    }

    template<typename T>
    bool Tree<T>::eh_completa(){
        //waiting
        return 0;
    }

    template<typename T>
    std::string Tree<T>::pre_ordem(){
        //waiting
        return 0;
    }

    template<typename T>
    std::string Tree<T>::imprime_arvore(int s){
        //waiting
        return 0;
    }

    template<typename T>
    int Tree<T>::remove(const T& value){
        if(m_root != nullptr){
            //pior caso
            if(m_root->value == value){
                if(m_root->left_son == nullptr and m_root->right_son == nullptr){
                    delete m_root;
                } else if(m_root->right_son == nullptr){

                } else if(m_root->left_son == nullptr){

                } else {

                }
            }
        }
        return -1;
    }

    template<typename T>
    bool Tree<T>::busca(const T& value){
        Node *var = new Node;
        // Verifica se a arvore é vazia
        if(m_root != nullptr){
            var = m_root;
            while(true){
                // Verifica se o valor do nó é o procurado
                if(var->value == value){
                    delete var;
                    return true;
                } else if(var->value > value and var->left_son != nullptr){
                    var = var->left_son;
                } else if(var->value < value and var->right_son != nullptr){
                    var = var->right_son;
                } else {
                    delete var;
                    return false;
                }
            }
        }
        delete var;
        return false;
    }

    template<typename T>
    int Tree<T>::insere(const T& value){
        Node *newnode = new Node;
        newnode->value = value;
        if(m_root != nullptr){
            Node *var = new Node;
            var = m_root;
            while(true){
                if(var->value == value){
                    return -1;
                } else if(var->value > value){
                    if(var->left_son == nullptr){
                        var->left_son = newnode;
                        //return var->left_son->value;
                        return newnode->value;
                    } else {
                        var = var->left_son;
                    }
                } else if(var->value < value){
                    if(var->right_son == nullptr){
                        var->right_son = newnode;
                        return newnode->value;
                    } else {
                        var = var->right_son;
                    }
                } 
            }
        } else {
            m_root = newnode;
        }
    }

}