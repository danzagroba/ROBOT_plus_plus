#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Inputs.hpp" 
#include "Jogador.hpp"
#include "Fase.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

#define SPRITE_PATH "../assets/subZero.png"
#define LEVEL_PATH "../levels/fase1.json"

class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* gerGraf;
    Gerenciadores::Gerenciador_Inputs* gerInputs;
    Entidades::Personagens::Jogador jogador;
    Fases::Fase fase;

private:
    void processarEventos();

public:
    Jogo();
    ~Jogo();

    void executar();
};

