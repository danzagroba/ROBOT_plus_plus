#include "Texto.hpp"
#include "Gerenciador_Grafico.hpp"

sf::Font Texto::fonte;
Gerenciador_Grafico* Texto::pgergraf = Gerenciador_Grafico::getGerenciador_Grafico();

Texto::Texto()
{
    if (!fonte.loadFromFile(FONT)) {
        cerr << "Erro ao carregar a fonte!" <<endl;
    }
    texto.setFont(fonte);
    texto.setString("");
    texto.setPosition(0, 0);
    texto.setFillColor(sf::Color::White);
}
Texto::~Texto()
{
}
void Texto::settexto(string txt)
{
    texto.setString(txt);
}
void Texto::tamanhofonte(int tamanho)
{
    texto.setCharacterSize(tamanho);
}
void Texto::settextopos(sf::Vector2f pos)
{
    texto.setPosition(pos);
}

sf::FloatRect Texto::gettamanho()
{
    return texto.getGlobalBounds();
}
void Texto::desenhar()
{
    pgergraf->desenhartxt(&texto);
}
void Texto::executar()
{}
