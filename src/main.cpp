#include <iostream>
#include "mesa.h"


int main(int argc, char * argv[]){

    std::string nome_arquivo;
    nome_arquivo = argv[1];

    Mesa game;

    if (game.validarArquivo(nome_arquivo)){
        std::cout << "Aposta válida" << std::endl;

        game.printBet();
    }else{
        std::cout << "Aposta inválida" << std::endl;
    }
   
    return 0;
}