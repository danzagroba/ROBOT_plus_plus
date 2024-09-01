#pragma once

#include "Fase.hpp"

#define FASE_NOITE_PATH "../levels/fase2.json"

namespace Fases
{
    class FaseNoite : public Fase
    {
    private:
        int maxGumbots;
        int minGumbots;
        int maxByteCrushers;
        int minByteCrushers;
        int maxMaquinaProjeteis;
        int minMaquinaProjeteis;
        int maxAgua;
        int minAgua;

    public:
        FaseNoite(float comprimento = 16.0f);
        ~FaseNoite();

    private:
        void criarGumbots();
        void criarByteCrushers();
        void criarMaquinaProjeteis();
        void criarAgua();
        void criarEntidades();
        void criarPilares();
    };
} using namespace Fases;