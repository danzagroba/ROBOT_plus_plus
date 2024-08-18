#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include "Ente.hpp"
namespace Entidades
{
    class Entidade: public Ente
    {
        protected:
            sf::Vector2f posicao;

        public:
            Entidade(const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
            virtual ~Entidade();
            void setPos(const sf::Vector2f& pos);
            void mover(const sf::Vector2f& deslocamento);
            const sf::Vector2f& getPos() const;
            virtual void executar() = 0;
            virtual void salvar() = 0;
    };
}using namespace Entidades;

#endif

