#pragma once
#include "Obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma: public Obstaculo
        {
            public:
                Plataforma(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                           const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f));
                ~Plataforma();
                void executar();
                void obstacular();
                void salvar();
        };
    } using namespace Obstaculos;
} using namespace Entidades;