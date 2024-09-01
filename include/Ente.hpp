#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include "Gerenciador_Grafico.hpp"

class Ente 
{
    protected:
        int id;
        static Gerenciadores::Gerenciador_Grafico* pGG;
        sf::Texture Textura;
        sf::Sprite Figura;

    public:
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;
        void desenhar();
        int getid();
        virtual void setFigura(const std::string& Sprite_Path);
        sf::FloatRect getBoundingBox();
        void setFiguraPos(const sf::Vector2f& pos);
        const sf::Sprite& getFigura() const;
};

