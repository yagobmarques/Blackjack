#ifndef DADO_H
#define DADO_H
#include <random>
class Dado
{
private:
  int valor;
  std::random_device rd;
  std::default_random_engine gen;
  std::uniform_int_distribution<> dis;

public:
  Dado();
  int jogar();
  int getValor();
};
#endif