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
    Jogador();
    ~Jogador();
    void setNome(string nome);
    void setSoma_acumulada(int i);
    void setStatus(int i);
    string getNome();
    int getSoma_acumulada();
    int getStatus();
};
#endif