#pragma once
#include "Obstaculo.hpp"

#define PILARSPRITE "../assets/pilar.png"
namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma: public Obstaculo
        {
            private:
                bool colidivel;
            public:
                Plataforma(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                           const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f),
                           bool cldv = true);
                ~Plataforma();
                const bool getcolidivel() const;
                void executar();
                void obstacular();
                void salvar();
        };
    } using namespace Obstaculos;
} using namespace Entidades;