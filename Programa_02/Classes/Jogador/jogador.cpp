/**
* @file jogador.cpp
* @brief Implementa as funções de jogador.h
* @author Yago Beserra Marques
* @since 25/04/2019
* @date 01/05/2019
*/
#include "jogador.h"
/**
* @brief Coloca Nome
* @return Nulo
*/
void Jogador::setNome(string nome)
{
    this->nome = nome;
}
/**
* @brief Metodo construtor
* @return Nulo
*/
Jogador::Jogador()
{
    this->soma_acumulada = 0;
    this->status = 0;
}
/**
* @brief Metodo destrutor
* @return Nulo
*/
Jogador::~Jogador()
{
}
/**
* @brief Coloca soma acumulada
* @param i Inteiro cujo valor será colocado em soma_acumulada
* @return Nulo
*/
void Jogador::setSoma_acumulada(int i)
{
    this->soma_acumulada = i;
}
/**
* @brief Modifica o status do jogador
* @param i Inteiro que modificará o status do jogador
* @return Nulo
*/
void Jogador::setStatus(int i)
{
    this->status = i;
}
/**
* @brief Pega valor da variável Nome
* @return String nome
*/
string Jogador::getNome()
{
    return this->nome;
}
/**
* @brief Pega valor de Soma acumulada
* @return int Soma acumulada
*/
int Jogador::getSoma_acumulada()
{
    return this->soma_acumulada;
}
/**
* @brief Pega valor de Status
* @return int Status
*/
int Jogador::getStatus()
{
    return this->status;
}
/**
* @brief Metodo que joga dados e já coloca o valor adicionando em soma acumulada
* @return Nulo
*/
void Jogador::jogarDados(){
    Dado d;
    int d1 = d.jogar();
    int d2 = d.jogar();
    this->soma_acumulada += d1 + d2;
}
