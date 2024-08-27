#include "Gerenciador_Eventos.hpp"

#include <iostream>

namespace Gerenciadores
{
    Gerenciador_Inputs* Gerenciador_Eventos::pGI = Gerenciador_Inputs::getGerenciador_Inputs();
    Gerenciador_Eventos* Gerenciador_Eventos::pGE = NULL;

    Gerenciador_Eventos::Gerenciador_Eventos()
    {}

    Gerenciador_Eventos::~Gerenciador_Eventos()
    {}

    Gerenciador_Eventos* Gerenciador_Eventos::getGerenciador_Eventos() 
    {
        if(pGE == NULL) 
        {
            pGE = new Gerenciador_Eventos();
            if(pGE == NULL) 
            {
                cout<<"Erro ao alocar gerenciador de eventos, fechando execução"<<endl;
                exit(1);
            }
        }
        return pGE;
    }

    void Gerenciador_Eventos::executar(sf::RenderWindow* window)
    {
        sf::Event event;
        while(window->pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window->close();
            }
            if(event.type == sf::Event::KeyReleased) 
                notificarTecla(event.key.code, false);
            else if(event.type == sf::Event::KeyPressed)
                notificarTecla(event.key.code, true);
            
            if (event.type == sf::Event::MouseButtonReleased) {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    notificarMouse(sf::Mouse::getPosition(*window));
                }
            }
        }
    }

    void Gerenciador_Eventos::notificarTecla(sf::Keyboard::Key key, const bool pressionado)
    {
        pGI->processainput(key, pressionado);
    }
    void Gerenciador_Eventos::notificarMouse(sf::Vector2i pos)
    {
        pGI->processainput(pos);
    }
}