#pragma once

#include "Fase.hpp"

#define FASE_DIA_PATH "../levels/fase1.json"

namespace Fases
{
    class FaseDia : public Fase
    {
    private:
        int maxGumbots;
        int minGumbots;
        int maxProjectileBots;
        int minProjectileBots;
        int maxMaquinaProjeteis;
        int minMaquinaProjeteis;
        int maxAgua;
        int minAguas;

    public:
        FaseDia(float comprimento = 16.0f);
        ~FaseDia();

        const bool terminouFase() const;

    private:
        void criarGumbots();
        void criarProjectileBots();
        void criarMaquinaProjeteis();
        void criarAgua();
        void criarEntidades();
        void criarPilares();
    };
} using namespace Fases;