#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>	
#include <iostream>
using namespace std;

class Jogador{
private:
    string nome;
    int soma_acumulada;
    int status; //Jogando, parou ou explodiu
public:
    Jogador(/* args */);
    ~Jogador();
};
#endif