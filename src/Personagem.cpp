#include "Personagem.hpp"

#include <cmath>


Personagem::Personagem(const int nVidas, 
                       const sf::Vector2f& pos)
    : Entidade(pos),
      num_vidas(nVidas),
      no_ar(true),
      puloBloqueado(false)
{
    id = 9;
    ladodireito = true;
    relogio.restart();
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
void Personagem::movereflip(const float vel, bool direito)
{
    if(direito)
    {
        ladodireito = true;
        Figura.setScale(1.f, 1.f);
        Figura.setOrigin(0, 0);
    }
    else
    {
        ladodireito = false;
        Figura.setScale(-1.f, 1.f);
        Figura.setOrigin(Figura.getLocalBounds().width, 0);
    }
    velocidade.x = vel;
}

void Personagem::tomarDano(const int dano)
{
    if((relogio.getElapsedTime()).asSeconds()>0.5)
    {
        num_vidas -= dano;
        relogio.restart();
    }
}

void Personagem::setNumVidas(const int nVidas)
{
    num_vidas = nVidas;
}

const int Personagem::getNumVidas() const
{
    return num_vidas;
}

void Personagem::aplicarForcaY(const float forca)
{
    float novaVel = velocidade.y+forca;

    if(std::abs(novaVel) > maxVel)
        velocidade.y = (novaVel < 0.0f) ? -maxVel : maxVel;
    else
        velocidade.y = novaVel;
}
