#include "Ranking.hpp"
#include "Gerenciador_Estados.hpp"
#include "json.hpp"

#include <fstream>
#include <string>

namespace Estados
{
    Ranking::Ranking()
    : Estado(4),
      colocacao(),
      primeiro(),
      segundo(),
      terceiro(),
      irAoMenu()
    {
        irAoMenu.trocarTexto("Ir ao menu");
        irAoMenu.setbotaopos(sf::Vector2f(300.0f, 500.0f));

        colocacao.settexto("Ranking");
        colocacao.settextopos(sf::Vector2f(250.0f, 70.0f));
        
        primeiro.settextopos(sf::Vector2f(200.0f, 150.0f));
        segundo.settextopos(sf::Vector2f(200.0f, 200.0f));
        terceiro.settextopos(sf::Vector2f(200.0f, 250.0f));

        carregarRanking();
    }

    void Ranking::carregarRanking()
    {
        std::string filePath = "../ranking/data.json";
        nlohmann::json rankings;

        // Load ranking data from file
        std::ifstream fileIn(filePath);
        if(fileIn.is_open()) 
        {
            fileIn >> rankings;
            fileIn.close();
            
            // Ensure the JSON is an array
            if (rankings.is_array()) 
            {
                if (rankings.size() > 0) 
                    primeiro.settexto(rankings[0]["nome"].get<std::string>() + " - " + std::to_string(rankings[0]["pontos"].get<int>()));
                if (rankings.size() > 1) 
                    segundo.settexto(rankings[1]["nome"].get<std::string>() + " - " + std::to_string(rankings[1]["pontos"].get<int>()));
                if (rankings.size() > 2) 
                    terceiro.settexto(rankings[2]["nome"].get<std::string>() + " - " + std::to_string(rankings[2]["pontos"].get<int>()));
            }
        } 
        else 
        {
            std::cerr << "Failed to open ranking file: " << filePath << std::endl;
        }
    }

    Ranking::~Ranking()
    {}

    void Ranking::executar()
    {
        sf::Event event;
        sf::Window* window = Gerenciador_Grafico::getGerenciador_Grafico()->getJanela();

        bool criouMenu = false;

        while (window->pollEvent(event)) 
        {
            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos =static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
                if(irAoMenu.getretangulo().getGlobalBounds().contains(mousePos))
                    criouMenu = true;
            }
        }

        desenhar();
        if(criouMenu)
            menu();
    }

    void Ranking::desenhar()
    {
        colocacao.desenhar();
        primeiro.desenhar();
        segundo.desenhar();
        terceiro.desenhar();
        irAoMenu.desenhar();
    }

    void Ranking::menu()
    {
        Gerenciador_Estados* gerEstados = Gerenciador_Estados::getGerenciador_Estados();
        gerEstados->popEstadoatual();
    }
}