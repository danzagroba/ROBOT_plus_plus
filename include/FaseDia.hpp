#pragma once

#include "Fase.hpp"

#define FASE_DIA_PATH "../levels/fase1.json"

namespace Fases
{
    class FaseDia : public Fase
    {
    private:
        int maxGumbots;
        int maxProjetctileBots;
        int maxAgua;
        int minAguas;
        int minProjectileBots;
        int minGumbots;

    public:
        FaseDia(float comprimento = 16.0f);
        ~FaseDia();

        const bool terminouFase() const;

    private:
        void criarGumbots();
        void criarProjectileBots();
        void criarAgua();
        void criarEntidades();
        void criarPilares();
    };
} using namespace Fases;