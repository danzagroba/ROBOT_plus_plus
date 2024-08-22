#include "Obstaculo.hpp"

Obstaculo::Obstaculo(const sf::Vector2f& pos, 
                     const sf::Vector2f& dimensoes,
                     bool dano)
: Entidade(pos, dimensoes, sf::Vector2f(0.0f, 0.0f)),
  danoso(dano)
{}

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