#include "Gumbot.hpp"
#include "Personagem.hpp"

Gumbot::Gumbot(const sf::Vector2f& pos):
Inimigo(3, pos, 1),
lado(true)
{
    setFigura(SPRITE_PATHGUMBOT);
    id = 5;
}
Gumbot::~Gumbot()
{
    
}
void Gumbot::andarlado()
{
    if(lado)
        setXvel(0.03f);
    else
        setXvel(-0.03f);
}
void Gumbot::trocalado()
{
    if(lado)
        lado = false;
    else
        lado = true;

}
void Gumbot::executar()
{
    aplicarForcaY(gravidade);
    andarlado();
    mover();
    desenhar();
}
void Gumbot::salvar()
{

}