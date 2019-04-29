#include <iostream>
#include <string>
#include "jogador.h"
#include "mesa.h"
#include "dado.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    cout<<"Bem vindo ao Blackjack ET!\n\n"<<endl;
    string escolha="-1";
    Mesa m;
    int aux;
    while(escolha!="0"){
      Mesa m;
      cout<<"Escolha uma das funcionalidades: "<<endl;
      cout<<"     -Iniciar uma mesa (1);"<<endl;
      cout<<"     -Sair (0);"<<endl;
      cout<<"Digite: ";
      try
        {
            getline(cin,escolha);
            aux = std::stoi(escolha);
        }
        catch(const std::exception& e)
        {
            aux= -1;
        }
      cout<<endl;
      switch (aux){
          case 1: 
              m.run(); 
              break;    
          case 0:
              cout<<"\nObrigado por jogar Blackjack ET!"<<endl;
              break;
          default:
              cout<<"Nenhum valor correspondente :(\n"<<endl;
              break;
      }
    }
    return 0;
}