#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <iostream>
#include "dado.h"
using namespace std;

class Jogador
{
  private:
    string nome;
    int soma_acumulada;
    int status; //Jogando, parou ou explodiu (-1 estourou, 0 jogando, 1 parou)
  public:
    Jogador();
    ~Jogador();
    void setNome(string nome);
    void setSoma_acumulada(int i);
    void setStatus(int i);
    string getNome();
    int getSoma_acumulada();
    int getStatus();
    void jogarDados();
};
#endif