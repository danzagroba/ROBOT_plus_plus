#include "Personagem.hpp"

#include <cmath>


Personagem::Personagem(const int nVidas, 
                       const sf::Vector2f& pos, 
                       const sf::Vector2f& dimensoes)
    : Entidade(pos, dimensoes),
      num_vidas(nVidas),
      no_ar(true),
      puloBloqueado(false)
{

}

Personagem::~Personagem()
{

}

void Personagem::setno_ar(bool na)
{
    no_ar = na;
}

void Personagem::permitirPulo()
{
    puloBloqueado = false;
}

void Personagem::pulo()
{
    if(no_ar == false && puloBloqueado == false)
    {
        aplicarForcaY(-0.3f);
        no_ar = true;
        puloBloqueado = true;
    }
}

void Personagem::tomarDano(const int dano)
{
    num_vidas -= dano;
}

void Personagem::setNumVidas(const int nVidas)
{
    num_vidas = nVidas;
}

void Personagem::aplicarForcaY(const float forca)
{
    float novaVel = velocidade.y+forca;

    if(std::abs(novaVel) > maxVel)
        velocidade.y = (novaVel < 0.0f) ? -maxVel : maxVel;
    else
        velocidade.y = novaVel;
}
