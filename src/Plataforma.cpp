#include "Plataforma.hpp"

Plataforma::Plataforma(const sf::Vector2f& pos, const sf::Vector2f& dimensoes, bool cldv)
    : Obstaculo(pos, dimensoes, false),
    colidivel(cldv)
{
    id = 8;
    if(!colidivel)
    {
        setFigura(PILARSPRITE);
    }
}

Plataforma::~Plataforma()
{}

const bool Plataforma::getcolidivel() const
{
    return colidivel;
}
void Plataforma::executar() 
{}

void Plataforma::obstacular() 
{}

void Plataforma::salvar()
{}   