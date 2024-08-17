#pragma once
#include <string>
#include <SFML/Graphics.hpp>
namespace Gerenciadores
{
    class Gerenciador_Grafico;
}using namespace Gerenciadores;

class Ente 
{
    protected:
        int id;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        sf::Texture Textura;
        sf::Sprite Figura;
    public:
        Ente();
        ~Ente();
        virtual void executar() = 0;
        void desenhar();
        void setFigura(string& Sprite_Path);
        sf::Sprite getFigura();
};
