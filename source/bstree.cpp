#include <string>

#include "bstree.h"

namespace edb{

    template<typename T>
    void Tree<T>::clear(){

    }

    template<typename T>
    int Tree<T>::enesimo_elemento(int n){

    }

    template<typename T>
    int Tree<T>::posicao(const T& value){

    }

    template<typename T>
    int Tree<T>::mediana(){

    }

    template<typename T>
    double Tree<T>::media(const T& value){

    }

    template<typename T>
    bool Tree<T>::eh_cheia(){

    }

    template<typename T>
    bool Tree<T>::eh_completa(){

    }

    template<typename T>
    std::string Tree<T>::pre_ordem(Node& root){
        if(!root) return "";

        setSeq_pre_ordem(getSeq_pre_ordem() + to_string(root->value) + " ");
        pre_ordem(root->left_son);
        pre_ordem(root->right_son)

        return getSeq_pre_ordem();
    }

    template<typename T>
    std::string Tree<T>::imprime_arvore(int s){

    }

    template<typename T>
    int Tree<T>::remove(const T& value){

    }

    template<typename T>
    bool Tree<T>::busca(const T& value){

    }

    template<typename T>
    int Tree<T>::insere(const T& value){
        
    }

}