#include "Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(Entidade* donoDoProjetil, const int danoProjetil, const sf::Vector2f& forcaInicial)
        : Entidade(donoDoProjetil ? donoDoProjetil->getPos() : sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f)),
          forca(forcaInicial),
          dano(danoProjetil),
          inserido(false)
    {
        setFigura(PROJETIL_SPRITE_PATH);
        velocidade = forca;
        id = 10;
    }

    Projetil::~Projetil()
    {

    }

    const int Projetil::getDano() const
    {
        return dano;
    }

    void Projetil::resetar()
    {
        id = 0;
    }
    bool Projetil::getinserido()
    {
        return inserido;
    }
    void Projetil::inseridonalista()
    {
        inserido = true;
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