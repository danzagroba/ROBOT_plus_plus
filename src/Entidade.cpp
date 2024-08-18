#include "Entidade.hpp"

#include <iostream>

Entidade::Entidade(const sf::Vector2f& pos):
Ente(),
posicao(pos)
{
    Figura.setPosition(posicao);
}
Entidade::~Entidade()
{

}
void Entidade::setPos(const sf::Vector2f& pos)
{
    posicao = pos;
    Figura.setPosition(posicao);
}
void Entidade::mover(const sf::Vector2f& deslocamento)
{
    posicao += deslocamento * pGG->getDeltaTime();
    Figura.setPosition(posicao);
    std::cout << "pos: " << posicao.x << " " << posicao.y << std::endl;
}
const sf::Vector2f& Entidade::getPos() const
{
    return posicao;
}


