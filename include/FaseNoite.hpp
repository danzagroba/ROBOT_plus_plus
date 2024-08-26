#pragma once

#pragma once

#include "Fase.hpp"

#define FASE_NOITE_PATH "../levels/fase2.json"

namespace Fases
{
    class FaseNoite : public Fase
    {
    public:
        FaseNoite(Gerenciadores::Gerenciador_Grafico* pGG = nullptr,
                  Gerenciadores::Gerenciador_Colisoes* pCO = nullptr,
                  Entidades::Personagens::Jogador* jgdr = nullptr,
                  Entidades::Personagens::Jogador* jgdrdois = nullptr,
                  float comprimento = 16.0f);
        ~FaseNoite();

    protected:
        void criarEntidades();
    };
}