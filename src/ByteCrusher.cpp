#include "ByteCrusher.hpp"

list<Projetil*> ByteCrusher::projeteischefao;

ByteCrusher::ByteCrusher(const sf::Vector2f& pos):
Inimigo(8, pos, 1)
{
    id= 15;
    setFigura(BYTECRUSHER_SPRITE_PATH);
    tempo.restart();
}
ByteCrusher::~ByteCrusher()
{

}

void ByteCrusher::criartirochefao()
{
    if(tempo.getElapsedTime().asSeconds()>1.5)
    {
        Projetil* pprojetil = new Projetil(this, 1, sf::Vector2f(-0.1f, -0.1f), 20);
        if(pprojetil)
        {
            projeteischefao.push_back(pprojetil);
        }
        tempo.restart();
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