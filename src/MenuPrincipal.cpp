#include "MenuPrincipal.hpp"

MenuPrincipal::MenuPrincipal()
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
}