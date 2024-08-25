#pragma once 

#include "Entidade.hpp"

#define PROJETIL_SPRITE_PATH "../assets/projetil.png"

namespace Entidades
{
    class Projetil : public Entidade
    {
    private:
        int dano;
        Entidade* dono;
        sf::Vector2f forca;

    public:
        Projetil(Entidade* donoDoProjetil = NULL, 
                 const int danoProjetil = 0, 
                 const sf::Vector2f& forcaInicial = sf::Vector2f(0.0f, 0.0f));
        ~Projetil();

        const int getDano() const;
        void resetar();    // Reseta a posição do projetil para a posicao do dono do projetil
        
        void executar();    // Atualiza a posição do projetil
        void salvar();
    };
}