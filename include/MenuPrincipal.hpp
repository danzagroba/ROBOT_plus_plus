#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Inputs.hpp" 
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Gerenciador_Eventos.hpp"
#include "Texto.hpp"
#include "Botao.hpp"

#include <iostream>
using namespace std;

namespace Estados
{
    class MenuPrincipal: public Estado, public Ente
    {
        private:
            Texto titulo;
            Botao numjogadores;
            Botao escolhefase;
            Botao novojogo;
            Botao ranking;
            Botao sair;
            int fase;

        public:
            void executar();
            void desenhar();
            void sairjogo();
            void trocarfase();
            void doisjogadores();
            MenuPrincipal();
            ~MenuPrincipal();
    };
} using namespace Estados;