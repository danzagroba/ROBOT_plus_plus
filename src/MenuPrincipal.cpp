#include "MenuPrincipal.hpp"


MenuPrincipal::MenuPrincipal():
novojogo("Novo Jogo",sf::Vector2f(300.0f,300.0f)),
continuar("Continuar",sf::Vector2f(300.0f,370.0f)),
ranking("Ranking",sf::Vector2f(300.0f,440.0f)),
sair("Sair", sf::Vector2f(300.0f,510.0f))
{
    titulo.settexto("ROBOT++");
    titulo.tamanhofonte(70);
    titulo.settextopos(sf::Vector2f(100,100));
}


MenuPrincipal::~MenuPrincipal()
{

}
void MenuPrincipal::executar()
{
    desenhar();
}
void MenuPrincipal::desenhar()
{
    titulo.desenhar();
    novojogo.desenhar();
    continuar.desenhar();
    ranking.desenhar();
    sair.desenhar();
}