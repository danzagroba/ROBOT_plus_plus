#include "Ente.hpp"
#include <SFML/Graphics.hpp>

#include "Gerenciador_Grafico.hpp"
#include <string>



Gerenciadores::Gerenciador_Grafico* Ente::pGG = Gerenciador_Grafico::getGerenciador_Grafico();


Ente::Ente():
id(0),
Figura(),
Textura()
{}

Ente::~Ente()
{
    
}
void Ente::desenhar()
{
    pGG->desenharEnte(this);
}
void Ente::setFigura(const std::string& Sprite_Path)
{
    if (!Textura.loadFromFile(Sprite_Path))
    {
        cout<<"Erro no caminho da pasta do sprite, textura não carregada"<<endl;
        return;
    }
    Figura.setTexture(Textura);

}
const sf::Sprite& Ente::getFigura() const{ return Figura; }
void Ente::setFiguraPos(const sf::Vector2f& pos)
{
    Figura.setPosition(pos);
}
int Ente::getid()
{
    return id;
}
sf::FloatRect Ente::getBoundingBox()
{
    return Figura.getGlobalBounds();
}

