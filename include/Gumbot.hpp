#pragma once
#include "Inimigo.hpp"

#define SPRITE_PATHGUMBOT "../assets/gumbot.png"

namespace Entidades
{
    namespace Personagens
    {
        class Gumbot:public Inimigo
        {
            private:
                bool lado;
                void andarlado();
            public:
                Gumbot(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                ~Gumbot();
                void trocalado();
                void executar();
                void salvar();
        };
    } using namespace Personagens;
} using namespace Entidades;