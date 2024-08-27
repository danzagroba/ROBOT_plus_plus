#pragma once

#include "Fase.hpp"

#define FASE_DIA_PATH "../levels/fase1.json"

namespace Fases
{
    class FaseDia : public Fase
    {
    public:
        FaseDia(float comprimento = 16.0f);
        ~FaseDia();

    protected:
        void criarEntidades();
    };
} using namespace Fases;