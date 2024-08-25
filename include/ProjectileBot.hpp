#pragma once

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
            static const int nProjeteis;
            Projetil* projetil;

        public:
            ProjectileBot(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
            ~ProjectileBot();
        
            void executar();
            void salvar();
        
            Projetil* getProjetil();
        };
    }
}