#include "mesa.h"
    Mesa::Mesa(){
    }
    Mesa::~Mesa(){
    }
    int Mesa::verificaNome(string nome){
      for(unsigned int j = 0; j< this->jogadores.size();j++){
        if (nome == this->jogadores[j].getNome()){
          return 1;
        }
      }
      return 0;
    }
    void Mesa::adicionaJogador(){
      Jogador j;
      string nome;
      string limbo;
      cout<<"Digite o nome do novo jogador: ";
      getline(cin,limbo);
      getline(cin,nome);
      j.setNome(nome);
      if (verificaNome(nome)==0){
        this->jogadores.push_back(j);
        cout<<"Jogador "<<nome<<" adicionado"<<endl;
      }
      else{
        cout<<"O jogador ja esta jogando\nVoltando ao menu...\n"<<endl;
      }
      cout<<endl;
    }
    void Mesa::verJogadores(){
      cout<<"Jogadores ativos:\n"<<endl;
      for(unsigned int j = 0; j < this->jogadores.size();j++){
        cout<<jogadores[j].getNome()<<endl;
      }
      cout<<endl;
    }
    void Mesa::removeJogador(){
      string nome, limbo;
      cout<<"Digite o nome do jogador a ser removido: ";
      getline(cin,limbo);
      getline(cin,nome);
      if (verificaNome(nome)==1){
        for(unsigned int j = 0; j < this->jogadores.size();j++){
          if(jogadores[j].getNome()==nome){
            this->jogadores.erase(jogadores.begin()+j);
            cout<<"Jogador "<<nome<<" removido\n"<<endl;
            break;
          }
        }
      }
      else{
        cout<<"Jogador inexiste\n"<<endl;
      }
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
            cout<<"     -Ver jogadores na partida (4);"<<endl;
            cout<<"     -sair (0);"<<endl;
            cout<<"Digite: ";
            cin>> this->aux;
            cout<<endl;           
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
                case 4:
                    Mesa::verJogadores();
                    break;
                default:
                    cout<<"Caractere invalido :("<<endl;
                    break;
            }
        }
        return 0;
    }