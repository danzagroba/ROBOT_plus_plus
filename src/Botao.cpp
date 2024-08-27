#include "Botao.hpp"

Gerenciador_Grafico* Botao::pgergraf = Gerenciador_Grafico::getGerenciador_Grafico();

Botao::Botao(string txt, sf::Vector2f pos):
selecionado(false)
{
    retanguloprincipal.setSize(sf::Vector2f(200.0f,50.0f));
    retanguloprincipal.setPosition(pos);
    retanguloprincipal.setFillColor(sf::Color::White);
    retangulosecundario.setSize(sf::Vector2f(190.0f,40.0f));
    retangulosecundario.setFillColor(sf::Color::Black);
    textobotao.settexto(txt);
    textobotao.tamanhofonte(20);

    sf::FloatRect textBounds = textobotao.gettamanho();
    sf::FloatRect rectpBounds = retanguloprincipal.getGlobalBounds();
    sf::FloatRect rectsBounds = retangulosecundario.getGlobalBounds();

    float x = rectpBounds.left + (rectpBounds.width - rectsBounds.width) / 2.0f;
    float y = rectpBounds.top + (rectpBounds.height - rectsBounds.height) / 2.0f;
    retangulosecundario.setPosition(x,y);

    x = rectpBounds.left + (rectpBounds.width - textBounds.width) / 2.0f;
    y = rectpBounds.top + (rectpBounds.height - textBounds.height) / 2.0f;
    textobotao.settextopos(sf::Vector2f(x,y));

}
Botao::~Botao()
{

}
void Botao::setbotaopos(sf::Vector2f pos)
{
    retanguloprincipal.setPosition(pos);

    sf::FloatRect textBounds = textobotao.gettamanho();
    sf::FloatRect rectpBounds = retanguloprincipal.getGlobalBounds();
    sf::FloatRect rectsBounds = retangulosecundario.getGlobalBounds();

    float x = rectpBounds.left + (rectpBounds.width - rectsBounds.width) / 2.0f;
    float y = rectpBounds.top + (rectpBounds.height - rectsBounds.height) / 2.0f;
    retangulosecundario.setPosition(x,y);

    x = rectpBounds.left + (rectpBounds.width - textBounds.width) / 2.0f;
    y = rectpBounds.top + (rectpBounds.height - textBounds.height) / 2.0f;
    textobotao.settextopos(sf::Vector2f(x,y));
}
void Botao::desenhar()
{
    pgergraf->desenhar(retanguloprincipal);
    pgergraf->desenhar(retangulosecundario);
    textobotao.desenhar();
}
void Botao::executar()
{
    desenhar();
}