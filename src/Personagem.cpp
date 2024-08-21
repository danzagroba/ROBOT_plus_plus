#include "Personagem.hpp"

#include <cmath>

const float Personagem::maxVel(1.25f);

Personagem::Personagem(const sf::Vector2f& vel, 
                       const int nVidas, 
                       const sf::Vector2f& pos, 
                       const sf::Vector2f& dimensoes)
    : Entidade(pos, dimensoes),
      num_vidas(nVidas),
      velocidade(vel)
{

}

Personagem::~Personagem()
{

}
void Personagem::pulo()
{
    if(no_ar == false)
    {
        aplicarForcaY(-0.5f);
        no_ar = true;
    }
}
void Personagem::setNumVidas(const int nVidas)
{
    num_vidas = nVidas;
}

const sf::Vector2f& Personagem::getVel() const
{
    return velocidade;
}

const float Personagem::getXVel() const
{
    return velocidade.x;
}

const float Personagem::getYVel() const
{
    return velocidade.y;
}

void Personagem::setVel(const sf::Vector2f& vel)
{
    velocidade = vel;
}

void Personagem::setXvel(const float vel)
{
    velocidade.x = vel;
}

void Personagem::setYvel(const float vel)
{
    velocidade.y = vel;
}

void Personagem::aplicarForca(const sf::Vector2f& forca)
{
    aplicarForcaX(forca.x);
    aplicarForcaY(forca.y);
}

void Personagem::aplicarForcaY(const float forca)
{
    float novaVel = velocidade.y+forca;

    if(std::abs(novaVel) > maxVel)
        velocidade.y = (novaVel < 0.0f) ? -maxVel : maxVel;
    else
        velocidade.y = novaVel;

    std::cout << velocidade.y << std::endl;
}

void Personagem::aplicarForcaX(const float forca)
{
    float novaVel = velocidade.x+forca;

    if(std::abs(novaVel) > maxVel)
        velocidade.x = (novaVel < 0.0f) ? -maxVel : maxVel;
    else
        velocidade.x = novaVel;
}

void Personagem::mover()
{
    posicao += velocidade*pGG->getDeltaTime();
    AreaColisao.left = posicao.x;
    AreaColisao.top = posicao.y;
    Figura.setPosition(posicao);
}