#include "Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {        
        
        Inimigo::Inimigo(const int nVidas, 
                         const sf::Vector2f& pos, 
                         const sf::Vector2f& dimensoes, 
                         const int maldade)
            : Personagem(nVidas, pos, dimensoes), nivelMaldade(maldade)
        {}
        
        Inimigo::~Inimigo()
        {}
        
        void Inimigo::danificar(Jogador* pJog)
        {
            pJog->tomarDano(nivelMaldade);
        }
    }
}