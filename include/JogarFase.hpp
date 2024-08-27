#pragma once

#include "Estado.hpp"
#include "FaseDia.hpp"
#include "FaseNoite.hpp"

namespace Estados
{
    class JogarFase: public Estado
    {
        private:
            FaseDia* pfasedia;
            FaseNoite* pfasenoite;
            int faseescolhida;
        public:
            JogarFase();
            ~JogarFase();
            void executar();

    };
} using namespace Estados;