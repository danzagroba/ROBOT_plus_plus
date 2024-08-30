#pragma once

#include "Entidade.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo: public Entidade
        {
            protected:
                bool danoso;

            public:
                Obstaculo(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                          const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f),
                          const bool dano = false);
                virtual ~Obstaculo();

                const bool eDanoso() const;

                virtual void executar() = 0;
                virtual void obstacular() = 0;
                virtual void salvar() = 0;
        };
    } using namespace Obstaculos;
} using namespace Entidades;

