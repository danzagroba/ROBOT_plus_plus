#include "Personagem.hpp"

Personagem::Personagem(const float vel, const int nVidas, const sf::Vector2f& pos):
Entidade(pos),
num_vidas(nVidas),
velocidade(vel)
{

}
Personagem::~Personagem()
{

}
void Personagem::setNumVidas(const int nVidas)
{
    num_vidas = nVidas;
}
const float Personagem::getVel() const
{
    return velocidade;
}
