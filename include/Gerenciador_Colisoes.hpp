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

//Padrão de projeto singleton e mediator (não tem abstrata de mediator)
//Centralização da lógica de interação: Gerenciador_Colisoes centraliza toda a lógica de colisão e interação entre entidades
//Intermediação da comunicação as entidades : Projetil, jogador, e outras entidades se comunicam INDIRETAMENTE através do gerenciador.
//Redução do acoplamento: as entidades não precisam conhecer os detalhes uma das outras pois o gerenciador lida com as interações.
//Flexibilidade e extensibilidade: novas entidades(desde que numa das classes definidas nos containers) podem ser adicionadas
//Sem afetar as classes existentes tornando o sistema flexivel e extensivel.
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