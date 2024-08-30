#pragma once

#include "Fase.hpp"

#define FASE_NOITE_PATH "../levels/fase2.json"

namespace Fases
{
    class FaseNoite : public Fase
    {
    private:
        int maxGumbots;
        int maxProjetctileBots;
        int maxAgua;
        int minAguas;
        int minProjectileBots;
        int minGumbots;

    public:
        FaseNoite(float comprimento = 16.0f);
        ~FaseNoite();

    private:
        void criarGumbots();
        void criarProjectileBots();
        void criarAgua();
        void criarEntidades();
        void criarPilares();
    };
} using namespace Fases;