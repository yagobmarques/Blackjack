    
/**
* @file jogador.h
* @brief Declara as funções e alguns parâmetros importantes para jogador.cpp
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/

#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <iostream>
#include "dado.h"
using namespace std;

class Jogador
{
  private:
    string nome; /**< Define o nome do jogador */
    int soma_acumulada; /**< Representa a soma de todos os dados tirados pelo jogador */
    int status;/**< Define o status do jogador. Se -1 é estourou, 0 é jogando, 1 é parou*/
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
