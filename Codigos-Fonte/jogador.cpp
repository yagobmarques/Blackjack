#include "jogador.h"
// aqui implementamos as funções em jogador.h
    void Jogador::setNome(string nome){
        this->nome = nome;
    }
    Jogador::Jogador(){
    }
    Jogador::~Jogador(){
    }
    void Jogador::setSoma_acumulada(int i){
        this->soma_acumulada = i;
    }
    void Jogador::setStatus(int i){
        this->status = i;
    }
    string Jogador::getNome(){
        return this->nome;
    }
    int Jogador::getSoma_acumulada(){
        return this->soma_acumulada;
    }
    int Jogador::getStatus(){
        return this->status;
    }