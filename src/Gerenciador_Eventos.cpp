#include "Gerenciador_Eventos.hpp"

#include <iostream>

namespace Gerenciadores
{
    Gerenciador_Inputs* Gerenciador_Eventos::pGI = Gerenciador_Inputs::getGerenciador_Inputs();
    Gerenciador_Eventos* Gerenciador_Eventos::pGE = NULL;

    Gerenciador_Eventos::Gerenciador_Eventos()
    {}

    Gerenciador_Eventos::~Gerenciador_Eventos()
    {
        std::cout << "gerenciador de eventos destruido\n";
    }

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
            if(event.type == sf::Event::Closed) 
                window->close();

            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                notificarMouse(sf::Mouse::getPosition(*window));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            notificarTecla(sf::Keyboard::A, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            notificarTecla(sf::Keyboard::S, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            notificarTecla(sf::Keyboard::D, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            notificarTecla(sf::Keyboard::W, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            notificarTecla(sf::Keyboard::Up, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            notificarTecla(sf::Keyboard::Left, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            notificarTecla(sf::Keyboard::Down, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            notificarTecla(sf::Keyboard::Right, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            notificarTecla(sf::Keyboard::Space, true);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            notificarTecla(sf::Keyboard::Enter, true);

        if(event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Up)
                notificarTecla(sf::Keyboard::Up, false);
            else if (event.key.code == sf::Keyboard::W)
                notificarTecla(sf::Keyboard::W, false);
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