#pragma once

#include "Estado.hpp"
#include "FaseDia.hpp"
//#include "FaseNoite.hpp"

//STATE
namespace Estados
{
    class JogarFase: public Estado
    {
        private:
            FaseDia* pfasedia;
            Texto pontos;
            //FaseNoite* pfasenoite;
            int faseescolhida;
        public:
            JogarFase();
            ~JogarFase();
            void executar();

    };
} using namespace Estados;