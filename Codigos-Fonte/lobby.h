/**
* @file lobby.h
* @brief Declara as funções para lobby.cpp
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/
#include <iostream>
#include <string>
#include "jogador.h"
#include "mesa.h"
#include "dado.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;
class Lobby
{
private:
    /* data */
public:
    Lobby(/* args */); /**< Costrutor*/
    ~Lobby(); /**< Destrutor */
    int runGame(); /**< Inicia um jogo ou sai do programa */
};
