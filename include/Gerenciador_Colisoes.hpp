#pragma once

#include "ListaEntidades.hpp"
#include "Obstaculo.hpp"
#include "Entidade.hpp"
#include "Fase.hpp"

#include <list>
#include <SFML/Window/Event.hpp>
#include <iostream>
using namespace std;

using namespace std;

//Padrão de projeto singleton e mediator
namespace Gerenciadores
{
    class Gerenciador_Colisoes
    {
        private:
            static Gerenciador_Colisoes* pgercol;
            //vector<Inimigo*> LIs;
            list<Obstaculo*> LOs;
            //ListaEntidades* obstaculos;
            ListaEntidades* jogadores;
            ListaEntidades* inimigos;

        private:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

            const bool colidiuComTile(const sf::FloatRect& bBox);

        public:
            static Gerenciador_Colisoes* getGerenciador_Colisoes();

            void setJogadores(ListaEntidades* jogs);
            void setInimigos(ListaEntidades* inims);

            bool calculaColisao(Entidade* e1, Entidade* e2);
            void inserirObstaculos(Obstaculo* e);
            void checarColisoesObstaculos();
            void tratarColisao(Entidade* e1, Entidade* e2);
    };
} using namespace Gerenciadores;