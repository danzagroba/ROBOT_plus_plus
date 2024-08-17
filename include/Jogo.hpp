#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Inputs.hpp" 
#include "Jogador.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

#define SPRITE_PATH "../assets/subZero.png"

class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* gerGraf;
    Gerenciadores::Gerenciador_Inputs* gerInputs;
    float deltaTime;
    sf::Clock clock;    // Usado para medir deltaTime
    Entidades::Personagens::Jogador jogador;

private:
    void atualizarDeltaTime();
    void processarEventos();

public:
    Jogo();
    ~Jogo();

    void executar();
};
