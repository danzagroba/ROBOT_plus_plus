#include "Bandeira.hpp"
#include "Fase.hpp"

namespace Entidades
{
    Bandeira::Bandeira(const sf::Vector2f& pos, Fases::Fase* pF, Jogador* pJU, Jogador* pJD)
        : Entidade(pos, sf::Vector2f(0.0f, 0.0f)),
          pFase(pF),
          jogadorUm(pJU),
          jogadorDois(pJD)
    {
        id = 40;
        setFigura(BANDEIRA_SPRITE_PATH);
    }

    Bandeira::~Bandeira()
    {}

    void Bandeira::executar()
    {
        if(!pFase)
            return;

        if(jogadorUm)
            if(getBoundingBox().intersects(jogadorUm->getBoundingBox()))
            {
                pFase->terminarFase();
                pGG->setfundo(false);
            }
    
        if(jogadorDois)
            if(getBoundingBox().intersects(jogadorDois->getBoundingBox()))
            {
                pFase->terminarFase();
                pGG->setfundo(false);
            }
    }

    void Bandeira::salvar()
    {}
}