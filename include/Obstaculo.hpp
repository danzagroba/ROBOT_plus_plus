#ifndef _OBSTACULO_H_
#define _OBSTACULO_H_

#include "Entidade.hpp"
#include "Jogador.hpp"
namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo: public Entidade
        {
            protected:
                bool danoso;
            public:
                virtual void executar() = 0;
                virtual void obstacular(Jogador* p) = 0;
        };
    } using namespace Obstaculos;
} using namespace Entidades;

#endif
