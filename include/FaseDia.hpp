#pragma once

#include "Fase.hpp"

#define FASE_DIA_PATH "../levels/fase1.json"

namespace Fases
{
    class FaseDia : public Fase
    {
    public:
        FaseDia(Gerenciadores::Gerenciador_Grafico* pGG = nullptr,
                Gerenciadores::Gerenciador_Colisoes* pCO = nullptr,
                Entidades::Personagens::Jogador* jgdr = nullptr,
                Entidades::Personagens::Jogador* jgdrdois = nullptr,
                float comprimento = 16.0f);
        ~FaseDia();

    protected:
        void criarEntidades();
    };
} using namespace Fases;