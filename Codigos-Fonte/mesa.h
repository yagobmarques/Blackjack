#ifndef MESA_H
#define MESA_H
#include <vector>
#include <iostream>
#include <string>
#include "jogador.h"
#include "dado.h"

class Mesa{
private:
    vector <Jogador> jogadores;
    Dado d1;
    Dado d2;
    int aux, valor_chave;
public:
    Mesa();
    ~Mesa();
    int run();
    void adicionaJogador();
    void removeJogador();
    string iniciaPartida(vector <Jogador> jogadores); 
    void verJogadores();
    int verificaNome(string nome);
};
#endif