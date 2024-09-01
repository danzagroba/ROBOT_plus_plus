#include "Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(Entidade* donoDoProjetil, const int danoProjetil, const sf::Vector2f& forcaInicial, int idd)
        : Entidade(donoDoProjetil ? donoDoProjetil->getPos() : sf::Vector2f(0.0f, 0.0f), sf::Vector2f(0.0f, 0.0f)),
          forca(forcaInicial),
          dano(danoProjetil)
    {
        id=idd;
        if(id == 20 || id == 30)
        {
            posicao.y+=8;

        }
        else if(id == 40)
        {
            posicao.x -=4;
        }
        else if(id == 45)
        {
            posicao.x -= 3;
            posicao.y +=10;
        }
        else if(id == 50)
        {
            posicao.x += 13;
            posicao.y += 10;
        }
        inserido=false;
        setFigura(PROJETIL_SPRITE_PATH);
        velocidade = forca;
    }

    Projetil::~Projetil()
    {}

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