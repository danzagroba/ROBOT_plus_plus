#include "FimJogo.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Estados.hpp"

namespace Estados
{
    FimJogo::FimJogo(const bool terminou)
        : Estado(3),
          fimDeJogo(),
          nome(),
          inserirNome(),
          irAoMenu("Ir ao menu", sf::Vector2f(300.0f,510.0f)),
          input("")
    {
        Gerenciador_Grafico* pgergraf = Gerenciador_Grafico::getGerenciador_Grafico();

        (pgergraf->getCamera()).setSize(pgergraf->getCamera().getSize().x, pgergraf->getCamera().getSize().y);

        fimDeJogo.settexto(terminou ? "Parabens" : "Tente de novo");
        fimDeJogo.tamanhofonte(70);
        fimDeJogo.settextopos(sf::Vector2f(pgergraf->getCamera().getCenter().x - (fimDeJogo.gettamanho().width)/2.0,100));

        inserirNome.settexto("Insira seu nome:");
        inserirNome.tamanhofonte(40);
        inserirNome.settextopos(sf::Vector2f(pgergraf->getCamera().getCenter().x - (fimDeJogo.gettamanho().width)/2.0,300.0f));
    
        nome.tamanhofonte(40);
        nome.settextopos(sf::Vector2f(pgergraf->getCamera().getCenter().x - (fimDeJogo.gettamanho().width)/2.0,370.0f));

        vetorbotoes.push_back(&irAoMenu);
    }

    FimJogo::~FimJogo()
    {}

    void FimJogo::executar()
    {

        sf::Event event;
        
        sf::Window* window = Gerenciador_Grafico::getGerenciador_Grafico()->getJanela();
        
        char novaLetra = '\0';

        while(window->pollEvent(event)) 
        {
            if(event.type == sf::Event::KeyPressed)
            { 
                if(event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z)
                {
                    novaLetra = event.key.code; 
                    break;
                }   
                else if(event.key.code == sf::Keyboard::Backspace)
                {
                    if(input.length() > 0)
                    {
                        input.erase(input.size() - 1);
                    }
                }
            }
        }
        
        if(novaLetra != '\0')
            input += novaLetra;

        if (input.length() > 3) 
            input = input.substr(0, 3);

        nome.settexto(input);

        desenhar();
    }

    void FimJogo::desenhar()
    {
        fimDeJogo.desenhar();
        inserirNome.desenhar();
        irAoMenu.desenhar();
        nome.desenhar();
    }

    void FimJogo::menu()
    {
        Gerenciador_Estados* gerEstados = Gerenciador_Estados::getGerenciador_Estados();
    
        gerEstados->popEstadoatual();
    }
}