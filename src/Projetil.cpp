#include "Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(Entidade* donoDoProjetil, const int danoProjetil, const sf::Vector2f& forcaInicial)
        : Entidade(donoDoProjetil ? donoDoProjetil->getPos() : sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f)),
          dono(donoDoProjetil), 
          forca(forcaInicial),
          dano(danoProjetil)
    {
        setFigura(PROJETIL_SPRITE_PATH);
        velocidade = forca;
        id = 10;
    }

    Projetil::~Projetil()
    {
        dono = NULL;
    }

    const int Projetil::getDano() const
    {
        return dano;
    }

    void Projetil::resetar()
    {
        if(!dono)
            return;

        posicao = dono->getPos();
        velocidade = forca;
    }

    void Projetil::executar()
    {
        mover();
        velocidade.y += gravidade;
    }

    void Projetil::salvar()
    {
        // TODO
    }
}