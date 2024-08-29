#pragma once 

#include "Entidade.hpp"
#include "Jogador.hpp"

#define BANDEIRA_SPRITE_PATH "../assets/flag.png"

namespace Fases
{
    class Fase;
}

namespace Entidades
{
    class Bandeira : public Entidade
    {
    private:
        Fases::Fase* pFase;
        Jogador* jogadorUm;
        Jogador* jogadorDois;

    public:
        Bandeira(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f), 
                 Fases::Fase* pF = NULL,
                 Jogador* pJU = NULL,
                 Jogador* pJD = NULL);
        ~Bandeira();

        void executar();
        void salvar();
    };
}