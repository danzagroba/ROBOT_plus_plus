#include "ByteCrusher.hpp"

list<Projetil*> ByteCrusher::projeteischefao;

ByteCrusher::ByteCrusher(const sf::Vector2f& pos):
Inimigo(8, pos, 1)
{
    id= 15;
    etapaataque = 1;
    setFigura(BYTECRUSHER_SPRITE_PATH);
    tempo.restart();
}
ByteCrusher::~ByteCrusher()
{

}

void ByteCrusher::criartirochefao()
{
    if(tempo.getElapsedTime().asSeconds()>1.0)
    {
        if(etapaataque == 1)
        {
            Projetil* pprojetil = new Projetil(this, 1, sf::Vector2f(-0.05f, -0.1f), 45);
            if(pprojetil)
            {
                projeteischefao.push_back(pprojetil);
            }
            pprojetil = new Projetil(this, 1, sf::Vector2f(0.05f, -0.1f), 50);
            if(pprojetil)
            {
                projeteischefao.push_back(pprojetil);
            }
            tempo.restart();
            etapaataque++;
        }
        else if(etapaataque == 2)
        {
            Projetil* pprojetil = new Projetil(this, 1, sf::Vector2f(-0.08f, -0.15f), 45);
            if(pprojetil)
            {
                projeteischefao.push_back(pprojetil);
            }
            pprojetil = new Projetil(this, 1, sf::Vector2f(0.08f, -0.15f), 50);
            if(pprojetil)
            {
                projeteischefao.push_back(pprojetil);
            }
            tempo.restart();
            etapaataque++;
        }
        else if(etapaataque == 3)
        {
            Projetil* pprojetil = new Projetil(this, 1, sf::Vector2f(-0.1f, -0.2f), 45);
            if(pprojetil)
            {
                projeteischefao.push_back(pprojetil);
            }
            pprojetil = new Projetil(this, 1, sf::Vector2f(0.1f, -0.2f), 50);
            if(pprojetil)
            {
                projeteischefao.push_back(pprojetil);
            }
            tempo.restart();
            etapaataque++;
        }
        else if(etapaataque == 6)
        {
            etapaataque = 0;
            tempo.restart();
        }
        else 
        {
            if(rand()%2)
            {
                posicao.x+=(rand()%5)+1;
            } else
            {
                posicao.x-=(rand()%5)+1;
            }
            etapaataque++;
            tempo.restart();
        }
    }
}

void ByteCrusher::removertirochefao(Projetil* ep)
{
    list<Projetil*>::iterator it = std::find(projeteischefao.begin(), projeteischefao.end(), ep);
    if (it != projeteischefao.end()) {
        projeteischefao.erase(it);
    }
}
list<Projetil*>* ByteCrusher::getprojeteischefao() {
    return &projeteischefao;
}

void ByteCrusher::executar()
{
    aplicarForcaY(gravidade);
    criartirochefao();
    mover();
}

void ByteCrusher::salvar()
{

}