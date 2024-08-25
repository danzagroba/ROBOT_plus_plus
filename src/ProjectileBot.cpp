#include "ProjectileBot.hpp"

namespace Entidades
{
    namespace Personagens
    {
        const int ProjectileBot::nProjeteis(3);

        ProjectileBot::ProjectileBot(const sf::Vector2f& pos)
            : Inimigo(3, pos, 1),
              projetil(NULL)
        {
            id = 12;
            setFigura(PROJECTILEBOT_SPRITE_PATH);
            projetil = new Projetil(this, 1, sf::Vector2f(-0.1f, -0.0f));
        }
        
        ProjectileBot::~ProjectileBot()
        {
            // O projetil e deletado na lista de entidades por enquanto
            // delete projetil;
            projetil = NULL;
        }
        
        void ProjectileBot::executar()
        {
            aplicarForcaY(gravidade);
            mover();
        }
    
        void ProjectileBot::salvar()
        {}

        Projetil* ProjectileBot::getProjetil()
        {
            return projetil;
        }
    }
}