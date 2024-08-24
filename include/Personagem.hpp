#pragma once

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
                sf::Clock relogio;

            public:
                Personagem(const int nVidas = 0, 
                           const sf::Vector2f& pos = sf::Vector2f(0.0f, 0.0f));
                virtual ~Personagem();
                
                void pulo();
                void setno_ar(bool na);
                void permitirPulo();

                virtual void tomarDano(const int dano);
                void setNumVidas(const int nVidas);

                void aplicarForcaY(const float forca);

                virtual void executar() = 0;
                virtual void salvar() = 0;
        };  
    } using namespace Personagens;
} using namespace Entidades;


