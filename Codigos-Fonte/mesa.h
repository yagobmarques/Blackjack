#ifdef MESA_H
#define MESA_H
#include <vector>
#include <iostream>
#include "jogador.h"
class Mesa{
private:
    vector <Jogador> jogadores;
    Dado d1;
    Dado d2;
public:
    Mesa(/* args */);
    ~Mesa();
};
#endif