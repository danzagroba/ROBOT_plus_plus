#include "Jogador.hpp"
#include <iostream>
using namespace std;

bool Jogador::doisjogadores = true;

Jogador::Jogador(const sf::Vector2f& vel, 
                 const int nVidas, 
                 const sf::Vector2f& pos, 
                 const sf::Vector2f& dimensoes)
    : Personagem(vel, nVidas, pos, dimensoes),
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

}

void Jogador::salvar()
{

}

