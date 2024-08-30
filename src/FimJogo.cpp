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
          irAoMenu("Ir ao menu", sf::Vector2f(150.0f,250.0f)),
          input("")
    {
        Gerenciador_Grafico* pgergraf = Gerenciador_Grafico::getGerenciador_Grafico();

        pgergraf->setCameraSize(800.0f, 600.0f);
        pgergraf->setCamera(sf::Vector2f(400.0f, 300.0f));

        fimDeJogo.settexto(terminou ? "Parabens" : "Tente de novo");
        fimDeJogo.tamanhofonte(70);
        fimDeJogo.settextopos(sf::Vector2f(pgergraf->getCamera().getCenter().x - (fimDeJogo.gettamanho().width)/2.0, 70.0f));

        inserirNome.settexto("Insira seu nome:");
        inserirNome.tamanhofonte(40);
        inserirNome.settextopos(sf::Vector2f(pgergraf->getCamera().getCenter().x - (fimDeJogo.gettamanho().width)/2.0, 140.0f));
    
        nome.tamanhofonte(40);
        nome.settextopos(sf::Vector2f(pgergraf->getCamera().getCenter().x - (fimDeJogo.gettamanho().width)/2.0, 210.0f));
        vetorbotoes.push_back(&irAoMenu);
        
    }

    FimJogo::~FimJogo()
    {}

    void FimJogo::executar()
    {
        sf::Event event;
        sf::Window* window = Gerenciador_Grafico::getGerenciador_Grafico()->getJanela();

        while (window->pollEvent(event)) 
        {
            if (event.type == sf::Event::TextEntered)
            {
                // Handle ASCII characters
                if (event.text.unicode < 128)
                {
                    cout<<"Caractere pressionado"<<endl;
                    if (event.text.unicode == '\b' && !input.empty())
                    {
                        // Handle backspace (remove last character)
                        input.pop_back();
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode < 128)
                    {
                        // Add the new character to the input string
                        input += static_cast<char>(event.text.unicode);
                    }
                }
            }
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos =static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
                cout <<"Funciona1 pos:x e y  "<< mousePos.x<<"   "<<mousePos.y <<endl;
                std::cout << "Retângulo Bounds: (" << irAoMenu.getretangulo().getGlobalBounds().left << ", " 
                << irAoMenu.getretangulo().getGlobalBounds().top << ", " 
                << irAoMenu.getretangulo().getGlobalBounds().width << ", " 
                << irAoMenu.getretangulo().getGlobalBounds().height << ")" << std::endl;
                if(irAoMenu.getretangulo().getGlobalBounds().contains(mousePos))
                {
                    cout <<"Funciona"<<endl;
                    menu();
                }
            }
        }

        // Limit input length to 3 characters
        if (input.length() > 3)
        {
            input = input.substr(0, 3);
        }

        // Update the text display
        nome.settexto(input);

        // Call the drawing function
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
        cout<<"veio CHAMAAA"<<endl;
        Gerenciador_Estados* gerEstados = Gerenciador_Estados::getGerenciador_Estados();
        gerEstados->popEstadoatual();
    }
}