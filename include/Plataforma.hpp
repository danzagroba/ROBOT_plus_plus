#pragma once
#include "Obstaculo.hpp"

#define PILARSPRITE "../assets/pilar.png"

namespace Gerenciadores
{
    class Gerenciador_Colisoes;
}

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma: public Obstaculo
        {
            private:
                bool colidivel;
                static Gerenciadores::Gerenciador_Colisoes* pGC;

            public:
                Plataforma(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                           const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f),
                           bool cldv = true);
                ~Plataforma();

                void executar();
                void obstacular(Jogador* pJogador);
                void salvar();
        };
    } using namespace Obstaculos;
} using namespace Entidades;