#include "Botao.hpp"

Gerenciador_Grafico* Botao::pgergraf = Gerenciador_Grafico::getGerenciador_Grafico();

Botao::Botao(string txt, sf::Vector2f pos):
selecionado(false)
{
    retangulo.setSize(sf::Vector2f(100.0f,50.0f));
    retangulo.setPosition(pos);
    textobotao.settexto(txt);
    textobotao.tamanhofonte(20);

    sf::FloatRect textBounds = textobotao.gettamanho();
    sf::FloatRect rectBounds = retangulo.getGlobalBounds();
    float x = rectBounds.left + (rectBounds.width - textBounds.width) / 2.0f;
    float y = rectBounds.top + (rectBounds.height - textBounds.height) / 2.0f;

    textobotao.settextopos(sf::Vector2f(x,y));

}
Botao::~Botao()
{

}
void Botao::setbotaopos(sf::Vector2f pos)
{
    retangulo.setPosition(pos);
}
void Botao::desenhar()
{
    pgergraf->desenhar(retangulo);
    textobotao.desenhar();
}
void Botao::executar()
{
    desenhar();
}