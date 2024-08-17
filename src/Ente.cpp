#include "Ente.hpp"
#include <SFML/Graphics.hpp>

#include "Gerenciador_Grafico.hpp"
#include <string>



Gerenciadores::Gerenciador_Grafico* Ente::pGG = NULL;

Ente::Ente():
id(-1)
{

}

Ente::~Ente()
{
    
}
void Ente::desenhar()
{
    Gerenciador_Grafico::getGerenciador_Grafico()->desenharEnte(this);
}
void Ente::setFigura(string& Sprite_Path)
{

    if (!Textura.loadFromFile(Sprite_Path))
    {
        cout<<"Erro no caminho da pasta do sprite, textura não carregada"<<endl;
        return;
    }
    Figura.setTexture(Textura);

}
sf::Sprite Ente::getFigura(){ return Figura; }

