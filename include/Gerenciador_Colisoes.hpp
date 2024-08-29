#pragma once

#include "ListaEntidades.hpp"
#include "Obstaculo.hpp"
#include "Inimigo.hpp"
#include "Fase.hpp"
#include "Gumbot.hpp"
#include "Projetil.hpp"

#include <list>
#include <set>
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
            vector<Inimigo*> LIs;
            list<Obstaculo*> LOs;
            vector<Jogador*> LJs;
            set<Projetil*> LPs;

        private:
            Gerenciador_Colisoes();
            ~Gerenciador_Colisoes();

        public:
            static Gerenciador_Colisoes* getGerenciador_Colisoes();

            bool calculaColisao(Entidade* e1, Entidade* e2);
            void limparlistas();
            void inserirInimigos(Inimigo* e);
            void inserirObstaculos(Obstaculo* e);
            void inserirJogadores(Jogador* e);
            void inserirProjetil(Projetil* e);

            void checarColisoesObstaculos();
            void tratarColisao(Entidade* e1, Entidade* e2);
            void tratarColisaoInimigo(Entidade* e1, Entidade* e2);
            void tratarColisaoJogadorInimigo(Entidade* e1, Entidade* e2);
    };
} using namespace Gerenciadores;