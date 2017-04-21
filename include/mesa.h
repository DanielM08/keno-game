#include <iostream>
#include <fstream>
#include <cstdlib> // for exit()
#include <string>
#include <vector>


struct Aposta {

    float cash;
    int rounds;
    std::vector<int> hints;

} ;

class Mesa {
    private:
        Aposta m_bet;

    public:
        bool validarArquivo(std::string nome_arquivo){

            //lendo arquivo
            std::ifstream bet(nome_arquivo);
            
            if (!bet){
                return false;
                exit(1);                
            }
            /*
             while (bet){
                 std::string dado;
                 getline(bet, dado);

             }

              m_bet.cash = 1.0;
              m_bet.rounds = 2;
            */
            std::string dado;
            //std::string::size_type sz;

            for(int i = 0; i <= 2; i++){

                if (i==0){
                    getline(bet, dado);
                    m_bet.cash = std::stof( dado );
                }else if(i==1){
                    getline(bet, dado);
                    m_bet.rounds = std::stoi( dado );
                }else if(i==2){ // Salvar dados no vector aqui <<<<
                    getline(bet, dado);
                    m_bet.hints = std::stoi( dado );
                    /*
                    while(true){
                         int value;
                         if( !(bet >> value) ){
                             break;
                         }
                         m_bet.hints.push_back(value);
                    }
                    */
                    
                }
                
            }
            
            return true;            
        }

        void printBet() {
                std::cout << "Cash: " << m_bet.cash << "\n";
                std::cout << "Rounds: " << m_bet.rounds << "\n";
                //std::cout << "Rounds: " << m_bet.hints[0] << "\n";
        }

        void mostraPayout();
        void sorteio();
        void atualizaGame();
        void retornaFinal();   
};