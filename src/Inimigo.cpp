#include "Inimigo.hpp"

namespace Entidades
{
    namespace Personagens
    {        
        
        Inimigo::Inimigo(const int nVidas, 
                         const sf::Vector2f& pos,
                         const int maldade)
            : Personagem(nVidas, pos), nivelMaldade(maldade)
        {
            id = 3;
        }
        
        Inimigo::~Inimigo()
        {}
        
        void Inimigo::danificar(Jogador* pJog)
        {
            pJog->tomarDano(nivelMaldade);
        }
    }
}