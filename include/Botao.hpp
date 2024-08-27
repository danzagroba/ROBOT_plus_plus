#pragma once

#include "Gerenciador_Grafico.hpp"
#include "Texto.hpp"

namespace Estados
{
    namespace UIelementos
    {
        class Botao
        {
            private:
                static Gerenciador_Grafico* pgergraf;
                Texto textobotao;
                sf::RectangleShape retangulo;
                bool selecionado;
            public:
                Botao(string txt, sf::Vector2f pos);
                ~Botao();
                void setbotaopos(sf::Vector2f pos);
                void desenhar();
                void executar();
        };
    }using namespace UIelementos;
}using namespace Estados;