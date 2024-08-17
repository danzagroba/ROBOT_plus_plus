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
                Jogador(const float vel = 0.0f, const int nVidas = 0, const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                ~Jogador();
                void executar();
                void salvar();
        };
    } using namespace Personagens;
} using namespace Entidades;



#endif
