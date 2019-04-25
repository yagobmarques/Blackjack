#include <iostream>
#include <string>
#include "jogador.h"
#include "mesa.h"
#include "dado.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    int n_estouro;
    cout<<"         Bem vindo ao Blackjack ET!\n\nEntre com um valor (inteiro) para definir o valor de estouro: ";
    cin>> n_estouro;
    while(n_estouro < 1){
        //criar funçao queverifica se nao eh um char ou uma string
        cout<<"Entre com um valor valido (inteiro naior que zero): ";
        cin>> n_estouro;
    }
    cout<<n_estouro<<endl;
    return 0;
}