#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Inputs.hpp" 
#include "Gerenciador_Colisoes.hpp"
#include "Jogador.hpp"
#include "Fase.hpp"
#include "FaseDia.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

#define SPRITE_PATHP1 "../assets/player1.png"
#define SPRITE_PATHP2 "../assets/player2.png"
#define LEVEL_PATH "../levels/fase1.json"

class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* gerGraf;
    Gerenciadores::Gerenciador_Inputs* gerInputs;
    Gerenciadores::Gerenciador_Colisoes* gerColisoes;
    Entidades::Personagens::Jogador jogador;
    Entidades::Personagens::Jogador* pjogadordois;
    Fases::FaseDia fase;

public:
    Jogo();
    ~Jogo();

    void executar();
};

