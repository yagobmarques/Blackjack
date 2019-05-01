/**
* @file mesa.h
* @brief Arquivo .h que declara as funções para mesa.cpp
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/
#ifndef MESA_H
#define MESA_H
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "jogador.h"
#include "dado.h"

class Mesa
{
  private:
    vector<Jogador> jogadores; /**< Vetor do tipo jogadores que contem os jogadores cadastrados pelo usuário */
    Dado d1; /**< Variavel do tipo Dado que retorna um valor randômico de 1-6 */
    Dado d2; /**< Variavel do tipo Dado que retorna um valor randômico de 1-6 */
    int aux; /**< Variavel auxiliar */
    int valor_chave; /**< Valor almejado do jogo para ganhar (definido pelo usuário */

  public:
    Mesa();
    ~Mesa();
    int run();
    void adicionaJogador();
    void removeJogador();
    string iniciaPartida(vector<Jogador> jogadores);
    void verJogadores();
    int verificaNome(string nome);
    int verificaJogadores();
    int jogadoresAtivos(vector<Jogador> jogadores);
    string analisaParados(vector<Jogador> jogadores);
};
#endif
