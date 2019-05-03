    
/**
* @file lobby.cpp
* @brief Implementa as funções de lobby.h
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/

#include "lobby.h"
/**
* @brief Construtor
* @return Nulo
*/
Lobby::Lobby(/* args */)
{
}
/**
* @brief Destrutor
* @return Nulo
*/
Lobby::~Lobby()
{
}
/**
* @brief Responsavel por iniciar uma Mesa ou sair do Programa
* @return Retorna um inteiro 
*/
int Lobby::runGame(){
    cout<<YELLOW<<"\nBem vindo ao Blackjack ET!\n"<<RESET<<endl;
    string escolha="-1"; /**< Variável de escolha */
    Mesa m; /**< Cria uma mesa */
    int aux; /**< Variavel para auxiliar no bloco try catch */
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
              cout<<YELLOW<<"\nObrigado por jogar Blackjack ET!"<<RESET<<endl;
              break;
          default:
              cout<<RED<<"Nenhum valor correspondente :(\n"<<RESET<<endl;
              break;
      }
    }
    return 0;
}
