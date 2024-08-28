#include "ProjectileBot.hpp"

std::list<Projetil*> ProjectileBot::projeteis;
namespace Entidades
{
    namespace Personagens
    {

        ProjectileBot::ProjectileBot(const sf::Vector2f& pos)
            : Inimigo(3, pos, 1)
        {
            id = 12;
            setFigura(PROJECTILEBOT_SPRITE_PATH);
            tempo.restart();
        }
        
        ProjectileBot::~ProjectileBot()
        {
            
        }
        
        void ProjectileBot::criartiro()
        {
            if(tempo.getElapsedTime().asSeconds()>1.5)
            {
                Projetil* pprojetil = new Projetil(this, 1, sf::Vector2f(-0.1f, -0.1f), 20);
                if(pprojetil)
                {
                    projeteis.push_back(pprojetil);
                }
                tempo.restart();
            }
        }

        void ProjectileBot::removertiro(Projetil* ep)
        {
            list<Projetil*>::iterator it = std::find(projeteis.begin(), projeteis.end(), ep);
            if (it != projeteis.end()) {
                projeteis.erase(it);
            }
        }

        void ProjectileBot::executar()
        {
            aplicarForcaY(gravidade);
            criartiro();
            mover();
        }

        list<Projetil*>* ProjectileBot::getprojeteis() {
            return &projeteis;
        }
        
        void ProjectileBot::salvar()
        {}
    }
}