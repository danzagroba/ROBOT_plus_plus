#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.hpp"

#include <SFML/Graphics.hpp>

namespace Entidades
{
    namespace Personagens 
    {
        class Personagem: public Entidade 
        {
            protected:
                int num_vidas;
                sf::Vector2f velocidade;
                static const float maxVel;

            public:
                Personagem(const sf::Vector2f& vel = sf::Vector2f(0.0f, 0.0f), 
                           const int nVidas = 0, 
                           const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f), 
                           const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f));
                virtual ~Personagem();
                void pulo();
                void setNumVidas(const int nVidas);

                const sf::Vector2f& getVel() const;
                const float getXVel() const;
                const float getYVel() const;

                void setVel(const sf::Vector2f& vel);
                void setXvel(const float vel);
                void setYvel(const float vel);

                void aplicarForca(const sf::Vector2f& forca);
                void aplicarForcaY(const float forca);
                void aplicarForcaX(const float forca);

                void mover();

                virtual void executar() = 0;
                virtual void salvar() = 0;
        };  
    } using namespace Personagens;
} using namespace Entidades;


#endif

