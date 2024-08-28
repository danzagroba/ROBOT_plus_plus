#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include <SFML/Graphics.hpp>

#include "Ente.hpp"

namespace Entidades
{
    class Entidade: public Ente
    {
        protected:
            sf::Vector2f posicao;
            sf::FloatRect AreaColisao;
            sf::Vector2f velocidade;
            static const float maxVel;
            static float gravidade;

        public:
            Entidade(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f), 
                     const sf::Vector2f& vel = sf::Vector2f(0.0f, 0.0f));
            virtual ~Entidade();
            void setPos(float xx, float yy);
            void mover();
            const sf::Vector2f& getPos() const;
            const sf::Vector2f& getVel() const;
            const float getXVel() const;
            const float getYVel() const;
            void setXvel(const float vel);
            void setYvel(const float vel);
            void setBoundingBox();
            virtual void executar() = 0;
            virtual void salvar() = 0;
            void setFigura(const std::string& Sprite_Path);
            sf::FloatRect getBoundingBox();
            static void setGravidade(float g);
            //virtual bool colidecomEntidade();
            //virtual void aocolidir();
    };
}using namespace Entidades;

#endif

