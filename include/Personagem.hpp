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
                bool no_ar;
                bool puloBloqueado;

            public:
                Personagem(const int nVidas = 0, 
                           const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f), 
                           const sf::Vector2f& dimensoes = sf::Vector2f(0.0f, 0.0f));
                virtual ~Personagem();
                
                void pulo();
                void setno_ar(bool na);
                void permitirPulo();

                void tomarDano(const int dano);
                void setNumVidas(const int nVidas);

                void aplicarForcaY(const float forca);

                virtual void executar() = 0;
                virtual void salvar() = 0;
        };  
    } using namespace Personagens;
} using namespace Entidades;


#endif

