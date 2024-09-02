#include "FimJogo.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Estados.hpp"
#include "Jogador.hpp"
#include "json.hpp"

#include <fstream>
#include <string>

namespace Estados
{
    FimJogo::FimJogo(const bool terminou)
        : Estado(3),
          fimDeJogo(),
          nome(),
          inserirNome(),
          irAoMenu(),
          input("")
    {
        
        Gerenciador_Grafico* pgergraf = Gerenciador_Grafico::getGerenciador_Grafico();
        pgergraf->setfundo(true);

        pgergraf->resetCamera();

        irAoMenu.trocarTexto("Ir ao menu");
        irAoMenu.setbotaopos(sf::Vector2f(300.0f, 500.0f));

        fimDeJogo.settexto(terminou ? "Parabens" : "Perdeu");
        fimDeJogo.tamanhofonte(70);
        fimDeJogo.settextopos(sf::Vector2f(250.0f, 70.0f));

        inserirNome.settexto("Insira seu nome:");
        inserirNome.tamanhofonte(40);
        inserirNome.settextopos(sf::Vector2f(250.0f, 140.0f));
    
        nome.tamanhofonte(40);
        nome.settextopos(sf::Vector2f(250.0f, 210.0f));
        vetorbotoes.push_back(&irAoMenu);
        
    }

    FimJogo::~FimJogo()
    {}

    void FimJogo::executar()
    {
        sf::Event event;
        sf::Window* window = Gerenciador_Grafico::getGerenciador_Grafico()->getJanela();

        bool criouMenu = false;

        while (window->pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed) 
            {
                window->close();
            }
            else if (event.type == sf::Event::TextEntered)
            
            {
                // Handle ASCII characters
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == '\b' && !input.empty())
                    {
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
                if(irAoMenu.getretangulo().getGlobalBounds().contains(mousePos))
                    criouMenu = true;
            }
        }

        if (input.length() > 3)
            input = input.substr(0, 3);
        nome.settexto(input);
        desenhar();
    
        if(criouMenu)
        {
            salvarPontuacao();
            menu();
        }
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

    void FimJogo::salvarPontuacao() 
    {
        try 
        {
            int pontos = Jogador::getpontuacao();

            std::string folderPath = "../ranking";
            std::string filePath = folderPath + "/data.json";

            // Ensure the directory exists
            std::filesystem::create_directory(folderPath);

            nlohmann::json rankings;

            // Attempt to read the existing rankings from the file
            std::ifstream fileIn(filePath);
            if (fileIn.is_open()) 
            {
                fileIn >> rankings;
                fileIn.close();

                if (!rankings.is_array()) 
                {
                    // If the JSON is not an array, reset it to an empty array
                    rankings = nlohmann::json::array();
                }
            } 
            else 
            {
                std::cerr << "No existing ranking file found. Creating a new one." << std::endl;
                rankings = nlohmann::json::array(); // Initialize rankings as an empty array
            }

            // Convert JSON to vector of pairs (name, points)
            std::vector<std::pair<std::string, int>> rankList;
            for (const auto& entry : rankings) 
            {
                if (entry.contains("nome") && entry.contains("pontos")) 
                {
                    rankList.emplace_back(entry["nome"], entry["pontos"]);
                }
            }

            // Add the new score
            rankList.emplace_back(input, pontos);

            // Sort the rankings by points in descending order
            std::sort(rankList.begin(), rankList.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });

            // Keep only the top 3
            if (rankList.size() > 3) {
                rankList.resize(3);
            }

            // Convert back to JSON
            rankings.clear();
            for (const auto& entry : rankList) 
            {
                nlohmann::json jsonEntry;
                jsonEntry["nome"] = entry.first;
                jsonEntry["pontos"] = entry.second;
                rankings.push_back(jsonEntry);
            }

            // Save updated rankings to the file
            std::ofstream fileOut(filePath);
            if (fileOut.is_open()) 
            {
                fileOut << rankings.dump(4); // Pretty print with 4 spaces indentation
                fileOut.close();
            } 
            else 
            {
                std::cerr << "Failed to open file for writing: " << filePath << std::endl;
            }
        } 
        catch (const std::exception& e) 
        {
            std::cerr << "An error occurred: " << e.what() << std::endl;
        }
        Jogador::aumentarpontuação(-(Jogador::getpontuacao()));
    }
}