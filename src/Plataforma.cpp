#include "Plataforma.hpp"
#include "Gerenciador_Colisoes.hpp"

Gerenciadores::Gerenciador_Colisoes* Plataforma::pGC(Gerenciador_Colisoes::getGerenciador_Colisoes());

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

void Plataforma::executar() 
{}

void Plataforma::obstacular(Jogador* pJogador) 
{
    if(colidivel)
        pGC->tratarColisao(pJogador, this);
}

void Plataforma::salvar()
{}   