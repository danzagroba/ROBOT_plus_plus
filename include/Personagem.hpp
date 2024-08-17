#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.hpp"
namespace Entidades
{
    namespace Personagens 
    {
        class Personagem: public Entidade 
        {
            protected:
                int num_vidas;
                int velocidade;
            public:
                Personagem();
                ~Personagem();
                void setNumVidas(const int nVidas);
                virtual void executar() = 0;
        };  
    } using namespace Personagens;
} using namespace Entidades;


#endif