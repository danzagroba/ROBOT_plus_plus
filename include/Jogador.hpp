#ifndef _JOGADOR_H_
#define _JOGADOR_H_

#include "Personagem.hpp"
#include <string>
using namespace std;

namespace Entidades
{
    namespace Personagens
    {
        class Jogador:public Personagem
        {
            private:
                int pontos;
                string nome;
            public:
                Jogador();
                ~Jogador();
                void executar();

        };
    } using namespace Personagens;
} using namespace Entidades;



#endif