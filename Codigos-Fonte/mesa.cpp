#include "mesa.h"
    Mesa::Mesa(){
    }
    Mesa::~Mesa(){
    }
    int Mesa::run(){
        this->aux = 1;
        while(this->aux!=0){
            cout<<"Escolha uma das funcionalidades: "<<endl;
            cout<<"     -sair (0);"<<endl;
            cout<<"     -Adicionar jogador (1);"<<endl;
            cout<<"     -Remover um jogador jogador (2);"<<endl;
            cout<<"     -Iniciar uma partida (3);"<<endl;
            cin>> this->aux;
            switch (aux){
                case 0:
                    break;
                case 1:
                    Mesa::adicionaJogador();
                    break;
                case 2:
                    Mesa::removeJogador();
                case 3:
                    Mesa::iniciaPartida(this->jogadores);
                default:
                    cout<<"Caractere invalido :("<<endl;
                    break;
            }
        }
        return 0;
    }