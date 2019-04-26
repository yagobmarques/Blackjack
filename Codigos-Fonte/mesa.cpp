#include "mesa.h"
    Mesa::Mesa(){
    }
    Mesa::~Mesa(){
    }
    void Mesa::adicionaJogador(){
    }
    void Mesa::removeJogador(){
    }
    std::__cxx11::string Mesa::iniciaPartida(std::vector<Jogador> jogadores){
        return "Yago";
    }
    int Mesa::run(){
        this->aux = 1;
        while(this->aux!=0){
            cout<<"Escolha uma das funcionalidades: "<<endl;
            cout<<"     -Adicionar jogador (1);"<<endl;
            cout<<"     -Remover um jogador jogador (2);"<<endl;
            cout<<"     -Iniciar uma partida (3);"<<endl;
            cout<<"     -sair (0);\n"<<endl;
            cout<<"Digite: ";
            cin>> this->aux;
            cout<<"\n"<<endl;            
            switch (aux){
                case 0:
                    break;
                case 1:
                    Mesa::adicionaJogador();
                    break;
                case 2:
                    Mesa::removeJogador();
                    break;
                case 3:
                    Mesa::iniciaPartida(this->jogadores);
                    break;
                default:
                    cout<<"Caractere invalido :("<<endl;
                    break;
            }
        }
        return 0;
    }