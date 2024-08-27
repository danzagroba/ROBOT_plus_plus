#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include "Gerenciador_Grafico.hpp"
#include "Gerenciador_Inputs.hpp" 
#include "Gerenciador_Colisoes.hpp"
#include "Gerenciador_Estados.hpp"
#include "Texto.hpp"
#include "Botao.hpp"

#include <iostream>
using namespace std;

#include "Estado.hpp"

namespace Estados
{
    class MenuPrincipal: public Estado
    {
        private:
            Texto titulo;
            Botao novojogo;
            Botao continuar;
            Botao ranking;
            Botao sair;
            

        public:
            void executar();
            void desenhar();
            MenuPrincipal();
            ~MenuPrincipal();
    };
} using namespace Estados;