#include <iostream>
#include <string>
#include "jogador.h"
#include "mesa.h"
#include "dado.h"
#include "colors.h"

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
      cout<<CYAN<<"----- MENU PRINCIPAL -----"<<RESET<<endl;
      cout<<"Escolha uma das funcionalidades: "<<endl;
      cout<<"1 - Iniciar uma mesa;"<<endl;
      cout<<"0 - Sair;"<<endl;
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
              cout<<CYAN<<"\nObrigado por jogar Blackjack ET!"<<RESET<<endl;
              break;
          default:
              cout<<RED<<"Nenhum valor correspondente :(\n"<<RESET<<endl;
              break;
      }
    }
    return 0;
}