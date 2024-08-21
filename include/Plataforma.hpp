#pragma once
#include "Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma: public Obstaculo
        {
            public:
                Plataforma();
                ~Plataforma();
                void executar();
                void obstacular();
        };
    } using namespace Obstaculos;
} using namespace Entidades;