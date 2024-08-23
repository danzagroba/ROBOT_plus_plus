#include "Obstaculo.hpp"

Obstaculo::Obstaculo(const sf::Vector2f& pos, const sf::Vector2f& dimensoes, const bool dano)
: Entidade(pos, sf::Vector2f(0.0f, 0.0f)),
  danoso(dano)
{
    AreaColisao.width = dimensoes.x;
    AreaColisao.height = dimensoes.y;
}

Obstaculo::~Obstaculo()
{}

void Obstaculo::executar()
{

}

void Obstaculo::obstacular(Jogador* p)
{

}

void Obstaculo::salvar()
{
    
}