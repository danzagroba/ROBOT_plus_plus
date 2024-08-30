#pragma once

#include "Gerenciador_Grafico.hpp"
#include "Texto.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>

namespace Estados
{
    namespace UIelementos
    {
        class Botao
        {
            private:
                static Gerenciador_Grafico* pgergraf;
                Texto textobotao;
                sf::RectangleShape retanguloprincipal;
                sf::RectangleShape retangulosecundario;
                bool selecionado;

            public:
                Botao(string txt = "", sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f));
                ~Botao();
                sf::RectangleShape getretangulo();
                void setbotaopos(sf::Vector2f pos);
                void trocarTexto(const string& novoTexto);
                void desenhar();
                void executar();
        };
    }using namespace UIelementos;
}using namespace Estados;