#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.hpp"
#include "Ente.hpp"

#define FONT "../assets/zig_____.ttf"
namespace Estados
{
    class Texto
    {
        private:
            static Gerenciador_Grafico* pgergraf;
            static sf::Font fonte;
            sf::Text texto;
        public:
            Texto();
            ~Texto();
            void settexto(string text);
            void tamanhofonte(int tamanho);
            void settextopos(sf::Vector2f pos);
            void desenhar();
            void executar();
    };

}using namespace Estados;