#ifndef _PERSONAGEM_H_
#define _PERSONAGEM_H_

#include "Entidade.hpp"
namespace Entidades
{
    namespace Personagens 
    {
        class Personagem: public Entidade 
        {
            protected:
                int num_vidas;
                float velocidade;
            public:
                Personagem(const float vel = 0.0f, 
                           const int nVidas = 0, 
                           const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f), 
                           const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f));
                virtual ~Personagem();
                
                void setNumVidas(const int nVidas);
                const float getVel() const;
                virtual void executar() = 0;
                virtual void salvar() = 0;

        };  
    } using namespace Personagens;
} using namespace Entidades;


#endif

