#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "bstree.h"

enum class function_e : short{
        ENESIMO  = 0,
        POSICAO,
        MEDIANA,
        MEDIA,
        CHEIA,
        COMPLETA,
        PREORDEM,
        IMPRIME,
        REMOVA,
        BUSCA,
        INSERE,
        ERRO
};

std::vector<std::string> split(const std::string & input_str, char delimiter = ' '){
    std::vector<std::string> tokens;

    std::istringstream iss;
    iss.str(input_str);
    std::string token;
    while(std::getline(iss >> std::ws, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

auto STR_UPPERCASE = [](const std::string & s ) -> std::string{
    std::string str { s };
    std::transform( str.begin(), str.end(), str.begin(), ::toupper);
    return str;
};

function_e what_function(const std::string & str){
    if(STR_UPPERCASE(str) == "ENESIMO")
        return function_e::ENESIMO;
    else if(STR_UPPERCASE(str) == "POSICAO")
        return function_e::POSICAO;
    else if(STR_UPPERCASE(str) == "MEDIANA")
        return function_e::MEDIANA;
    else if(STR_UPPERCASE(str) == "MEDIA")
        return function_e::MEDIA;
    else if(STR_UPPERCASE(str) == "CHEIA")
        return function_e::CHEIA;
    else if(STR_UPPERCASE(str) == "COMPLETA")
        return function_e::COMPLETA;
    else if(STR_UPPERCASE(str) == "PREORDEM")
        return function_e::PREORDEM;
    else if(STR_UPPERCASE(str) == "IMPRIMA")
        return function_e::IMPRIME;
    else if(STR_UPPERCASE(str) == "REMOVA")
        return function_e::REMOVA;
    else if(STR_UPPERCASE(str) == "BUSCAR")
        return function_e::BUSCA;
    else if(STR_UPPERCASE(str) == "INSIRA")
        return function_e::INSERE;
    else
        return function_e::ERRO;
}

auto result_function(function_e func, std::vector<std::string> comands, edb::Tree<int> & t, std::string & msg){
    auto result = NULL;
    switch(func){
        case function_e::ENESIMO:
            if(comands.size() != 2){
                msg =  "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int n = std::stoi(comands[1]);
                result =  t.enesimo_elemento(n);
                if(result == -1)
                    msg = "O número n é maior que o número de nós da arvore";
                else
                    msg = std::to_string(result);
            }
            break;
        case function_e::POSICAO:
            if(comands.size() != 2){
                msg = "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int value = std::stoi(comands[1]);
                result = t.posicao(value);
                if(result == -1)
                    msg = "O valor não está na arvore";
                else 
                    msg = std::to_string(result);
            }
            break;
        case function_e::MEDIANA:
            result = t.mediana();
            msg = std::to_string(result);
            break;
        case function_e::MEDIA:
            if(comands.size() != 2){
                msg = "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int value = std::stoi(comands[1]);
                result = t.media(value);
                if(result == -1)
                    msg = "Não existe nó na arvore com o valor passado";
                else
                    msg = std::to_string(result);
            }
            break;
        case function_e::CHEIA:
            result = t.eh_cheia();
            if(result)
                msg = "A árvore é cheia";
            else 
                msg = "A árvore não é cheia";
            break;
        case function_e::COMPLETA:
            result = t.eh_completa();
            if(result)
                msg = "A árvore é completa";
            else
                msg = "A árvore não é completa";
            break;
        case function_e::PREORDEM:
            auto root = t.getRoot();
            msg =  t.pre_ordem(root);
            break;
        case function_e::IMPRIME:
            if(comands.size() != 2){
                msg = "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int n = std::stoi(comands[1]);
                msg = t.imprime_arvore(n);
            }
            break;
        case function_e::REMOVA:
            if(comands.size() != 2){
                msg = "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int value = std::stoi(comands[1]);
                result = t.remove(value);
                if(result == -1)
                    msg = std::to_string(value) + " não está na árvore, não pode ser removido";
                else
                    msg = std::to_string(result) + " removido";
            }
            break;
        case function_e::BUSCA:
            if(comands.size() != 2){
                msg = "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int value = std::stoi(comands[1]);
                result = t.busca(value);
                if(result)
                    msg = "Chave encontrada";
                else
                    msg = "Chave não encontrada";
            }
            break;
        case function_e::INSERE:
            if(comands.size() != 2){
                msg = "Operação invalida, está faltando informação ou tem a mais";
            } else {
                int value = std::stoi(comands[1]);
                t.insere(value);
                if(result == -1)
                    msg = std::to_string(value) + " já está na árvore, não pode ser adicionada";
                else
                    msg = std::to_string(result) + " adicionado";
            }
            break;
        case function_e::ERRO:
            msg =  "Erro";
            break;
        default:
            msg = "Função não encontrada";
            break;
    }
    return result;
}

void archive(std::string namefile, edb::Tree<int> & t, bool flag,std::string namefileout = "docs/saida.txt"){
    std::ifstream filein;
    std::ofstream fileout;
    std::string line;
    std::string msg;

    filein.open(namefile);
    if(!flag)
        fileout.open(namefileout);
    if(filein.is_open()){
        while(std::getline(filein >> std::ws, line)){
            msg.clear();
            std::vector<std::string> comands = split(line);
            if(comands.empty())
                continue;
            function_e func = what_function(comands[0]);
            auto result = result_function(func, comands, t, msg);
            if(!flag){
                if(fileout.is_open())
                    fileout << msg << std::endl;
                else
                    std::cerr << "Erro ao abrir o arquivo de saida\n";
            } else {
                std::cout << msg << std::endl;
            }
        }
    } else {
        std::cerr << "Erro ao abrir o arquivo de entrada\n";
    }
    if(!flag)
        fileout.close();
    filein.close();
}

void arquivonos(std::string namefile, edb::Tree<int> & t){
    std::ifstream file;
    std::string str;
    file.open(namefile);
    if(file.is_open()){
        std::getline(file >> std::ws, str);
        std::vector<std::string> nodes = split(str);
        for(int i = 0; i < nodes.size(); i++){
            try{
                t.insere(std::stoi(nodes[i]));
            }
            catch(const std::exception& e) {
                std::cerr << "Erro: argumento invalido. " << e.what() << '\n';
            } catch( const std::out_of_range& e){
                std::cerr << "Erro: estouro de intervalo. " << e.what() << '\n';
            }
        }
    } else {
        std::cerr << "Erro ao abrir o arquivo\n";
    }
    file.close();
}

void console(edb::Tree<int> & t){

}

void imprime_funcoes(){
    std::cout << "ENESIMO N\n"
              << "POSICAO N\n"
              << "MEDIANA\n"
              << "MEDIA\n"
              << "CHEIA\n"
              << "COMPLETA\n"
              << "IMPRIMA S\n"
              << "REMOVA N\n"
              << "BUSCAR N\n"
              << "INSIRA N\n"
              << "Para mais informações, acesse o codigo fonte do arquivo \"tree.h\"\n"
              << "você pode voltar a ver o padrão acima digitando \"-help\",e para parar a execução \"-exit\"(apenas pelo console)\n"
              << "Esse foi um trabalho academico feito por Victor Gabriel e Daniel Lucas\n";
}

int main(int argc, char **argv){
    edb::Tree<int> t;
    std::cout<< "Bem-vindo a nossa implementação de uma árvore de busca binaria. :)\n"
             << "Implementamos dois jeitos para testar ela, você pode optar por testar no console, digitando as funções uma por vez, ou por arquivo.\n"
             << "Caso queira por arquivo, você deve passar ao menos 2 arquivos, o primeiro sendo os valores dos nós, em uma unica linha separado por ' ' .\n"
             << "O segundo sendo as funções, sendo uma por linha, e o terceiro sendo o de saida, que é opicional. Caso queira que a saida seja o console passe '-c'\n"
             << "Exemplo: ./exec arquivonos.txt arquivofuncoes.txt -c arquivosaida.txt(opicional)\n"
             << "Em ambos os casos, deve seguir o padrão para chamada de funções, e cada um por vez(por linha, caso arquivo).\n"
             << "Segue abaixo o padrão das funções:\n";
             imprime_funcoes();
    if(argc > 1){
        std::string filein, fileout, nodes;
        nodes = argv[1];
        filein = argv[2];
        arquivonos(nodes, t);
        if(argc == 4 ){
            if(argv[3] == "-c")
                archive(filein, t, true);
            else
                archive(filein, t, false, argv[3]);
        } else if( argc == 5){
            if(argv[3] == "-c")
                archive(filein, t, true, argv[4]);
            else
                archive(filein, t, false, argv[4]);
        }
    } else {
        console(t);
    }
    return 0;
}