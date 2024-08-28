#include "Agua.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        int Agua::dano(1);

        Agua::Agua(const sf::Vector2f& pos)
            : Obstaculo(pos, sf::Vector2f(16.0f, 16.0f), true)
        {
            id = 9;
            setFigura("../assets/water.png");
            setPos(posicao.x, posicao.y+1);
        }
        
        Agua::~Agua()
        {}
        
        void Agua::executar() 
        {
        }
        
        void Agua::obstacular() 
        {
        }

        void Agua::salvar()
        {
        }

        const int Agua::getDano()
        {
            return dano;
        }
    }
}