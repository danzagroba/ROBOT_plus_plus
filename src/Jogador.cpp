#include "Jogador.hpp"
#include <iostream>
using namespace std;

bool Jogador::doisjogadores = true;

Jogador::Jogador(const float vel, const int nVidas, const sf::Vector2f& pos):
Personagem(vel, nVidas, pos),
pontos(0),
nome()
{

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

