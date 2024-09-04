#include "FimJogo.hpp"
#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Estados.hpp"
#include "Jogador.hpp"
//#include "json.hpp"

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
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == '\b' && !input.empty())
                    {
                        input.pop_back();
                    }
                    else if (event.text.unicode >= 32 && event.text.unicode < 128)
                    {
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

            std::string caminhoPasta = "../ranking";
            std::string caminhoArquivo = caminhoPasta + "/data.json";

            std::filesystem::create_directory(caminhoPasta);

            nlohmann::json rankings;

            std::ifstream arquivoEntrada(caminhoArquivo);
            if (arquivoEntrada.is_open()) 
            {
                arquivoEntrada >> rankings;
                arquivoEntrada.close();

                if (!rankings.is_array()) 
                {
                    rankings = nlohmann::json::array();
                }
            } 
            else 
            {
                std::cerr << "Nenhum arquivo de ranking existente encontrado. Criando um novo." << std::endl;
                rankings = nlohmann::json::array();
            }

            std::vector<std::pair<std::string, int>> listaRanking;
            for (const nlohmann::json& entrada : rankings) 
            {
                if (entrada.contains("nome") && entrada.contains("pontos")) 
                {
                    listaRanking.emplace_back(entrada["nome"], entrada["pontos"]);
                }
            }

            listaRanking.emplace_back(input, pontos);

            std::sort(listaRanking.begin(), listaRanking.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                return a.second > b.second;
            });

            if (listaRanking.size() > 3) {
                listaRanking.resize(3);
            }

            rankings.clear();
            for (const std::pair<std::string, int>& entrada : listaRanking) 
            {
                nlohmann::json jsonEntrada;
                jsonEntrada["nome"] = entrada.first;
                jsonEntrada["pontos"] = entrada.second;
                rankings.push_back(jsonEntrada);
            }

            std::ofstream arquivoSaida(caminhoArquivo);
            if (arquivoSaida.is_open()) 
            {
                arquivoSaida << rankings.dump(4); 
                arquivoSaida.close();
            } 
            else 
            {
                std::cerr << "Falha ao abrir o arquivo para escrita: " << caminhoArquivo << std::endl;
            }
        } 
        catch (const std::exception& e) 
        {
            std::cerr << "Ocorreu um erro: " << e.what() << std::endl;
        }
        Jogador::aumentarpontuação(-(Jogador::getpontuacao()));
    }

}