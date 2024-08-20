#include "Entidade.hpp"

#include <iostream>

Entidade::Entidade(const sf::Vector2f& pos):
Ente(),
posicao(pos)
{
    Figura.setPosition(posicao);
}
Entidade::~Entidade()
{

}

void Entidade::setPos(float xx, float yy)
{
    posicao.x = xx;
    posicao.y = yy;
    Figura.setPosition(posicao);
}
void Entidade::mover(const sf::Vector2f& deslocamento)
{
    posicao += deslocamento * pGG->getDeltaTime();
    Figura.setPosition(posicao);
    std::cout << "pos: " << posicao.x << " " << posicao.y << std::endl;
}
const sf::Vector2f& Entidade::getPos() const
{
    return posicao;
}
void Entidade::setFigura(const std::string& Sprite_Path)
{
    if (!Textura.loadFromFile(Sprite_Path))
    {
        cout<<"Erro no caminho da pasta do sprite, textura não carregada"<<endl;
        return;
    }
    Figura.setTexture(Textura);
    AreaColisao = Figura.getGlobalBounds();

}


