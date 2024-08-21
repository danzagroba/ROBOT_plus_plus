#include "Obstaculo.hpp"

Obstaculo::Obstaculo(const sf::Vector2f& pos, 
                     const sf::Vector2f& dimensoes,
                     bool dano)
: Entidade(pos, dimensoes),
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