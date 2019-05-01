/**
* @file dado.h
* @brief Cabeçalhos das funçoes
* @author Yago Beserra Marques
* @date 01/05/2019
*/
#ifndef DADO_H
#define DADO_H
#include <random>
class Dado
{
private:
  int valor; /**< Valor aleatorio obtido*/
  std::random_device rd;
  std::default_random_engine gen;
  std::uniform_int_distribution<> dis;

public:
  Dado();
  int jogar();
  int getValor();
};
#endif
