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
    Mesa m;
    cout<<"Bem vindo ao Blackjack ET!\n\n"<<endl;
    cout<<"Escolha uma das funcionalidades: "<<endl;
    cout<<"     -Sair (1);"<<endl;
    cout<<"     -Iniciar uma mesa (0);"<<endl;
    cin>>n_estouro;
    while(n_estouro!=1 && n_estouro!=2){
        cout<<"\nEntre com um valor valido...n\n"<<endl;
        cin>>n_estouro;
    }
    switch (n_estouro)
    {
        case 1: 
            m.run(); 
            break;    
        case 2:
            cout<<"\nObrigado por jogar Blackjack ET!"<<endl;
        default:
            break;
    }
    

    return 0;
}