#include "Agua.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        int Agua::dano(3);

        Agua::Agua(const sf::Vector2f& pos)
            : Obstaculo(pos, sf::Vector2f(16.0f, 16.0f), true)
        {
            id = 9;
            setFigura("../assets/water.png");
        }
        
        Agua::~Agua()
        {}
        
        void Agua::executar() 
        {
            desenhar();
        }
        
        void Agua::obstacular() 
        {
            // rodar animação?
        }

        const int Agua::getDano()
        {
            return dano;
        }
    }
}