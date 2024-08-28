#pragma once

#include<list>

#include "Inimigo.hpp"
#include "Projetil.hpp"

#define PROJECTILEBOT_SPRITE_PATH "../assets/projectileBot.png"

namespace Entidades
{
    namespace Personagens
    {
        class ProjectileBot : public Inimigo
        {
        private:
            static list<Projetil*> projeteis;
            sf::Clock tempo;


        public:
            ProjectileBot(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
            ~ProjectileBot();
        
            void criartiro();
            static void removertiro(Projetil* ep);

            static std::list<Projetil*>* getprojeteis();
            void executar();
            void salvar();
        
        };
    }
}