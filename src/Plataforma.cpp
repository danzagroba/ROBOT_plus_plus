#include "Plataforma.hpp"

Plataforma::Plataforma(const sf::Vector2f& pos, const sf::Vector2f& dimensoes)
    : Obstaculo(pos, dimensoes, false)
{
    id = 8;
}

Plataforma::~Plataforma()
{}

void Plataforma::executar() 
{}

void Plataforma::obstacular() 
{}

void Plataforma::salvar()
{}   