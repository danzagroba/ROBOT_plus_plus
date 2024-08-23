#include "Entidade.hpp"

#include <iostream>


const float Entidade::maxVel(1.25f);

float Entidade::gravidade(0.01);

Entidade::Entidade(const sf::Vector2f& pos, const sf::Vector2f& vel):
Ente(),
posicao(pos),
velocidade(vel),
AreaColisao(pos, sf::Vector2f(0.0f, 0.0f))
{
    Figura.setPosition(posicao);
    id = -1;
}

Entidade::~Entidade()
{

}

void Entidade::setPos(float xx, float yy)
{
    posicao.x = xx;
    posicao.y = yy;
    Figura.setPosition(posicao);
    AreaColisao.left = posicao.x;
    AreaColisao.top = posicao.y;
}

void Entidade::mover()
{
    posicao += velocidade * pGG->getDeltaTime();
    AreaColisao.left = posicao.x;
    AreaColisao.top = posicao.y;
    Figura.setPosition(posicao);
    //std::cout << "pos: " << posicao.x << " " << posicao.y << std::endl;
}

void Entidade::setXvel(const float vel)
{
    velocidade.x = vel;
}

void Entidade::setYvel(const float vel)
{
    velocidade.y = vel;
}
void Entidade::setBoundingBox()
{
    AreaColisao = Figura.getGlobalBounds();
}

const sf::Vector2f& Entidade::getVel() const
{
    return velocidade;
}

const float Entidade::getXVel() const
{
    return velocidade.x;
}

const float Entidade::getYVel() const
{
    return velocidade.y;
}

sf::FloatRect Entidade::getBoundingBox()
{
    return AreaColisao;
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

void Entidade::setGravidade(float g)
{
    gravidade = g;
}
