#include "Jogador.hpp"
#include <iostream>
using namespace std;

bool Jogador::doisjogadores = true;

Jogador::Jogador(const sf::Vector2f& vel, 
                 const int nVidas, 
                 const sf::Vector2f& pos)
    : Personagem(nVidas, pos),
      pontos(0),
      nome()
{
    id = 1; // ID utilizado pra jogadores
}

Jogador::~Jogador()
{

}

bool Jogador::getdoisjogadores()
{
    return doisjogadores;
}

void Jogador::executar()
{
    aplicarForcaY(gravidade);
    mover();
    setXvel(0.0f);
    desenhar();
}
void Jogador::tomarDano(const int dano)
{
    if((relogio.getElapsedTime()).asSeconds()>0.5)
    {
        cout<<"Dano tomado! vidas:"<<num_vidas<<endl;
        num_vidas -= dano;
        permitirPulo();
        pulo();
        relogio.restart();
    }
}
void Jogador::salvar()
{

}

