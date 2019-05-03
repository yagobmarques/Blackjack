/**
* @file dado.cpp
* @brief Implementa as funções de dado.h
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/
#include "dado.h"

/**
* @brief Metodo construtor
* @return Nulo
*/
Dado::Dado() : rd(), gen(rd()), dis(1, 6)
{
    valor = std::round(dis(gen));
}
/**
* @brief Funcao que obtem o valor aleatório de um dado
* @return Valor randomico de 1 - 6
*/
int Dado::jogar()
{
    valor = std::round(dis(gen));
    return valor;
}
/**
* @brief Função que pega o valor armazenado
* @return O prórprio valor
*/
int Dado::getValor()
{
    return this->valor;
}
