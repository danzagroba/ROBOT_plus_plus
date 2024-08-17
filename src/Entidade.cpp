#include "Entidade.hpp"

Entidade::Entidade(const sf::Vector2f& pos):
Ente(),
posicao(pos)
{

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
    posicao += deslocamento;
    Figura.setPosition(posicao);
}
const sf::Vector2f& Entidade::getPos() const
{
    return posicao;
}

