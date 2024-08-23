#pragma once
#include "Inimigo.hpp"

#define SPRITE_PATHP1 "../assets/gumbot.png"

namespace Entidades
{
    namespace Personagens
    {
        class Gumbot:public Inimigo
        {
            private:
                

            public:
                Gumbot();
                ~Gumbot();
        };
    } using namespace Personagens;
} using namespace Entidades;