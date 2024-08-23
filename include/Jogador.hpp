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
                static bool doisjogadores;

            public:
                Jogador(const sf::Vector2f& vel = sf::Vector2f(0.0f, 0.0f), 
                        const int nVidas = 0, 
                        const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                ~Jogador();
                
                static bool getdoisjogadores();
                void executar();
                void salvar();
        };
    } using namespace Personagens;
} using namespace Entidades;


#endif

