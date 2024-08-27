#include "MenuPrincipal.hpp"


MenuPrincipal::MenuPrincipal():
novojogo("Novo Jogo",sf::Vector2f(350.0f,300.0f))
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
}