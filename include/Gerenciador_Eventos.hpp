#pragma once

#include "Gerenciador_Inputs.hpp"

#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
    class Gerenciador_Eventos
    {
    private:
        static Gerenciador_Inputs* pGI;
        static Gerenciador_Eventos* pGE;

    public:
        Gerenciador_Eventos();
        ~Gerenciador_Eventos();

        static Gerenciador_Eventos* getGerenciador_Eventos();

        void executar(sf::RenderWindow* window);

        void notificarTecla(sf::Keyboard::Key key, const bool pressionado);
        void notificarMouse(sf::Vector2i pos);
    };
}