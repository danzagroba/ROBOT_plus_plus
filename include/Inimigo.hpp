#pragma once 

#include "Jogador.hpp"

namespace Entidades
{
    namespace Personagens
    {
        class Inimigo : public Personagem
        {
        protected:
            int nivelMaldade;
        
        public:
            Inimigo(const int nVidas = 0, 
                    const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f),
                    const int maldade = 0);
            virtual ~Inimigo();

            void danificar(Jogador* pJog);
            virtual void salvar() = 0;
            virtual void executar() =0;
        };
    }
}