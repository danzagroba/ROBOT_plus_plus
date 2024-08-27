#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Inputs.hpp" 
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Gerenciador_Eventos.hpp"

#include"MenuPrincipal.hpp"

#include "Jogador.hpp"
#include "Fase.hpp"
#include "FaseDia.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

#define LEVEL_PATH "../levels/fase1.json"

class Jogo
{
private:
    Gerenciadores::Gerenciador_Grafico* gerGraf;
    Gerenciadores::Gerenciador_Inputs* gerInputs;
    Gerenciadores::Gerenciador_Colisoes* gerColisoes;
    Gerenciadores::Gerenciador_Estados* gerEstados;
    Gerenciadores::Gerenciador_Eventos* gerEventos;
    Fases::FaseDia fase;

public:
    Jogo();
    ~Jogo();

    void executar();
};

